#ifndef prg_cpp
#define prg_cpp

#include <string>
#include <typeindex>
#include <typeinfo>
#include <vector>
#include <variant>


class PermittedResponseGroup{
    private:
        int m_precedence;
        std::vector<std::type_index> m_responses;
        bool m_responseRequired = true;
    public:

        PermittedResponseGroup(int precedence, std::vector<std::type_index> permittedResponses, bool responseRequired): 
            m_precedence(precedence), m_responses(permittedResponses), m_responseRequired(responseRequired)
            {}

        int getPrecedence(){
            return m_precedence;
        }

        bool isResponseRequired(){
            return m_responseRequired;
        }

        std::vector<std::type_index>  getResponses(){
            return m_responses;
        }
};

#endif
