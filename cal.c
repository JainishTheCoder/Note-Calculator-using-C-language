/*
                    Aim : BCP micro project
                    Name : Currency note calculator
                    Developed by : Prakhar Parikh
                                   Jainish Prajapati
                                   Sanket Sathvara
                                   Rudra Rathod
                                   Dhaval Panchal
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
    int money_array[20] = {2000, 1000, 500, 200, 100, 50, 20, 10, 5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int user_input, amount;
    char run = 'y';

    while ((int)run == 121)
    {
        printf("\t\t\t\t\tWelcome to currency calculator\n\nPlease enter the amount : ");
        scanf("%d", &user_input);

        amount = user_input;

        int divider, final_array_length = 0;
        for (int divider_index = 0; divider_index <= 9; divider_index++)
        {
            divider = money_array[divider_index];
            if (((int)user_input / divider) == 0)
            {
                continue;
            }
            money_array[divider_index + 10] = user_input / divider;
            user_input %= divider;
            final_array_length++;
        }

        int final_array[final_array_length * 2], final_array_index = 0;
        for (int initial_array_index = 10; initial_array_index <= 19; initial_array_index++)
        {
            if (money_array[initial_array_index] != 0)
            {
                final_array[final_array_index] = money_array[initial_array_index - 10];
                final_array[final_array_index + 1] = money_array[initial_array_index];
                final_array_index += 2;
            }
            else
            {
                continue;
            }
        }

        printf("\n\n\nCurrency notes required = %d -> ", final_array_length);

        for (int printer = 0; printer < final_array_length * 2; printer += 2)
        {
            if (printer == 0)
            {
                printf("%d*%d", final_array[printer + 1], final_array[printer]);
            }
            else
            {
                printf(" + %d*%d", final_array[printer + 1], final_array[printer]);
            }
        }
        printf(" = %d\n\n\n", amount);

        printf("Do you want to re-calculate (y for yes... n for no)... ");
        scanf("%c", &run);
    check:
        if ((int)run == 121)
        {
            system("cls");
            continue;
        }
        else if ((int)run == 110)
        {
            break;
        }
        else
        {
            printf("Please enter y or n : ");
            fflush(stdin);
            scanf("%c", &run);
            goto check;
        }
    }

    printf("\n\n\nThank you using our calculator. We hope you had a great experience...");
    printf("\n\nApplication Developed by : ");
    printf("\tPrakhar Parikh\n");
    printf("\t\t\t\tJainish Prajapati\n");
    printf("\t\t\t\tRudra Rathod\n");
    printf("\t\t\t\tSanket Sathvara\n");
    printf("\t\t\t\tDhaval Panchal\n");

    getch();
}
