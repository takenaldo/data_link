#include <iostream>
#include <vector>
#include "UplinckResponse.h"
UplinkResponse::UplinkResponse(const std::string& mesg) {
    URGENCY= URGENCY::Normal;
    alert = ALRT::LowAlert;
    MessageElement = mesg;
    assignID();
}

UplinkResponse::~UplinkResponse() {}

void UplinkResponse::displayResponseDetails() {
    std::cout << "Message: " << MessageElement << std::endl;
    std::cout << "URGENCYLevel: " << URGENCY<< std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkResponse::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + MessageElement +
           ", URGENCYency: " + std::to_string(URGENCYency) + ", Alert: " + std::to_string(alert);
}

void UplinkResponse::assignID() {
    if (MessageElement == "UNABLE") {
        id = 0;
    } else if (MessageElement == "STAQNDBY") {
        id = 1;
    } else if (MessageElement == "REQUEST DEFERRED") {
        id = 2;
    } else if (MessageElement == "ROGER") {
        id = 3;
    }else if (MessageElement == "AFFIRM") {
        id = 4;
    }else if (MessageElement == "NEGATIVE") {
        id = 5;
    }else if (MessageElement == "ROGER 7500") {
        id = 235;
    }else if (MessageElement == " REQUEST FORWARDED") {
        id = 211;
    }else if (MessageElement == "REQUEST ALREADY RECEIVED") {
        id = 218;
    }
    else {
        id = -1;
    }
}