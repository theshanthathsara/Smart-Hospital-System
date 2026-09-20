#include <stdio.h>
#include "data.h"
#include "report.h"

void generateReports(void)
{
    if ( patientCount==0 )
    {
        printf("\nNo Patients registered yet\n");
        return;
    }

    int normal=0,urgent=0,critical=0;

    for ( int i=0 ; i<patientCount; i++ )
    {
        if ( emergencyLevel[i]==1 )
        {
            normal++;
        }
        else if ( emergencyLevel[i]==2 )
        {
            urgent++;
        }
        else if ( emergencyLevel[i]==3 )
        {
            critical++;
        }
    }

    float totalRevenue=0.0f,totalDiscount=0.0f;

    for ( int i=0 ; i<patientCount ; i++ )
    {
        totalRevenue+=finalTotal[i];
        totalDiscount+=discount[i];
    }

    float occupancyPercentage[NUM_WARDS];

    for ( int w=0; w<NUM_WARDS ; w++ )
    {
        int occupied=0;
        for ( int b=0 ; b<bedCapacity[w] ; b++ )
        {
            if ( bedOccupancy[w][b]==1 )
            {
                occupied++;
            }
        }
        occupancyPercentage[w]=(occupied*100.0f)/bedCapacity[w];
    }

    int highestPay=0;

    for ( int i=1 ; i<patientCount ; i++ )
    {
        if ( finalTotal[i]>finalTotal[highestPay])
        {
            highestPay=i;
        }
    }

    printf("\n=======HOSPITAL FULL REPORT=============\n");
    printf(" Level 1(normal) : %d\n",normal);
    printf(" Level 2(Urgent) : %d\n",urgent);
    printf(" Leve; 3(Critical):%d\n",critical);

    printf("\nFinancial Summary\n");
    printf(" Total Revenue :LKR %.2f\n",totalRevenue);
    printf("Total Discounts:LKR %.2f\n",totalDiscount);

    printf("\nBed Occupancy per Ward:\n");
    for ( int w=0; w<NUM_WARDS ;w++ )
    {
        printf(" %-20s : %.1f%%\n",wardName[w],occupancyPercentage[w]);
    }

    printf("\nHighest Paying patient:\n");
    printf(" Name : %s\n",patientName[highestPay]);
    printf(" Bill : LKR %.2f\n",finalTotal[highestPay]);
    printf("==========================================\n");
}
