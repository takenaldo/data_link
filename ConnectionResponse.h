#include<string>
#include"DataLinkMessage.h"
class ConnectionResponse : public DataLinkMessage
{
private:
    /* data */
public:

 std::string response;
    std::string messageType = "UM";
    ConnectionResponse(
        int id,
        std::string responseMessage
        );

    ~ConnectionResponse();
};
