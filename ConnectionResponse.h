// ConnectionResponse.h
#ifndef CONNECTION_RESPONSE_H
#define CONNECTION_RESPONSE_H

#include "DataLinkMessage.h"
#include <string>

class ConnectionResponse {
public:
    // Mandatory attribute
    std::string response;
    std::string msg;
    
    ConnectionResponse(std::string resp);

    // Parameterized Constructor with optional attributes
    
    std::string toString() const;   
    

   
};

#endif // LOGONRESPONSE_H
