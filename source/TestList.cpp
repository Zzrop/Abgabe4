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
TEST_CASE("delete an element with pop_front" ,"[modifiers]"){
	List <int> list;
	list.push_back(42);
	list.pop_front();
	REQUIRE (0 == list.size());
	list.push_back(1);
	list.push_back(2);
	list.pop_front();
	REQUIRE (2 == list.front());
}

TEST_CASE("delete an element with pop_back" ,"[modifiers]"){
	List <int> list;
	list.push_back(42);
	list.pop_back();
	REQUIRE (0 == list.size());
	list.push_back(12);
	list.push_back(34);
	list.pop_back();
	REQUIRE (12 == list.back());
}

TEST_CASE("should be empty after clearing", "[modifiers]")
{
List <int> list;
list.push_front(1);
list.push_front(2);
list.push_front(3);
list.push_front(4);
list.clear ();
REQUIRE(list.empty());
}

TEST_CASE ("should be an empty range after default construction", "[iterators]")
{
List<int> list;
auto b = list.begin();
auto e = list.end();
REQUIRE(b == e);
}

TEST_CASE("provide acces to the first element with begin", "[iterators]")
{
List<int> list;
list.push_front(42);
REQUIRE(42 == *list.begin());
}

TEST_CASE("comparing 2 lists", "[iterators]")
{
List<int> l1;
l1.push_front(42);
List<int> l2;
List<int> l3;
l2.push_front(42);
REQUIRE(l1 != l3);
REQUIRE(l1 == l2);
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
