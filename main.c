#include <stdio.h>
#include <stdlib.h>

int selectOption();
int selector;

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

        if (choice==1)
        {
            printf("\nRegister Patient\n");
            printf("Not implemented yet\n");
            printf("1.Go to main menu\n");
            printf("2.Exit\n");

            selectOption();

            if ( selector==1 )
            {
                continue;
            }
            if ( selector==2 )
            {
                break;
            }
            else
            {
                printf("Invalid character, going back to main menu...\n");
            }

        }
        else if ( choice==2 )
        {
            printf("\nView bed status.not implemented yet\n");
        }

        else if ( choice==3 )
        {
            printf("\nGenerate bill.not implemented yet\n");
        }
        else if ( choice==4 )
        {
            printf("\nReports\n");
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

int selectOption()
{
    scanf("%d",&selector);
    return selector;
}
