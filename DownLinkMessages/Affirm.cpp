#ifndef AFFIRM_CPP
#define AFFIRM_CPP


#include<iostream>
#include<vector>
#include<variant>


#include "Response.cpp"

namespace dm::response{

class Affirm: public Response{
private:

const std::string AFFIRM = "AFFIRM";

std::vector<std::variant<int, float, double, std::string>>  m_initializePhrases(){
    return {AFFIRM};
}

public:

Affirm(): dm::Response(4)

{
    setMessage(buildMessage(m_initializePhrases()));
}


};

}

#endif