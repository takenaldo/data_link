#include <thread>
#include <iostream>

#include "Tower.h"
#include "DataLinkMessage.h"
#include "LogonResponse.h"

Tower::Tower(){}

void Tower::send(std::string message){

    DataLinkMessage dataLinkMessage {message};
    // TODO: dataLinkMessage valid
    zmq::context_t sender_ctx;
    zmq::socket_t sender_socket;
    TowerSender towerSender {sender_ip, sender_ctx, zmq::socket_type::push};

    zmq::message_t zmq_message(message.size());
    memcpy(zmq_message.data(), message.data(), message.size());
    towerSender.socket.send(zmq_message, zmq::send_flags::none);
    std::this_thread::sleep_for(std::chrono::seconds(1));

}


void Tower::send(DataLinkMessage message){
    // if valid
    send(message.toString());
}


void Tower::start_receiving(){
    std::cout<<receiver_ip<<std::endl;

    try{
        zmq::context_t ctx(1);
        TowerReceiver receiver{receiver_ip, ctx, zmq::socket_type::pull};
        std::string received_message = receiver.recieve();
        std::cout<<"Received Message: "<<received_message<<"\n\n\n";

        DataLinkMessage datalinkMessage{received_message};

        if (datalinkMessage.id == DataLinkMessage::DM_LOGON_REQUEST){
            std::cout<<"\n\nLOGON REQUEST RECEIVED\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            // send("connection stablished\n");
        }

    }
     catch (const std::invalid_argument& e) {
        std::cout<<e.what();
     }
}

int main(){


    Tower tower{};

    std::cout<<"Start Receiving ..."<<std::endl; 
    tower.start_receiving();

    int input = 0;
    std::cout<<"Choose What To Do:\n";
    std::cout<<"(1). Accept\n";
    std::cout<<"(2). Decline\n\n";
    std::cin>>input;
    LogonResponse logonResponse = {
        1, "communication stablished"
    };

    switch (input)
    {
    case 1:
        std::cout<<"\n\nSending response to aircraft...\n\n";

        tower.send(logonResponse.toString());
        break;
    
    default:
        break;
    }
    return 0;
}