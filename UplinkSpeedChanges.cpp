#include <iostream>
#include <vector>
#include "UplinkSpeedChanges.h"
UplinkSpeedChanges::UplinkSpeedChanges(const std::string& mesg) {
    urgency = URG::Low;
    alert = ALRT::LowAlert;
    message_element = mesg;
    assignID();
}

UplinkSpeedChanges::~UplinkSpeedChanges() {}

void UplinkSpeedChanges::displaySpeedDetails() {
    std::cout << "Message: " << message_element << std::endl;
    std::cout << "Urgency Level: " << urgency << std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkSpeedChanges::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + message_element +
           ", Urgency: " + std::to_string(urgency) + ", Alert: " + std::to_string(alert);
}

void UplinkSpeedChanges::assignID() {
    if (message_element.find("AT TIME") == 0 && message_element.find("EXPECT") != std::string::npos) {
        id = 100;
    } else if (message_element.find("AT POSITION") == 0 && message_element.find("EXPECT") != std::string::npos) {
        id = 101;
    } else {
        id = -1;
    }
}

int main() {
    int choice;
    std::string message;
    UplinkSpeedChanges speedMessage("");
    std::cout << "Choose a speedMessage type:\n";
    std::cout << "1.  EXPECTED SPEED AT SPECIFIC TIME\n";
    std::cout << "2.  EXPECTED SPEED AT SPECIFIC POSITION\n";                 
    std::cout << "Enter your choice (1-2): ";
    std::cin >> choice;

    switch (choice) {
        case 1: {
            int time;
            int speed;
            std::cout << "Enter the time: ";
            std::cin >> time;
            std::cout << "Enter the expected speed: ";
            std::cin>>speed;
            message = "AT TIME " + std::to_string(time) +" EXPECT "+std::to_string(speed) + " SPEED ";
            speedMessage = UplinkSpeedChanges(message);
            break;
        }
        case 2: {
           int speed;
           int position;
           std::cout << "Enter the position: ";
            std::cin>>position;
            std::cout << "Enter the distance: ";
            std::cin >> speed;

            message = "AT POSITION" + std::to_string(position) + " EXPECT " +std::to_string(speed) + " SPEED ";
            speedMessage = UplinkSpeedChanges(message);
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
                    case 1: speedMessage.urgency = UplinkSpeedChanges::URG::Distress; break;
                    case 2: speedMessage.urgency = UplinkSpeedChanges::URG::Urgent; break;
                    case 3: speedMessage.urgency = UplinkSpeedChanges::URG::Normal; break;
                    case 4: speedMessage.urgency = UplinkSpeedChanges::URG::Low; break;
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
                    case 1: speedMessage.alert =UplinkSpeedChanges::ALRT::HighAlert; break;
                    case 2: speedMessage.alert = UplinkSpeedChanges::ALRT::MediumAlert; break;
                    case 3: speedMessage.alert = UplinkSpeedChanges::ALRT::LowAlert; break;
                    case 4: speedMessage.alert = UplinkSpeedChanges::ALRT::NoAlertingRequired; break;
                    default: std::cout << "Invalid alert level." << std::endl; continue;
                }
                break;
            }

            case 4:
                std::cout << message << std::endl << speedMessage.toString() << std::endl;
                finished = true;
                break;

            default:
                std::cout << "Invalid choice. Please select a number between 1 and 4." << std::endl;
        }
    }

    return 0;
}
