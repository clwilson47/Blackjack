#include "Data.h"

Card setCardValues()
    { 

        //names for the cards 
        string cardName[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

        int rnum = 0; 
        Card card; 

        //generate random number for the 13 cards in deck
        rnum = (rand() % 13 + 1);

        //update the card using the rnum
        card.setCardName(cardName[rnum]); 
        card.setCardValue(rnum); 

        return card; 

    }

void playerDraw(int playerTotal)
{
    char drawAgain; 


    //draw as much as user wants 
    do
    {
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

    } while (drawAgain != 'y'); 
}

void dealerDraw()
{

}