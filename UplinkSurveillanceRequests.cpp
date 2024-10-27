#include <iostream>
#include <vector>
#include "UplinkSurveillanceRequests.h"
UplinkSurveillanceRequests::UplinkSurveillanceRequests(const std::string& mesg) {
    urgency = URG::Normal;
    alert = ALRT::MediumAlert;
    message_element = mesg;
    assignID();
}

UplinkSurveillanceRequests::~UplinkSurveillanceRequests() {}

void UplinkSurveillanceRequests::displaySurcillanceDetails() {
    std::cout << "Message: " << message_element << std::endl;
    std::cout << "Urgency Level: " << urgency << std::endl;
    std::cout << "Alert Level: " << alert << std::endl;
}

std::string UplinkSurveillanceRequests::toString() {
    return "ID: " + std::to_string(id) + ", Message: " + message_element +
           ", Urgency: " + std::to_string(urgency) + ", Alert: " + std::to_string(alert);
}

void UplinkSurveillanceRequests::assignID() {
    if (message_element.find("CONTACT") == 0 && message_element.find("position") == std::string::npos) {
        id = 117;  
    } else if (message_element.find("AT") == 0 && message_element.find("position") != std::string::npos) {
        id = 118;
    } else {
        id = -1;
    }
}


int main() {
    int choice;
    std::string message;
    UplinkSurveillanceRequests SurveillanceMessage("");
    std::cout << "Choose a SurveillanceMessage type:\n";
    std::cout << "1.  CONTACT WITH ATS\n";
    std::cout << "2.  CONTACT WITH ATS AT SPESFIC POSITION\n";                 
    std::cout << "Enter your choice (1-2): ";
    std::cin >> choice;

    switch (choice) {
        case 1: {
            std::string unitName;
            int frequency;
            std::cout << "Enter the unitName: ";
            std::cin >> unitName;
            std::cout << "Enter the frequency to contact: ";
            std::cin>>frequency;
            message = "CONTACT " + (unitName) +" UNIT AT "+std::to_string(frequency) + " frequency ";
            SurveillanceMessage = UplinkSurveillanceRequests(message);
            break;
        }
        case 2: {
           std::string unitName;
           int frequency;
           int position;
           std::cout<<"Enter spesfic position: ";
           std::cin>>position;
           std::cout << "Enter the unitName: ";
            std::cin>>unitName;
            std::cout << "Enter the frequency to contact: ";
            std::cin >> frequency;

            message = "AT " + std::to_string(position) + " position"+ " CONTACT " + (unitName) +" UNIT AT "+std::to_string(frequency) + " frequency ";
            SurveillanceMessage = UplinkSurveillanceRequests(message);
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
                    case 1: SurveillanceMessage.urgency = UplinkSurveillanceRequests::URG::Distress; break;
                    case 2: SurveillanceMessage.urgency = UplinkSurveillanceRequests::URG::Urgent; break;
                    case 3: SurveillanceMessage.urgency = UplinkSurveillanceRequests::URG::Normal; break;
                    case 4: SurveillanceMessage.urgency = UplinkSurveillanceRequests::URG::Low; break;
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
                    case 1: SurveillanceMessage.alert =UplinkSurveillanceRequests::ALRT::HighAlert; break;
                    case 2: SurveillanceMessage.alert = UplinkSurveillanceRequests::ALRT::MediumAlert; break;
                    case 3: SurveillanceMessage.alert = UplinkSurveillanceRequests::ALRT::LowAlert; break;
                    case 4: SurveillanceMessage.alert = UplinkSurveillanceRequests::ALRT::NoAlertingRequired; break;
                    default: std::cout << "Invalid alert level." << std::endl; continue;
                }
                break;
            }

            case 4:
                std::cout << message << std::endl << SurveillanceMessage.toString() << std::endl;
                finished = true;
                break;

            default:
                std::cout << "Invalid choice. Please select a number between 1 and 4." << std::endl;
        }
    }

    return 0;
}
