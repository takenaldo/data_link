#include <iostream>
#include <string>
#include <sstream>
#include <vector>


#include "DataLinkMessage.h"

DataLinkMessage::DataLinkMessage(){
    
}

DataLinkMessage::DataLinkMessage(std::string data_link_message){

    // Create a stringstream object with the input string
    std::stringstream ss(data_link_message);

    // Tokenize the input string by comma delimiter
    std::string token;
    std::vector<std::string> tokens;
    char delimiter = ',';

    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }



    // Output the string after splitting
    // std::cout << "String after splitting: "<< data_link_message << std::endl;

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



