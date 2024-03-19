#include <stdio.h>
#include <stdlib.h>

struct batsman
{
    char name[50] ;
    int runs , score , balls ,ones , twos , threes , fours , sixes ;
};
struct batsman bat;
struct bowler
{
    char name[50];
    int runs_given, wickets, overs;
};
struct bowler bowl;

long int size = sizeof(bat);
FILE *fp,*ft;

void addrecord_batsman()
{
    system("cls");
    fseek(fp, 0, SEEK_END);
    char another = 'y';
    int choice;
    while (another == 'y') {
        printf("Enter the Batsman details  :\n");

        printf("Enter name of batsman:\n");
        scanf("%s",&bat.name);
        printf("Enter the number of ones scored by player:\n ");
        scanf("%d",&bat.ones);
        printf("Enter the number of twos scored by player:\n ");
        scanf("%d",&bat.twos);
        printf("Enter the number of threes scored by player:\n ");
        scanf("%d",&bat.threes);
        printf("Enter the number of fours scored by player:\n ");
        scanf("%d",&bat.fours);
        printf("Enter the number of sixes scored by player:\n ");
        scanf("%d",&bat.sixes);
        printf("Enter the balls played by the player:\n");
        scanf("%d",&bat.balls);
        fwrite(&bat, size, 1, fp);
        printf("Enter the Bowlers details  :\n");

        printf("\nWant to add another record (Y/N) : ");
        scanf("%c", &another);
    }
}


void addrecord_bowler()
{
    system("cls");
    fseek(ft, 0, SEEK_END);
    char another = 'y';
    int choice;

    while (another == 'y') {

        printf("Enter name of bowler:");
        scanf("%s", &bowl.name);
        printf("Enter the runs given by the bowler:\n ");
        scanf("%d", &bowl.runs_given);
        printf("Enter the overs bowled by the bowler:\n");
        scanf("%d", &bowl.overs);
        printf("Enter the wickets taken by the bowler\n");
        scanf("%d", &bowl.wickets);
        fwrite(&bowl, size, 1, ft);
        printf("\nWant to add another record (Y/N) : ");
        scanf("%c", &another);
    }
}

void displayrecord_batsman()
{
    system("cls");

    rewind(fp);
    printf("=====================================================================================================");
    printf("\nNAME\t\tONES\t\tTWOS\t\tTHREES\t\tFOURS\t\tSIXES\t\tBALLS\n");
    printf("=====================================================================================================\n");

    while (fread(&bat, size, 1, fp) == 1)
        printf("\n%s\t%d\t%d\t%d\t%d\t%d\t%d",bat.name, bat.ones, bat.twos, bat.threes,bat.fours,bat.sixes,bat.balls);

    printf("\n\n\n\t");
    system("pause");
}

void displayrecord_bowler()
{
    system("cls");

    rewind(ft);
    printf("\n==========================================================");
    printf("\nNAME\t\tOVERS\t\tWICKETS\t\tRUNS\n");
    printf("==========================================================\n");

    while (fread(&bowl, size, 1, ft) == 1)
        printf("\n%s\t%d\t%d\t%d",bowl.name,bowl.overs,bowl.runs_given,bowl.wickets);

    printf("\n\n\n\t");
    system("pause");
}

int main()
{
    int choice;

    fp = fopen("data1.txt", "r+");
    if (fp == NULL) {
        fp = fopen("data1.txt", "w+");
        if (fp == NULL) {
            printf("\nCannot open file...");
            exit(1);
        }
    }
    ft = fopen("data2.txt", "r+");
    if (ft == NULL) {
        ft = fopen("data2.txt", "w+");
        if (ft == NULL) {
            printf("\nCannot open file...");
            exit(1);
        }
    }

    while (1) {
        printf("\n 1. ADD RECORD FOR BATSMAN\n");
        printf("\n 2. ADD RECORD FOR BOWLER\n");
        printf("\n 3. DISPLAY RECORDS FOR BATSMAN\n");
        printf("\n 4. DISPLAY RECORDS FOR BOWLER\n");
        printf("\n 5. EXIT\n");
        printf("\nENTER YOUR CHOICE...\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            addrecord_batsman();
            break;
        case 2:
            addrecord_bowler();
            break;
        case 3:
            displayrecord_batsman();
            break;
        case 4:
            displayrecord_bowler();
            break;
        case 5:
            fclose(fp);
            fclose(ft);
            exit(0);
            break;
        default:
            printf("INVALID CHOICE...\n");
        }
    }
    return 0;
}
