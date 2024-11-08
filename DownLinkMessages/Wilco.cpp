#ifndef WILCO_CPP
#define WILCO_CPP

#include<iostream>
#include<vector>
#include<variant>

#include "Response.cpp"

namespace dm::response{

class Wilco: public Response{
private:

const std::string WILCO_PHRASE = "WILCO";

std::vector<std::variant<int, float, double, std::string>>  m_initializePhrases(){
    return {WILCO_PHRASE};
}

public:

Wilco(): dm::Response(0)
{
    setMessage(buildMessage(m_initializePhrases()));
}


};

}


#endif