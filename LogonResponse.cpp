
#include "LogonResponse.h"
#include <string>

LogonResponse::LogonResponse(std::string resp)
    : response(resp) , msg(resp) {
      
    
    // this ->msg = this ->response;
    
    }


// // Convert LogonResponse to a string format
std::string LogonResponse::toString() const {
    
  std::string msg = "Response: " + response;
  return msg;
}
