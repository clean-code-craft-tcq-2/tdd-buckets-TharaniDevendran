#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <stdio.h>
#include "CheckNoOfSequenceSamples.h"

TEST_CASE("Read No of sequence samples")
{
 int CurrentAnalogBit[12] ={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 int TotalNoOfSamples=CheckNoOfSequenceSamples(CurrentSamples, NoOfSamples);
 REQUIRE(TotalNoOfSamples == 1);
}
