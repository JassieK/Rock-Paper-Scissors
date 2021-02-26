#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int generator(int n)
{
    srand(time(NULL));
    return rand() % n;
}

int compare(char a, char b)
{
    int s;

    if (a == b)
    {
        s = 2;
    }

    else if ((a == 'R') && (b == 'S'))
    {

        s = 1;
    }

    else if ((a == 'P') && (b == 'R'))
    {

        s = 1;
    }

    else if ((a == 'S') && (b == 'P'))
    {

        s = 1;
    }

    else
    {

        s = -1;
    }

    return s;
}

int main()
{
    int i;
    char user[10];
    char comp[10];
    int s, pscore = 0, qscore = 0;
    char name[50];
    printf("Enter your nick name\n");
    gets(name);
    for (i = 1; i <= 3; i++)
    {
        s = 0;
        char c;
        printf("Enter R for rock\nEnter P for paper\nEnter S for scissors\n\n\n");
        scanf("%c", &c);
        getchar();
        switch (c)
        {
        case 'R':
            strcpy(user, "Rock");
            break;

        case 'P':
            strcpy(user, "Paper");
            break;

        case 'S':
            strcpy(user, "Scissors");
            break;

        default:
            printf("Invalid");
            break;
        }

        int n;
        n = generator(3);
        char compc[3] = {'R', 'P', 'S'};
        switch (compc[n])
        {
        case 'R':
            strcpy(comp, "Rock");
            break;

        case 'P':
            strcpy(comp, "Paper");
            break;

        case 'S':
            strcpy(comp, "Scissors");
            break;

        default:
            printf("Invalid\n");
            break;
        }

        printf("%s Chose %s\n", name, user);
        printf("PC Chose %s\n", comp);

        s = compare(c, compc[n]);

        if (s == 1)
        {
            pscore++;
            printf("Yay %s you got it\n\n\n", name);
        }

        else if (s == 2)
        {
            printf("TIE\n\n\n");
        }

        else if (s == -1)
        {
            qscore++;
            printf("Sadly pc got it\n\n\n");
        }
    }

    printf("Total score \nYou = %d \nP.C = %d\n", pscore, qscore);
    if (pscore > qscore)
        printf("%s win", name);

    else if (pscore < qscore)
        printf("%s lose", name);

    else
        printf("Its a Tie");
}
