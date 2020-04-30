//
// Created by Ginton on 30/04/2020.
//
#include <iostream>
#include <string>
#include<complex>
#include<math.h>
#include "doctest.h"
#include "solver.hpp"

using namespace std;

using solver::solve, solver::RealVariable, solver::ComplexVariable;
///Real Variable...
TEST_CASE("Real Variable Operator+/Operator- :  ()+/-x = +/-(Random Number) ")
{
    RealVariable x;
            CHECK(solve(x == 1) == 1);
            CHECK(solve(x+2 == 1) == -1);
            CHECK(solve(15+x-1 == 1) == -13);
            CHECK(solve(15+x-1 == 1+16) == 3);
            CHECK(solve(x+x+x == 21) == 7);
            CHECK(solve(x+x+x == 22+x) == 11);
            CHECK(solve(x+x+2 == 12+x) == 10);
            CHECK(solve(1*x == 0) == 0);
            CHECK(solve(2*x*3 == 6) == 1);
            CHECK(solve(2*2*x*2 == 12) == 2);
            CHECK(solve(x+x+2 == 12+x) == 10);
            CHECK(solve(x*x == 0) == 0);
            CHECK(solve(x*x*2 == 72) == 6)  ;
}

TEST_CASE("Real Variable Operator * : ()*x +/- () == +/-/*(Random Number)")
{
    RealVariable x;

            CHECK(solve(1*x == 0) == 0);
            CHECK(solve(2*x*3 == 6) == 1);
            CHECK(solve(2*2*x*2 == 12) == 2);
            CHECK(solve(x == 1) == 1);
            CHECK(solve(x+2 == 1) == -1);
            CHECK(solve(15+x-1 == 1) == -13);
            CHECK(solve(15+x-1 == 1+16) == 3);
            CHECK(solve(x+x+x == 21) == 7);
            CHECK(solve(x+x+x == 22+x) == 11);
            CHECK(solve(x+x+2 == 12+x) == 10);
            CHECK(solve(x*x == 0) == 0);
            CHECK(solve(x*x*2 == 72) == 6)  ;

}

TEST_CASE("Real Variable Operator MIX")
{
    RealVariable x;
            CHECK(solve(2*(x^2) -64==0 ) == 5.6568542);
            CHECK(solve((x^2) -16==0 ) == 4);
            CHECK(solve(9*(x^2) == 729) == 1);
            CHECK(solve((x+2)*(x-3) == 0) == -2);
            CHECK(solve(2*x-4 == 10)==7);
            CHECK(solve(5*x-10 == 5)==3);
            CHECK(solve(-7*x == 14)==-2);
            CHECK(solve(22*x+7 == 19*x+4)==-1);
            CHECK(solve(3*x+10 == 15*x-14)==2);
            CHECK(solve((x+2)*(x-3) == 0) == 3);
            CHECK(solve((x+12)*(6+x-3) == 0) == -12);
            CHECK(solve((x+12)*(6+x-3) == 0) == 3);
            CHECK(solve(-1*(x^2) + -22*x + 7104 == 0) == 74);
            CHECK(solve(-1*(x^2) + -22*x + 7104 == 0) == -96);
            CHECK(solve(-6*(x^2) + 90*x + 96  == 0) == -1);
            CHECK(solve(-6*(x^2) + 90*x + 96  == 0) == 16);
            CHECK(solve(25*x + 6 == 99*(x^2)) == 0.15041102);
            CHECK(solve(-99*x^2 + 25*x + 6 == 0) == -0.40293628);
            CHECK(solve((3*x)*x + x*7.5 + 16*x == -40) == -2.5);
            CHECK(solve((3*x)*x + x*7.5 + 16*x == -40) == -5.33333333);
            CHECK(solve((x-2)*(x+1) == (x-1)*(x+3) == 0.3333333 ));
            CHECK(solve(((x+1)^2) == 2*(x-3)+2) == -3);
            CHECK(solve(((x+1)^2) == 2*(x-3)+2) == 3);
            CHECK(solve((x^2) + 3*x +1  == ((x-2)^2)) == 0.42857142);
            CHECK(solve((55*(x^2) -15*x - 50)/5 == 0) == -5);
            CHECK(solve((55*(x^2) -15*x - 50)/5 == 0) == 2);
            CHECK(solve(x^2 - 5484*x + 1248548 == 0) ==238);
            CHECK(solve(x^2 - 5484*x + 1248548 == 0) == 5246);
            CHECK(solve(x^2 + (38.66666667)*x - 26.2222222 == 0) == 0.6666666667);
            CHECK(solve(x^2 +3*x == -2) == -2);
            CHECK(solve(x^2 +3*x == -2) == -1);
            CHECK(solve(x^2 +3*x == -2) == -1);
            CHECK(solve((0.5)*x^2 +1.1*x - 2.3 == 0) == 1.310394159);
            CHECK(solve((0.5)*x^2 +1.1*x - 2.3 == 0) == -3.510394159);
            CHECK(solve(x^2 - x +0.5 == 0) == 0.5);
            CHECK(solve(x^2 - x +0.5 == 0) == 0.25);
            CHECK(solve(((x+2)^2) - 1 == 0) == -2);
            CHECK(solve(((x+2)^2) - 1 == 0) == -1);
            CHECK(solve(((x-4)^2) - 9 == 0) == 4);
            CHECK(solve(((x-4)^2) - 9 == 0) == -9);
            CHECK(solve((-1*(x-5)^2)== -3) == 6.732050808);
            CHECK(solve((-1*(x-5)^2)== -3) == 3.267949192);


}

