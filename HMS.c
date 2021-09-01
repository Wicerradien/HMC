//
//  main.c
//  HMS
//
//  Created by Nafiur Rahman Dhrubo on 8/24/21.
//

#include <stdio.h>
#include <string.h>
#include<conio.h>
#include<stdlib.h>

void MainMenu();
void wlcomescreen();
void Title ();
void Login ();
void Add ();
void Display();
void Search();
void Modify();
void Delete();
void Fopen();
void Fclose();

struct Patient
{
    char Name[50];
    char Gender[10];
    char Problem[50];
    char Doctor[50];
    char Email[50];
    int Room, Mobile, Age;
}x[10000];

int n = 0, i = 0, j = 0, a = 0, sum = 0, g = 0, flag = 0, num = 0;

int main()
{
    system("cls");
    wlcomescreen ();
    Title ();
    Login ();
}

/************************Main Menu function********************************/
void MainMenu (void)
{
    Fopen ();
    system("cls");
    int c, i, q;

    while(c != 6)
    {
        Title ();
        printf("\n\t\t\t\t\tSelect Option for\n\n\t\t\t\t\t1. ADD Patients Record\n\t\t\t\t\t2. Display Patients Record\n\t\t\t\t\t3. Search Patients Record\n\t\t\t\t\t4. Modify Patients Record\n\t\t\t\t\t5. Delete Patients Record\n\t\t\t\t\t6. Exit and stored data\n\n\t\t\t\t\tPlease choose the Option-> ");
        scanf("%d", &c);
        fflush(stdin);

        if(c == 1)
        {
            system("cls");
            Add();
        }
        else if(c == 2)
        {
            system("cls");
            Display ();
        }
        else if(c == 3)
        {
            system("cls");
            Search();
        }
        else if(c == 4)
        {
            system("cls");
            Modify ();
        }
        else if(c == 5)
        {
            system("cls");
            Delete ();
        }
        else if(c == 6)
        {
            write();
            Fclose();
            return 0;
        }
        else
        {
            system("cls");
            printf("\n\n\t\t\t\t\tInvalid Input!");
        }
        printf("\n\n");
    }

}

/*************************Welcome Screen function********************************/
void wlcomescreen ()
{
    printf("\n\t\t\t\t\t**********Welcome To**********");
    printf("\n\t\t\t\t\tBD Hospital Management System");
    printf("\n\n\n\n\t\t\t\t\tPress any key to continue-> ");
    getch();
    system("cls");
}

/****************************Title function*************************************/
void Title ()
{
    printf("\n");
    printf("\t\t\t\t\t  ********************");
    printf("\n\t\t\t\t\t  *   BD Hospital    *\n");
    printf("\t\t\t\t\t  ********************\n");
}

/************************User login*************************************/
void Login ()
{
   char username[]="abhi";
    char password[]="abhi211";
    char usr[20],pass[20];

    while(1)
    {
        printf("\n\t\t\t\t\tEnter Username and Password\n");
        printf("\n\t\t\t\t\tUSERNAME : ");
        scanf("%s",usr);
        printf("\n\t\t\t\t\tPASSWORD: ");

        int i=0;
        do{
            pass[i]=getch();
            if(pass[i]!='\r')
            {
                printf("*");
            }
            i++;
        }while(pass[i-1]!='\r');
        pass[i-1]='\0';

        if(strcmp(username,usr)!=0)
        {
            printf("\n\n\t\t\t\t\tUsername does not exist");
        }
        else if(strcmp(password,pass)!=0)
        {
            printf("\n\n\t\t\t\t\tIncorrect password");
        }
        else if(strcmp(username,usr)==0 && strcmp(password,pass)==0)
        {
            printf("\n\n\t\t\t\t\t>>>Login Successful<<<");
            printf("\n\t\t\t\t\tPress any key to go Manue driven-> ");
            getch();
            MainMenu();
            break;
        }
    }

      printf("\n\n\t\t\t\t\tThank you for visiting\n\n\n\n\n\n\n\n\n");
}

