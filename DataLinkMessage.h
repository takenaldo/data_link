#ifndef DATALINK_MESSSAGE_H
#define DATALINK_MESSSAGE_H


#include <string>
#include <typeindex>
#include <typeinfo>
#include<vector>
#include<variant>

// #include "DownLinkMessages/PermittedResponseGroup.cpp"

#include "PRG.cpp"

enum Urgency{
    DISTRESS,
    URGENT,
    NORMAL,
    LOW
};

enum Alert{
    HIGH,
    MEDIUM,
    LOW_ALERT,
    NO_ALERT
};
namespace MessageCategory{
    static std::string UPLINK_MESSAGE= "UM";
    static std::string DOWNLINK_MESSAGE = "DM";
}

class DataLinkMessage{

private:
    Urgency m_urgency;
    Alert m_alert;
    PermittedResponseGroup m_prg;

    int m_id; // identification
    std::string messageType; // UM or DM
    std::string message; // actual message

    std::string m_messageCategory;

    std::vector<std::type_index> m_permittedResponses; //TODO: remove this

public:

    int min; // message identification
    int mrn; // reference
    
    bool responseRequired;

    static const int DM_LOGON_REQUEST = 99;
    static const int UM_LOGON_RESPONSE = 1;
    static const int DM_CONNECTION_RESPONSE = 99;  ///

    // DataLinkMessage();
    // DataLinkMessage(std::string );

    // DataLinkMessage(
    //     std::string messageType,
    //     int id,
    //     int min,
    //     int mrn,
    //     std::string message,
    //     std::string URG,
    //     std::string ALRT,
    //     bool responseRequired
    // );

    DataLinkMessage(
        std::string messageCategory, 
        int id, 
        Alert alert, 
        Urgency urgency, 
        // std::vector<std::type_index> permittedGroups,
        PermittedResponseGroup permittedResponseGroup
    );

    std::string buildMessage(std::vector<std::variant<int, float, double, std::string>> m_phrases );
    std::string toString();

    std::string getMessage();

    int getID();
    Alert getAlert();
    Urgency getUrgency();
    std::string getTypeInfo();
    std::string getMessageCategory();
    std::vector<std::type_index> getPermittedResponses();
    PermittedResponseGroup getPermittedResponseGroup();

    void setID(int id);
    void setAlert(Alert alert);
    void setMessage(std::string msg);
    void setUrgency(Urgency urgency);

    bool isResponsePermitted(const std::type_info& );
};

#endif
