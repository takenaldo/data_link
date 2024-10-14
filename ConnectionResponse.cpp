#include "ConnectionResponse.h"
#include <string>

ConnectionResponse::ConnectionResponse(std::string resp)
    : response(resp) , msg(resp) {
      
    
    // this ->msg = this ->response;
    
    }



std::string ConnectionResponse::toString() const {
    
  std::string msg = "Response: " + response;
  return msg;
}
