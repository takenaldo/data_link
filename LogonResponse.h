// LogonResponse.h
#ifndef LOGONRESPONSE_H
#define LOGONRESPONSE_H

#include "DataLinkMessage.h"
#include <string>

class LogonResponse {
public:
    // Mandatory attribute
    std::string response;
    std::string msg;
    
    LogonResponse(std::string resp);

    // Parameterized Constructor with optional attributes
    
    std::string toString() const;   
    

   
};

#endif // LOGONRESPONSE_H
