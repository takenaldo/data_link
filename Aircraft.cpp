#include <thread>
#include "Aircraft.h"
#include "AircraftReceiver.h"
#include "LogonRequest.h"
#include "ConnectionResponse.h"

#include "DownLinkMessages/Roger.cpp"
#include "DownLinkMessages/RequestLevel.cpp"



Aircraft::Aircraft(){
    zmq::context_t sender_ctx;
    zmq::socket_t sender_socket;
    
    zmq::context_t receiver_ctx;
    zmq::socket_t receiver_socket;

}

Aircraft::Aircraft (
    std::string aircraft_identification,
    std::string airaft_registration,
    std::string aircraft_address,
    std::string departure,
    std::string destination
)
{
    this->identification = aircraft_identification;
    this->registeration = airaft_registration;
    this->aircraft_address = aircraft_address;
    this->departure = departure;
    this->destination = destination;
}


void Aircraft::send(std::string message){

    // DataLinkMessage dataLinkMessage {message};
    // TODO: dataLinkMessage valid

    zmq::context_t sender_ctx;
    zmq::socket_t sender_socket;
    MockDownlinkSender mockDownLinkSender {sender_ip, sender_ctx, zmq::socket_type::push};

    zmq::message_t zmq_message(message.size());
    
    memcpy(zmq_message.data(), message.data(), message.size());

    mockDownLinkSender.socket.send(zmq_message, zmq::send_flags::none);
    
    std::cerr << "Sent: " << message << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

}


void Aircraft::send(DataLinkMessage message){
    // if valid
    send(message.toString());
}


// Start Receiving Messages
void Aircraft::startReceiving() {
    std::cout << "Aircraft is ready to receive Logon Responses...\n" << std::endl;

    // while (true) {
        try {

            zmq::context_t receiver_ctx(1);
            zmq::socket_t receiver_socket;    
            AircraftReceiver receiver{receiver_ip,  receiver_ctx, zmq::socket_type::pull};
            std::string receivedMessage = receiver.recieve();
            std::cout<<"Received Message: "<<receivedMessage<<"\n\n";
        

            // zmq::socket_t receiver_socket;
            // zmq::message_t zmq_message;
            //  std::string receiver_ip = "tcp://127.0.0.1:5555";
            // zmq::context_t receiver_ctx{1}; // Initialize with 1 I/O thread

            // AircraftReceiver receiver{receiver_ip,  receiver_ctx, zmq::socket_type::pull };
            // std::string receivedMessage = receiver.recieve();
            // std::cout<<"Received Message: "<<receivedMessage<<"\n\n";
    
        }
        catch (const zmq::error_t& e) {
            std::cerr << "ZeroMQ Error: " << e.what() << std::endl;
            // break; // Exit loop on error
        }
        // catch (const std::invalid_argument& e) {
        //     std::cerr << "Invalid Argument: " << e.what() << std::endl;
        // }
    }

    //// //  =========================connection Response 


    void Aircraft::startResponse(){

    try{
        zmq::context_t ctx(1);
        AircraftReceiver receiver{receiver_ip, ctx, zmq::socket_type::pull};
        std::string received_message = receiver.recieve();
        std::cout<<"Connected ======== "<<received_message<<"\n\n\n";

        // DataLinkMessage datalinkMessage{received_message};
        //  std::cout << "Received Message ID: " << datalinkMessage.m_id << std::endl;
        // std::cout << "Expected DM_CONNECTION_RESPONSE ID: " << DataLinkMessage::DM_CONNECTION_RESPONSE << std::endl;

        // if (datalinkMessage.m_id == DataLinkMessage::DM_CONNECTION_RESPONSE){
        //     std::cout << "\n\nCONNECTION REQUEST RECEIVED\n";
        //      std::cout << "Connection Status : " << datalinkMessage.message << std::endl;

        //         if (datalinkMessage.message == "ACCEPTED") {
        //             std::cout << "Connection has been accepted." << std::endl;
                    
        //         }
        //         else if (datalinkMessage.message == "REJECTED") {
        //             std::cout << "Connection has been rejected." << std::endl;
                 
        //         }
        //         else {
        //             std::cout << "Unknown connection status received." << std::endl;
        //         }


        // } else {
        //     std::cout << "Received message ID does not match DM_CONNECTION_RESPONSE.\n";
        // }

    }
       
     catch (const std::invalid_argument& e) {
        std::cout<<e.what();
     }
}


int main(){

    Aircraft aircraft{"ET-AUE", "N704YA", "A0B1C2","HAAB", "HASC"};

    std::cout<<"Start Sending ..."<<std::endl; 

    dm::response::Roger roger;

    dm::vertical_request::RequestLevel requestlevel{180};

    aircraft.send(requestlevel);

    return 0;
}

