#ifndef UPLINKRESPONSE_H
#define UPLINKRESPONSE_H

#include <string>
#include "DataLinkMessage.h"

class UplinkAdditionalMessages : public DataLinkMessage
{
public:
    std::string message_element;
    URG::Type urgency;
    ALRT::Type alert;
    UplinkAdditionalMessages(const std::string &mesg);
    ~UplinkAdditionalMessages();

    void displayAdditionalDetails();
    std::string toString();
    void assignID();
};

#endif
