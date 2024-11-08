#ifndef STANDBY_CPP
#define STANDBY_CPP


#include<iostream>
#include<vector>
#include<variant>

#include "Response.cpp"


namespace dm::response{

class Standby: public Response{
private:

const std::string STANDBY = "STANDBY";

std::vector<std::variant<int, float, double, std::string>>  m_initializePhrases(){
    return {STANDBY};
}

public:

Standby(): dm::Response(2)
{
    setMessage(buildMessage(m_initializePhrases()));
}


};

}

#endif