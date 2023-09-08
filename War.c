#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "time.h"

void delay(void)
{
   int c, d;
   
   for (c = 1; c <= 32767; c++)
       for (d = 1; d <= 32767; d++)
       {}
}

void war(void) {
    printf("--------------------------------------------------------------------------------\n");
    printf("Thank you for playing the War card game!\n");
    delay();
    printf("In war, there is a wager made at the beginning of each round.\n");
    delay();
    printf("Then both the dealer and the player are dealt one card.\n");
    delay();
    printf("If the players card is higher than the dealer, the player doubles their bet.\n");
    delay();
    printf("In the case of a tie, another card is given to each player.\n");
    delay();
    printf("Do you want to play war? (Y/N)\n");
    printf("--------------------------------------------------------------------------------\n\n");

int two_cutoff = 165191049;
int three_cutoff = 330382099;
int four_cutoff = 495573149;
int five_cutoff = 660764199;
int six_cutoff = 825955248;
int seven_cutoff = 991146298;
int eight_cutoff = 1156337348;
int nine_cutoff = 1321528398;
int ten_cutoff = 1486719447;
int jack_cutoff = 1651910497;
int queen_cutoff = 1817101547;
int king_cutoff = 1982292597;
int ace_cutoff = RAND_MAX;

bool playing = 0;
int money = 0;

while (1) {
char reading = 0;
scanf(" %c", &reading);

if (reading == 'Y' || reading == 'y') {
    playing = 1;
    money = 500;
    break;
}

else if (reading == 'N' || reading == 'n') {
    break;
}

else {
    printf("Invalid Input!\n");
}
}

while (playing) {

    int wager = 0;
    int rand1 = 0;
    int rand2 = 0;
    char *s1 = "";
    char *s2 = "";
    
    printf("----------------------------------------------------\n");
    printf("Total Money: %d\n", money);
    printf("How much would you like to wager? (Enter an Integer)\n");
    printf("----------------------------------------------------\n\n");

    while (1) {

    scanf("%d", &wager);

    if (wager > money) {
        printf("----------------------------------------------------\n");
        printf("Wager amount cannot be higher than your money total.\n");
        printf("----------------------------------------------------\n\n");

    }

    else if (wager < 0) {
        printf("----------------------------------------------------\n");
        printf("Wager amount cannot be negative.\n");
        printf("----------------------------------------------------\n\n");
    }

    else {
        break;
    }

    }

    rand1 = rand();
    rand2 = rand();

    if (rand1 < two_cutoff) {
        s1 = "Two";
    }

    else if (rand1 < three_cutoff) {
        s1 = "Three";
    }    

    else if (rand1 < four_cutoff) {
        s1 = "Four";
    }

    else if (rand1 < five_cutoff) {
        s1 = "Five";
    }

    else if (rand1 < six_cutoff) {
        s1 = "Six";
    }

    else if (rand1 < seven_cutoff) {
        s1 = "Seven";
    }

    else if (rand1 < eight_cutoff) {
        s1 = "Eight";
    }    

    else if (rand1 < nine_cutoff) {
        s1 = "Nine";
    }

    else if (rand1 < ten_cutoff) {
        s1 = "Ten";
    }
    
    else if (rand1 < jack_cutoff) {
        s1 = "Jack";
    }

    else if (rand1 < queen_cutoff) {
        s1 = "Queen";
    }

    else if (rand1 < king_cutoff) {
        s1 = "King";
    }    

    else {
        s1 = "Ace";
    }

    if (rand2 < two_cutoff) {
        s2 = "Two";
    }
    
    else if (rand2 < three_cutoff) {
        s2 = "Three";
    }

    else if (rand2 < four_cutoff) {
        s2 = "Four";
    }

    else if (rand2 < five_cutoff) {
        s2 = "Five";
    }    

    else if (rand2 < six_cutoff) {
        s2 = "Six";
    }

    else if (rand2 < seven_cutoff) {
        s2 = "Seven";
    }
    
    else if (rand2 < eight_cutoff) {
        s2 = "Eight";
    }

    else if (rand2 < nine_cutoff) {
        s2 = "Nine";
    }

    else if (rand2 < ten_cutoff) {
        s2 = "Ten";
    }    

    else if (rand2 < jack_cutoff) {
        s2 = "Jack";
    }

    else if (rand2 < queen_cutoff) {
        s2 = "Queen";
    }
    
    else if (rand2 < king_cutoff) {
        s2 = "King";
    }

    else {
        s2 = "Ace";
    }

    printf("----------------------------------------------------\n");
    printf("Dealer has: %s\n", s1);
    printf("Player has: %s\n", s2);
    printf("----------------------------------------------------\n\n");
    delay();

    if (strcmp(s1, s2) == 0) {
        printf("----------------------------------------------------\n");
        printf("Tie! No money lost or gained.\n");
        printf("----------------------------------------------------\n\n");
        delay();
    }

    else if (rand2 > rand1) {
        printf("----------------------------------------------------\n");
        printf("Player wins! Players %s is greater than Dealers %s.\n", s2, s1);
        int oldmoney = money;
        money = money + wager;
        printf("Money has increased by %d from %d to %d.\n", wager, oldmoney, money);
        printf("----------------------------------------------------\n\n");
        delay();
    }

    else {
        printf("----------------------------------------------------\n");
        printf("Dealer wins. Dealers %s is greater than Players %s.\n", s1, s2);
        int oldmoney = money;
        money = money - wager;
        printf("Money has decreased by %d from %d to %d.\n", wager, oldmoney, money);
        printf("----------------------------------------------------\n\n");
        delay();
    }

    if (money <= 0) {
        printf("----------------------------------------------------\n");
        printf("Game Over! Would you like to play again? (y/n)\n");
        printf("----------------------------------------------------\n\n");

    while (1) {
        char reading2 = 0;
        scanf(" %c", &reading2);

        if (reading2 == 'Y' || reading2 == 'y') {
        money = 500;
        break;
        }

        else if (reading2 == 'N' || reading2 == 'n') {
        playing = 0;
        break; 
        }

        else {
        printf("Invalid Input!\n"); }
        }
        }
}
}

int main(void) {
    war();
}
