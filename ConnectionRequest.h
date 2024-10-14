#ifndef CONNECTION_REQUEST_H
#define CONNECTION_REQUEST_H

#include "DataLinkMessage.h"

class ConnectionRequest: public DataLinkMessage{

private:

public:
  /// we need the DLC adress and Facility designstion 
    std::string atsu_icao_code;
    std::string registeration;
    std::string aircraft_address;
    std::string departure;
    std::string destination;

    std::string messageType = "UM";

    bool responseRequired = true;

    ConnectionRequest(
        int id,
        std::string atsu,
        std::string reg,
        std::string address,
        std::string departure,
        std::string destination
    );

    virtual std::string toString();

};

#endif
