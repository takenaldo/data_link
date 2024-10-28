#include <iostream>
#include <vector>
#include "UplinkConfirmationRequests.h"
UplinkConfirmationRequests::UplinkConfirmationRequests(const std::string& mesg) {
    URGENCY= URGENCY::Normal;
    alert = ALRT::LowAlert;
    MessageElement = mesg;
    assignID();
}

UplinkConfirmationRequests::~UplinkConfirmationRequests() {}

void UplinkConfirmationRequests::displayComfirmationDetails() {
    std::cout << "Message: " << MessageElement << std::endl;
    std::cout << "URGENCYLevel: " << URGENCY<< std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkConfirmationRequests::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + MessageElement +
           ", URGENCYency: " + std::to_string(URGENCYency) + ", Alert: " + std::to_string(alert);
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