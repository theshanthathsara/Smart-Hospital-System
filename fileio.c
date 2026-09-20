#include <stdio.h>
#include "data.h"
#include "fileio.h"

void saveBedStatus(void)
{
    FILE * filePointer;
    int w,b;

    filePointer=fopen("bed_status.txt","w");

    if ( filePointer==NULL )
    {
        printf("could not save bed status.\n");
        return;
    }
    for ( w=0; w<NUM_WARDS; w++ )
    {
        for ( b=0; b<bedCapacity[b]; b++ )
        {
            fprintf(filePointer,"%d\n",bedOccupancy[w][b]);
        }
    }
    fclose(filePointer);
}

void loadBedStatus(void)
{
    FILE *filePointer;
    int w,b;
    int value;

    filePointer=fopen("beds_status.txt","r");

    if ( filePointer==NULL )
    {
        return;
    }

    for ( w=0 ; w<NUM_WARDS ; w++ )
    {
        for ( b=0; b<bedCapacity[w]; b++ )
        {
            fscanf(filePointer,"%d",&value);
            bedOccupancy[w][b]=value;
        }
    }
    fclose(filePointer);
}

void appendPatientRecord(int i)
{
    FILE *filePointer;

    filePointer=fopen("patient_records.txt","a");

    if ( filePointer==NULL )
    {
        printf("could not save patient record.\n");
        return;
    }

    fprintf(filePointer,"PAT-%d | %s | Age %d | Urgenecy %d | LKR %.2f\n",patientID[i],patientName[i],patientAge[i],emergencyLevel[i],finalTotal[i]);
    fclose(filePointer);
}
