#ifndef LOGIN_REQUEST_H
#define LOGIN_REQUEST_H
#include<string>
#include "DataLinkMessage.h"

class LogonResponse: public DataLinkMessage
{
private:
   
public:
    
    std::string response;
    std::string messageType = "UM";
    LogonResponse(
        int id,
        std::string responseMessage
        );
};

#endif