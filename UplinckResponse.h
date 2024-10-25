#ifndef UPLINKRESPONSE_H
#define UPLINKRESPONSE_H

#include <string>
#include "DataLinkMessage.h"

class UplinkResponse : public DataLinkMessage
{
public:
    std::string message_element;
    URG::Type urgency;
    ALRT::Type alert;

    UplinkResponse(int id, const std::string& mesg, URG::Type urg , ALRT::Type alrt);
    UplinkResponse(int id, const std::string& mesg, ALRT::Type alrt);
    UplinkResponse(int id, const std::string& mesg, URG::Type urg);
    UplinkResponse(int ident, const std::string &mesg);
    ~UplinkResponse();

    void displayResponseDetails();
    std::string toString();
};

#endif
