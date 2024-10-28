#include <iostream>
#include <vector>
#include "UplinkLateralOffsets.h"
UplinkLateralOffsets::UplinkLateralOffsets(const std::string& mesg) {
    URGANCYency = URGANCY::Normal;
    alert = ALRT::MediumAlert;
    MessageElement = mesg;
    assignID();
}

UplinkLateralOffsets::~UplinkLateralOffsets() {}

void UplinkLateralOffsets::displayOffsetDetails() {
    std::cout << "Message: " << MessageElement << std::endl;
    std::cout << "URGANCYency Level: " << URGANCYency << std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkLateralOffsets::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + MessageElement +
           ", URGANCYency: " + std::to_string(URGANCYency) + ", Alert: " + std::to_string(alert);
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