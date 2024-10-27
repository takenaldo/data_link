#include <iostream>
#include <vector>
#include "UplinkRoutemodifications.h"
UplinkRoutemodifications::UplinkRoutemodifications(const std::string& mesg) {
    urgency = URG::Normal;
    alert = ALRT::MediumAlert;
    message_element = mesg;
    assignID();
}

UplinkRoutemodifications::~UplinkRoutemodifications() {}

void UplinkRoutemodifications::displayRouteDetails() {
    std::cout << "Message: " << message_element << std::endl;
    std::cout << "Urgency Level: " << urgency << std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkRoutemodifications::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + message_element +
           ", Urgency: " + std::to_string(urgency) + ", Alert: " + std::to_string(alert);
}

void UplinkRoutemodifications::assignID() {
    if (message_element.find("PROCEED DIRECT TO") != std::string::npos && message_element.find("WHEN ABLE") == std::string::npos) {
        id = 74;
    } else if (message_element.find("WHEN ABLE PROCEED DIRECT TO") == 0) {
        id = 75;
    } else {
        id = -1;
    }
}



int main() {
    int choice;
    std::string message;
    UplinkRoutemodifications routeMessage("");
    std::cout << "Choose a routeMessage type:\n";
    std::cout << "1.  FROM ITS PRESET POSITION TO A SPECIFIED POSITION\n";
    std::cout << "2.  DIRECTLY TO THE SPECIFIED POSITION \n";                 
    std::cout << "Enter your choice (1-2): ";
    std::cin >> choice;

    switch (choice) {
        case 1: {
            int position;
            std::cout << "Enter the position: ";
            std::cin >> position;
            
            message = " PROCEED DIRECT TO " + std::to_string(position);
            routeMessage = UplinkRoutemodifications(message);
            break;
        }
        case 2: {
            int position;
           std::cout << "Enter the position: ";
            std::cin>>position;

            message = " WHEN ABLE PROCEED DIRECT TO " + std::to_string(position);
            routeMessage = UplinkRoutemodifications(message);
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
                    case 1: routeMessage.urgency = UplinkRoutemodifications::URG::Distress; break;
                    case 2: routeMessage.urgency = UplinkRoutemodifications::URG::Urgent; break;
                    case 3: routeMessage.urgency = UplinkRoutemodifications::URG::Normal; break;
                    case 4: routeMessage.urgency = UplinkRoutemodifications::URG::Low; break;
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
                    case 1: routeMessage.alert =UplinkRoutemodifications::ALRT::HighAlert; break;
                    case 2: routeMessage.alert = UplinkRoutemodifications::ALRT::MediumAlert; break;
                    case 3: routeMessage.alert = UplinkRoutemodifications::ALRT::LowAlert; break;
                    case 4: routeMessage.alert = UplinkRoutemodifications::ALRT::NoAlertingRequired; break;
                    default: std::cout << "Invalid alert level." << std::endl; continue;
                }
                break;
            }

            case 4:
                std::cout << message << std::endl << routeMessage.toString() << std::endl;
                finished = true;
                break;

            default:
                std::cout << "Invalid choice. Please select a number between 1 and 4." << std::endl;
        }
    }

    return 0;
}
