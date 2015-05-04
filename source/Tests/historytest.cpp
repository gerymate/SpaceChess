#include "catch.hpp"

#include "history.h"
#include "gameevent.h"
#include "king.h"
#include "queen.h"
#include <string>
#include <sstream>

namespace Model {
struct MockGameEvent : public GameEvent
{
    static int numberOfMockGameEvents;
    int id {0};
    int executed { 0 };

    MockGameEvent() { id = ++numberOfMockGameEvents; }
    virtual ~MockGameEvent() { --numberOfMockGameEvents; }
    bool execute() { ++executed; return true; }
    bool revert() { --executed; return true; }
    std::string getNotation() const
    {
	std::stringstream notation;
	notation << "MockGameEvent #" << id;
	return notation.str();
    }
};
int MockGameEvent::numberOfMockGameEvents = 0;
} // namespace Model

SCENARIO("We test a new game history", "[history]")
{
    using namespace Model;
    GIVEN("a new history")
    {
	Board board;
	History history { &board };
	
	REQUIRE ( history.getNextPlayer() == Player::Nobody );
	
	WHEN("we try to step back beyond creation")
	{
	    REQUIRE( history.stepBack() == false );

	    PointerToGameEvent shouldBeCreation = history.getCurrentEvent();
	    REQUIRE ( shouldBeCreation->getNotation() == "Game created." );
	    
	    THEN("nothing to do yet")
	    {
		REQUIRE ( history.actualize() == false );
	    }	    
	}
	
	WHEN("we add 3 new gameevent")
	{
	    std::shared_ptr<MockGameEvent> event1 {new MockGameEvent};
	    std::shared_ptr<MockGameEvent> event2 {new MockGameEvent};
	    std::shared_ptr<MockGameEvent> event3 {new MockGameEvent};
	    
	    PointerToGameEvent p1 = event1;
	    PointerToGameEvent p2 = event2;
	    PointerToGameEvent p3 = event3;

	    history.addEvent(p1);
	    history.addEvent(p2);
	    history.addEvent(p3);
	    
	    REQUIRE( history.stepForward() );
	    REQUIRE( history.getCurrentEvent()->getNotation() == std::string{"MockGameEvent #1"} );
	    REQUIRE( event1->executed == 1 );
	    REQUIRE( event2->executed == 0 );
	    REQUIRE( event3->executed == 0 );
	    
	    REQUIRE( history.actualize() );
	    REQUIRE( history.getCurrentEvent()->getNotation() == std::string{"MockGameEvent #3"} );
	    REQUIRE( event2->executed == 1 );
	    REQUIRE( event3->executed == 1 );
	    
	    REQUIRE( history.stepBack() );
	    REQUIRE( history.getCurrentEvent()->getNotation() == std::string{"MockGameEvent #2"} );
	    REQUIRE( event2->executed == 1 );
	    REQUIRE( event3->executed == 0 );
	    
	    history.reset();
	    REQUIRE( history.stepForward() );
	    history.clearFuture();
	    REQUIRE( history.stepForward() == false );
	    REQUIRE( history.getCurrentEvent()->getNotation() == std::string{"MockGameEvent #1"} );
	    REQUIRE( event1->executed == 2 );
	    
	}
    }
    
}


