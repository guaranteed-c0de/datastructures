#include <catch2/catch_test_marcos.hpp>
#include "math_functions.h"

TEST_CASE("Square root of positive numbers", "[math]") {
  REQUIRE(compute_square_root(25.0) == 5.0);
  REQUIRE(compute_square_root(0.0) == 0.0);
}

TEST_CASE("Square root of negative numbers", "[math]") {
  REQUIRE(compute_square_root(-1.0) == -1.0);
}
