#include <iostream>
#include <vector>
#include "UplinkSystemManagementMessages.h"
UplinkSystemManagementMessages::UplinkSystemManagementMessages(const std::string& mesg) {
    urgency = URG::Urgent;
    alert = ALRT::MediumAlert;
    message_element = mesg;
    assignID();
}

UplinkSystemManagementMessages::~UplinkSystemManagementMessages() {}

void UplinkSystemManagementMessages::displayManagementDetails() {
    std::cout << "Message: " << message_element << std::endl;
    std::cout << "Urgency Level: " << urgency << std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkSystemManagementMessages::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + message_element +
           ", Urgency: " + std::to_string(urgency) + ", Alert: " + std::to_string(alert);
}

void UplinkSystemManagementMessages::assignID() {
    if (message_element.find("ERROR") == 0) {
        id = 159; 
    } else if (message_element.find("NEXT DATA AUTHORITY") == 0) {
        id = 160;  
    } else {
        id = -1;
    }
}



int main() {
    int choice;
    std::string message;
    UplinkSystemManagementMessages managementMessage("");
    std::cout << "Choose a System management Message type:\n";
    std::cout << "1. ERROR\n";
    std::cout << "2. NEXT DATA AUTHORITY\n";                 
    std::cout << "Enter your choice (1-2): ";
    std::cin >> choice;

    switch (choice) {
        case 1: {
            std::string error;
            std::cout << "Enter the error: ";
            std::getline(std::cin >> std::ws, error);
            message = "ERROR " + (error);
            managementMessage = UplinkSystemManagementMessages(message);
            break;
        }
        case 2: {
           std::string faCility;
           std::cout << "Enter the facility: ";
           std::getline(std::cin >> std::ws, faCility);
            message = "NEXT DATA AUTHORITY " + (faCility);
            managementMessage = UplinkSystemManagementMessages(message);
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
                    case 1: managementMessage.urgency = UplinkSystemManagementMessages::URG::Distress; break;
                    case 2: managementMessage.urgency = UplinkSystemManagementMessages::URG::Urgent; break;
                    case 3: managementMessage.urgency = UplinkSystemManagementMessages::URG::Normal; break;
                    case 4: managementMessage.urgency = UplinkSystemManagementMessages::URG::Low; break;
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
                    case 1: managementMessage.alert =UplinkSystemManagementMessages::ALRT::HighAlert; break;
                    case 2: managementMessage.alert = UplinkSystemManagementMessages::ALRT::MediumAlert; break;
                    case 3: managementMessage.alert = UplinkSystemManagementMessages::ALRT::LowAlert; break;
                    case 4: managementMessage.alert = UplinkSystemManagementMessages::ALRT::NoAlertingRequired; break;
                    default: std::cout << "Invalid alert level." << std::endl; continue;
                }
                break;
            }

            case 4:
                std::cout << message << std::endl << managementMessage.toString() << std::endl;
                finished = true;
                break;

            default:
                std::cout << "Invalid choice. Please select a number between 1 and 4." << std::endl;
        }
    }

    return 0;
}
