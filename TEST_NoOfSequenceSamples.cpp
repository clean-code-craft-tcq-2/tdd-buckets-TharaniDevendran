#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <stdio.h>
#include "CheckNoOfSequenceSamples.h"

TEST_CASE("Read No of sequence samples from an array of 0 as values")
{
 int CurrentAnalogBit[12] ={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 int TotalNoOfSamples=CheckNoOfSequenceSamples(CurrentAnalogBit, 12);
 REQUIRE(TotalNoOfSamples == 1);
}

TEST_CASE("Read No of sequence samples from an array of 12 consecutive samples")
{
 int CurrentAnalogBit[12] ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,12};
 int TotalNoOfSamples=CheckNoOfSequenceSamples(CurrentAnalogBit, 12);
 REQUIRE(TotalNoOfSamples == 1);
}

TEST_CASE("Check the no of sequence sample in an invalid array")
{
 int CurrentAnalogBit[12] ={1, 4095, 3, 4, 5, 6, 7, 4096, 9, 10, 4093,4094};
 int TotalNoOfSamples=CheckNoOfSequenceSamples(CurrentAnalogBit, 12);
 REQUIRE(TotalNoOfSamples == 2);
}

TEST_CASE("Read No of sequence samples from an array of Ramdom Analogsamples")
{
 int CurrentAnalogBit[12] ={409, 818, 1228, 1637, 2047, 2456, 2866, 3275, 3685, 4094, 4503,4918};
 int TotalNoOfSamples=CheckNoOfSequenceSamples(CurrentAnalogBit, 12);
 REQUIRE(TotalNoOfSamples == 4);
}

TEST_CASE("Check Null Array") {
  int CurrentAnalogBit[12] = {};
  int TotalNoOfSamples=CheckNoOfSequenceSamples(CurrentAnalogBit, 12);
 REQUIRE(TotalNoOfSamples == 1);
}
