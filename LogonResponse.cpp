#include "LogonResponse.h"
#include <string>

LogonResponse::LogonResponse(
    int ident,
    std::string responseMessage
    ){
    this->response = responseMessage;

    this ->message = this ->response;
}