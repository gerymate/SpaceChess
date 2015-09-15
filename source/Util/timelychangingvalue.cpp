#include "timelychangingvalue.h"

using namespace std::chrono;

namespace Util {

TimelyChangingValue::TimelyChangingValue(double theTargetValue, std::chrono::seconds theChangeDuration)
    : targetValue{theTargetValue}, changeDuration{theChangeDuration}
{
    currentValue = targetValue;
}

TimelyChangingValue& TimelyChangingValue::operator=(double theNewTargetValue)
{
    targetValue = theNewTargetValue;
    startValue = currentValue;
    startTime = steady_clock::now();
    return *this;
}

TimelyChangingValue::operator double()
{
    if (currentValue != targetValue)
    {
	steady_clock::time_point now { steady_clock::now() };
	if (now >= startTime + changeDuration)
	{
	    currentValue = targetValue;
	} else {
	    steady_clock::duration timeElapsed { now - startTime };
	    currentValue = startValue + ( (timeElapsed / changeDuration) * (targetValue - startValue) );
	}
    }
    return currentValue;
}
    
    
}