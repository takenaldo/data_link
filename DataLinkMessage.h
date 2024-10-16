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

    static const int DM_LOGON_REQUEST = 99;

    static const int UM_LOGON_RESPONSE = 1;
    static const int DM_CONNECTION_RESPONSE = 100;  ///


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