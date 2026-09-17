#include <stdio.h>
#include "data.h"
#include "ward.h"

int allocateBed(int wardID)
{
    int w=wardID-1;
    for (int b=0 ; b<bedCapacity[w]; b++ )
    {
        if (bedOccupancy[w][b]==0)
        {
            bedOccupancy[w][b]=1;
            return b;
        }
    }
    return -1;
}

void displayBedStatus(void)
{
    for ( int w=0; w<NUM_WARDS ; w++ )
    {
        printf("\n%s (%d beds):\n",wardName[w],bedCapacity[w]);
        for ( int b=0 ; b<bedCapacity[w]; b++ )
        {
            printf("Bed %02d: %s\n",b+1,bedOccupancy[w][b]?"Occupied":"Available");

        }
    }
}
