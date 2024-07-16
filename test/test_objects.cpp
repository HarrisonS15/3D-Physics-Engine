#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <objects.hpp>


TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Line line = Line(Vertex(1,1,1), Vertex(1,2,1));
    REQUIRE(line.length == 1);
}