#include <iostream>
#include <string>
#include "DownLink.h"

enum class MessageIntentUse {
    LEAVING,
    CLIMBING
};

class DownLinkReports {
protected:
    MessageIntentUse intent;
    MessageElement element;
    std::string urgency;
    std::string alert;
    std::string response;

public:
    DownLinkReports(MessageIntentUse intent, MessageElement element)
        : intent(intent), element(element) {}

    virtual std::string getInfo() const {
        return "Intent: " + getIntentName() + ", Element: " + getElementName() +
               ", Urgency: " + urgency + ", Alert: " + alert + ", Response: " + response;
    }

    virtual std::string processMessage() const = 0;

    // Set the flags (urgency, alert, response) based on chosen parameters
    void setFlags(const std::string& urg, const std::string& alrt, const std::string& resp) {
        urgency = urg;
        alert = alrt;
        response = resp;
    }

private:
    // Convert intent enum to string
    std::string getIntentName() const {
        switch (intent) {
            case MessageIntentUse::LEAVING: return "LEAVING";
            case MessageIntentUse::CLIMBING: return "CLIMBING";
            default: return "UNKNOWN";
        }
    }

    // Convert element enum to string
    std::string getElementName() const {
        switch (element) {
            case MessageElement::URG: return "URG";
            case MessageElement::ALRT: return "ALRT";
            case MessageElement::RESP: return "RESP";
            default: return "UNKNOWN";
        }
    }
};

// Downlink Message Class (Inherits from DownLinkReports)
class DownlinkMessage : public DownLinkReports {
public:
    DownlinkMessage(MessageIntentUse intent, MessageElement element)
        : DownLinkReports(intent, element) {}

    std::string processMessage() const override {
        return "Processing Request Voice Contact Frequency: " + getInfo();
    }
};

// Function to choose Message Intent
MessageIntentUse chooseIntent() {
    int choice;
    std::cout << "Choose Message Intent:\n"
              << "1. LEAVING\n"
              << "2. CLIMBING\n";
    std::cin >> choice;

    switch (choice) {
        case 1: return MessageIntentUse::LEAVING;
        case 2: return MessageIntentUse::CLIMBING;
        default:
            std::cout << "Invalid choice, defaulting to LEAVING.\n";
            return MessageIntentUse::LEAVING;
    }
}

// Function to choose Message Element
MessageElement chooseElement() {
    int choice;
    std::cout << "Choose Message Element:\n"
              << "1. URG\n"
              << "2. ALRT\n"
              << "3. RESP\n";
    std::cin >> choice;

    switch (choice) {
        case 1: return MessageElement::URG;
        case 2: return MessageElement::ALRT;
        case 3: return MessageElement::RESP;
        default:
            std::cout << "Invalid choice, defaulting to URG.\n";
            return MessageElement::URG;
    }
}

// Function to set flags (N, M, L, etc.) for Downlink Message
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
