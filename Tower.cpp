#include <thread>
#include "Tower.h"
#include "DataLinkMessage.h"

#include "LogonResponse.h"

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
             int choice = 0 ;
             std::cout << "Choose Response to Send:\n";
                std::cout << "(1). Accepted\n";
                std::cout << "(2). Rejected\n";
                // std::cout << "(3). Other\n";
                std::cout << "Enter your choice: ";
           
                std::cin >> choice;

                LogonResponse logonResponse("Communication Stablished"); // Default response

               switch (choice) {
                    case 1:
                        logonResponse.response = "accepted";
                        break;
                    case 2:
                        logonResponse.response = "rejected";
                        std::cout << "Enter failure reason: ";
                        std::cin.ignore(); // Clear the input buffer
                        break;
                    default:
                        std::cout << "Invalid choice. Defaulting to 'accepted'." << std::endl;
                        logonResponse.response = "On process";
                        break;
                    }
             std::cout << "Sending Response: " << logonResponse.response << std::endl;

            // Serialize and send the response
            std::string responseStr = logonResponse.toString();
            send(responseStr);

            std::cout << "Response Sent Successfully.\n";

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