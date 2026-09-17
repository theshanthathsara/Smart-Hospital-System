#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

//-------Size Constants-----

#define NUM_SPECIALTIES 4
#define NUM_WARDS       4
#define MAX_BEDS        20
#define MAX_PATIENTS    100
#define NAME_LEN        50

//----lookup tables-Doctor speciality-----

extern char specialityName[NUM_SPECIALTIES][30];
extern float consultantFee[NUM_SPECIALTIES];
extern int consultantTime[NUM_SPECIALTIES];
extern int patientCap[NUM_SPECIALTIES];
extern int specialityQueue[NUM_SPECIALTIES];

//---lookup tables-Ward data-------

extern char wardName[NUM_WARDS][30];
extern float bedRate[NUM_WARDS];
extern int bedCapacity[NUM_WARDS];

//---bed occupancy--------

extern int bedOccupancy[NUM_WARDS][MAX_BEDS];

//---patient details----

extern int patientID[MAX_PATIENTS];
extern char patientName[MAX_PATIENTS][NAME_LEN];
extern int patientAge[MAX_PATIENTS];
extern int emergencyLevel[MAX_PATIENTS];
extern int patientSpeciality[MAX_PATIENTS];
extern int isAdmitted[MAX_PATIENTS];
extern int patientWard[MAX_PATIENTS];
extern int bedID[MAX_PATIENTS];
extern int daysAdmitted[MAX_PATIENTS];

//----Billing Calculations-----

extern float baseFee[MAX_PATIENTS];
extern float surcharge[MAX_PATIENTS];
extern float wardCost[MAX_PATIENTS];
extern float grossTotal[MAX_PATIENTS];
extern float discount[MAX_PATIENTS];
extern float finalTotal[MAX_PATIENTS];
extern int waitingTime[MAX_PATIENTS];

//---global counter----

extern int patientCount;

#endif // DATA_H_INCLUDED
