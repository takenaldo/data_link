#include <iostream>
#include <string>
#include "DownLink.h"

enum class MessageIntentUse {
    REQUEST,
    REQUEST_BLOCK
};



class DownLinkVerticalRequest {
protected:
    MessageIntentUse intent;
    MessageElement element;
    std::string urgency;
    std::string alert;
    std::string response;

public:
    DownLinkVerticalRequest(MessageIntentUse intent, MessageElement element)
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
            case MessageIntentUse::REQUEST: return "REQUEST";
            case MessageIntentUse::REQUEST_BLOCK: return "REQUEST BLOCK";
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

class DownlinkMessage : public DownLinkVerticalRequest {
public:
    DownlinkMessage(MessageIntentUse intent, MessageElement element)
        : DownLinkVerticalRequest(intent, element) {}

    std::string processMessage() const override {
        return "Processing Vertical Request Downlink message: " + getInfo();
    }
};

MessageIntentUse chooseIntent() {
    int choice;
    std::cout << "Choose Message Intent:\n"
              << "1. REQUEST\n"
              << "2. REQUEST_BLOCK\n";

    std::cin >> choice;

    switch (choice) {
        case 1: return MessageIntentUse::REQUEST;
        case 2: return MessageIntentUse::REQUEST_BLOCK;
        default:
            std::cout << "Invalid choice, defaulting to REQUEST.\n";
            return MessageIntentUse::REQUEST;
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

int main() {
    MessageIntentUse intent = chooseIntent();
    MessageElement element = chooseElement();

    DownlinkMessage downlinkMessage(intent, element);

    setDownlinkFlags(downlinkMessage);

    std::cout << downlinkMessage.processMessage() << std::endl;

    return 0;
}
