#include "MockUplinkReceiver.h"

MockUplinkReceiver::MockUplinkReceiver(std::string url, zmq::context_t& context, zmq::socket_type type) : socket(context, type){
    ip = url;
    socket.connect(ip);
}

void MockUplinkReceiver::recieve(){
    for (int i = 0; i < 10; ++i) {
        zmq::message_t zmq_message;
        std::optional<long unsigned int> s = socket.recv(zmq_message, zmq::recv_flags::none);
        std::string message(static_cast<char*>(zmq_message.data()), zmq_message.size());
        std::cout << "Received: " << message << std::endl;
    }
}



void MockUplinkReceiver::close(){
    socket.close();
}


int main(){
    zmq::context_t ctx(1);
    MockUplinkReceiver receiver{"tcp://localhost:5556", ctx, zmq::socket_type::pull};
    receiver.recieve();
}


