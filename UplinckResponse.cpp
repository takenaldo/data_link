#include <iostream>
#include "UplinckResponse.h"
#include <vector>
#include "UplinckResponse.h"
UplinkResponse::UplinkResponse(int ident, const std::string& mesg, URG::Type urg, ALRT::Type alrt)
{
    id = ident;
    urgency = urg;
    alert = alrt;
    message_element = mesg;
}


UplinkResponse::UplinkResponse(int ident, const std::string& mesg, ALRT::Type alrt) 
    {
        id = ident;
    urgency=URG::Normal;
    alert=alrt, 
    message_element=mesg;}

UplinkResponse::UplinkResponse(int ident, const std::string& mesg, URG::Type urg) 
     {
        id = ident;
    urgency=urg;
    alert=ALRT::LowAlert, 
    message_element=mesg;}
UplinkResponse::UplinkResponse(int ident, const std::string& mesg) 
     {
        id = ident;
    urgency=URG::Normal;
    alert=ALRT::LowAlert, 
    message_element=mesg;
    }

UplinkResponse::~UplinkResponse() {}

void UplinkResponse::displayResponseDetails() {
    std::cout << "Message: " << message_element << std::endl;
    std::cout << "Urgency Level: " << urgency << std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkResponse::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + message_element +
           ", Urgency: " + std::to_string(urgency) + ", Alert: " + std::to_string(alert);
}

void assignID(std::vector<UplinkResponse>& responses) {
    for (auto& response : responses) {
        if (response.message_element == "UNABLE") {
            response.id = 0;
        }
    }
}

int main() {
    UplinkResponse response(0, "UNABLE", UplinkResponse::URG::Normal);
    UplinkResponse response1(1, "STAQNDBY",UplinkResponse::ALRT::HighAlert);
    UplinkResponse response2(2, "REUEST DEFERRED", UplinkResponse::URG::Normal, UplinkResponse::ALRT::LowAlert);
    UplinkResponse response3(3, "ROGER");
    
    std::cout << "Full Response as String: " << response.toString() << std::endl;
    std::cout << "Full Response as String: " << response1.toString() << std::endl;
    std::cout << "Full Response as String: " << response2.toString() << std::endl;
   
    return 0;
}