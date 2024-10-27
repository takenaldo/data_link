#include <iostream>
#include <vector>
#include "UplinkCrossingConstraints.h"
UplinkCrossingConstraints::UplinkCrossingConstraints(const std::string& mesg) {
    urgency = URG::Low;
    alert = ALRT::LowAlert;
    message_element = mesg;
    assignID();
}

UplinkCrossingConstraints::~UplinkCrossingConstraints() {}

void UplinkCrossingConstraints::displaycrossingDetails() {
    std::cout << "Message: " << message_element << std::endl;
    std::cout << "Urgency Level: " << urgency << std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkCrossingConstraints::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + message_element +
           ", Urgency: " + std::to_string(urgency) + ", Alert: " + std::to_string(alert);
}

void UplinkCrossingConstraints::assignID() {
    if (message_element.find("EXPECT TO CROSS") == 0 && message_element.find("AT OR ABOVE") == std::string::npos) {
        id = 42;
    } else if (message_element.find("EXPECT TO CROSS") == 0 && message_element.find("AT OR ABOVE") != std::string::npos) {
        id = 43;
    } else {
        id = -1;
    }
}


int main() {
    int choice;
    std::string message;
    UplinkCrossingConstraints crossing("");
    std::cout << "Choose a crossing type:\n";
    std::cout << "1.  EXPECT TO CROSS (position) AT (level)\n";
    std::cout << "2.  EXPECT TO CROSS (position) AT OR ABOVE (level)\n";                 
    std::cout << "Enter your choice (1-2): ";
    std::cin >> choice;

    switch (choice) {
        case 1: {
            int level;
            int position;
            std::cout << "Enter the expected cross position: ";
            std::cin >> position;
            std::cout << "Enter the expected cross level: ";
            std::cin>>level;
            message = "EXPECT TO CROSS " + std::to_string(position) + " POSITION AT LEVEL " +std::to_string(level);
            crossing = UplinkCrossingConstraints(message);
            break;
        }
        case 2: {
            int level;
            int position;
            std::cout << "Enter the expected cross position: ";
            std::cin >> position;
            std::cout << "Enter the expected cross level: ";
            std::cin>>level;
            message = "EXPECT TO CROSS " + std::to_string(position) + " POSITION AT OR ABOVE LEVEL " +std::to_string(level);
            crossing = UplinkCrossingConstraints(message);
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
                    case 1: crossing.urgency = UplinkCrossingConstraints::URG::Distress; break;
                    case 2: crossing.urgency = UplinkCrossingConstraints::URG::Urgent; break;
                    case 3: crossing.urgency = UplinkCrossingConstraints::URG::Normal; break;
                    case 4: crossing.urgency = UplinkCrossingConstraints::URG::Low; break;
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
                    case 1: crossing.alert =UplinkCrossingConstraints::ALRT::HighAlert; break;
                    case 2: crossing.alert = UplinkCrossingConstraints::ALRT::MediumAlert; break;
                    case 3: crossing.alert = UplinkCrossingConstraints::ALRT::LowAlert; break;
                    case 4: crossing.alert = UplinkCrossingConstraints::ALRT::NoAlertingRequired; break;
                    default: std::cout << "Invalid alert level." << std::endl; continue;
                }
                break;
            }

            case 4:
                std::cout << message << std::endl << crossing.toString() << std::endl;
                finished = true;
                break;

            default:
                std::cout << "Invalid choice. Please select a number between 1 and 4." << std::endl;
        }
    }

    return 0;
}
