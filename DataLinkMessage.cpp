#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "DataLinkMessage.h"

DataLinkMessage::DataLinkMessage(){
    
}

DataLinkMessage::DataLinkMessage(std::string dataLinkMessage){

    // Create a stringstream object with the input string
    std::stringstream ss(dataLinkMessage);

    // Tokenize the input string by comma delimiter
    std::string token;
    std::vector<std::string> tokens;
    char delimiter = ',';

    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }



    // Output the string after splitting
    // std::cout << "String after splitting: "<< dataLinkMessage << std::endl;

    int i = 0;
    for (const auto& part : tokens) {
        std::cout<<part;
        switch (i)
        {
        case 0:
            this-> messageType = part;
            /* code */
            break;
        case 1:
            this->id = std::stoi(part);
            break;
        case 2:
            this->message = part;
            /*
            TODO: based on the message text create a message type class
            
            */
            break;
        default:
            break;
        }
        i++;
    }
}

DataLinkMessage::DataLinkMessage(      
        std::string messageType,
        int id,
        int min,
        int mrn,
        std::string message,
        bool responseRequired
){
    this->messageType = messageType;
    this->id = id;
    this->min = min;
    this->mrn = mrn;
    this->message = message;
    this->responseRequired = responseRequired;

}

std::string DataLinkMessage::toString(){
    std::string msg = messageType +","+ std::to_string(id) +","+ message;
    return  msg;
}



// int main(){
//     DataLinkMessage dataLinkMessage {};
//     dataLinkMessage.messageType = "DM";
//     dataLinkMessage.id = 6;
//     dataLinkMessage.message = "REQUEST FL350";
//     dataLinkMessage.min = 8;
//     dataLinkMessage.mrn = 0;
//     dataLinkMessage.responseRequired = false;

//     std::cout<<"Data Link message: "<<dataLinkMessage.toString()<<std::endl;



//     return 0;
// }
