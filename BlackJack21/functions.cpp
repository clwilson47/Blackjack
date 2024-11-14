/*
    Name: functions.cpp
    Author: Cole Wilson
    Date: 10-31-24
    Purpose: various functions to make the driver actually work
*/


#include "blackjack.h"

/*
    Function: assignValues
    Purpose: generate random values to be assigned to cards with appropiate values for jack, queen, king
*/
int assignValues(int playerTotal, int dealerTotal)
{
    int rnum = 0, card = 0; 

    //generate random number for the 13 cards in deck
    rnum = (rand() % 13 + 1);
    card = rnum;

   
    
    //ace is special
    if (card == 1)
    { 
        card = aceCheck(playerTotal, dealerTotal); 
        return card; 
    }

    //otherwise just return card 
    return card; 
}

/*
    Function: aceCheck
    Purpose: give ace card a value of 1 or 10 as appropiate 
*/
int aceCheck(int playerTotal, int dealerTotal)
{
    int ace = 0; 
    if(1 + playerTotal > 21 || 1 + dealerTotal > 21)
        ace = 1; 

    else if(10 + playerTotal < 21 || 10 + dealerTotal < 21)
        ace = 10; 

    return ace; 
}


/* 
    Function: dealPlayerCards
    Purpose: deal player cards as long as desired or until bust
*/
void dealPlayerCards (int playerTotal, string cardName)
{
    char drawAgain = 'y'; 
    int rnum = 0, card = 0;

    do 
    {
        cout << "\n\nThe dealer will now deal your first card"; 

        //player total is running value 
        playerTotal += assignValues(rnum, card); 

        //need to check for previous aces


        // output card and total
        cout << "\nYour card: " << cardName[card - 1];
        cout << "\n\nYour total is " << playerTotal; 

        //draw more cards less than 21
        if (playerTotal < 21)
        {
            cout << "\n\nWould you like to draw another card?"; 
            cout << "\nPlease enter y/n: "; 
            cin >> drawAgain; 
            cin.ignore(); 
        }

        //case if player gets perfect 21
        else if (playerTotal == 21)
        {
            cout << "\n\nNice! Perfect Score! Lets see how the dealer does"; 
            drawAgain = 'n'; 
        }

        
        //case player goes over 21
        else if (playerTotal > 21)
        {
            cout << "\n\nOh no! You busted! You lose!"; 
            drawAgain = 'n'; 
        }

    } while (playerTotal < 21 || drawAgain == 'y' || drawAgain == 'Y'); 
    
}


/*
    Function: dealDealerCards
    Purpose: let the dealer play against the player after player done
*/
void dealDealerCards (int dealerTotal, int playerTotal)
{
    char drawAgain = 'y'; 
    do 
    {
        int rnum, card = 0; 

        //dealer total is running value 
        dealerTotal += assignValues(rnum, card); 

        //need to check for previous aces

        
        cout << "\n\nThe dealer's total is " << dealerTotal; 

        //dealer tries to beat player if his cards are less than theirs
        if (dealerTotal < playerTotal)
        {
            cout << "\n\nThe dealer will now draw another card"; 
            drawAgain = 'y'; 
        
        }

        //dealer stops drawing cards if they beat the player
        else if (dealerTotal > playerTotal)
        {
            cout << "Oh no! The dealer got a higher score than you! You lose."; 
            drawAgain = 'n'; 
        }

        //case if dealer and player tie for 21
        else if (dealerTotal == 21)
        {
            cout << "\n\nOh no! The dealer tied with you! You lose."; 
            drawAgain = 'n'; 
        }

        
        //case if dealer goes over 21
        else if (dealerTotal > 21)
        {
            cout << "\n\nThe dealer busted! You win!"; 
            drawAgain = 'n'; 
        }


    } while (drawAgain == 'y'); 
}