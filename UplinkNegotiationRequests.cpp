#include <iostream>
#include <vector>
#include "UplinkNegotiationRequests.h"
UplinkNegotiationRequests::UplinkNegotiationRequests(const std::string& mesg) {
    urgent= URGENCY::Normal;
    alert = ALERT::LowAlert;
    MessageElement = mesg;
    assignID();
}

UplinkNegotiationRequests::~UplinkNegotiationRequests() {}

void UplinkNegotiationRequests::displayNegotiationDetails() {
    std::cout << "Message: " << MessageElement << std::endl;
    std::cout << "URGENCYLevel: " << urgent<< std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkNegotiationRequests::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + MessageElement +
           ", URGENCY: " + std::to_string(urgent) + ", Alert: " + std::to_string(alert);
}

void UplinkNegotiationRequests::assignID() {
    if (MessageElement.find("WHEN CAN YOU ACCEPT") == 0) {
        id = 148;
    } else if (MessageElement.find("CAN YOU ACCEPT LEVEL") == 0 && MessageElement.find("AT") != std::string::npos) {
        id = 149;
    } else {
        id = -1;
    }
}