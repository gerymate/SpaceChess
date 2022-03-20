#include "log.h"
#include <iostream>

Log::Log(const std::string& logMe)
{
    std::cerr << logMe << "\n";
}

void Log::operator()(const std::string& logMe) const
{
    std::cerr << logMe << "\n";
}

void Log::that(const std::string& logMe)
{
    std::cerr << logMe << "\n";
}

void Log::that(const std::string& variableName, const double& variable)
{
    std::cerr << variableName << " = " << variable << "\n";
}

Log::~Log()
{
    std::cerr.flush();
}
