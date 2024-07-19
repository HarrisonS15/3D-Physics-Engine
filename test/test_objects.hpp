#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include <iostream>
#include <objects.hpp>

// Vertex Tests
    Vertex v1 = Vertex(1,2,3);
    Vertex v2 = Vertex(9,7,8);
    Vertex vertexMidPoint =  v1.getMidPoint(v2);
TEST_CASE( "Test Vertex Constructor", "[vertex]" ) {
    REQUIRE(v1.getX() == 1);
    REQUIRE(v1.getY() == 2);
    REQUIRE(v1.getZ() == 3);
    REQUIRE(v2.getX() == 9);
    REQUIRE(v2.getY() == 7);
    REQUIRE(v2.getZ() == 8);
}

TEST_CASE( "Test Vertex getMidPoint", "[vertex.getMidPoint]" ) {
    REQUIRE(vertexMidPoint.getX() == 5);
    REQUIRE(vertexMidPoint.getY() == 4.5);
    REQUIRE(vertexMidPoint.getZ() == 5.5);
}

// Line Tests
    Line line = Line(Vertex(7,4,3), Vertex(17,6,2));
    Line line2 = Line(Vertex(15,-9,0), Vertex(-13,-4,-1));

TEST_CASE( "Test Line Constructor", "[line]" ) {
    REQUIRE(line.getVertexA().getX() == 7);
    REQUIRE(line.getVertexA().getY() == 4);
    REQUIRE(line.getVertexA().getZ() == 3);
    REQUIRE(line.getVertexB().getX() == 17);
    REQUIRE(line.getVertexB().getY() == 6);
    REQUIRE(line.getVertexB().getZ() == 2);
}

TEST_CASE( "Test Line length", "[line]" ) {
    REQUIRE(std::round(line.getLength()/0.00001)*0.00001 == std::round(10.246951/0.00001)*0.00001);
}

TEST_CASE( "Test Line getCenterOfLine", "[line.getCenterOfLine]" ) {
    Vertex centerVertex = line2.getCenterOfLine();
    REQUIRE(centerVertex.getX() == 1);
    REQUIRE(centerVertex.getY() == -6.5);
    REQUIRE(centerVertex.getZ() == -0.5);
}
// Object2D Tests

    //Triangle Tests