TEST_CASE("Complex Variable Operator MIX") {
    using namespace complex_literals;
    ComplexVariable y;

            CHECK(solve((55 * (y ^ 2) - 15 * y - 50) / 5 == 0) == 2i);
            CHECK(solve(y ^ 2 + 12 * y + 1 == (6 * y) * 2) == -1i);
            CHECK(solve((y - 2) * (y - 3) + y ^ 2 == 5 * y + 6) == -1i);
            CHECK(solve(y ^ 2 + 12 * y + 1 == (6 * y) * 2) == 0i);
            CHECK(solve(y ^ 2 + 12 * y + 1 == (6 * y) * 2 - 6) == -3i);
            CHECK(solve(y ^ 2 + 12 * y + 1 == (6 * y) * 2) == -1i);
            CHECK(solve(12 * y ^ 2 + 4 * y + 8 == 0) == -0.16666666 + 0.7993052539i);
            CHECK(solve(y ^ 2 - 4 * y == -5).real() == 2);
            CHECK((solve((y^2)+100==0)==complex<double> (0,10) ||solve((y^2)+100==0)==complex<double> (0,-10) ));
            CHECK(solve(y+5 == y-y+6i) == std::complex<double>(-5,6));
            CHECK((solve(2 * y - 4 == 10) == double(7)));
            CHECK((solve(y + 4 == 10) == double(6)));
            CHECK((solve(y + y - y - 4 == 10) == double(14)));
            CHECK((solve((y ^ 2) == 0) == double(0)));


}

TEST_CASE("throws"){
    RealVariable x;
    CHECK_THROWS_AS(solve((x^2) +2 == -2*x), std::exception);
    CHECK_THROWS_AS(solve((x^2) + 6*x  == -13), std::exception);
    CHECK_THROWS_AS(solve((x^2) - 8*x +17 == 0), std::exception);
    CHECK_THROWS(solve(x/0 == 0));
    CHECK_THROWS(solve(10/x == 0));
    CHECK_THROWS(solve(x/(1-1) == -1));
    CHECK_THROWS_AS(solve((x^2) -2*x +26 == 0), std::exception);
    CHECK_THROWS(solve((x ^ 2) == -8));
    CHECK_THROWS(solve((x ^ 2) == -6));
    CHECK_THROWS(solve((x ^ 2) == -1));
    CHECK_THROWS(solve((x ^ 2) == -2));
    CHECK_THROWS(solve((x ^ 2) == -4));
    CHECK_THROWS_AS(solve((x^2)- 7*x + 14 == 2*x), std::exception);
    CHECK_THROWS_AS(solve((x^2) -2*x + 5 == 2*x), std::exception);
    CHECK_THROWS(solve((x^2)==-16));

    CHECK_THROWS(solve(2*(x^2)-3*x+4 == 0));
    CHECK_THROWS(solve(-1*x+2 == -1*x+4));
    CHECK_THROWS(solve(3*x/0.5*x-6 == 0));
    CHECK_THROWS((solve(5 * (x ^ 2) + 6 * x + 7 == 0)));
    CHECK_THROWS((solve(3 * (x ^ 2) + 4 * x + 5 == 0)));
    CHECK_THROWS((solve((x ^ 2) + 2 * x + 3 == 0)));
}
TEST_CASE("Extra") {
    ComplexVariable x;
            CHECK(((solve((x ^ 2) == 6.5025) == complex<double>(2.55, 0)) ||
                   (solve((x ^ 2) == 6.5025f) == complex<double>(-2.55, 0))));
            CHECK(((solve((x ^ 2) == 1.5625) == complex<double>(1.25, 0)) ||
                   (solve((x ^ 2) == 1.5625) == complex<double>(-1.25, 0))));
            CHECK(((solve((x ^ 2) == -6.5025f) == 2.55i) || (solve((x ^ 2) == -6.5025f) == -2.55i)));
            CHECK(((solve((x ^ 2) == -1.5625) == 1.25i) || (solve((x ^ 2) == -1.5625) == -1.25i)));



}
