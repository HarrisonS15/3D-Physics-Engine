#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include <iostream>
#include <objects.hpp>

int main( int argc, char* argv[] ) {
  Catch::Session session; // There must be exactly one instance

  // writing to session.configData() here sets defaults
  // this is the preferred way to set them

  int returnCode = session.applyCommandLine( argc, argv );
  if( returnCode != 0 ) // Indicates a command line error
        return returnCode;

  // writing to session.configData() or session.Config() here
  // overrides command line args
  // only do this if you know you need to

  int numFailed = session.run();

  // numFailed is clamped to 255 as some unices only use the lower 8 bits.
  // This clamping has already been applied, so just return it here
  // You can also do any post run clean-up here
  return numFailed;
}

// Vertex Tests
    Vertex v1 = Vertex(1,2,3);
    Vertex v2 = Vertex(9,7,8);
    Vertex vertexMidPoint =  v1.getMidPoint(v2);
TEST_CASE( "Test Vertex Constructor", "[vertex]" ) {
    REQUIRE(v1.x == 1);
    REQUIRE(v1.y == 2);
    REQUIRE(v1.z == 3);
    REQUIRE(v2.x == 9);
    REQUIRE(v2.y == 7);
    REQUIRE(v2.z == 8);
}

TEST_CASE( "Test Vertex getMidPoint", "[vertex.getMidPoint]" ) {
    REQUIRE(vertexMidPoint.x == 5);
    REQUIRE(vertexMidPoint.y == 4.5);
    REQUIRE(vertexMidPoint.z == 5.5);
}

// Line Tests
    Line line = Line(Vertex(7,4,3), Vertex(17,6,2));
    Line line2 = Line(Vertex(15,-9,0), Vertex(-13,-4,-1));

TEST_CASE( "Test Line Constructor", "[line]" ) {
    REQUIRE(line.a.x == 7);
    REQUIRE(line.a.y == 4);
    REQUIRE(line.a.z == 3);
    REQUIRE(line.b.x == 17);
    REQUIRE(line.b.y == 6);
    REQUIRE(line.b.z == 2);
}
TEST_CASE( "Test Line length", "[line]" ) {
    REQUIRE(std::round(line.length/1)*1 == 10.246951);
}

TEST_CASE( "Test Line getCenterOfLine", "[line.getCenterOfLine]" ) {
    Vertex centerVertex = line2.getCenterOfLine();
    REQUIRE(centerVertex.x == 1);
    REQUIRE(centerVertex.y == -6.5);
    REQUIRE(centerVertex.z == -0.5);
}
// Object2D Tests

    //Triangle Tests