/**********************************Add record*******************************/
void Add()
{
    printf("\n\t\t\t\t\tHow Many Entry Do You Want To Add?->  ");
    scanf("%d", &n);

    sum = n + num;

    printf("\n\t\t\t\t\t---ADD Patient/s Details---\n");
    for(i = num; i < sum; i++)
    {
        printf("\n\n");
        fflush(stdin);
        printf("\t\t\t\t\tPatient Name : ");
        gets(x[i].Name);
        fflush(stdin);
        printf("\t\t\t\t\tAge : ");
        scanf("%d", &x[i].Age);
        fflush(stdin);
        printf("\t\t\t\t\tGender : ");
        gets(x[i].Gender);
        fflush(stdin);
        printf("\t\t\t\t\tProblems/Symptoms : ");
        gets(x[i].Problem);
        fflush(stdin);
        printf("\t\t\t\t\tMobile number : ");
        scanf("%d", &x[i].Mobile);
        fflush(stdin);
        printf("\t\t\t\t\tEmail : ");
        gets(x[i].Email);
        fflush(stdin);
        printf("\t\t\t\t\tRoom number : ");
        scanf("%d", &x[i].Room);
        fflush(stdin);
        printf("\t\t\t\t\tPrescribed Doctor : ");
        gets(x[i].Doctor);
        fflush(stdin);
        printf("\n");
        //j++;
        num++;
    }
     system("cls");
     printf("\n\t\t\t\t\t Add Successfully...\n");
}

/**********************************View record******************************/
void Display ()
{
    FILE *fp;
    i = 0;
    fp = fopen("DisplayRecord.txt", "w");
    if (fp==NULL)
    {
        printf("\n\t\t\t\t\tFile is not created");
    }
     printf("\t\t\t\t\t-----------------------------------");
    while (i < num)
    {
        printf("\n");
        printf("\t\t\t\t\tSerial Number : %d\n",i);
        printf("\t\t\t\t\tPatient Name : ");
        puts(x[i].Name);
        printf("\t\t\t\t\tAge : %d\n",x[i].Age);
        printf("\t\t\t\t\tGender : ");
        puts(x[i].Gender);
        printf("\t\t\t\t\tProblems/symptoms : ");
        puts(x[i].Problem);
        printf("\t\t\t\t\tMobile number : %d\n",x[i].Mobile);
        printf("\t\t\t\t\tEmail : ");
        puts(x[i].Email);
        printf("\t\t\t\t\tRoom number : %d\n",x[i].Room);
        printf("\t\t\t\t\tPrescribed Doctor : ");
        puts(x[i].Doctor);
        printf("\n");
        fprintf(fp,"%d %s %d %s %s %d %s %d %s", i, x[i].Name, x[i].Age, x[i].Gender, x[i].Problem, x[i].Mobile,x[i].Email,x[i].Room,x[i].Doctor);
        i++;

    }
     printf("\t\t\t\t\t-----------------------------------");
     getch();
     system("cls");
     fclose(fp);
}

