#include <iostream>
#include <vector>
#include "UplinkAdditionalMessages.h"
UplinkAdditionalMessages::UplinkAdditionalMessages(const std::string& mesg) {
    urgency = URG::Low;
    alert = ALRT::NoAlertingRequired;
    message_element = mesg;
    assignID();
}

UplinkAdditionalMessages::~UplinkAdditionalMessages() {}

void UplinkAdditionalMessages::displayAdditionalDetails() {
    std::cout << "Message: " << message_element << std::endl;
    std::cout << "Urgency Level: " << urgency << std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkAdditionalMessages::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + message_element +
           ", Urgency: " + std::to_string(urgency) + ", Alert: " + std::to_string(alert);
}

void UplinkAdditionalMessages::assignID() {
    if (message_element.find("WHEN READY") == 0) {
        id = 164; 
    } else if (message_element.find("IMMEDIATELY") == 0) {
        id = 230;  
    } else {
        id = -1;
    }
}


int main() {
    int choice;
    std::string message;
    UplinkAdditionalMessages additionalMessage("");
    std::cout << "Choose a additional Message type:\n";
    std::cout << "1. WHEN READY\n";
    std::cout << "2. IMMEDIATELY\n";                 
    std::cout << "Enter your choice (1-2): ";
    std::cin >> choice;

    switch (choice) {
        case 1: {
            message = "WHEN READY ";
            additionalMessage = UplinkAdditionalMessages(message);
            break;
        }
        case 2: {
            message = "IMMEDIATELY ";
            additionalMessage = UplinkAdditionalMessages(message);
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
                    case 1: additionalMessage.urgency = UplinkAdditionalMessages::URG::Distress; break;
                    case 2: additionalMessage.urgency = UplinkAdditionalMessages::URG::Urgent; break;
                    case 3: additionalMessage.urgency = UplinkAdditionalMessages::URG::Normal; break;
                    case 4: additionalMessage.urgency = UplinkAdditionalMessages::URG::Low; break;
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
                    case 1: additionalMessage.alert =UplinkAdditionalMessages::ALRT::HighAlert; break;
                    case 2: additionalMessage.alert = UplinkAdditionalMessages::ALRT::MediumAlert; break;
                    case 3: additionalMessage.alert = UplinkAdditionalMessages::ALRT::LowAlert; break;
                    case 4: additionalMessage.alert = UplinkAdditionalMessages::ALRT::NoAlertingRequired; break;
                    default: std::cout << "Invalid alert level." << std::endl; continue;
                }
                break;
            }

            case 4:
                std::cout << message << std::endl << additionalMessage.toString() << std::endl;
                finished = true;
                break;

            default:
                std::cout << "Invalid choice. Please select a number between 1 and 4." << std::endl;
        }
    }

    return 0;
}
