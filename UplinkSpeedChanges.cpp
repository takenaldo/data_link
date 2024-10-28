#include <iostream>
#include <vector>
#include "UplinkSpeedChanges.h"
UplinkSpeedChanges::UplinkSpeedChanges(const std::string& mesg) {
    URGANCYency = URGANCY::Low;
    alert = ALRT::LowAlert;
    MessageElement = mesg;
    assignID();
}

UplinkSpeedChanges::~UplinkSpeedChanges() {}

void UplinkSpeedChanges::displaySpeedDetails() {
    std::cout << "Message: " << MessageElement << std::endl;
    std::cout << "URGANCYency Level: " << URGANCYency << std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkSpeedChanges::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + MessageElement +
           ", URGANCYency: " + std::to_string(URGANCYency) + ", Alert: " + std::to_string(alert);
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