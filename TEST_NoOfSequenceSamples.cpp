#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <stdio.h>
#include "CheckNoOfSequenceSamples.h"

int CurrentSamples[7] = {3, 3, 5, 4, 10, 11, 12};

TEST_CASE("Read No of sequence samples")
{
 int TotalNoOfSamples=CheckNoOfSequenceSamples(CurrentSamples, sizeof(CurrentSamples)/sizeof(CurrentSamples[0]));
 REQUIRE(TotalNoOfSamples == 2);
}
