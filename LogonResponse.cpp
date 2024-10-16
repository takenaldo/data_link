#include "LogonResponse.h"
#include <string>

LogonResponse::LogonResponse(
    int ident,
    std::string responseMessage
    ){
    id = ident;
    this->response = responseMessage;

    this ->message = this->response;
    
    }