/*********************************Search record**********************************/
void Search ()
{
    system("cls");
    int s, h, f;
    char u[100];

    printf("\n\t\t\t\t\tBy what you want to search\n\n");
    printf("\t\t\t\t\t1. Name\n\t\t\t\t\t2. Mobile number\n\t\t\t\t\t3. Room number\n\t\t\t\t\t4. Problems/symptoms\n\t\t\t\t\t5. Age\n\t\t\t\t\t6. Doctor Name\n\n\t\t\t\t\tChoose the option-> ");
    scanf("%d", &h);

    if(h == 1)
    {
        int f = 1;
        fflush(stdin);
        printf("\t\t\t\t\tEnter the name to search : ");
        gets(u);
        fflush(stdin);
        for(g = 0; g < num; g++)
        {
            if(strcmp(u, x[g].Name) == 0)
            {

               printf("\n\t\t\t\t\t-----Search successful-----\n");
               printf("\n");
               printf("\t\t\t\t\tSerial No. : %d\n", g);
               printf("\t\t\t\t\tPatient Name : ");
               puts(x[g].Name);
               printf("\t\t\t\t\tAge : %d\n",x[g].Age);
               printf("\t\t\t\t\tGender : ");
               puts(x[g].Gender);
               printf("\t\t\t\t\tProblems/symptoms : ");
               puts(x[g].Problem);
               printf("\t\t\t\t\tMobile number : %d\n",x[g].Mobile);
               printf("\t\t\t\t\tEmail : ");
               puts(x[g].Email);
               printf("\t\t\t\t\tRoom number : %d\n",x[g].Room);
               printf("\t\t\t\t\tPrescribed Doctor : ");
               puts(x[g].Doctor);
               printf("\n\t\t\t\t\t---------------------");
               f = 0;
            }
        }
            if(f == 1)
                printf("\n\t\t\t\t\tSearch Unsuccessful! please try again\n");

    }
     else if(h == 2)
    {
        int f = 1;
        printf("\n\t\t\t\t\tEnter the Mobile number to search : ");
        scanf("%d", &f);
        for(g = 0; g < num; g++)
        {
            if(f == x[g].Mobile)
            {
               printf("\n\t\t\t\t\t-----Search successful-----\n");
               printf("\n");
               printf("\t\t\t\t\tSerial No. : %d\n", g);
               printf("\t\t\t\t\tPatient Name : ");
               puts(x[g].Name);
               printf("\t\t\t\t\tAge : %d\n",x[g].Age);
               printf("\t\t\t\t\tGender : ");
               puts(x[g].Gender);
               printf("\t\t\t\t\tProblems/symptoms : ");
               puts(x[g].Problem);
               printf("\t\t\t\t\tMobile number : %d\n",x[g].Mobile);
               printf("\t\t\t\t\tEmail : ");
               puts(x[g].Email);
               printf("\t\t\t\t\tRoom number : %d\n",x[g].Room);
               printf("\t\t\t\t\tPrescribed Doctor : ");
               puts(x[g].Doctor);
               printf("\n\t\t\t\t\t---------------------");
               f = 0;
            }
        }
            if(f==1)
                printf("\n\t\t\t\t\tSearch Unsuccessful! please try again\n");
    }

    else if(h == 3)
    {
        int f = 1;
        printf("\n\t\t\t\t\tEnter Room number to search : ");
        scanf("%d", &f);
        for(g = 0; g < num; g++)
        {
            if(f == x[g].Room)
            {
               printf("\n\t\t\t\t\t-----Search successful-----\n");
               printf("\n");
               printf("\t\t\t\t\tSerial No. : %d\n", g);
               printf("\t\t\t\t\tPatient Name : ");
               puts(x[g].Name);
               printf("\t\t\t\t\tAge : %d\n",x[g].Age);
               printf("\t\t\t\t\tGender : ");
               puts(x[g].Gender);
               printf("\t\t\t\t\tProblems/symptoms : ");
               puts(x[g].Problem);
               printf("\t\t\t\t\tMobile number : %d\n",x[g].Mobile);
               printf("\t\t\t\t\tEmail : ");
               puts(x[g].Email);
               printf("\t\t\t\t\tRoom number : %d\n",x[g].Room);
               printf("\t\t\t\t\tPrescribed Doctor : ");
               puts(x[g].Doctor);
               printf("\n\t\t\t\t\t---------------------");
               f = 0;
            }
        }
            if(f==1)
                printf("\n\t\t\t\t\tSearch Unsuccessful! please try again->");

    }
     else if(h == 4)
    {
        int f = 1;
        fflush(stdin);
        printf("\t\t\t\t\tEnter the Problems/Symptoms to search : ");
        gets(u);
        fflush(stdin);
        for(g = 0; g < num; g++)
        {
            if(strcmp(u, x[g].Problem) == 0)
            {
               printf("\n\t\t\t\t\t-----Search successful-----\n");
               printf("\n");
               printf("\t\t\t\t\tSerial No. : %d\n", g);
               printf("\t\t\t\t\tPatient Name : ");
               puts(x[g].Name);
               printf("\t\t\t\t\tAge : %d\n",x[g].Age);
               printf("\t\t\t\t\tGender : ");
               puts(x[g].Gender);
               printf("\t\t\t\t\tProblems/symptoms : ");
               puts(x[g].Problem);
               printf("\t\t\t\t\tMobile number : %d\n",x[g].Mobile);
               printf("\t\t\t\t\tEmail : ");
               puts(x[g].Email);
               printf("\t\t\t\t\tRoom number : %d\n",x[g].Room);
               printf("\t\t\t\t\tPrescribed Doctor : ");
               puts(x[g].Doctor);
               printf("\n\t\t\t\t\t---------------------");
               f = 0;
            }
        }
            if(f==1)
                printf("\n\t\t\t\t\tSearch Unsuccessful! please try again\n\t");

    }

    else if(h == 5)
    {
        int f = 1;
        printf("\n\t\t\t\t\tEnter the Age to search : ");
        scanf("%d", &f);
        for(g = 0; g < num; g++)
        {
            if(f == x[g].Age)
            {
               printf("\n\t\t\t\t\t-----Search successful-----\n");
               printf("\n");
               printf("\t\t\t\t\tSerial No. : %d\n", g);
               printf("\t\t\t\t\tPatient Name : ");
               puts(x[g].Name);
               printf("\t\t\t\t\tAge : %d\n",x[g].Age);
               printf("\t\t\t\t\tGender : ");
               puts(x[g].Gender);
               printf("\t\t\t\t\tProblems/symptoms : ");
               puts(x[g].Problem);
               printf("\t\t\t\t\tMobile number : %d\n",x[g].Mobile);
               printf("\t\t\t\t\tEmail : ");
               puts(x[g].Email);
               printf("\t\t\t\t\tRoom number : %d\n",x[g].Room);
               printf("\t\t\t\t\tPrescribed Doctor : ");
               puts(x[g].Doctor);
               printf("\n\t\t\t\t\t---------------------");
               f = 0;
            }
        }
             if(f==1)
                printf("\n\t\t\t\t\tSearch Unsuccessful! please try again\n");


    }
    else if(h == 6)
    {
        int f = 1;
        fflush(stdin);
        printf("\t\t\t\t\tEnter the Doctor name to search : ");
        gets(u);
        fflush(stdin);
        for(g = 0; g < num; g++)
        {
            if(strcmp(u, x[g].Doctor) == 0)
            {

               printf("\n\t\t\t\t\t-----Search successful-----\n");
               printf("\n");
               printf("\t\t\t\t\tSerial No. : %d\n", g);
               printf("\t\t\t\t\tPatient Name : ");
               puts(x[g].Name);
               printf("\t\t\t\t\tAge : %d\n",x[g].Age);
               printf("\t\t\t\t\tGender : ");
               puts(x[g].Gender);
               printf("\t\t\t\t\tProblems/symptoms : ");
               puts(x[g].Problem);
               printf("\t\t\t\t\tMobile number : %d\n",x[g].Mobile);
               printf("\t\t\t\t\tEmail : ");
               puts(x[g].Email);
               printf("\t\t\t\t\tRoom number : %d\n",x[g].Room);
               printf("\t\t\t\t\tPrescribed Doctor : ");
               puts(x[g].Doctor);
               printf("\n\t\t\t\t\t---------------------");
               f = 0;
            }
        }
            if(f == 1)
                printf("\n\t\t\t\t\tSearch Unsuccessful! please try again\n\t");

    }
    else
        printf("\n\n\t\t\t\t\tInvalid Input!!!Please try again\n");
        getch();
        system("cls");
}

