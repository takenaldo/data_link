#include <iostream>
// #include <string>
#include <zmq.hpp>
#include <thread>

#include "MockDownlinkSender.h"

MockDownlinkSender::MockDownlinkSender(std::string url,zmq::context_t& context, zmq::socket_type type)
    : socket(context, type)
{
    ip = url;
    try{

    }
    catch(const zmq::error_t& e){
        std::cerr << e.what() << std::endl;
    }
    socket.bind(ip);
}

MockDownlinkSender::~MockDownlinkSender()
{
    std::cout << "In Tower Socket Destructor\n";
}



void MockDownlinkSender::send(std::string message){
    
    for (int i = 0; i < 10; ++i) {
        // std::string message = "Hello " + std::to_string(i);
        zmq::message_t zmq_message(message.size());
        
        memcpy(zmq_message.data(), message.data(), message.size());

        socket.send(zmq_message, zmq::send_flags::none);
        
        std::cerr << "Sent: " << message << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void MockDownlinkSender::close(){
    socket.close();
}


// int main(){
//     zmq::context_t ctx(1);
//     MockDownlinkSender mockDownLinkSender {"tcp://*:5555", ctx, zmq::socket_type::push};


//     DataLinkMessage dataLinkMessage {"DM,6,REQUEST,FL350"};
//     // dataLinkMessage.messageType = "DM";
//     // dataLinkMessage.id = 6;
//     // dataLinkMessage.message = "REQUEST FL350";
//     // dataLinkMessage.min = 8;
//     // dataLinkMessage.mrn = 0;
//     // dataLinkMessage.responseRequired = false;

//     mockDownLinkSender.send(dataLinkMessage.toString());
//     mockDownLinkSender.close();
// }
