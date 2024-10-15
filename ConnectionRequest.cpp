#include "ConnectionRequest.h"
#include <string>

ConnectionRequest::ConnectionRequest(int ident, std::string requestedMessage)
{
    id = ident;
     this->messageR = requestedMessage;

    this ->message = this ->messageR;
}
 ConnectionRequest::~ConnectionRequest(){
    
 }