/*************************************Modify Record************************************/
void Modify ()
{
    int p, q;
    fflush(stdin);
    printf("\n\t\t\t\t\tChoose the option What do you want to Edit?\n\n");
    printf("\t\t\t\t\t1. Name\n\t\t\t\t\t2. Problems/Symptoms\n\t\t\t\t\t3. Age\n\t\t\t\t\t4. Room number\n\t\t\t\t\t5. Mobile number\n\t\t\t\t\t6. Email\n\t\t\t\t\t7. Doctor name\n\t\t\t\t\t8. Gender\n");
    printf("\n\t\t\t\t\tChoose the Option -> ");
    scanf("%d", &q);

    if(q <= 8)
    {
        printf("\t\t\t\t\tEnter serial number of the patient(0-%d) to Modify-> ", num - 1);
        scanf("%d", &p);
        if(p < num)
        {
            if(q == 1)
            {
                fflush(stdin);
                printf("\t\t\t\t\tEnter New Name : ");
                gets(x[p].Name);

            }
            else if(q == 2)
            {
                fflush(stdin);
                printf("\t\t\t\t\tEnter New Problems/Symptoms : ");
                gets(x[p].Problem);
            }
            else if(q == 3)
            {
                fflush(stdin);
                printf("\t\t\t\t\tEnter New age : ");
                scanf("%d", &x[p].Age);
            }

            else if(q == 4)
            {
                fflush(stdin);
                printf("\t\t\t\t\tEnter New Room No. : ");
                scanf("%d", &x[p].Room);
            }

            else if(q == 5)
            {
                fflush(stdin);
                printf("\t\t\t\t\tEnter New Mobile No. : ");
                scanf("%d", &x[p].Mobile);
            }
            else if(q == 6)
            {
                fflush(stdin);
                printf("\t\t\t\t\tEnter New Email : ");
                gets(x[p].Email);
            }
            else if(q == 7)
            {
                fflush(stdin);
                printf("\t\t\t\t\tEnter New Doctor Name : ");
                gets(x[p].Doctor);
            }
            else if(q == 8)
            {
                fflush(stdin);
                printf("\t\t\t\t\tEnter New Gender : ");
                gets(x[p].Gender);
            }
            system("cls");
            printf("\n\n\t\t\t\t\tEdit Successfully...\n");
        }
        else
        {
            printf("\n\n\t\t\t\t\tInvalid number! Try Again\n\n");
        }
    }
    else
    {
        printf("\n\n\t\t\t\t\tInvalid Option! Try Again\n\n");
    }
}

