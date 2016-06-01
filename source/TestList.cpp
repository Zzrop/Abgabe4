#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "list.hpp"

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
