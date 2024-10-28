#include <iostream>
#include <vector>
#include "UplinkSurveillanceRequests.h"
UplinkSurveillanceRequests::UplinkSurveillanceRequests(const std::string& mesg) {
    urgent= URGENCY::Normal;
    alert = ALERT::MediumAlert;
    MessageElement = mesg;
    assignID();
}

UplinkSurveillanceRequests::~UplinkSurveillanceRequests() {}

void UplinkSurveillanceRequests::displaySurcillanceDetails() {
    std::cout << "Message: " << MessageElement << std::endl;
    std::cout << "URGENCYLevel: " << urgent<< std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkSurveillanceRequests::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + MessageElement +
           ", URGENCY: " + std::to_string(urgent) + ", Alert: " + std::to_string(alert);
}

void UplinkSurveillanceRequests::assignID() {
    if (MessageElement.find("CONTACT") == 0 && MessageElement.find("position") == std::string::npos) {
        id = 117;  
    } else if (MessageElement.find("AT") == 0 && MessageElement.find("position") != std::string::npos) {
        id = 118;
    } else {
        id = -1;
    }
}