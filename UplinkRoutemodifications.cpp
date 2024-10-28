#include <iostream>
#include <vector>
#include "UplinkRoutemodifications.h"
UplinkRoutemodifications::UplinkRoutemodifications(const std::string& mesg) {
    URGENCY= URGENCY::Normal;
    alert = ALRT::MediumAlert;
    MessageElement = mesg;
    assignID();
}

UplinkRoutemodifications::~UplinkRoutemodifications() {}

void UplinkRoutemodifications::displayRouteDetails() {
    std::cout << "Message: " << MessageElement << std::endl;
    std::cout << "URGENCYLevel: " << URGENCY<< std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkRoutemodifications::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + MessageElement +
           ", URGENCYency: " + std::to_string(URGENCYency) + ", Alert: " + std::to_string(alert);
}

void UplinkRoutemodifications::assignID() {
    if (MessageElement.find("PROCEED DIRECT TO") != std::string::npos && MessageElement.find("WHEN ABLE") == std::string::npos) {
        id = 74;
    } else if (MessageElement.find("WHEN ABLE PROCEED DIRECT TO") == 0) {
        id = 75;
    } else {
        id = -1;
    }
}