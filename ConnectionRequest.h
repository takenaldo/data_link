#include <string>
#include "DataLinkMessage.h"

class ConnectionRequest: public DataLinkMessage
{
private:
    /* data */
public:

    std::string AtcuId;
    std::string messageR;
    std::string messageType = "UM";

    bool responseRequired = true;
    ~ConnectionRequest();

    ConnectionRequest(int id, std::string requestedMessage);
};
