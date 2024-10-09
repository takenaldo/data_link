#include <thread>


#include "Tower.h"
#include "DataLinkMessage.h"

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
    std::cerr << "Sent: " << message << std::endl;
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

    return 0;
}