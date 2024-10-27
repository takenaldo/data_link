#include <iostream>
#include <vector>
#include "UplinkConfirmationRequests.h"
UplinkConfirmationRequests::UplinkConfirmationRequests(const std::string& mesg) {
    urgency = URG::Normal;
    alert = ALRT::LowAlert;
    message_element = mesg;
    assignID();
}

UplinkConfirmationRequests::~UplinkConfirmationRequests() {}

void UplinkConfirmationRequests::displayComfirmationDetails() {
    std::cout << "Message: " << message_element << std::endl;
    std::cout << "Urgency Level: " << urgency << std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkConfirmationRequests::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + message_element +
           ", Urgency: " + std::to_string(urgency) + ", Alert: " + std::to_string(alert);
}

void UplinkConfirmationRequests::assignID() {
    if (message_element == "REPORT BACK ON ROUTE") {
        id = 127;
    } else if (message_element.find("REPORT LEAVING") == 0) {
        id = 128;
    } else {
        id = -1;
    }
}



int main() {
    int choice;
    std::string message;
    UplinkConfirmationRequests comfirmationMessage("");
    std::cout << "Choose a comfirmation request type:\n";
    std::cout << "1. REPORT BACK ON ROUTE\n";
    std::cout << "2. REPORT LEAVING LAVEL\n";                 
    std::cout << "Enter your choice (1-2): ";
    std::cin >> choice;

    switch (choice) {
        case 1: {
            message = "REPORT BACK ON ROUTE";
            comfirmationMessage = UplinkConfirmationRequests(message);
            break;
        }
        case 2: {
           int level;
            std::cout << "Enter the level: ";
            std::cin>>level;

            message = "REPORT LEAVING " + std::to_string(level);
            comfirmationMessage = UplinkConfirmationRequests(message);
            break;
        }
        default:
            std::cout << "Invalid choice. Please select either 1 or 2." << std::endl;
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
                    case 1: comfirmationMessage.urgency = UplinkConfirmationRequests::URG::Distress; break;
                    case 2: comfirmationMessage.urgency = UplinkConfirmationRequests::URG::Urgent; break;
                    case 3: comfirmationMessage.urgency = UplinkConfirmationRequests::URG::Normal; break;
                    case 4: comfirmationMessage.urgency = UplinkConfirmationRequests::URG::Low; break;
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
                    case 1: comfirmationMessage.alert =UplinkConfirmationRequests::ALRT::HighAlert; break;
                    case 2: comfirmationMessage.alert = UplinkConfirmationRequests::ALRT::MediumAlert; break;
                    case 3: comfirmationMessage.alert = UplinkConfirmationRequests::ALRT::LowAlert; break;
                    case 4: comfirmationMessage.alert = UplinkConfirmationRequests::ALRT::NoAlertingRequired; break;
                    default: std::cout << "Invalid alert level." << std::endl; continue;
                }
                break;
            }

            case 4:
                std::cout << message << std::endl << comfirmationMessage.toString() << std::endl;
                finished = true;
                break;

            default:
                std::cout << "Invalid choice. Please select a number between 1 and 4." << std::endl;
        }
    }

    return 0;
}
