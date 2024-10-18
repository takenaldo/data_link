
#include "LogonResponse.h"
#include <string>

LogonResponse::LogonResponse(std::string resp)
    : response(resp) , msg(resp) {
      
    
    // this ->msg = this ->response;
    
    }



std::string LogonResponse::toString() const {
    
  std::string msg = "Response: " + response;
  return msg;
}
