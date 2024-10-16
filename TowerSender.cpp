#include <iostream>
// #include <string>
#include <zmq.hpp>
#include <thread>

#include "TowerSender.h"
#include "DataLinkMessage.h"

TowerSender::TowerSender(std::string url,zmq::context_t& context, zmq::socket_type type)
    : socket(context, type)
{
    ip = url;
    socket.bind(ip);
}

TowerSender::~TowerSender()
{
        std::cout << "****"; // It was linke this  std::cout << "In Tower Socket Destructor"; i edit it becuse i get distracted in mt tower.cpp out put at coonectionrequest 
}

void TowerSender::print(std::string msg){
    std::cout << "in print"<< msg;
}


void TowerSender::send(std::string message){
    
    zmq::message_t zmq_message(message.size());
    memcpy(zmq_message.data(), message.data(), message.size());
    socket.send(zmq_message, zmq::send_flags::none);
    std::cerr << "Sent: " << message << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void TowerSender::close(){
    socket.close();
}


// int main(){
//     zmq::context_t ctx(1);
//     TowerSender towerSender{"tcp://*:5556", ctx, zmq::socket_type::push};


//     // DataLinkMessage dataLinkMessage {"UM,6,RESPONSE,WILCO"};

//     DataLinkMessage dataLinkMessage {};
//     dataLinkMessage.messageType = "UM";
//     dataLinkMessage.id = 1;
//     dataLinkMessage.message = "STANDBY";
//     dataLinkMessage.min = 12;
//     dataLinkMessage.mrn = 8;
//     dataLinkMessage.responseRequired = true;


//     towerSender.send(dataLinkMessage.toString());
// }
