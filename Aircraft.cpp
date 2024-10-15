#include <thread>
#include "Aircraft.h"
#include "LogonRequest.h"
#include "ConnectionResponse.h"
Aircraft::Aircraft(){
    zmq::context_t senderCtx;
    zmq::socket_t senderSocket;

    zmq::context_t receiverCtx;
    zmq::socket_t receiverSocket;
}

Aircraft::Aircraft (
    std::string aircraftIdentification,
    std::string airaftRegistration,
    std::string aircraftAddress,
    std::string departure,
    std::string destination
){
    this->identification = aircraftIdentification;
    this->registeration = airaftRegistration;
    this->aircraftAddress = aircraftAddress;
    this->departure = departure;
    this->destination = destination;
}

void Aircraft::send(std::string message){

    DataLinkMessage dataLinkMessage {message};
    // TODO: dataLinkMessage valid

    zmq::context_t senderCtx;
    zmq::socket_t senderSocket;
    MockDownlinkSender mockDownLinkSender {senderIp, senderCtx, zmq::socket_type::push};

    zmq::message_t zmqMessage(message.size());
    
    memcpy(zmqMessage.data(), message.data(), message.size());

    mockDownLinkSender.socket.send(zmqMessage, zmq::send_flags::none);
    
    std::cerr << "Sent: " << message << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

}

void Aircraft::send(DataLinkMessage message){
    // if valid
    send(message.toString());
}

void Aircraft::startReceiving(){

    try{
        zmq::context_t receiverCtx(1);
        zmq::socket_t receiverSocket;
        AircraftReceiver receiver{receiverIp, receiverCtx, zmq::socket_type::pull};
        std::string receivedMessage = receiver.recieve();
        std::cout<<"Received Message: "<<receivedMessage<<"\n\n";
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
                aircraft.startReceiving();
                aircraft.startReceiving();
                std::cout<<"you want to create a connection ?\n";
                std::cout<<"1. create conection \n";
                std::cout<<"2. decline \n";
                int input;
                std::cin>>input;
                ConnectionResponse conResponse ={
                    2, "connection created"
                };
                switch (input)
                {
                case 1:
                std::cout<<"\n\ncreating connection...\n\n";
                    aircraft.send(conResponse.toString());
                    break;
                
                default:
                    break;
                }
            }
            
            break;
        case 2:
            break;

    }
    return 0;
}