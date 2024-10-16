#include"AircraftReceiver.h"
#include"DataLinkMessage.h"

AircraftReceiver::AircraftReceiver(std::string url, zmq::context_t& context, zmq::socket_type type) : socket(context, type){
    ip = url;
    socket.connect(ip);
}
std::string AircraftReceiver::recieve(){
     zmq::message_t zmqMessage;
    std::optional<long unsigned int> s = socket.recv(zmqMessage, zmq::recv_flags::none);
    std::string message(static_cast<char*>(zmqMessage.data()), zmqMessage.size());
    return message;
}