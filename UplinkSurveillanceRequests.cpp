#include <iostream>
#include <vector>
#include "UplinkSurveillanceRequests.h"
UplinkSurveillanceRequests::UplinkSurveillanceRequests(const std::string& mesg) {
    URGENCY= URGENCY::Normal;
    alert = ALRT::MediumAlert;
    MessageElement = mesg;
    assignID();
}

UplinkSurveillanceRequests::~UplinkSurveillanceRequests() {}

void UplinkSurveillanceRequests::displaySurcillanceDetails() {
    std::cout << "Message: " << MessageElement << std::endl;
    std::cout << "URGENCYLevel: " << URGENCY<< std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkSurveillanceRequests::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + MessageElement +
           ", URGENCYency: " + std::to_string(URGENCYency) + ", Alert: " + std::to_string(alert);
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