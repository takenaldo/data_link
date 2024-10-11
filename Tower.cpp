#include <thread>
#include <iostream>
#include "Tower.h"
#include "DataLinkMessage.h"
#include "LogonResponse.h"

Tower::Tower(){}

void Tower::send(std::string message){

    DataLinkMessage dataLinkMessage {message};
    // TODO: dataLinkMessage valid
    zmq::context_t senderCtx;
    zmq::socket_t senderSocket;
    TowerSender towerSender {senderIp, senderCtx, zmq::socket_type::push};

    zmq::message_t zmqMessage(message.size());
    memcpy(zmqMessage.data(), message.data(), message.size());
    towerSender.socket.send(zmqMessage, zmq::send_flags::none);
    std::this_thread::sleep_for(std::chrono::seconds(1));

}

void Tower::send(DataLinkMessage message){
    send(message.toString());
}

void Tower::startReceiving(){

    try{
        zmq::context_t ctx(1);
        TowerReceiver receiver{receiverIp, ctx, zmq::socket_type::pull};
        std::string receivedMessage = receiver.recieve();
        std::cout<<"Received Message: "<<receivedMessage<<"\n\n\n";

        DataLinkMessage datalinkMessage{receivedMessage};

        if (datalinkMessage.id == DataLinkMessage::DmLogonRequest){
            std::cout<<"\n\nLOGON REQUEST RECEIVED\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

    }
     catch (const std::invalid_argument& e) {
        std::cout<<e.what();
     }
}

int main(){

    Tower tower{};

    std::cout<<"Start Receiving ..."<<std::endl; 
    tower.startReceiving();

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