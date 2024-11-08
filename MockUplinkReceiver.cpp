#include "MockUplinkReceiver.h"

MockUplinkReceiver::MockUplinkReceiver(std::string url, zmq::context_t& context, zmq::socket_type type) : socket(context, type){
    ip = url;
    socket.connect(ip);
}

void MockUplinkReceiver::recieve(){
    for (int i = 0; i < 10; ++i) {
        zmq::message_t zmqMessage;
        std::optional<long unsigned int> s = socket.recv(zmqMessage, zmq::recv_flags::none);
        std::string message(static_cast<char*>(zmqMessage.data()), zmqMessage.size());
        std::cout << "Received: " << message << std::endl;
    }
}



void MockUplinkReceiver::close(){
    socket.close();
}


// int main(){
//     zmq::context_t ctx(1);
//     MockUplinkReceiver receiver{"tcp://localhost:5556", ctx, zmq::socket_type::pull};
//     receiver.recieve();
// }


