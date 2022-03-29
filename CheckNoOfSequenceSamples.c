#include <stdio.h>
#include <stdlib.h>
#include "CheckNoOfSequenceSamples.h"

int minValues[MAX_NUMBER_OF_READINGS] = {0};
int maxValues[MAX_NUMBER_OF_READINGS] = {0};
int countValues[MAX_NUMBER_OF_READINGS] = {0};

/* Comparator Function for qsort */
int compareGivenInputs (const void * firstInput, const void * secondInput) {
    return ( *(int*)firstInput - *(int*)secondInput );
}

int* SortArray(int *Readings, int NumberOfSamples) {
    qsort(Readings,NumberOfSamples,sizeof(int),compareGivenInputs);
    return Readings;
}

/* Returns an array with Count of Elements provided in input array*/
int* provideCountOfDistinctElementsInArray(int *ArrayElements, int sizeOfArray) {
    int *arrayToStoreCount;
    arrayToStoreCount = (int*)calloc(MAX_NUMBER_OF_READINGS, sizeof(int));
    
    for(int i=0; i<sizeOfArray; i++)
    {
        int index = ArrayElements[i];
        arrayToStoreCount[index]++;
    }
    return arrayToStoreCount;
    free(arrayToStoreCount);
}

/* Finds the range of the reading and returns the number of ranges */
int ProvideRangeCountOfSamples(int* countOfReadings) {
    int minRange = -1, maxRange = -1, rangeCounter = 0, readingsCounter = 0;
  
    for(int i=0; i<MAX_NUMBER_OF_READINGS; i++)
    {
        if((countOfReadings[i] != 0))
        {
            readingsCounter += countOfReadings[i];
            if(minRange == -1)
            {
                minRange = i;
                maxRange = i;
            }
            else
            {
                maxRange = i;
            }
        }
        else if(readingsCounter != 0)
        {
            minValues[rangeCounter] = minRange;
            maxValues[rangeCounter] = maxRange;
            countValues[rangeCounter] = readingsCounter;
            rangeCounter++;
            readingsCounter = 0;
            minRange = -1;
            maxRange = -1;
        }  
    }
    return rangeCounter;
}

void PrintToConsole(int NoOfSequenceSample) {
    for(int i=0; i<NoOfSequenceSample; i++)
    {
        printf("%d-%d, %d\n",minValues[i],maxValues[i],countValues[i]);
    }
}

int CheckNoOfSequenceSamples(int *CurrentSamples, int NumberOfSamples)
{
    int *sortedArray =SortArray(CurrentSamples,NumberOfSamples);
    int *countOfReadings = provideCountOfDistinctElementsInArray(sortedArray,NumberOfSamples);
    int NoOfSequenceSample = ProvideRangeCountOfSamples(countOfReadings);
    (void)PrintToConsole(NoOfSequenceSample);
    return NoOfSequenceSample;
}
