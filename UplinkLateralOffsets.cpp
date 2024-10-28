#include <iostream>
#include <vector>
#include "UplinkLateralOffsets.h"
UplinkLateralOffsets::UplinkLateralOffsets(const std::string& mesg) {
    urgent= URGENCY::Normal;
    alert = ALERT::MediumAlert;
    MessageElement = mesg;
    assignID();
}

UplinkLateralOffsets::~UplinkLateralOffsets() {}

void UplinkLateralOffsets::displayOffsetDetails() {
    std::cout << "Message: " << MessageElement << std::endl;
    std::cout << "URGENCYLevel: " << urgent<< std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkLateralOffsets::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + MessageElement +
           ", URGENCY: " + std::to_string(urgent) + ", Alert: " + std::to_string(alert);
}

void UplinkLateralOffsets::assignID() {
    if (MessageElement.find("OFFSET") == 0 && MessageElement.find("AT") == std::string::npos) {
        id = 64;
    } else if (MessageElement.find("AT") == 0 && MessageElement.find("OFFSET") != std::string::npos) {
        id = 65;
    } else {
        id = -1;
    }
}