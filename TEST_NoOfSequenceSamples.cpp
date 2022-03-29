#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <stdio.h>
#include "CheckNoOfSequenceSamples.h"

int CurrentSamples[7] = {3, 3, 5, 4, 10, 11, 12};
int CurrentAnalogBit[12] ={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

TEST_CASE("Read No of sequence samples")
{
 int NoOfSamples = sizeof(CurrentSamples)/sizeof(CurrentSamples[0]);
 int TotalNoOfSamples=CheckNoOfSequenceSamples(CurrentSamples, NoOfSamples);
 REQUIRE(TotalNoOfSamples == 2);
}


TEST_CASE("Read 12bits of samples and check the No of sample sequence")
{
 int TotalNoOfSamples= CheckNoOfSequenceSamples(CurrentAnalogBit, 12);
 REQUIRE(TotalNoOfSamples == 1);
}
