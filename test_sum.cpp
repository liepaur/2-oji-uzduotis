#define CATCH_CONFIG_MAIN  // Catch2 sukurs main() automatiškai
#include "catch_amalgamated.hpp"
#include "sum.h"

// Testai
TEST_CASE("Sum of positive numbers", "[sum]") {
    REQUIRE(sum(2, 3) == 5);
}

TEST_CASE("Sum of negative numbers", "[sum]") {
    REQUIRE(sum(-2, -3) == -5);
}

TEST_CASE("Sum with zeros", "[sum]") {
    REQUIRE(sum(0, 5) == 5);
    REQUIRE(sum(0, 0) == 0);
}

TEST_CASE("Sum of large numbers", "[sum]") {
    REQUIRE(sum(1000000, 2000000) == 3000000);
}

