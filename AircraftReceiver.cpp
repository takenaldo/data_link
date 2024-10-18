
#include "TowerReceiver.h"
#include "DataLinkMessage.h"
#include "AircraftReceiver.h"

AircraftReceiver::AircraftReceiver(std::string url, zmq::context_t& context, zmq::socket_type type) : socket(context, type){
    ip = url;
    socket.connect(ip);
}

std::string AircraftReceiver::recieve(){
    zmq::message_t zmq_message;
    std::optional<long unsigned int> s = socket.recv(zmq_message, zmq::recv_flags::none);
    std::string message(static_cast<char*>(zmq_message.data()), zmq_message.size());

    std::cout << "Received: " << message << std::endl;

    return message;
}


