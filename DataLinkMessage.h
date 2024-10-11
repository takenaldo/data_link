#ifndef DATALINK_MESSSAGE_H
#define DATALINK_MESSSAGE_H
#include <string>

class DataLinkMessage{

private:
public:
    int id; // identification
    
    int min; // message identification
    int mrn; // reference
    
    std::string message; // actual message

    std::string messageType; // UM or DM

    bool responseRequired;

    static const int DmLogonRequest = 99;

    static const int UmlogonResponse = 1;


    DataLinkMessage();
    DataLinkMessage(std::string );

    DataLinkMessage(
        std::string messageType,
        int id,
        int min,
        int mrn,
        std::string message,
        bool responseRequired
    );

    std::string toString();

};

#endif