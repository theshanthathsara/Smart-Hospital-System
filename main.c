#include <stdio.h>
#include <stdlib.h>
#include "patient.h"
#include "ward.h"
#include "data.h"
#include "billing.h"
#include "report.h"


int main()
{
    int choice=0;

    do {
        printf("\nSMART HOSPITAL SYSTEM\n");
        printf("=====================\n");
        printf("1.Register Patient\n");
        printf("2.View Bed Status\n");
        printf("3.Generate Bill\n");
        printf("4.Reports\n");
        printf("5.Exit\n");
        printf("---------------------\n");
        printf("Enter Choice : ");

        if (scanf("%d",&choice)!=1){
            while (getchar()!='\n');
            printf("Please enter a number.\n");
            continue;
        }

        while (getchar()!='\n');

        if (choice==1)
        {
            registerPatient();
        }
        else if ( choice==2 )
        {
            displayBedStatus();
        }

        else if ( choice==3 )
        {
            if ( patientCount==0 )
            {
                printf("\nNo patients registered yet.\n");
            }
            else
            {
                int n;
                displayAllPatients();
                printf("Enter patient number to bill(1 to %d) : ",patientCount );
                scanf("%d",&n);

                while ( getchar()!='\n');

                if ( n>=1 && n<=patientCount )
                {
                    generateBill(n-1);
                }
                else
                {
                    printf("Invalid input!\n");
                }
            }
        }
        else if ( choice==4 )
        {
            generateReports();
        }
        else if ( choice==5 )
        {
            printf("\nGood Bye!\n");
        }
        else
        {
            printf("\nInvalid choice.\n");
        }

    } while (choice!=5);

    return 0;
}


