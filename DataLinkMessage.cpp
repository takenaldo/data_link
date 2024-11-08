#include <iostream>
#include <string>
#include <sstream>
#include <vector>


#include "DataLinkMessage.h"

// DataLinkMessage::DataLinkMessage(){
    
// }

// DataLinkMessage::DataLinkMessage(std::string data_link_message){

//     // Create a stringstream object with the input string
//     std::stringstream ss(data_link_message);

//     // Tokenize the input string by comma delimiter
//     std::string token;
//     std::vector<std::string> tokens;
//     char delimiter = ',';

//     while (getline(ss, token, delimiter)) {
//         tokens.push_back(token);
//     }



//     // Output the string after splitting
//     // std::cout << "String after splitting: "<< data_link_message << std::endl;

//     int i = 0;
//     for (const auto& part : tokens) {
//         std::cout<<part;
//         switch (i)
//         {
//         case 0:
//             this-> messageType = part;
//             /* code */
//             break;
//         case 1:
//             this->m_id = std::stoi(part);
//             break;
//         case 2:
//             this->message = part;
//             /*
//             TODO: based on the message text create a message type class
            
//             */
//             break;
//         default:
//             break;
//         }
//         i++;
//     }
// }

// DataLinkMessage::DataLinkMessage(      
//         std::string messageType,
//         int id,
//         int min,
//         int mrn,
//         std::string message,
//         std::string URG,
//         std::string ALRT,
//         bool responseRequired
// ){
//     this->messageType = messageType;
//     this->m_id = id;
//     this->min = min;
//     this->mrn = mrn;
//     this->message = message;
//     this->responseRequired = responseRequired;

// }


DataLinkMessage::DataLinkMessage(
    std::string messageCategory, int id, Alert alert, Urgency urgency, PermittedResponseGroup permittedResponseGroup
):
m_id(id),
m_messageCategory(messageCategory), 
m_alert(alert), 
m_urgency(urgency), 
// m_permittedResponses(permittedResponses),
m_prg(permittedResponseGroup)


{}

int DataLinkMessage::getID(){
    return m_id;
}

std::string DataLinkMessage::getMessage(){
    return message;
}

Alert DataLinkMessage::getAlert(){
    return m_alert;
}

Urgency DataLinkMessage::getUrgency(){
    return m_urgency;
}

void DataLinkMessage::setID(int id){
    m_id = id;
}

void DataLinkMessage::setAlert(Alert alert){
    m_alert = alert;
}

void DataLinkMessage::setUrgency(Urgency urgency){
    m_urgency = urgency;
}

std::string DataLinkMessage::getTypeInfo(){
    return "Urgency: "+ std::to_string(getUrgency()) + "\t\tAlert: " + std::to_string(getAlert());
}

std::string DataLinkMessage::getMessageCategory(){
    return m_messageCategory;
}

std::vector<std::type_index> DataLinkMessage::getPermittedResponses(){
    return m_permittedResponses;
}


PermittedResponseGroup DataLinkMessage::getPermittedResponseGroup(){
    return m_prg;
}


void DataLinkMessage::setMessage(std::string msg){
    message = msg;
}

std::string DataLinkMessage::toString(){
    return m_messageCategory +","+ std::to_string(m_id) +","+ message;
}

std::string DataLinkMessage::buildMessage(std::vector<std::variant<int, float, double, std::string>> phrases){

    std::string msg = "";

    for(auto phrase : phrases){
        if(std::holds_alternative<int>(phrase))
            msg += std::to_string(std::get<int>(phrase));
        else if(std::holds_alternative<float>(phrase))
            msg += std::to_string(std::get<float>(phrase));        
        else if(std::holds_alternative<double>(phrase))
            msg += std::to_string(std::get<double>(phrase));        
        else
            msg += std::get<std::string>(phrase);        
    
        msg += " ";
    }
    return msg;
}


bool DataLinkMessage::isResponsePermitted(const std::type_info& msgTypeID){
    // std::vector<std::type_index> classTypes = getPermittedResponses();


    // Variable to check
    // dm::response::Roger var;

    // Check if the variable's type matches any in the array
    std::type_index varType = (msgTypeID);
    bool matchFound = false;

    for (const auto& type : getPermittedResponses()) {
        std::cout<<".... "<<type.name()<<" === "<<varType.name()<<"\n\n";
        if (varType == type) {
            // std::cout<<".... "<<varType.name();

            matchFound = true;
            break;
        }
    }

    if (matchFound) {
        std::cout << "\nThe variable matches one of the class types in the array." << std::endl;
        return true;
    } else {
        std::cout << "\nThe variable does not match any of the class types in the array.";
        return false;
    }

    }

