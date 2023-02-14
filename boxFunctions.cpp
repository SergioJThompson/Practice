//----------------------------------------------------------
// CS161 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

//This pragma supresses a bunch of warnings QTCreator produces (and should not)
#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"

//Hide some false warnings - this is supposed to look commented out
// clazy:skip

//Tell clang analyzer to ignore doctest.h
#ifndef __clang_analyzer__
#include "doctest.h"
#endif

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

//-----------------------------------------------------------------------------------

#include <iostream>
using namespace std;

//Your functions here



///----------------------------------------------------------------------------------
/// Tests
/// Uncomment tests to work on them. Make sure any test that does not compile or
/// causes a crash gets commented back out. Any test that runs should be left
/// on (uncommented), even if the test fails.
///----------------------------------------------------------------------------------

// TEST_CASE( "getArea" ) {
//     cout << "1: getArea" << endl;
//     CHECK( getArea(2, 4) == 8 );
//     CHECK( getArea(12, 7) == 84 );
// }

// TEST_CASE( "getVolume" ) {
//     cout << "2: getVolume" << endl;
//     CHECK( getVolume(2, 4, 3) == 24 );
//     CHECK( getVolume(12, 7, 2) == 168 );
// }

// TEST_CASE( "leftoverCardboard" ) {
//     cout << "3: leftoverCardboard" << endl;
//     CHECK( leftoverCardboard(3) == 36 );
//     CHECK( leftoverCardboard(10) == 400 );
// }

// TEST_CASE( "getMaxHeight" ) {
//     cout << "4: getMaxHeight" << endl;
//     CHECK( getMaxHeight(5, 10) == 2 );
//     CHECK( getMaxHeight(10, 5) == 2 );
//     CHECK( getMaxHeight(12, 16) == 5 );
//     CHECK( getMaxHeight(18, 16) == 7 );
// }

// TEST_CASE( "getBestHeight" ) {
//     cout << "5: getBestHeight" << endl;
//     CHECK( getBestHeight(10, 15) == 2 );
//     CHECK( getBestHeight(15, 10) == 2 );
//     CHECK( getBestHeight(16, 14) == 3 );
//     CHECK( getBestHeight(20, 22) == 4 );
//     CHECK( getBestHeight(300, 180) == 36 );
// }

// TEST_CASE( "createBoxDescription" ) {
//     cout << "6: createBoxDescription" << endl;

//     string test1 = createBoxStatsString(8, 6, 2);
//     string goal1 = "2       8       6       96      16";
//     //INFO will only print if test is failed
//     INFO("test1|", test1, "|");
//     INFO("goal1|", goal1, "|");
//     CHECK( test1 == goal1 );

//     string test2 = createBoxStatsString(13, 20, 4);
//     string goal2 = "4       13      20      1040    64";
//     //INFO will only print if test is failed
//     INFO("test2|", test2, "|");
//     INFO("goal2|", goal2, "|");
//     CHECK( test2 == goal2 );
// }

// TEST_CASE( "printBoxOptions" ) {
//     cout << "7: printOptions" << endl;

//     //Not really a unit test. Need to verify output manually

//     cout << R"(Expected:
// Height  Width   Length  Volume  Leftover Amount
// 1       18      13      234     4
// 2       16      11      352     16
// 3       14      9       378     36***
// 4       12      7       336     64
// 5       10      5       250     100
// 6       8       3       144     144
// 7       6       1       42      196
// --------------------------------------------------
// )";

//     cout << "Result:" << endl;
//     printBoxOptions(20, 15);

// }
