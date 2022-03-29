#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <stdio.h>
#include "CheckNoOfSequenceSamples.h"

TEST_CASE("Read No of sequence samples")
{
 int CurrentAnalogBit[12] ={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 int TotalNoOfSamples=CheckNoOfSequenceSamples(CurrentSamples, 12);
 REQUIRE(TotalNoOfSamples == 1);
}

TEST_CASE("Read No of sequence samples")
{
 int CurrentAnalogBit[12] ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,12};
 int TotalNoOfSamples=CheckNoOfSequenceSamples(CurrentSamples, 12);
 REQUIRE(TotalNoOfSamples == 1);
}
