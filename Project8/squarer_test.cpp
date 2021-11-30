/* squarer_test.cpp
 * Created by:
 * Glenn G. Chappell
 * 2021-11-19
 *
 * Finished by:
 * Aleks McCormick
 * 2021/11/22
 *
 * For CS 311 Fall 2021
 * Test program for class Squarer
 * For Project 8, Exercise B
 * Uses the "doctest" unit-testing framework, version 2
 * Requires doctest.h, squarer.h
 */

// Includes for code to be tested
#include "squarer.h"         // For class Squarer
#include "squarer.h"         // Double-inclusion check, for testing only

// Includes for the "doctest" unit-testing framework
#define DOCTEST_CONFIG_IMPLEMENT
                             // We write our own main
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
                             // Reduce compile time
#include "doctest.h"         // For doctest

// Includes for all test programs
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;

// Additional includes for this test program
// NONE

// Printable name for this test suite
const std::string test_suite_name =
    "class Squarer"
    " - CS 311 Proj 8, Ex B";


/******************************************/
/***            Test Cases              ***/
/******************************************/


TEST_CASE("Squarer: Positive Ints")
{
    Squarer sq;

	SUBCASE("Square 0"){
		INFO("0 squared is 0");
		REQUIRE(sq(0) == 0);
	}
	SUBCASE("Square 1"){
		INFO("1 squared is 1");
		REQUIRE(sq(1) == 1);
	}
	SUBCASE("Square 2"){
		INFO("2 squared is 4");
		REQUIRE(sq(2) == 4);
	}
	SUBCASE("Square 7"){
		INFO("7 squared is 49");
		REQUIRE(sq(7) == 49);
	}
	SUBCASE("Square 10"){
		INFO("10 squared is 100");
		REQUIRE(sq(10) == 100);
	}
	SUBCASE("Square 12234"){
		INFO("12234 squared is 149670756");
		REQUIRE(sq(12234) == 149670756);
	}
}// End Positive ints test case

TEST_CASE("Squarer: Negative Ints")
{
	Squarer sq;

	SUBCASE("Square -1"){
		INFO("-1 squared is 1");
		REQUIRE(sq(-1) == 1);
	}
	SUBCASE("Square -2"){
		INFO("-2 squared is 4");
		REQUIRE(sq(-2) == 4);
	}
	SUBCASE("Square -7"){
		INFO("-7 squared is 49");
		REQUIRE(sq(-7) == 49);
	}
	SUBCASE("Square -10"){
		INFO("-10 squared is 100");
		REQUIRE(sq(-10) == 100);
	}
	SUBCASE("Square -12234"){
		INFO("-12234 squared is 149670756");
		REQUIRE(sq(-12234) == 149670756);
	}
}// End Negative ints test case

TEST_CASE("Squarer: Floating-point values")
{
	Squarer sq;

	SUBCASE("Square 0.0"){
		INFO("0.0 squared is 0.0");
		REQUIRE(sq(0.0) == 0.0);
	}
	SUBCASE("Square 1.5"){
		INFO("1.5 squared is 2.25");
		REQUIRE(sq(1.5) == doctest::Approx(2.25));
	}
	SUBCASE("Square -2.9"){
		INFO("-2.9 squared is 8.41");
		REQUIRE(sq(-2.9) == doctest::Approx(8.41));
	}
	SUBCASE("Square 7.7"){
		INFO("7.7 squared is 59.29");
		REQUIRE(sq(7.7) == doctest::Approx(59.29));
	}
	SUBCASE("Square -10.10"){
		INFO("-10.1 squared is 102.01");
		REQUIRE(sq(-10.1) == doctest::Approx(102.01));
	}
	SUBCASE("Square 12234.00002"){
		INFO("12234.00002 squared is 149670756.4893600004");
		REQUIRE(sq(12234.00002) == doctest::Approx(149670756.4893600004));
	}
}// End Floating-point values test case

TEST_CASE("Squarer: Const values"){
	Squarer sq;
	const int num = 5;

	SUBCASE("Const variable"){
		INFO("Square Const int Variable");
		REQUIRE(sq(num) == 25);
	}

	SUBCASE("Double Squarer"){
		INFO("Square the result produced by Squarer");
		REQUIRE(sq(sq(num)) == 625);
	}
}// End Const values test case


/******************************************/
/***           Main Program             ***/
/******************************************/


// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}


// Main program
// Run all tests. Prompt for ENTER before exiting.
int main(int argc,
         char *argv[])
{
    doctest::Context dtcontext;
                             // Primary doctest object
    int dtresult;            // doctest return code; for return by main

    // Handle command line
    dtcontext.applyCommandLine(argc, argv);
    dtresult = 0;            // doctest flags no command-line errors
                             //  (strange but true)

    if (!dtresult)           // Continue only if no command-line error
    {
        // Run test suites
        cout << "BEGIN tests for " << test_suite_name << "\n" << endl;
        dtresult = dtcontext.run();
        cout << "END tests for " << test_suite_name << "\n" << endl;
    }

    // If we want to do something else here, then we need to check
    // context.shouldExit() first.

    // Wait for user
    std::cout << "Press ENTER to quit ";
    userPause();

    // Program return value is return code from doctest
    return dtresult;
}

