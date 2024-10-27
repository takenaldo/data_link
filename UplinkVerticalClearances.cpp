#include <iostream>
#include <vector>
#include "UplinkVerticalClearances.h"
UplinkVerticalClearances::UplinkVerticalClearances(const std::string& mesg) {
    urgency = URG::Low;
    alert = ALRT::LowAlert;
    message_element = mesg;
    assignID();
}

UplinkVerticalClearances::~UplinkVerticalClearances() {}

void UplinkVerticalClearances::displayClearanceDetails() {
    std::cout << "Message: " << message_element << std::endl;
    std::cout << "Urgency Level: " << urgency << std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkVerticalClearances::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + message_element +
           ", Urgency: " + std::to_string(urgency) + ", Alert: " + std::to_string(alert);
}

void UplinkVerticalClearances::assignID() {
    if (message_element.find("EXPECT ") == 0 && message_element.find("CLIMB AT") == std::string::npos) {
        id = 6;
    } else if (message_element.find("EXPECT CLIMB AT") == 0) {
        id = 7;
    } else {
        id = -1;
    }
}


int main() {
    int choice;
    std::string message;
    UplinkVerticalClearances clearance("");
    std::cout << "Choose a clearance type:\n";
    std::cout << "1. EXPECT (level)\n";
    std::cout << "2. EXPECT CLIMB AT (time)\n";                 
    std::cout << "Enter your choice (1-2): ";
    std::cin >> choice;

    switch (choice) {
        case 1: {
            int level;
            std::cout << "Enter the expected level: ";
            std::cin >> level;
            message = "EXPECT " + std::to_string(level);
            clearance = UplinkVerticalClearances(message);
            break;
        }
        case 2: {
            int time;
            std::cout << "Enter the expected climb time in minutes: ";
            std::cin >> time;
            message = "EXPECT CLIMB AT " + std::to_string(time) + " minutes";
            clearance = UplinkVerticalClearances(message);
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
                    case 1: clearance.urgency = UplinkVerticalClearances::URG::Distress; break;
                    case 2: clearance.urgency = UplinkVerticalClearances::URG::Urgent; break;
                    case 3: clearance.urgency = UplinkVerticalClearances::URG::Normal; break;
                    case 4: clearance.urgency = UplinkVerticalClearances::URG::Low; break;
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
                    case 1: clearance.alert =UplinkVerticalClearances::ALRT::HighAlert; break;
                    case 2: clearance.alert = UplinkVerticalClearances::ALRT::MediumAlert; break;
                    case 3: clearance.alert = UplinkVerticalClearances::ALRT::LowAlert; break;
                    case 4: clearance.alert = UplinkVerticalClearances::ALRT::NoAlertingRequired; break;
                    default: std::cout << "Invalid alert level." << std::endl; continue;
                }
                break;
            }

            case 4:
                std::cout << message << std::endl << clearance.toString() << std::endl;
                finished = true;
                break;

            default:
                std::cout << "Invalid choice. Please select a number between 1 and 4." << std::endl;
        }
    }

    return 0;
}