/******************************************Delete Record**************************************/
void Delete ()
{
    int f, h;
    printf("\n\t\t\t\tEnter Serial number of the patient(0-%d) to Delete-> ", num - 1);
    scanf("%d", &f);
    if(f < num)
    {
        printf("\n\n\t\t\t\t\tWhat do you want?\n\n");
        printf("\t\t\t\t\t1. Delete Full Data\n\t\t\t\t\t2. Delete Patient Name\n\t\t\t\t\t3. Delete Problems/Symptoms\n\t\t\t\t\t4. Delete Age\n\t\t\t\t\t5. Delete Room number\n\t\t\t\t\t6. Delete Mobile number\n\t\t\t\t\t7. Delete Email\n\t\t\t\t\t8. Delete Prescribed Doctor name\n\t\t\t\t\t9. Delete Gender\n\n\t\t\t\t\tChoose the option -> ");
        scanf("%d", &h);
        if(h == 1)
        {
            while(f < num)
            {
                strcpy(x[f].Name, x[f + 1].Name);
                strcpy(x[f].Problem, x[f + 1].Problem);
                strcpy(x[f].Email, x[f + 1].Email);
                strcpy(x[f].Doctor, x[f + 1].Doctor);
                strcpy(x[f].Gender, x[f + 1].Gender);
                x[f].Age = x[f + 1].Age;
                x[f].Room = x[f + 1].Room;
                x[f].Mobile = x[f + 1].Mobile;
                f++;
            }
            num--;
        }
        else if(h == 2)
        {
            strcpy(x[f].Name, "Cleared");

        }
        else if(h == 3)
        {
            strcpy(x[f].Problem, "Cleared");
        }
        else if(h == 4)
        {
            x[f].Age = 0;
        }
        else if(h == 5)
        {
            x[f].Room = 0;
        }
        else if(h == 6)
        {
            x[f].Mobile = 0;
        }
        else if(h == 7)
        {
            strcpy(x[f].Email, "Cleared");

        }
        else if(h == 8)
        {
            strcpy(x[f].Doctor, "Cleared");

        }
         else if(h == 9)
        {
            strcpy(x[f].Gender, "Cleared");

        }
        system("cls");

       printf("\n\n\t\t\t\t\tDelete Successfully\n");
    }
    else
        printf("\n\n\t\t\t\t\tInvalid Serial number!\n\n");

}
/*******File open read and write mode*/
void Fopen ()
{
    FILE *fp;
    fp = fopen("DataStore.txt", "r");

    if(fp == NULL)
    {
        fp = fopen("DataStore.txt","w");
        printf("\n\n\t\t\t\t\tFile open Successfully\n\n\n");
        fclose(fp);
    }

    num = fread(x, sizeof(struct Patient),10000, fp);

    fclose(fp);
}
/*******After exit Data is stored in a File*/
void Fclose ()
{
    FILE *fp;
    fp = fopen("DataStore.txt","w");
    if(fp == NULL)
    {
        printf("\n\n\t\t\t\t\tError");
        exit(1);
    }
    fwrite(x,sizeof(struct Patient), num, fp);

    fclose(fp);
}
