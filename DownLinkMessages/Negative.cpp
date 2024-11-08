#ifndef NEGATIVE_CPP
#define NEGATIVE_CPP


#include<iostream>
#include<vector>
#include<variant>

#include "Response.cpp"


namespace dm::response{

class Negative: public Response{
private:

const std::string NEGATIVE = "NEGATIVE";

std::vector<std::variant<int, float, double, std::string>>  m_initializePhrases(){
    return {NEGATIVE};
}

public:

Negative(): dm::Response(5)
{
    setMessage(buildMessage(m_initializePhrases()));
}

};

}


#endif 