// (C) Máté Gergely - gerymate@gmail.com
#include "catch2/catch.hpp"

#include "timelychangingvalue.h"

using namespace Util;

TEST_CASE("A TimelyChangingValue can be created, initialized and queried.")
{
    TimelyChangingValue changingValue { 5.0 };
    double queriedValue { changingValue };

    REQUIRE( queriedValue == 5.0 );
    
    SECTION("A TimelyChangingValue changes value slowly", "")
    {
	changingValue = 10.0;
	
	// wait 0.1s
	std::chrono::steady_clock::time_point oneSecLater { std::chrono::steady_clock::now() + std::chrono::milliseconds(100) };
	while (std::chrono::steady_clock::now() < oneSecLater);
	
	queriedValue = changingValue;
	
	REQUIRE( 5.0 <= queriedValue );
	REQUIRE( queriedValue < 10.0 );
	
	// wait 1s
	oneSecLater = std::chrono::steady_clock::now() + std::chrono::seconds(1);
	while (std::chrono::steady_clock::now() < oneSecLater);
		
	queriedValue = changingValue;
	REQUIRE( queriedValue == 10.0 );
    }
}


