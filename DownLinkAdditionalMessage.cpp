#include <iostream>
#include <string>
#include "DownLink.h" 
enum class MessageIntentUse {
    DueToWeather,
    DueToAircraft
};

class DownLinkAdditionalMessage {
protected:
    MessageIntentUse intent;
    MessageElement element;
    std::string urgency;
    std::string alert;
    std::string response;

public:
    DownLinkAdditionalMessage(MessageIntentUse intent, MessageElement element)
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
            case MessageIntentUse::DueToWeather: return "DueToWeather";
            case MessageIntentUse::DueToAircraft: return "DueToAircraft";
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

class DownlinkMessage : public DownLinkAdditionalMessage {
public:
    DownlinkMessage(MessageIntentUse intent, MessageElement element)
        : DownLinkAdditionalMessage(intent, element) {}

    std::string processMessage() const override {
        return "Processing Request Voice Contact Frequency: " + getInfo();
    }
};

MessageIntentUse chooseIntent() {
    int choice;
    std::cout << "Choose Message Intent:\n"
              << "1. DueToWeather\n"
              << "2. DueToAircraft\n";

    std::cin >> choice;

    switch (choice) {
        case 1: return MessageIntentUse::DueToWeather;
        case 2: return MessageIntentUse::DueToAircraft;
        default:
            std::cout << "Invalid choice, defaulting to DueToWeather.\n";
            return MessageIntentUse::DueToWeather;
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


