#include "LogonResponse.h"
#include <string>
LogonResponse::LogonResponse(
    int ident,
    std::string responsemessage
    ){
    this->response = responsemessage;

    this ->message = this ->response;
}


std::string LogonResponse::toString() {
    std::string msg =  messageType + " , " + std::to_string(id) + " , "+ message;
    return msg;
}