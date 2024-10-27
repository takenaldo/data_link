#include <iostream>
#include <vector>
#include "UplinkLateralOffsets.h"
UplinkLateralOffsets::UplinkLateralOffsets(const std::string& mesg) {
    urgency = URG::Normal;
    alert = ALRT::MediumAlert;
    message_element = mesg;
    assignID();
}

UplinkLateralOffsets::~UplinkLateralOffsets() {}

void UplinkLateralOffsets::displayOffsetDetails() {
    std::cout << "Message: " << message_element << std::endl;
    std::cout << "Urgency Level: " << urgency << std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkLateralOffsets::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + message_element +
           ", Urgency: " + std::to_string(urgency) + ", Alert: " + std::to_string(alert);
}

void UplinkLateralOffsets::assignID() {
    if (message_element.find("OFFSET") == 0 && message_element.find("AT") == std::string::npos) {
        id = 64;
    } else if (message_element.find("AT") == 0 && message_element.find("OFFSET") != std::string::npos) {
        id = 65;
    } else {
        id = -1;
    }
}


int main() {
    int choice;
    std::string message;
    UplinkLateralOffsets offsets("");
    std::cout << "Choose a offsets type:\n";
    std::cout << "1.  OFFSET (specified distance) (direction) OF ROUTE\n";
    std::cout << "2.  AT (position) OFFSET (specified distance) (direction) OF ROUTE\n";                 
    std::cout << "Enter your choice (1-2): ";
    std::cin >> choice;

    switch (choice) {
        case 1: {
            int distance;
            int direction;
            std::cout << "Enter the distance: ";
            std::cin >> distance;
            std::cout << "Enter the direction: ";
            std::cin>>direction;
            message = "OFFSET " + std::to_string(distance) +" "+std::to_string(direction)+ " OF ROUTE";
            offsets = UplinkLateralOffsets(message);
            break;
        }
        case 2: {
           int distance;
           int direction;
           int position;
           std::cout << "Enter the position: ";
            std::cin>>position;
            std::cout << "Enter the distance: ";
            std::cin >> distance;
            std::cout << "Enter the direction: ";
            std::cin>>direction;

            message = "AT " + std::to_string(position) + " OFFSET " +std::to_string(distance) + " " + std::to_string(direction) + " OF ROUTE ";
            offsets = UplinkLateralOffsets(message);
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
                    case 1: offsets.urgency = UplinkLateralOffsets::URG::Distress; break;
                    case 2: offsets.urgency = UplinkLateralOffsets::URG::Urgent; break;
                    case 3: offsets.urgency = UplinkLateralOffsets::URG::Normal; break;
                    case 4: offsets.urgency = UplinkLateralOffsets::URG::Low; break;
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
                    case 1: offsets.alert =UplinkLateralOffsets::ALRT::HighAlert; break;
                    case 2: offsets.alert = UplinkLateralOffsets::ALRT::MediumAlert; break;
                    case 3: offsets.alert = UplinkLateralOffsets::ALRT::LowAlert; break;
                    case 4: offsets.alert = UplinkLateralOffsets::ALRT::NoAlertingRequired; break;
                    default: std::cout << "Invalid alert level." << std::endl; continue;
                }
                break;
            }

            case 4:
                std::cout << message << std::endl << offsets.toString() << std::endl;
                finished = true;
                break;

            default:
                std::cout << "Invalid choice. Please select a number between 1 and 4." << std::endl;
        }
    }

    return 0;
}
