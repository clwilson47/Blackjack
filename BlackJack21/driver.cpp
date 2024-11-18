/*
    Name: Black Jack function
    Author: Cole Wilson
    Date: 10-31-24
    Purpose: run a black jack game for the user
*/


#include "LinkedList.h"
#include "Data.cpp"




int main()
{
    //a bunch of variable initializations
    char runProg = 'y';
    char drawAgain; 
    int playerTotal = 0, dealerTotal = 0; 
    

    // run as often as desired
    do
    {
        cout << "\n\nWelcome to the Blackjack Program!"; 

        
        //linked lists to store player cards 
        LinkedList<Card> playerCards; 
        LinkedList<Card> dealerCards; 
        Card playerCard, dealerCard; 

        
        //initial two cards for dealer and player
        for(int i = 0; i < 2; i++)
        {
            playerCards.appendNode(setCardValues()); 
            dealerCards.appendNode(setCardValues()); 
        }

        //show user their initial cards 
        cout << "\n\nThese are your cards: " << playerCards; 

        do 
        {
            playerCards.appendNode(setCardValues()); 

            //show user their new cards 
            cout << "\n\nThese are your cards: " << playerCards; 

            playerTotal; 


            //draw more cards if total less than 21
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
               
        } while(drawAgain == 'y' || drawAgain == 'Y'); 
        
        
        


       
        cout << "\n\nwould your like to play again? "; 
        cout << "\nPlease enter a y or n: "; 
        
    } while (runProg == 'y' || runProg == 'Y'); //end while loop

    return 0; //end program

}