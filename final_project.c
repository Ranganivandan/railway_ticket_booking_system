#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int flag = 0; /// flag
char username[50];
char mail[50];
char pass[50];
char feedb[500];
int sitting = 1;

int feedback()
{

    FILE *feedbac = fopen("userfeedback.txt", "a");
    fprintf(feedbac, ":::FEEDBACK::::\n");
    fprintf(feedbac, "username: %s\n", username);
    fprintf(feedbac, "feedback: %s\n", feedb);
    fclose(feedbac);
    return 0;
}

struct class
{
    char c[20];
};

char source[10], destini[10];
char passlogin[10], userlogin[20];
char loginusername[50];
char loginpass[50];
int entercalss;
int choicetrain;
int age;
// function declare
void createaccount();
void login();
void bookticket();
int  cancelticket();
int ticketdetail();

int main()
{
    int choice;
    char username[20];

    int pass;

    // pattern
    for (int i = 0; i <= 12; i++)
    {
        printf("*");
        if (i == 12)
        {
            printf("welcome");
        }
    }
    for (int i = 0; i <= 12; i++)
    {
        printf("*");
    }
    // choice
    do
    {
        printf("\nRailway Ticket Booking System\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Book Ticket\n");
        printf("4. Cancel Ticket\n");
        printf("5. logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        system("cls");

        switch (choice)
        {
        case 1:
            createaccount();
            break;
        case 2:
            login();
            break;
        case 3:
            bookticket();
            break;
        case 4:
            cancelticket();
            
            break;
        case 5:
            printf("you logout succesfully\n");
            break;

        default:
            break;
        }
    } while (choice != 5);
    return 0;
}

// function account;
void createaccount()
{
int flag=0;
    printf("enter username\n");
    scanf("%s", username);
    reenter:
    printf("enter E-mail \n");
    scanf("%s", mail);
    
  // character extraction
   
    for (int i = 0; mail[i] != '\0'; i++) {
        if (mail[i] == '@') { 
            flag=1;
            
        }
        else{
            
            
        }
    }
    if(flag==1)printf("valid email  \n");
    else{
        
         printf("invalid Email\n");
    goto reenter;   // goto reneter email

    }

    printf("enter password\n");
    scanf("%s", pass);
    printf("enter age\n");
    scanf("%d", &age);
    printf("your account created succesfully %s.....", username);
    system("cls");
    FILE *file = fopen("accountuserinfo.txt", "a");

    fprintf(file, "%s\t %s\t  %s %d\n", username, pass,mail, age);
    fclose(file);
    return;
}

// function login;
void login()
{
    
    static int flag=0;     // declare static keyword flag
    
    if (flag != 3)
    {
        printf("enter username");
        scanf("%s", loginusername);
        printf("enter password");
        scanf("%s", loginpass);
        system("cls");
        FILE *file = fopen("accountuserinfo.txt", "r");

        while (fscanf(file, "%s %s", username, pass) != EOF)
        {
            if (strcmp(loginusername, username) == 0 && strcmp(loginpass, pass) == 0)
            {
                printf("login succesfully %s!.....", username);
                fclose(file);
                return;
            }
            else
            {
                flag++;
                printf("enters valid username and password!......\n");
                fclose(file);

                if (flag == 3)
                {
                    printf(" Too many failed attempts, please try again after logout\n");
                    return;
                }
                login();
            }
        }

        return;
    }

    else
    {

        printf("\n:::::you already failed many login attempts,please try again after logout:::::\n");
    }
}

void bookticket()
{

    printf("enter deperture station\n");
    scanf("%s", source);
    printf("enter destination station\n");
    scanf("%s", destini);
    /////////
system("cls");
    printf("available trains");
    printf("\n:::: TRAINS:::::::TRAIN NUMBER::::::::PRICE:::::::\n");
    printf("1. INTERSITY EXP   22960   Rs.200\n");
    printf("2. VANDE BHARAT    22196   rs.800\n");
    printf("3. SAURASTRA EXP   12905   Rs.300\n");
    printf("4. shalimer exp    12905   Rs.300\n");
    printf("5. SAURASTRA MAIL  22946   Rs.400\n");
    printf("6. okha exp        22959   Rs.500\n");
    printf("enter choices which train would you prefer\n");
    scanf("%d", &choicetrain);
    switch (choicetrain)
    {
    case 1:
        ticketdetail(choicetrain);

        break;
    case 2:
        ticketdetail(choicetrain);

        break;
    case 3:
        ticketdetail(choicetrain);

        break;

    case 4:
        ticketdetail(choicetrain);

        break;
    case 5:
        ticketdetail(choicetrain);
        break;
    case 6:
        ticketdetail(choicetrain);
        break;

    default:
        printf("enter valid input number\n ");
        break;
    }
}

int ticketdetail()
{
    switch (choicetrain)
    {
        int numberoftickets;

    case 1:
        printf("number of tickets?");
        scanf("%d", &numberoftickets);
        // classes

        printf("which class would you prefer\n");
        printf("1.AC(2A)\n 2.AC(3A)\n 3.SLEEPER\n 4.SITTING(2S)\n");
        scanf("%d", &entercalss);
        ///////

        printf("total cost is %d/-", numberoftickets * 200);
        printf("enter password and pay %d\n", numberoftickets * 200);
        scanf("%s", passlogin);
        printf("enter username");
        scanf("%s", userlogin);
        FILE *file = fopen("accountuserinfo.txt", "r");  // f=accountuserinfo
        FILE *ffile1 = fopen("ticketselldata.txt", "a"); // ff=ticketselldata
        FILE *fffile1 = fopen("ticket.txt", "a");        // fff=userticket
        fscanf(file, " %s %s", username, pass);
        if (strcmp(passlogin, pass) == 0 && strcmp(userlogin, username) == 0)
        {
            printf("succesfully you buy tickets %s!\n", username);
        }
        else
        {
            printf("enter valid username and password ");
        }
        fclose(file);

        fprintf(ffile1, "name\tnumberoftickets\ttotal\n");
        fprintf(ffile1, "%s %d %d", username, numberoftickets, numberoftickets * 200);
        fclose(ffile1);

        fprintf(fffile1, "\n:::::: Electronic reservation slip[ERS] ::::::\n");
        fprintf(fffile1, "\npassenger detail\nName\n");
        fprintf(fffile1, "%s\n", username);
        fprintf(fffile1, "train name:intercity exp\n");
        fprintf(fffile1, "train number:22960\n");

        fprintf(fffile1, "deperature: %s\n", source);
        fprintf(fffile1, "destination: %s\n", destini);
        /////
        switch (entercalss)
        {
        case 1:
            fprintf(fffile1, "class:AC(2A)\n");
            fprintf(fffile1, "sitting: A%d\n", sitting);
            sitting++;
            break;
        case 2:
            fprintf(fffile1, "class:AC (3A)\n");
            fprintf(fffile1, "sitting: A%d\n", sitting);
            sitting++;
            break;
        case 3:
            fprintf(fffile1, "class:SLEPPER\n");
            fprintf(fffile1, "sitting: S%d\n", sitting);
            sitting++;
            break;
        case 4:
            fprintf(fffile1, "class:SITTING(2S)\n");
            fprintf(fffile1, "sitting: 2S%d\n", sitting);
            sitting++;
            break;

        default:
            printf("enter valid class\n");
            break;
        }

        fprintf(fffile1, "::::::transaction details::::::\n");
        fprintf(fffile1, "transaction ID is: %d\n", rand());
        fprintf(fffile1, "price of %d is %d\n", numberoftickets, numberoftickets * 200);
        fprintf(fffile1, "cgst:%f\n", (float)numberoftickets * 200 * 0.18);
        fprintf(fffile1, "sgst: %f\n", (float)numberoftickets * 200 * 0.18);
        fprintf(fffile1, "total:%f\n", (float)(numberoftickets * 200 * 0.18 * 2) + (numberoftickets * 200));
        fprintf(fffile1, "::::::::::THANK YOU ::::::::::");
        fclose(fffile1);

        //      printf("enter your feedback(under 500 letters)");
        //   scanf("%s",feedb);
        //  feedback(feedb);
        //  system("cls");
        // printf("feedback submitted succesfully.....");

        break;
    case 3: // saurastra
        printf("number of tickets?");
        scanf("%d", &numberoftickets);
        printf("which class would you prefer\n");
        printf("1.AC(2A)\n 2.AC(3A)\n 3.SLEEPER\n 4.SITTING(2S)\n");
        scanf("%d", &entercalss);
        printf("total cost is %d/-", numberoftickets * 300);
        // if (entercalss== 1)
        // {
        //       printf("enter password and pay %d\n",(numberoftickets*300)+300);
        // }
        // else if (entercalss==2)
        // {
        //       printf("enter password and pay %d",(numberoftickets*300)+200);
        // }
        // else if (entercalss==3)
        // {
        //     /* code */  printf("enter password and pay %d",(numberoftickets*300)+100);
        // }
        // else if (entercalss==4)
        // {
        //       printf("enter password and pay %d",(numberoftickets*300)+50);
        // }

        // else{
        //     printf("enter valid");

        // }

        printf("enter password and pay %d\n", (numberoftickets * 300));

        scanf("%s", passlogin);
        printf("enter username");
        scanf("%s", userlogin);
        FILE *file1 = fopen("accountuserinfo.txt", "r");
        FILE *ffile3 = fopen("ticketselldata.txt", "a");
        FILE *fffile3 = fopen("ticket.txt", "a");
        fscanf(file1, " %s %s", username, pass);
        if (strcmp(passlogin, pass) == 0 && strcmp(userlogin, username) == 0)
        {
            printf("succesfully you buy tickets %s!\n", username);
        }
        else
        {
            printf("enter valid username and password ");
            ticketdetail(choicetrain);
        }
        fclose(file1);

        fprintf(ffile3, "name\tnumberoftickets\ttotal\n");
        fprintf(ffile3, "%s %d %d", username, numberoftickets, numberoftickets * 200);
        fclose(ffile3);
        fprintf(fffile3, "\n:::::: Electronic reservation slip[ERS] ::::::\n");

        fprintf(fffile3, "\npassenger detail\nName\n");
        fprintf(fffile3, "%s\n", username);
        fprintf(fffile3, "train name:saurastra exp\n");
        fprintf(fffile3, "train number:12905\n");
        fprintf(fffile3, "deperature: %s\n", source);
        fprintf(fffile3, "destination: %s\n", destini);

        switch (entercalss)
        {
        case 1:
            fprintf(fffile3, "class:AC(2A)\n");
            fprintf(fffile3, "sitting: A%d\n", sitting);
            sitting++;
            break;
        case 2:
            fprintf(fffile3, "class:AC (3A)\n");
            fprintf(fffile1, "sitting: A%d\n", sitting);
            sitting++;
            break;
        case 3:
            fprintf(fffile3, "class:SLEPPER\n");
            fprintf(fffile1, "sitting: S%d\n", sitting);
            sitting++;
            break;
        case 4:
            fprintf(fffile3, "class:SITTING(2S)\n");
            fprintf(fffile1, "sitting: 2S%d\n", sitting);
            sitting++;
            break;

        default:
            printf("enter valid class\n");
            break;
        }

        fprintf(fffile3, "::::::transaction details::::::\n");
        fprintf(fffile3, "transaction ID is: %d\n", rand());
        fprintf(fffile3, "price of %d is %d\n", numberoftickets, numberoftickets * 200);
        fprintf(fffile3, "cgst:%f\n", (float)numberoftickets * 200 * 0.18);
        fprintf(fffile3, "sgst: %f\n", (float)numberoftickets * 200 * 0.18);
        fprintf(fffile3, "total:%f\n", (float)(numberoftickets * 200 * 0.18 * 2) + (numberoftickets * 200));
        fprintf(fffile3, "::::::::::THANK YOU ::::::::::");
        fclose(fffile3);

        break;

    case 2: // vandebharat
        printf("number of tickets?");

        scanf("%d", &numberoftickets);
        printf("which class would you prefer\n");
        printf("1.AC(2A)\n 2.AC(3A)\n 3.SLEEPER\n 4.SITTING(2S)\n");
        scanf("%d", &entercalss);
        printf("total cost is %d/-", numberoftickets * 800);
        printf("enter password and pay %d\n", numberoftickets * 800);
        scanf("%s", passlogin);
        printf("enter username");
        scanf("%s", userlogin);

        FILE *file2 = fopen("accountuserinfo.txt", "r");
        FILE *ffile2 = fopen("ticketselldata.txt", "a");
        FILE *fffile2 = fopen("ticket.txt", "a");
        fscanf(file2, " %s %s", username, pass);
        if (strcmp(passlogin, pass) == 0 && strcmp(userlogin, username) == 0)
        {
            printf("succesfully you buy tickets %s!\n", username);
        }
        else
        {
            printf("enter valid username and password ");
        }
        fclose(file2);
        fprintf(ffile2, "name\tnumberoftickets\ttotal\n");
        fprintf(ffile2, "%s %d %d", username, numberoftickets, numberoftickets * 200);
        fclose(ffile2);
        fprintf(fffile2, "\n:::::: Electronic reservation slip[ERS] ::::::\n");

        fprintf(fffile2, "\npassenger detail\nName\n");
        fprintf(fffile2, "%s\n", username);
        fprintf(fffile2, "train name:vandebharat\n");
        fprintf(fffile2, "train number:22196\n");
        fprintf(fffile2, "deperature: %s\n", source);
        fprintf(fffile2, "destination: %s\n", destini);

        switch (entercalss)
        {
        case 1:
            fprintf(fffile2, "class:AC(2A)\n");
            fprintf(fffile2, "sitting: A%d\n", sitting);
            sitting++;
            break;
        case 2:
            fprintf(fffile2, "class:AC (3A)\n");
            fprintf(fffile2, "sitting: A%d\n", sitting);
            sitting++;
            break;
        case 3:
            fprintf(fffile2, "class:SLEPPER\n");
            fprintf(fffile2, "sitting: %d\n", sitting);
            sitting++;
            break;
        case 4:
            fprintf(fffile2, "class:SITTING(2S)\n");
            fprintf(fffile2, "sitting: 2%d\n", sitting);
            sitting++;
            break;

        default:
            printf("enter valid class\n");
            break;
        }

        fprintf(fffile2, "::::::transaction details::::::\n");
        fprintf(fffile2, "transaction ID is: %d\n", rand());
        fprintf(fffile2, "price of %d is %d\n", numberoftickets, numberoftickets * 200);
        fprintf(fffile2, "cgst:%f\n", (float)numberoftickets * 800 * 0.18);
        fprintf(fffile2, "sgst: %f\n", (float)numberoftickets * 800 * 0.18);
        fprintf(fffile2, "total:%f\n", (float)(numberoftickets * 800 * 0.18 * 2) + (numberoftickets * 200));
        fprintf(fffile2, "::::::::::THANK YOU ::::::::::");
        fclose(fffile2);

        break;

    case 4: // vandebharat
        printf("number of tickets?");

        scanf("%d", &numberoftickets);
        printf("which class would you prefer\n");
        printf("1.AC(2A)\n 2.AC(3A)\n 3.SLEEPER\n 4.SITTING(2S)\n");
        scanf("%d", &entercalss);
        printf("total cost is %d/-", numberoftickets * 300);
        printf("enter password and pay %d\n", numberoftickets * 300);
        scanf("%s", passlogin);
        printf("enter username");
        scanf("%s", userlogin);
        FILE *file3 = fopen("accountuserinfo.txt", "r");
        FILE *ffile4 = fopen("ticketselldata.txt", "a");
        FILE *fffile4 = fopen("ticket.txt", "a");
        fscanf(file3, " %s %s", username, pass);
        if (strcmp(passlogin, pass) == 0 && strcmp(userlogin, username) == 0)
        {
            printf("succesfully you buy tickets %s!\n", username);
        }
        else
        {
            printf("enter valid username and password ");
        }
        fclose(file3);

        fprintf(ffile4, "name\tnumberoftickets\ttotal\n");
        fprintf(ffile4, "%s %d %d", username, numberoftickets, numberoftickets * 200);
        fclose(ffile4);
        fprintf(fffile4, "\n:::::: Electronic reservation slip[ERS] ::::::\n");

        fprintf(fffile4, "\npassenger detail\nName\n");
        fprintf(fffile4, "%s\n", username);
        fprintf(fffile4, "train name:shalimer exp\n");
        fprintf(fffile4, "train number:12905\n");
        fprintf(fffile4, "deperature: %s\n", source);
        fprintf(fffile4, "destination: %s\n", destini);

        switch (entercalss)
        {
        case 1:
            fprintf(fffile4, "class:AC(2A)\n");
            fprintf(fffile4, "sitting: A%d\n", sitting);
            sitting++;
            break;
        case 2:
            fprintf(fffile4, "class:AC (3A)\n");
            fprintf(fffile4, "sitting: A%d\n", sitting);
            sitting++;
            break;
        case 3:
            fprintf(fffile4, "class:SLEPPER\n");
            fprintf(fffile4, "sitting: S%d\n", sitting);
            sitting++;
            break;
        case 4:
            fprintf(fffile4, "class:SITTING(2S)\n");
            fprintf(fffile4, "sitting: 2S%d\n", sitting);
            sitting++;
            break;

        default:
            printf("enter valid class\n");
            break;
        }

        fprintf(fffile4, "::::::transaction details::::::\n");
        fprintf(fffile4, "transaction ID is: %d\n", rand());
        fprintf(fffile4, "price of %d is %d\n", numberoftickets, numberoftickets * 200);
        fprintf(fffile4, "cgst:%f\n", (float)numberoftickets * 300 * 0.18);
        fprintf(fffile4, "sgst: %f\n", (float)numberoftickets * 300 * 0.18);
        fprintf(fffile4, "total:%f\n", (float)(numberoftickets * 300 * 0.18 * 2) + (numberoftickets * 200));
        fprintf(fffile4, "::::::::::THANK YOU ::::::::::");
        fclose(fffile4);
        break;

    case 5:
        printf("number of tickets?");

        scanf("%d", &numberoftickets);
        printf("which class would you prefer\n");
        printf("1.AC(2A)\n 2.AC(3A)\n 3.SLEEPER\n 4.SITTING(2S)\n");
        scanf("%d", &entercalss);
        printf("total cost is %d/-", numberoftickets * 400);
        printf("enter password and pay %d\n", numberoftickets * 400);
        scanf("%s", passlogin);
        printf("enter username");
        scanf("%s", userlogin);
        FILE *file4 = fopen("accountuserinfo.txt", "r");
        FILE *ffile5 = fopen("ticketselldata.txt", "a");
        FILE *fffile5 = fopen("ticket.txt", "a");

        fscanf(file4, " %s %s", username, pass);
        if (strcmp(passlogin, pass) == 0 && strcmp(userlogin, username) == 0)
        {
            printf("succesfully you buy tickets %s!\n", username);
        }
        else
        {
            printf("enter valid username and password ");
        }
        fclose(file4);
        fprintf(ffile5, "name\tnumberoftickets\ttotal\n");
        fprintf(ffile5, "%s %d %d", username, numberoftickets, numberoftickets * 200);
        fclose(ffile5);
        fprintf(fffile5, "\n:::::: Electronic reservation slip[ERS] ::::::\n");

        fprintf(fffile5, "\npassenger detail\nName\n");
        fprintf(fffile5, "%s\n", username);
        fprintf(fffile5, "train name:saurastra mail\n");
        fprintf(fffile5, "train number:22946\n");
        fprintf(fffile5, "deperature: %s\n", source);
        fprintf(fffile5, "destination: %s\n", destini);

        switch (entercalss)
        {
        case 1:
            fprintf(fffile5, "class:AC(2A)\n");
            fprintf(fffile5, "sitting: 2S%d\n", sitting);
            sitting++;
            break;
        case 2:
            fprintf(fffile5, "class:AC (3A)\n");
            fprintf(fffile5, "sitting: 2S%d\n", sitting);
            sitting++;
            break;
        case 3:
            fprintf(fffile5, "class:SLEPPER\n");
            fprintf(fffile5, "sitting: 2S%d\n", sitting);
            sitting++;
            break;
        case 4:
            fprintf(fffile5, "class:SITTING(2S)\n");
            fprintf(fffile5, "sitting: 2S%d\n", sitting);
            sitting++;
            break;

        default:
            printf("enter valid class\n");
            break;
        }

        fprintf(fffile5, "::::::transaction details::::::\n");
        fprintf(fffile5, "transaction ID is: %d\n", rand());
        fprintf(fffile5, "price of %d is %d\n", numberoftickets, numberoftickets * 200);
        fprintf(fffile5, "cgst:%f\n", (float)numberoftickets * 400 * 0.18);
        fprintf(fffile5, "sgst: %f\n", (float)numberoftickets * 400 * 0.18);
        fprintf(fffile5, "total:%f\n", (float)(numberoftickets * 400 * 0.18 * 2) + (numberoftickets * 200));
        fprintf(fffile5, "::::::::::THANK YOU ::::::::::");
        fclose(fffile5);

        break;

    case 6: // vandebharat
        printf("number of tickets?");

        scanf("%d", &numberoftickets);
        printf("which class would you prefer\n");
        printf("1.AC(2A)\n 2.AC(3A)\n 3.SLEEPER\n 4.SITTING(2S)\n");
        scanf("%d", &entercalss);
        printf("total cost is %d/-", numberoftickets * 500);
        printf("enter password and pay %d\n", numberoftickets * 500);
        scanf("%s", passlogin);
        printf("enter username");
        scanf("%s", userlogin);
        FILE *file5 = fopen("accountuserinfo.txt", "r");
        FILE *ffile6 = fopen("ticketselldata.txt", "a");
        FILE *fffile6 = fopen("ticketselldata.txt", "a");
        fscanf(file5, " %s %s", username, pass);
        if (strcmp(passlogin, pass) == 0 && strcmp(userlogin, username) == 0)
        {
            printf("succesfully you buy tickets %s!\n", username);
        }
        else
        {
            printf("enter valid username and password ");
        }
        fclose(file5);
        fprintf(ffile6, "name\tnumberoftickets\ttotal\n");
        fprintf(ffile6, "%s %d %d", username, numberoftickets, numberoftickets * 200);
        fclose(ffile6);
        fprintf(fffile6, ":::::: Electronic reservation slip[ERS] ::::::\n");

        fprintf(fffile6, "\npassenger detail\nName\n");
        fprintf(fffile6, "%s\n", username);
        fprintf(fffile6, "train name:okha exp\n");
        fprintf(fffile6, "train number:22956\n");
        fprintf(fffile6, "deperature: %s\n", source);
        fprintf(fffile6, "destination: %s\n", destini);
        switch (entercalss)
        {
        case 1:
            fprintf(fffile6, "class:AC(2A)\n");
            fprintf(fffile6, "sitting: 2S%d\n", sitting);
            sitting++;
            break;
        case 2:
            fprintf(fffile6, "class:AC (3A)\n");
            fprintf(fffile6, "sitting: 2S%d\n", sitting);
            sitting++;
            break;
        case 3:
            fprintf(fffile6, "class:SLEPPER\n");
            fprintf(fffile6, "sitting: 2S%d\n", sitting);
            sitting++;
            break;
        case 4:
            fprintf(fffile6, "class:SITTING(2S)\n");
            fprintf(fffile6, "sitting: 2S%d\n", sitting);
            sitting++;
            break;

        default:
            printf("enter valid class\n");

            break;
        }

        fprintf(fffile6, "::::::transaction details::::::\n");
        fprintf(fffile6, "transaction ID is: %d\n", rand());
        fprintf(fffile6, "price of %d is %d\n", numberoftickets, numberoftickets * 200);
        fprintf(fffile6, "cgst:%f\n", (float)numberoftickets * 500 * 0.18);
        fprintf(fffile6, "sgst: %f\n", (float)numberoftickets * 500 * 0.18);
        fprintf(fffile6, "total:%f\n", (float)(numberoftickets * 500 * 0.18 * 2) + (numberoftickets * 200));
        fprintf(fffile6, "::::::::::THANK YOU ::::::::::");
        fclose(fffile6);
        break;
    }
}
int  cancelticket(){




  FILE *filec = fopen("ticket.txt", "r");
    if (!filec) {
     printf("ticket does not exist");

    }
else{
    ;
    fopen("ticket.txt","w");
printf("ticket cancelled succesfully\n");
}

    return 0;
fclose(filec);






}
