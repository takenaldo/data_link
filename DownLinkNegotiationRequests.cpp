#include <iostream>
#include <string>
#include "DownLink.h"

enum class MessageIntentUse {
    WhenSpeed,
    WhenSpeedToSpeed
};

class DownLinkNegotiationRequests {
protected:
    MessageIntentUse intent;
    MessageElement element;
    std::string urgency;
    std::string alert;
    std::string response;

public:
    DownLinkNegotiationRequests(MessageIntentUse intent, MessageElement element)
        : intent(intent), element(element) {}

    virtual std::string getInfo() const {
        return "Intent: " + getIntentName() + ", Element: " + getElementName() +
               ", Urgency: " + urgency + ", Alert: " + alert + ", Response: " + response;
    }

    virtual std::string processMessage() const = 0;

    void setFlags(const std::string& urg, const std::string& alrt, const std::string& resp) {
        urgency = urg;
        alert = alrt;
        response = resp;
    }

private:
    std::string getIntentName() const {
        switch (intent) {
            case MessageIntentUse::WhenSpeed: return "WhenSpeed";
            case MessageIntentUse::WhenSpeedToSpeed: return "WhenSpeedToSpeed";
            default: return "UNKNOWN";
        }
    }

    std::string getElementName() const {
        switch (element) {
            case MessageElement::URG: return "URG";
            case MessageElement::ALRT: return "ALRT";
            case MessageElement::RESP: return "RESP";
            default: return "UNKNOWN";
        }
    }
};

class DownlinkMessage : public DownLinkNegotiationRequests {
public:
    DownlinkMessage(MessageIntentUse intent, MessageElement element)
        : DownLinkNegotiationRequests(intent, element) {}

    std::string processMessage() const override {
        return "Processing Request Voice Contact Frequency: " + getInfo();
    }
};

MessageIntentUse chooseIntent() {
    int choice;
    std::cout << "Choose Message Intent:\n"
              << "1. WhenSpeed\n"
              << "2. WhenSpeedToSpeed\n";
    std::cin >> choice;

    switch (choice) {
        case 1: return MessageIntentUse::WhenSpeed;
        case 2: return MessageIntentUse::WhenSpeedToSpeed;
        default:
            std::cout << "Invalid choice, defaulting to WhenSpeed.\n";
            return MessageIntentUse::WhenSpeed;
    }
}

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

