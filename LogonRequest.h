#ifndef LOGIN_REQUEST_H
#define LOGIN_REQUEST_H

#include "DataLinkMessage.h"

class LogonRequest: public DataLinkMessage{

private:

public:

    std::string atsuIcaoCode;
    std::string registeration;
    std::string aircraftAddress;
    std::string departure;
    std::string destination;

    std::string messageType = "DM";

    bool responseRequired = true;

    LogonRequest(
        int id,
        std::string atsu,
        std::string reg,
        std::string address,
        std::string departure,
        std::string destination
    );


};

#endif
