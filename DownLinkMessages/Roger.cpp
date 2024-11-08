#ifndef ROGER_CPP
#define ROGER_CPP

#include<iostream>
#include<vector>
#include<variant>

#include "Response.cpp"

namespace dm::response{

class Roger: public Response{
private:

const std::string ROGER = "ROGER";

std::vector<std::variant<int, float, double, std::string>>  m_initializePhrases(){
    return {ROGER};
}

public:

Roger(): dm::Response(3)
{
    setMessage(buildMessage(m_initializePhrases()));
}


};

}

#endif