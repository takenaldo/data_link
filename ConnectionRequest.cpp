#include "ConnectionRequest.h"

ConnectionRequest::ConnectionRequest(int ident, const std::string& mesg) {
    m_id = ident;
    this->mesg = mesg;  
    this->message = this->mesg;
}


std::string ConnectionRequest::toString() {
    return messageType + " , " + std::to_string(m_id) + " , " + message;
}
