#include <stdio.h>
#include <string.h>
#include "data.h"
#include "ward.h"
#include "patient.h"

static void clearInputBuffer(void)
{
    int c;
    while ((c=getchar())!= '\n' && c!=EOF){ }
}

void registerPatient(void)
{
    int i=patientCount;

    if (patientCount>=MAX_PATIENTS)
    {
        printf("\nPatient limit reached.Cannot register more patients.\n");
        return;
    }

    printf("\n===NEW PATIENT REGISTRATION====\n");

    patientID[i]=1000+patientCount+1;

    printf("Enter patient name : ");
    fgets(patientName[i],NAME_LEN,stdin);
    patientName[i][strcspn(patientName[i],"\n")]='\0';

    int age;
    do
    {
        printf("Enter patient age : ");
        scanf("%d",&age);
        clearInputBuffer();
        if ( age<0 || age>120 )
            printf("Invalid age! Enter a value between 0 and 120.\n");
    }while ( age<0 || age>120 );
    patientAge[i]=age;

    int urgency;
    do
    {
        printf("Enter urgency level (1=Normal ,2=urgent, 3=critical) : ");
        scanf("%d",&urgency);
        clearInputBuffer();
        if ( urgency<1 || urgency>3 )
        {
            printf("Invalid input!\n");
        }
    }while ( urgency<1 || urgency>3 );
    emergencyLevel[i]=urgency;

    int speciality;
    do
    {
        printf("\nAvailable specialities:\n");
        for ( int s=0; s<NUM_SPECIALTIES; s++ )
        {
            printf(" %d. %s (LKR %.2f)\n",s+1,specialityName[s],consultantFee[s]);
        }
        printf("Enter speciality ID (1-%d): ",NUM_SPECIALTIES);
        scanf("%d",&speciality);
        clearInputBuffer();
        if ( speciality<1 || speciality>NUM_SPECIALTIES )
        {
            printf("Invalid input!\n");
        }
    }while ( speciality<1 || speciality>NUM_SPECIALTIES );

    patientSpeciality[i]=speciality;
    specialityQueue[ speciality-1 ]++;
    baseFee[i]=consultantFee[speciality-1];

    int admitted;
    do
    {
        printf("\nIs patient admitted to a ward (1=yes,0=no) : ");
        scanf("%d",&admitted);
        clearInputBuffer();
        if ( admitted!=0 && admitted!=1 )
        {
            printf("Invalid input!\n");
        }
    }while ( admitted!=0 && admitted!=1 );
    isAdmitted[i]=admitted;

    if ( admitted==1 )
    {
        int ward;
        do
        {
            printf("\nAvailable Wards:\n");
            for ( int w=0; w<NUM_WARDS; w++ )
            {
                printf(" %d. %s (LKR %.2f/day, Capacity %d)\n",w+1,wardName[w],bedRate[w],bedCapacity[w]);
            }
            printf("Enter ward ID (1-%d) : ",NUM_WARDS);
            scanf("%d",&ward);
            clearInputBuffer();
            if ( ward<1 || ward>NUM_WARDS )
            {
                printf("Invalid input!\n");
            }
        }while ( ward<1 || ward>NUM_WARDS );

        int bed=allocateBed(ward);
        if ( bed== -1 )
        {
            printf("\nSorry, %s is FULL.Registering as outpatient instead.\n",wardName[ward-1]);

            isAdmitted[i]=0;
            patientWard[i]=0;
            daysAdmitted[i]=0;
            bedID[i]=-1;
        }
        else
        {
            int days;
            do
            {
                printf("Enter number of days admitted : ");
                scanf("%d",&days);
                clearInputBuffer();
                if ( days <= 0 )
                {
                    printf("Invalid input!\n");
                }
            }while ( days <= 0);

            patientWard[i]=ward;
            daysAdmitted[i]=days;
            bedID[i]=bed;
            printf("Assgined to %s, Bed #%02d\n",wardName[ward-1],bed+1);
        }
    }
    else
    {
        patientWard[i]=0;
        daysAdmitted[i]=0;
        bedID[i]=-1;
    }

    patientCount++;
    printf("\nPatient registered successfully!\n");
}

void displayAllPatients(void)
{
    if ( patientCount == 0 )
    {
        printf("\nNo patients registered yet.\n");
        return;
    }

    printf("\n%-4s %-10s %-20s %-5s %-8s %-12s %-6s\n","NO","ID","Name","Age","Urgency","Speciality","Ward");

    for ( int i=0; i<patientCount; i++ )
    {
        printf("%-4d PAT-%-6d %-20s %-5d %-8d %-12s %-6s\n",i+1,patientID[i],patientName[i],patientAge[i],emergencyLevel[i],specialityName[patientSpeciality[i]-1],isAdmitted[i]?wardName[patientWard[i]-1] : "OPD");
    }
}
