#include "event.h"

Event::Event(std::string theSender, std::string theMessage, std::string theParameters) 
    : sender (theSender), message (theMessage), parameters (theParameters) 
{

}

Event::~Event()
{

}
