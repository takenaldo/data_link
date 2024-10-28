#include <iostream>
#include <vector>
#include "UplinkAdditionalMessages.h"
UplinkAdditionalMessages::UplinkAdditionalMessages(const std::string& mesg) {
    URGENCY= URGENCY::Low;
    alert = ALRT::NoAlertingRequired;
    MessageElement = mesg;
    assignID();
}

UplinkAdditionalMessages::~UplinkAdditionalMessages() {}

void UplinkAdditionalMessages::displayAdditionalDetails() {
    std::cout << "Message: " << MessageElement << std::endl;
    std::cout << "URGENCYLevel: " << URGENCY<< std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkAdditionalMessages::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + MessageElement +
           ", URGENCYency: " + std::to_string(URGENCYency) + ", Alert: " + std::to_string(alert);
}

void UplinkAdditionalMessages::assignID() {
    if (MessageElement.find("WHEN READY") == 0) {
        id = 164; 
    } else if (MessageElement.find("IMMEDIATELY") == 0) {
        id = 230;  
    } else {
        id = -1;
    }
}