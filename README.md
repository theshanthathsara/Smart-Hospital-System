\# Smart Hospital \& Resource Allocation System



A simple C program for CSC 1012 (Introduction to Computer Programming).

It simulates a hospital system where patients can be registered, assigned

beds, and billed.



\## What it does



\- Register a new patient (name, age, urgency level, specialty)

\- Assign a bed if the patient is admitted to a ward

\- Calculate and print the patient's bill

\- Show reports (total patients, revenue, bed occupancy, etc.)

\- Save data to files so bed status is remembered next time you run it



\## Files



\- `main.c` - the menu and main program

\- `data.h` / `data.c` - stores all the data (patients, wards, specialties)

\- `patient.c` - handles patient registration

\- `ward.c` - handles bed allocation

\- `billing.c` - calculates the bill

\- `report.c` - shows summary reports

\- `fileio.c` - saves and loads data from text files



\## How to run it



Open `SmartHospitalSystem.cbp` in Code::Blocks and click Build and Run.



\## Notes



This project uses parallel arrays instead of structs, as allowed by the

assignment instructions.



\## Author



U.A.Y.T.Thathsara



\## Index No



AS20250483

