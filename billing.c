#include <stdio.h>
#include "data.h"
#include "billing.h"

void calculateWaitTime(int i)
{
    int s=patientSpeciality[i]-1;
    waitingTime[i]=specialityQueue[s]*consultantTime[s];
}

void calculateSurcharge(int i)
{
    float surchargePercentage=0.0f;
    if ( emergencyLevel[i]==2 )
    {
        surchargePercentage=0.20f;
    }
    else if ( emergencyLevel[i]==3 )
    {
        surchargePercentage=0.50f;
    }
    surcharge[i]=baseFee[i]*surchargePercentage;
}

void calculateWardCost(int i)
{
    if (isAdmitted[i])
    {
        int w=patientWard[i]-1;
        wardCost[i]=daysAdmitted[i]*bedRate[w];
    }
    else
    {
        wardCost[i]=0.0f;
    }
}

void calculateGrossTotal(int i)
{
    grossTotal[i]=baseFee[i]+surcharge[i]+wardCost[i];
}

void calculateDiscount(int i)
{
    if ( patientAge[i]<5 || patientAge[i]>65 )
    {
        discount[i]=grossTotal[i]*0.15f;
    }
    else
    {
        discount[i]=0.0f;
    }
}

void calculateFinalAmount(int i)
{
    finalTotal[i]=grossTotal[i]-discount[i];
}

void generateBill(int i)
{
    calculateWaitTime(i);
    calculateSurcharge(i);
    calculateWardCost(i);
    calculateGrossTotal(i);
    calculateDiscount(i);
    calculateFinalAmount(i);

    const char *urgencyText[]={"","Normal","Urgent","Critical"};

    printf("\n====SMART HOSPITAL SYSTEM BILL====\n");
    printf("\n----------------------------------\n");
    printf("Patient ID            :PAT-%d\n",patientID[i]);
    printf("Patient Name   : %s\n", patientName[i]);
    printf("Age            : %d Years%s\n", patientAge[i],(discount[i] > 0) ? " (15% Subsidy Eligible)" : "");
    printf("Specialty      : %s\n", specialityName[patientSpeciality[i] - 1]);

    if (isAdmitted[i]) {
        printf("Assigned Ward  : %s (Bed #%02d)\n",wardName[patientWard[i]-1], bedID[i]+1);
    }
    else
    {
        printf("Assigned Ward  : Outpatient(OPD)\n");
    }
    printf("Urgency Level : Level %d (%s)\n",emergencyLevel[i],urgencyText[emergencyLevel[i]]);
    printf("Base consulatant fee : LKR %.2f\n",baseFee[i]);
    printf("Emergency Surcharge  : LKR %.2f\n",surcharge[i]);
    printf("Ward stay cost (%d Days) : LKR %.2f\n",daysAdmitted[i],wardCost[i]);
    printf("------------------------------------------\n");
    printf("Gross Total Bill     : LKR %.2f\n",grossTotal[i]);
    printf("Age Subsidy Discount : LKR %.2f\n",discount[i]);
    printf("------------------------------------------\n");
    printf("Final Amount         : LKR %.2f\n",finalTotal[i]);
    printf("Estimated Waiting Time: LKR %d mins\n",waitingTime[i]);
    printf("==========================================\n");
}
