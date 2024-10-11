#include <thread>
#include "Aircraft.h"

#include "LogonRequest.h"


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
){
    this->identification = aircraft_identification;
    this->registeration = airaft_registration;
    this->aircraft_address = aircraft_address;
    this->departure = departure;
    this->destination = destination;
}


void Aircraft::send(std::string message){

    DataLinkMessage dataLinkMessage {message};
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


void Aircraft::start_receiving(){
    std::cout<<receiver_ip<<std::endl;

    try{
        zmq::context_t receiver_ctx(1);
        zmq::socket_t receiver_socket;
        AircraftReceiver receiver{receiver_ip, receiver_ctx, zmq::socket_type::pull};
        std::string received_message = receiver.recieve();
        std::cout<<"Received Message: "<<received_message<<"\n\n";
        

    }
     catch (const std::invalid_argument& e) {
        std::cout<<e.what();
     }
}

int main(){

    Aircraft aircraft{"ET-AUE", "N704YA", "A0B1C2","HAAB", "HASC"};

    std::cout<<"Start Sending ..."<<std::endl; 


    int input  = 0;

    std::cout<<"Choose What To Do:\n";
    std::cout<<"(1). Send DownLink Messages\n";
    std::cout<<"(2). Start Receiving Uplink Messages\n\n";

    std::cin>>input;
    LogonRequest logonRequest = {
        99, "HIAB", "ET-AUE", "A0B1C2", "HAAB", "HASC"
    };

    switch (input)
    {
        case 1:
            std::cout<<"\n\nSending Logon Request to Tower...\n\n";
            aircraft.send(logonRequest.toString());

            if (logonRequest.responseRequired)
            {
                aircraft.start_receiving();
            }
            
            
            break;
             
        case 2:
            break;

    }



    return 0;
}