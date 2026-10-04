/*

  Compile with: g++ main.cpp ../src/fac.cpp catch_amalgamated
  Run with ./a.out

*/


//#define CATCH_CONFIG_RUNNER
//#define CATCH_AMALGAMATED_CUSTOM_MAIN
#include <iostream>
#include "catch_amalgamated.hpp"
//#include "../src/fac.h"
#include "../src/complex.h"
#include <cmath>
using namespace std;
#define EULER 2.71828182845904523536

#ifdef CATCH_AMALGAMATED_CUSTOM_MAIN

int main( int argc, char* argv[] ) {
  // global setup...

  int result = Catch::Session().run( argc, argv );

  // global clean-up...
    cout << "Hello Catch2 Build with custom main()\n";

  return result;
}

#else    //Not CATCH_AMALGAMATED_CUSTOM_MAIN

TEST_CASE("Running tests on sqrt operator", "[Complex]") {
  CHECK(sqrt(Complex(1.0, 0.0)) == Complex(1.0, 0.0));
  CHECK(sqrt(Complex(4.0, 0.0)) == Complex(2.0, 0.0));
  CHECK(sqrt(Complex(-25.0, 0.0)) == Complex(0.0, 5.0));
  CHECK(sqrt(Complex(0.0, 1.0)) == Complex(sqrt(2)/2, sqrt(2)/2));
  CHECK(sqrt(Complex(0.0, 4.0)) == Complex(sqrt(2), sqrt(2)));
  CHECK(sqrt(Complex(0.0, -128.0)) == Complex(8.0, -8.0));
  CHECK(sqrt(Complex(0.0, 2.0)) == Complex(1.0, 1.0));
  CHECK(sqrt(Complex(13.0, 84.0)) == Complex(7.0, 6.0));
  CHECK(sqrt(Complex(16.0, 30.0)) == Complex(5.0, 3.0));
  CHECK(sqrt(Complex(-16.0, 30.0)) == Complex(3.0, 5.0));
  CHECK(sqrt(Complex(16.0, -30.0)) == Complex(5.0, -3.0));
}

TEST_CASE("Running tests on basic arithmetic operations") {
    CHECK(Complex(1.0, 2.0)+Complex(2.0, 3.0) == Complex(3.0, 5.0));
    CHECK(Complex(2.0, 4.0)-Complex(1.0, 2.0) == Complex(1.0, 2.0));
    CHECK(Complex(2.0, 3.0)*Complex(1.0, 2.0) == Complex(-4.0, 7.0));
    CHECK(Complex(2.0, 1.0)/Complex(1.0, 2.0) == Complex(0.8, -0.6));
    CHECK(Complex(1.0, 4.0)+Complex(2.0, 3.0) == Complex(3.0, 7.0));
    CHECK(Complex(2.0, 0.0)-Complex(1.0, 1.0) == Complex(1.0, -1.0));
    CHECK(Complex(2.0, 3.0)*Complex(2.0, 4.0) == Complex(-8.0, 14.0));
    CHECK(Complex(3.0, 11.0)/Complex(3.0, 1.0) == Complex(2.0, 3.0));

}

TEST_CASE("Test on != method", "[Complex]")
{
    cout << "Running tests on Complex != operator" << endl;
    CHECK(Complex(1.0, 2.0) != Complex(2.0, 1.0));
    CHECK(Complex(3.0, 1.0) != Complex(2.0, 3.0));
    CHECK(Complex(3.0, 2.0) != Complex(2.0, 0.0));
    CHECK_FALSE(Complex(1.0, 1.0) != Complex(1.0, 1.0));
    cout << "Running tests on Complex == operator" << endl;
    CHECK(Complex(1.0, 0.0)==Complex(1.0, 0.0));
    CHECK_FALSE(Complex(1.0, 2.0)==Complex(2.0, 1.0));
    CHECK(Complex(1.0, 3.0)==Complex(1.0, 3.0));
    CHECK_FALSE(Complex(3.0, 1.0)==Complex(1.0, 0.0));
    CHECK_FALSE(Complex(1.0, 3.0)==Complex(3.0, 1.0));
}

TEST_CASE("Test on arg method", "[Complex]")
{
    cout << "Running tests on Complex arg function" << endl;
    CHECK(arg(Complex(1.0, 0.0)) == 0.0);
    CHECK(arg(Complex(1.0, 1.0)) == 0.7853981633974483);

}

TEST_CASE("Test on conj method", "[Complex]")
{
    cout << "Running tests on Complex conj function" << endl;
    CHECK(conj(Complex(1.0, 2.0)) == Complex(1.0, -2.0));
    CHECK(conj(Complex(0.0, 0.0)) == Complex(0.0, 0.0));

}

TEST_CASE("Test on exp method", "[Complex]")
{
    cout << "Running tests on Complex exp function" << endl;
    CHECK(exp(Complex(0.0, 2.0)) == Complex(cos(2.0), sin(2.0)));
    CHECK(exp(Complex(7.0, 5.0)) == Complex(pow(EULER, 7.0)*cos(5.0), pow(EULER, 7.0)*sin(5.0)));
    CHECK(exp(Complex(3.0, 2.0)) == Complex(pow(EULER, 3.0)*cos(2.0), pow(EULER, 3.0)*sin(2.0)));
}



TEST_CASE("Test on log method", "[Complex]")
{
    cout << "Running tests on Complex log function" << endl;
    CHECK(log(Complex(0.0, 2.0)) == Complex(log(sqrt(pow(0.0, 2) + pow(2.0, 2))), arg(Complex(0.0, 2.0))));
    CHECK(log(Complex(3.0, 0.0)) == Complex(log(3.0), 0.0));

}

TEST_CASE("Test on sqrt method", "[Complex]")
{
    cout << "Running tests on Complex sqrt function" << endl;
    CHECK(sqrt(Complex(1.0, 0.0)) == Complex(1.0, 0.0));
    CHECK(sqrt(Complex(-3.0, 4.0)) == Complex(1.0, 2.0));
    CHECK(sqrt(Complex(4.0, 0.0)) == Complex(2.0, 0.0));
    CHECK(sqrt(Complex(3.0, 4.0)) == Complex(2.0, 1.0));

}

TEST_CASE("Test on norm method", "[Complex]")
{
    cout << "Running tests on Complex norm function" << endl;
    CHECK(norm(Complex(-8.0, 6.0)) == 100.0);
    CHECK(norm(Complex(3.0, 4.0)) == 25.0);

}

TEST_CASE("Test on abs method", "[Complex]")
{
    cout << "Running tests on Complex abs function" << endl;
    CHECK(abs(Complex(-8.0, 6.0)) == 10.0);
    CHECK(abs(Complex(3.0, 4.0)) == 5.0);

}

TEST_CASE("Test on real method", "[Complex]")
{
    cout << "Running tests on Complex real function" << endl;
    CHECK(real(Complex(1.0, 0.0)) == 1.0);
    CHECK(real(Complex(-2.0, 1.0)) == -2.0);

}

#endif  //ifndef CATCH_AMALGAMATED_CUSTOM_MAIN
