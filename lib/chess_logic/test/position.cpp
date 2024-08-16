#include <catch2/catch_test_macros.hpp>

#include "chess_position.h"

/**
 * Test cases for constructor with file and rank
 */

TEST_CASE(
    "ChessPosition: constructor with file and rank should create a valid "
    "position") {
  ChessPosition position('a', 1);
  REQUIRE(position.isValid());
  REQUIRE(position.toData() == 0x11);
}

TEST_CASE(
    "ChessPosition: constructor with invalid file and rank should create an "
    "invalid position") {
  SECTION("Invalid file") {
    ChessPosition position('i', 1);
    REQUIRE(!position.isValid());
  }

  SECTION("Invalid rank") {
    ChessPosition position('a', 0);
    REQUIRE(!position.isValid());
  }

  SECTION("Invalid file and rank") {
    ChessPosition position('i', 0);
    REQUIRE(!position.isValid());
  }
}

/**
 * Test cases for constructor with algebraic notation
 */

TEST_CASE(
    "ChessPosition: constructor with algebraic notation should create a valid "
    "position") {
  ChessPosition position("a1");
  REQUIRE(position.isValid());
  REQUIRE(position.toData() == 0x11);
}

TEST_CASE(
    "ChessPosition: constructor with invalid algebraic notation should create "
    "an invalid position") {
  SECTION("Invalid length") {
    ChessPosition position("a");
    REQUIRE(!position.isValid());
  }

  SECTION("Invalid file") {
    ChessPosition position("i1");
    REQUIRE(!position.isValid());
  }

  SECTION("Invalid rank") {
    ChessPosition position("a0");
    REQUIRE(!position.isValid());
  }

  SECTION("Invalid file and rank") {
    ChessPosition position("i0");
    REQUIRE(!position.isValid());
  }
}

/**
 * Test cases for constructor with data
 */

TEST_CASE(
    "ChessPosition: constructor with data should create a valid position") {
  ChessPosition position(0x11);
  REQUIRE(position.isValid());
  REQUIRE(position.toData() == 0x11);
}

TEST_CASE(
    "ChessPosition: constructor with invalid data should create an invalid "
    "position") {
  ChessPosition position(0x00);
  REQUIRE(!position.isValid());
}

/**
 * Test cases for getFile
 */

TEST_CASE("ChessPosition: getFile should return the file of the position") {
  ChessPosition position('a', 2);
  REQUIRE(position.getFile() == 0x01);
}

/**
 * Test cases for getRank
 */

TEST_CASE("ChessPosition: getRank should return the rank of the position") {
  ChessPosition position('a', 2);
  REQUIRE(position.getRank() == 0x02);
}

/**
 * Test cases for toString
 */

TEST_CASE(
    "ChessPosition: toString should return the position in algebraic "
    "notation") {
  ChessPosition position('a', 2);
  REQUIRE(position.toString() == "a2");
}

TEST_CASE(
    "ChessPosition: toString should return an empty string for an invalid "
    "position") {
  ChessPosition position('i', 0);
  REQUIRE(position.toString().empty());
}

/**
 * Test cases for operator==
 */

TEST_CASE("ChessPosition: operator== should compare two positions") {
  ChessPosition position1('a', 2);
  ChessPosition position2('a', 2);
  ChessPosition position3('b', 2);
  ChessPosition position4('a', 3);

  REQUIRE(position1 == position2);
  REQUIRE(!(position1 == position3));
  REQUIRE(!(position1 == position4));
}

/**
 * Test cases for operator!=
 */

TEST_CASE("ChessPosition: operator!= should compare two positions") {
  ChessPosition position1('a', 2);
  ChessPosition position2('a', 2);
  ChessPosition position3('b', 2);
  ChessPosition position4('a', 3);

  REQUIRE(!(position1 != position2));
  REQUIRE(position1 != position3);
  REQUIRE(position1 != position4);
}

/**
 * Test cases for operator+
 */

TEST_CASE("ChessPosition: operator+ should sum two positions") {
  ChessPosition position1('a', 2);
  ChessPosition position2('b', 3);

  ChessPosition position3 = position1 + position2;
  REQUIRE(position3.toData() == 0x35);
}

/**
 * Test cases for operator-
 */

TEST_CASE("ChessPosition: operator- should subtract two positions") {
  ChessPosition position1('b', 3);
  ChessPosition position2('a', 2);

  ChessPosition position3 = position1 - position2;
  REQUIRE(position3.toData() == 0x11);
}
