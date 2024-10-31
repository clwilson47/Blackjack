/*
Name: blackjack.h
Author: Cole Wilson
Date: 10-31-24
Purpose: classes to store deck of card stuff 
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//function prototypes
int assignValues(int, int); 
int aceCheck(int, int); 
void dealPlayerCards(int, string); 
void dealDealerCards (int, int); 

class Card
{
    private: 
        //stores card info 
        int cardValue; 
        string cardName; 

    public: 

        //getters 
        int getCardValue(){return cardValue;}
        string getCardName(){return cardName;}
        

        //setters 
        void setCardValue(int newCardValue){cardValue = newCardValue;}
        void setCardName(string newCardName){cardName = newCardName;}
       

        //stream operator overload
        friend ostream& operator << (ostream& os, const Card& C)
        {
            os << "\n\nCard: " << C.cardName << "\nValue: " << C.cardValue << "\n\n"; 
            
            return os; 
        }

};

struct DeckofCards
{
    
    //names for the cards 
    string cardName[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Jack", "Queen", "King"};

    //number of total cards 
    int numCards; 
    numCards = 52; 

    string cardDeck[numCards]; 
    
    

    //update values
    for (int i = 0; i < numCards; i++)
    {
        
    }
    

}; 