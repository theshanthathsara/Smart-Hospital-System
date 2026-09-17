#include "data.h"

//---lookup tabels-doctor speciality---

char specialityName[NUM_SPECIALTIES][30]={
    "General Practice(OPD)",
    "Paediatrics",
    "Cardiology",
    "Neurology"
};

float consultantFee[NUM_SPECIALTIES]={1500.00f,2500.00f,4500.00f,5000.00f};
int consultantTime[NUM_SPECIALTIES]={15,20,30,30};
int patientCap[NUM_SPECIALTIES]={30,20,12,10};
int specialityQueue[NUM_SPECIALTIES]={0,0,0,0};

//---lookup tables-Ward data-------

char wardName[NUM_WARDS][30]={
    "General Ward",
    "Paediatric Ward",
    "Surgical Ward",
    "ICU(Intensive Care Unit"
};
float bedRate[NUM_WARDS]={3000.00f,6000.00f,12000.00f,25000.00f};
int bedCapacity[NUM_WARDS]={20,10,10,5};

//---bed occupancy--------

int bedOccupancy[NUM_WARDS][MAX_BEDS]={0};


//---patient details----

int patientID[MAX_PATIENTS]={0};
char patientName[MAX_PATIENTS][NAME_LEN]={0};
int patientAge[MAX_PATIENTS]={0};
int emergencyLevel[MAX_PATIENTS]={0};
int patientSpeciality[MAX_PATIENTS]={0};
int isAdmitted[MAX_PATIENTS]={0};
int patientWard[MAX_PATIENTS]={0};
int bedID[MAX_PATIENTS]={0};
int daysAdmitted[MAX_PATIENTS]={0};


//----Billing Calculations-----

float baseFee[MAX_PATIENTS]={0};
float surcharge[MAX_PATIENTS]={0};
float wardCost[MAX_PATIENTS]={0};
float grossTotal[MAX_PATIENTS]={0};
float discount[MAX_PATIENTS]={0};
float finalTotal[MAX_PATIENTS]={0};
int waitingTime[MAX_PATIENTS]={0};

//---global counter----

int patientCount=0;
