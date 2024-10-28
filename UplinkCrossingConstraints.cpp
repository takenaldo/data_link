#include <iostream>
#include <vector>
#include "UplinkCrossingConstraints.h"
UplinkCrossingConstraints::UplinkCrossingConstraints(const std::string& mesg) {
    URGENCY= URGENCY::Low;
    alert = ALRT::LowAlert;
    MessageElement = mesg;
    assignID();
}

UplinkCrossingConstraints::~UplinkCrossingConstraints() {}

void UplinkCrossingConstraints::displaycrossingDetails() {
    std::cout << "Message: " << MessageElement << std::endl;
    std::cout << "URGENCYLevel: " << URGENCY<< std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkCrossingConstraints::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + MessageElement +
           ", URGENCYency: " + std::to_string(URGENCYency) + ", Alert: " + std::to_string(alert);
}

void UplinkCrossingConstraints::assignID() {
    if (MessageElement.find("EXPECT TO CROSS") == 0 && MessageElement.find("AT OR ABOVE") == std::string::npos) {
        id = 42;
    } else if (MessageElement.find("EXPECT TO CROSS") == 0 && MessageElement.find("AT OR ABOVE") != std::string::npos) {
        id = 43;
    } else {
        id = -1;
    }
}