#include <iostream>
#include <vector>
#include "UplinkVerticalClearances.h"
UplinkVerticalClearances::UplinkVerticalClearances(const std::string& mesg) {
    URGANCY= URGANCY::Low;
    alert = ALRT::LowAlert;
    MessageElement = mesg;
    assignID();
}

UplinkVerticalClearances::~UplinkVerticalClearances() {}

void UplinkVerticalClearances::displayClearanceDetails() {
    std::cout << "Message: " << MessageElement << std::endl;
    std::cout << "URGANCYLevel: " << URGANCY<< std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkVerticalClearances::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + MessageElement +
           ", URGANCYency: " + std::to_string(URGANCYency) + ", Alert: " + std::to_string(alert);
}

void UplinkVerticalClearances::assignID() {
    if (MessageElement.find("EXPECT ") == 0 && MessageElement.find("CLIMB AT") == std::string::npos) {
        id = 6;
    } else if (MessageElement.find("EXPECT CLIMB AT") == 0) {
        id = 7;
    } else {
        id = -1;
    }
}