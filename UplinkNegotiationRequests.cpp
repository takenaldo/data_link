#include <iostream>
#include <vector>
#include "UplinkNegotiationRequests.h"
UplinkNegotiationRequests::UplinkNegotiationRequests(const std::string& mesg) {
    urgency = URG::Normal;
    alert = ALRT::LowAlert;
    message_element = mesg;
    assignID();
}

UplinkNegotiationRequests::~UplinkNegotiationRequests() {}

void UplinkNegotiationRequests::displayNegotiationDetails() {
    std::cout << "Message: " << message_element << std::endl;
    std::cout << "Urgency Level: " << urgency << std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkNegotiationRequests::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + message_element +
           ", Urgency: " + std::to_string(urgency) + ", Alert: " + std::to_string(alert);
}

void UplinkNegotiationRequests::assignID() {
    if (message_element.find("WHEN CAN YOU ACCEPT") == 0) {
        id = 148;
    } else if (message_element.find("CAN YOU ACCEPT LEVEL") == 0 && message_element.find("AT") != std::string::npos) {
        id = 149;
    } else {
        id = -1;
    }
}




int main() {
    int choice;
    std::string message;
    UplinkNegotiationRequests negotiationMessage("");
    std::cout << "Choose a Negotiation request type:\n";
    std::cout << "1. REQUEST TO ACCEPTE THE LEVEL\n";
    std::cout << "2. REQUEST TO ACCEPTE THE LEVEL AT SPECIFIED POSITION\n";                 
    std::cout << "Enter your choice (1-2): ";
    std::cin >> choice;

    switch (choice) {
        case 1: {
            
           int level;
            std::cout << "Enter the level: ";
            std::cin>>level;

            message ="WHEN CAN YOU ACCEPT " + std::to_string(level);
            negotiationMessage = UplinkNegotiationRequests(message);
            break;
        }
        case 2: {
           int level;
           int position;
            std::cout << "Enter the level: ";
            std::cin>>level;
            std::cout<<"Enter the position: ";
            std::cin>>position;

            message = "CAN YOU ACCEPT LEVEL " + std::to_string(level) + " AT " + std::to_string(position) + " position";
            negotiationMessage = UplinkNegotiationRequests(message);
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
                    case 1: negotiationMessage.urgency = UplinkNegotiationRequests::URG::Distress; break;
                    case 2: negotiationMessage.urgency = UplinkNegotiationRequests::URG::Urgent; break;
                    case 3: negotiationMessage.urgency = UplinkNegotiationRequests::URG::Normal; break;
                    case 4: negotiationMessage.urgency = UplinkNegotiationRequests::URG::Low; break;
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
                    case 1: negotiationMessage.alert =UplinkNegotiationRequests::ALRT::HighAlert; break;
                    case 2: negotiationMessage.alert = UplinkNegotiationRequests::ALRT::MediumAlert; break;
                    case 3: negotiationMessage.alert = UplinkNegotiationRequests::ALRT::LowAlert; break;
                    case 4: negotiationMessage.alert = UplinkNegotiationRequests::ALRT::NoAlertingRequired; break;
                    default: std::cout << "Invalid alert level." << std::endl; continue;
                }
                break;
            }

            case 4:
                std::cout << message << std::endl << negotiationMessage.toString() << std::endl;
                finished = true;
                break;

            default:
                std::cout << "Invalid choice. Please select a number between 1 and 4." << std::endl;
        }
    }

    return 0;
}
