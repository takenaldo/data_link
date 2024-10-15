#include "ConnectionResponse.h"
#include <string>

ConnectionResponse::ConnectionResponse(
    int ident,
    std::string responseMessage
    ){
    id = ident;
    this->response = responseMessage;

    this ->message = this->response;
    
    }
 ConnectionResponse::~ConnectionResponse(){
    
 }