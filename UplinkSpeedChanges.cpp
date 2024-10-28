#include <iostream>
#include <vector>
#include "UplinkSpeedChanges.h"
UplinkSpeedChanges::UplinkSpeedChanges(const std::string& mesg) {
    URGENCY= URGENCY::Low;
    alert = ALRT::LowAlert;
    MessageElement = mesg;
    assignID();
}

UplinkSpeedChanges::~UplinkSpeedChanges() {}

void UplinkSpeedChanges::displaySpeedDetails() {
    std::cout << "Message: " << MessageElement << std::endl;
    std::cout << "URGENCYLevel: " << URGENCY<< std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkSpeedChanges::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + MessageElement +
           ", URGENCYency: " + std::to_string(URGENCYency) + ", Alert: " + std::to_string(alert);
}

void UplinkSpeedChanges::assignID() {
    if (MessageElement.find("AT TIME") == 0 && MessageElement.find("EXPECT") != std::string::npos) {
        id = 100;
    } else if (MessageElement.find("AT POSITION") == 0 && MessageElement.find("EXPECT") != std::string::npos) {
        id = 101;
    } else {
        id = -1;
    }
}