#ifndef UNABLE_CPP
#define UNABLE_CPP

#include<iostream>
#include<vector>
#include<variant>

#include "Response.cpp"


namespace dm::response{

class Unable: public Response{
private:

const std::string UNABLE_PHRASE = "UNABLE";

std::vector<std::variant<int, float, double, std::string>>  m_initializePhrases(){
    return {UNABLE_PHRASE};
}

public:

Unable(): dm::Response(1)
{
    setMessage(buildMessage(m_initializePhrases()));
}


};

}


#endif