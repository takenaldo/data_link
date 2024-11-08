#ifndef CONNECTION_REQUEST_H
#define CONNECTION_REQUEST_H

#include "DataLinkMessage.h"

class ConnectionRequest : public DataLinkMessage {
public:
    std::string mesg;          
    std::string messageType = "UM";  
    bool responseRequired = true;    

    ConnectionRequest(int id, const std::string& mesg);

    virtual std::string toString();
};

#endif
