


#include "blackjack.h"


/*
    Function: assignValues
    Purpose: generate random values to be assigned to cards with appropiate values for jack, queen, king
*/
int assignValues(int rnum, int card)
{
    //initialize values
    rnum = 0;
    card = 0;
    int ace = 0; 
    //generate random number for the 13 cards in deck
    rnum = (rand() % 13 + 1);

    card = rnum;

    // jack, queen, and king = 10
    if (card == 11 || card == 12 || card == 13)
        card = 10;
    
    //ace is special
    if (card == 1)
    {
        ace = 1; 

        //return ace uniquely since it's special
        return ace; 
    }

    //otherwise just return card 
    return card; 
}

/*
    Function: aceCheck
    Purpose: give ace card a value of 1 or 10 as appropiate 
*/
int aceCheck(int playerTotal, int dealerTotal, int ace)
{
    if(1 + playerTotal > 21)
        ace = 1; 

    if(10 + playerTotal < 21)
        ace = 10; 

    return ace; 
}

/* 
    Function: dealCards
    Purpose: deal out cards as long as desired or until bust
*/
void dealCards (int playerTotal, int dealerTotal)
{
    do 
    {
        cout << "Your total is " << playerTotal; 

        if (playerTotal < 21)
        {
            cout << "Would you like to draw another card?"; 
        }
        else if (playerTotal == 21)
            cout << "Nice! Perfect Score! Lets see how the dealer does"; 
    } while (playerTotal < 21); 
    
}