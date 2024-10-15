#include "LogonRequest.h"

LogonRequest::LogonRequest(
    int ident,
    std::string atsu,
    std::string reg,
    std::string address,
    std::string departure,
    std::string destination
){
    id = ident;
    this->atsuIcaoCode = atsu;
    this->registeration = reg;
    this->aircraftAddress = address;
    this->departure = departure;
    this->destination = destination;
    this->min = 1;
    this->mrn = 1;

    this->message = this->atsuIcaoCode + " " +
                    this->registeration + " " + 
                    this->aircraftAddress + " " + 
                    this->departure + " " + 
                    this->destination + " " + 
                    this->registeration;
}