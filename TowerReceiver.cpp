#include "TowerReceiver.h"
#include "DataLinkMessage.h"


TowerReceiver::TowerReceiver(std::string url, zmq::context_t& context, zmq::socket_type type) : socket(context, type){
    ip = url;
    socket.connect(ip);
}

std::string TowerReceiver::recieve(){
    zmq::message_t zmqMessage;
    std::optional<long unsigned int> s = socket.recv(zmqMessage, zmq::recv_flags::none);
    std::string message(static_cast<char*>(zmqMessage.data()), zmqMessage.size());

    std::cout << "Received: " << message << std::endl;

    return message;

    // DataLinkMessage downlink {message};

    // std::cout<<"ID:                     "<<downlink.id<<std::endl;
    // std::cout<<"Message Type:           "<<downlink.messageType<<std::endl;
    // std::cout<<"Message:                "<<downlink.message<<std::endl;
    // std::cout<<"Min:                    "<<downlink.min<<std::endl;
    // std::cout<<"Mrn:                    "<<downlink.mrn<<std::endl;
    // std::cout<<"Response required:      "<<downlink.responseRequired<<std::endl;


}


// int main(){
//     zmq::context_t ctx(1);
//     TowerReceiver receiver{"tcp://localhost:5555", ctx, zmq::socket_type::pull};
//     receiver.recieve();
// }


