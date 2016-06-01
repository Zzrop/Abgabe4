#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "list.hpp"


TEST_CASE("add an element with push_front" ,"[modifiers]"){
	List <int> list;
	list.push_front(42);
	REQUIRE (42 == list.front());
	list.push_front(12);
	REQUIRE (12 == list.front());
	REQUIRE (42 == list.back());
}

TEST_CASE("add an element with push_back" ,"[modifiers]"){
	List <int> list;
	list.push_back(42);
	REQUIRE (42 == list.back());
	list.push_back(12);
	REQUIRE (12 == list.back());
	REQUIRE (42 == list.front());
}
/*
TEST_CASE("vector","x,y"){

	Vec2 v1{1.0,1.0};
	Vec2 v2;

	REQUIRE(v1.x == 1.0);
	REQUIRE(v1.y == 1.0);
	REQUIRE(v2.x == 0.0);
	REQUIRE(v2.y == 0.0);

}
*/


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
