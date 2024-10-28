#include <iostream>
#include <vector>
#include "UplinkSystemManagementMessages.h"
UplinkSystemManagementMessages::UplinkSystemManagementMessages(const std::string& mesg) {
    urgent= URGENCY::Urgent;
    alert = ALERT::MediumAlert;
    MessageElement = mesg;
    assignID();
}

UplinkSystemManagementMessages::~UplinkSystemManagementMessages() {}

void UplinkSystemManagementMessages::displayManagementDetails() {
    std::cout << "Message: " << MessageElement << std::endl;
    std::cout << "URGENCYLevel: " << urgent<< std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkSystemManagementMessages::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + MessageElement +
           ", URGENCY: " + std::to_string(urgent) + ", Alert: " + std::to_string(alert);
}

void UplinkSystemManagementMessages::assignID() {
    if (MessageElement.find("ERROR") == 0) {
        id = 159; 
    } else if (MessageElement.find("NEXT DATA AUTHORITY") == 0) {
        id = 160;  
    } else {
        id = -1;
    }
}