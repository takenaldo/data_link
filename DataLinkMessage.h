#include <string>


class DataLinkMessage{

private:
public:
    int id; // identification
    
    int min; // message identification
    int mrn; // reference
    
    std::string message; // actual message

    std::string messageType; // UM or DM

    bool responseRequired;

    DataLinkMessage();
    DataLinkMessage(std::string );

    DataLinkMessage(
        std::string messageType,
        int id,
        int min,
        int mrn,
        std::string message,
        bool responseRequired
    );


    std::string toString(){
        /*
        * Return a string representation of the message
        */

       std::string msg = messageType +","+ std::to_string(id) +","+ message;

        return  msg;
    }

};