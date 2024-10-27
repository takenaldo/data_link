#include <iostream>
#include <vector>
#include "UplinckResponse.h"
UplinkResponse::UplinkResponse(const std::string& mesg) {
    urgency = URG::Normal;
    alert = ALRT::LowAlert;
    message_element = mesg;
    assignID();
}

UplinkResponse::~UplinkResponse() {}

void UplinkResponse::displayResponseDetails() {
    std::cout << "Message: " << message_element << std::endl;
    std::cout << "Urgency Level: " << urgency << std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkResponse::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + message_element +
           ", Urgency: " + std::to_string(urgency) + ", Alert: " + std::to_string(alert);
}

void UplinkResponse::assignID() {
    if (message_element == "UNABLE") {
        id = 0;
    } else if (message_element == "STAQNDBY") {
        id = 1;
    } else if (message_element == "REQUEST DEFERRED") {
        id = 2;
    } else if (message_element == "ROGER") {
        id = 3;
    }else if (message_element == "AFFIRM") {
        id = 4;
    }else if (message_element == "NEGATIVE") {
        id = 5;
    }else if (message_element == "ROGER 7500") {
        id = 235;
    }else if (message_element == " REQUEST FORWARDED") {
        id = 211;
    }else if (message_element == "REQUEST ALREADY RECEIVED") {
        id = 218;
    }
    else {
        id = -1;
    }
}

int main() {
    int choice;
    std::string message;
    UplinkResponse response("");
    std::cout << "Choose a response type:\n";
    std::cout << "1. UNABLE                      "<< "6. NEGATIVE\n";
    std::cout << "2. STANDBY                     "<< "7. ROGER 7500\n";
    std::cout << "3. REQUEST DEFERRED            "<< "8. REQUEST FORWARDED\n";
    std::cout << "4. ROGER                       "<< "9. REQUEST ALREADY RECEIVED\n";
    std::cout << "5. AFFIRM\n";
    std::cout << "Enter your choice (1-9): ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            message = "UNABLE";
            response = UplinkResponse(message);
            break;
        case 2:
            message = "STAQNDBY";
            response = UplinkResponse(message);
            break;
        case 3:
            message = "REQUEST DEFERRED";
            response = UplinkResponse(message);
            break;
        case 4:
            message = "ROGER";
            response = UplinkResponse(message);
            break;
         case 5:
            message = "AFFIRM";
            response = UplinkResponse(message);
            break;
        case 6:
            message = "NEGATIVE";
            response = UplinkResponse(message);
            break;
        case 7:
            message = " ROGER 7500";
            response = UplinkResponse(message);
            break;
        case 8:
            message = "REQUEST FORWARDED";
            response = UplinkResponse(message);
        case 9:
            message = "REQUEST ALREADY RECEIVED";
            response = UplinkResponse(message);
            break;
        default:
            std::cout << "Invalid choice. Please select a number between 1 and 9." << std::endl;
            return 1;
    }

    int input2;
    bool finished = false;
    while (!finished) {
        std::cout << "Choose:\n";
        std::cout << "1. CANCEL                      "<< "3. ALERT\n";
        std::cout << "2. URGENT                     "<< "4. SEND\n";
        std::cin >> input2;

        switch (input2) {
            case 1:
                std::cout << "Action canceled." << std::endl;
                finished = true;
                break;

            case 2: {
                int urg;
                std::cout << "Choose Urgency level:\n";
                std::cout << "1. Distress                      " << "3. Normal\n";
                std::cout << "2. Urgent                        " << "4. Low\n";
                std::cin >> urg;
                
                switch (urg) {
                    case 1: response.urgency = UplinkResponse::URG::Distress; break;
                    case 2: response.urgency = UplinkResponse::URG::Urgent; break;
                    case 3: response.urgency = UplinkResponse::URG::Normal; break;
                    case 4: response.urgency = UplinkResponse::URG::Low; break;
                    default: std::cout << "Invalid urgency level." << std::endl; continue;
                }
                break;
            }

            case 3: {
                int alrt;
                std::cout << "Choose Alert level:\n";
                std::cout << "1. HighAlert                      " << "3. LowAlert\n";
                std::cout << "2. MediumAlert                    " << "4. NoAlertingRequired\n";
                std::cin >> alrt;
                
                switch (alrt) {
                    case 1: response.alert =UplinkResponse::ALRT::HighAlert; break;
                    case 2: response.alert = UplinkResponse::ALRT::MediumAlert; break;
                    case 3: response.alert = UplinkResponse::ALRT::LowAlert; break;
                    case 4: response.alert = UplinkResponse::ALRT::NoAlertingRequired; break;
                    default: std::cout << "Invalid alert level." << std::endl; continue;
                }
                break;
            }

            case 4:
                std::cout << message << std::endl << response.toString() << std::endl;
                finished = true;
                break;

            default:
                std::cout << "Invalid choice. Please select a number between 1 and 4." << std::endl;
        }
    }

    return 0;
}
