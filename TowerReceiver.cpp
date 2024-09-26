#include "TowerReceiver.h"

TowerReceiver::TowerReceiver(std::string url, zmq::context_t& context, zmq::socket_type type) : socket(context, type){
    ip = url;
    socket.connect(ip);
}

void TowerReceiver::recieve(){
    for (int i = 0; i < 10; ++i) {
        zmq::message_t zmq_message;
        std::optional<long unsigned int> s = socket.recv(zmq_message, zmq::recv_flags::none);
        std::string message(static_cast<char*>(zmq_message.data()), zmq_message.size());
        std::cout << "Received: " << message << std::endl;
    }
}


int main(){
    zmq::context_t ctx(1);
    TowerReceiver receiver{"tcp://localhost:5555", ctx, zmq::socket_type::pull};
    receiver.recieve();
}


