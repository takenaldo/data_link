#include <iostream>
#include <string>
#include "DownLink.h"

// Enum to represent message intent types
enum class MessageIntentUse {
    RequestSpeed,
    RequestSpeedToSpeed
};

// Class representing downlink speed requests
class DownLinkSpeedRequests {
protected:
    MessageIntentUse intent; // Message intent
    MessageElement element;   // Message element
    std::string urgency;      // Urgency flag
    std::string alert;        // Alert flag
    std::string response;     // Response flag

public:
    // Constructor to initialize intent and element
    DownLinkSpeedRequests(MessageIntentUse intent, MessageElement element)
        : intent(intent), element(element) {}

    // Method to get message information
    virtual std::string getInfo() const {
        return "Intent: " + getIntentName() + ", Element: " + getElementName() +
               ", Urgency: " + urgency + ", Alert: " + alert + ", Response: " + response;
    }

    // Pure virtual method for processing the message
    virtual std::string processMessage() const = 0;

    // Method to set flags based on chosen parameters
    void setFlags(const std::string& urg, const std::string& alrt, const std::string& resp) {
        urgency = urg;
        alert = alrt;
        response = resp;
    }

private:
    // Convert intent enum to string
    std::string getIntentName() const {
        switch (intent) {
            case MessageIntentUse::RequestSpeed: 
                return "Request Speed";
            case MessageIntentUse::RequestSpeedToSpeed: 
                return "Request Speed To Speed";
            default: 
                return "Unknown Intent";
        }
    }

    // Convert element enum to string
    std::string getElementName() const {
        switch (element) {
            case MessageElement::URG: 
                return "URG";
            case MessageElement::ALRT: 
                return "ALRT";
            case MessageElement::RESP: 
                return "RESP";
            default: 
                return "Unknown Element";
        }
    }
};

// Class representing a downlink message (inherits from DownLinkSpeedRequests)
class DownlinkMessage : public DownLinkSpeedRequests {
public:
    DownlinkMessage(MessageIntentUse intent, MessageElement element)
        : DownLinkSpeedRequests(intent, element) {}

    std::string processMessage() const override {
        return "Processing Speed Request: " + getInfo();
    }
};

// Function to choose message intent from user input
MessageIntentUse chooseIntent() {
    int choice;
    std::cout << "Choose Message Intent:\n"
              << "1. Request Speed\n"
              << "2. Request Speed To Speed\n";
    
    std::cin >> choice;

    switch (choice) {
        case 1: 
            return MessageIntentUse::RequestSpeed;
        case 2: 
            return MessageIntentUse::RequestSpeedToSpeed;
        default:
            std::cout << "Invalid choice, defaulting to Request Speed.\n";
            return MessageIntentUse::RequestSpeed;
    }
}

// Function to choose message element from user input
MessageElement chooseElement() {
    int choice;
    std::cout << "Choose Message Element:\n"
              << "1. URG\n"
              << "2. ALRT\n"
              << "3. RESP\n";
    
    std::cin >> choice;

    switch (choice) {
        case 1: 
            return MessageElement::URG;
        case 2: 
            return MessageElement::ALRT;
        case 3: 
            return MessageElement::RESP;
        default:
            std::cout << "Invalid choice, defaulting to URG.\n";
            return MessageElement::URG;
    }
}

// Function to set flags for the downlink message
void setDownlinkFlags(DownlinkMessage& message) {
    std::string urg, alrt, resp;
    std::cout << "Enter URG flag (e.g., N, M): ";
    std::cin >> urg;
    std::cout << "Enter ALRT flag (e.g., L, M): ";
    std::cin >> alrt;
    std::cout << "Enter RESP flag (e.g., Y, N): ";
    std::cin >> resp;

    message.setFlags(urg, alrt, resp);
}
