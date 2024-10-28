#include <iostream>
#include <vector>
#include "UplinkConfirmationRequests.h"
UplinkConfirmationRequests::UplinkConfirmationRequests(const std::string& mesg) {
    URGANCY= URGANCY::Normal;
    alert = ALRT::LowAlert;
    MessageElement = mesg;
    assignID();
}

UplinkConfirmationRequests::~UplinkConfirmationRequests() {}

void UplinkConfirmationRequests::displayComfirmationDetails() {
    std::cout << "Message: " << MessageElement << std::endl;
    std::cout << "URGANCYLevel: " << URGANCY<< std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkConfirmationRequests::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + MessageElement +
           ", URGANCYency: " + std::to_string(URGANCYency) + ", Alert: " + std::to_string(alert);
}

void UplinkConfirmationRequests::assignID() {
    if (MessageElement == "REPORT BACK ON ROUTE") {
        id = 127;
    } else if (MessageElement.find("REPORT LEAVING") == 0) {
        id = 128;
    } else {
        id = -1;
    }
}