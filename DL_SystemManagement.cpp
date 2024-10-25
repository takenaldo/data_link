#include <iostream>
#include <string>


enum class MessageIntentUse {
     ERROR ,
     NotCurrentData
    
};

enum class MessageElement {
    URG,
    ALRT,
    RESP
};


class Message {
protected:
    MessageIntentUse intent;
    MessageElement element;
    std::string urgency;
    std::string alert;
    std::string response;

public:
    Message(MessageIntentUse intent, MessageElement element)
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
            case MessageIntentUse::  ERROR: return "  ERROR";
            case MessageIntentUse:: NotCurrentData: return " NotCurrentData";
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

// Downlink Message Class (Inherits from Message)
class DownlinkMessage : public Message {
public:
    DownlinkMessage(MessageIntentUse intent, MessageElement element)
        : Message(intent, element) {}

    std::string processMessage() const override {
        return "Processing  Request Voice Contact Frequency : " + getInfo();
    }
};

// Function to choose Message Intent
MessageIntentUse chooseIntent() {
    int choice;
    std::cout << "Choose Message Intent:\n"
              << "1.   ERROR\n"
              << "2.  NotCurrentData\n";
            
    std::cin >> choice;

    switch (choice) {
        case 1: return MessageIntentUse::  ERROR;
        case 2: return MessageIntentUse:: NotCurrentData;
        
        default:
            std::cout << "Invalid choice, defaulting to Request.\n";
            return MessageIntentUse::  ERROR;
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

// Main function to run the program
int main() {
    // Choosing Intent and Element for the Downlink Message
    MessageIntentUse intent = chooseIntent();
    MessageElement element = chooseElement();

    // Create Downlink Message
    DownlinkMessage downlinkMessage(intent, element);

    // Set the flags for the message
    setDownlinkFlags(downlinkMessage);

    // Process and display the message information
    std::cout << downlinkMessage.processMessage() << std::endl;

    return 0;
}
