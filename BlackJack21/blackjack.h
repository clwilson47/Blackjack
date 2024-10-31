/*
Name: Black Jack function
Author: Cole Wilson
Date: 9-18-24
Purpose: run a black jack game for the user
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

class DeckofCards
{

}; 