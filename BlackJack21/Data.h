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

class Card
{
    private: 
        //stores card info 
        int cardValue = 0;                      //face value, 1-9 or 10
        string cardName = "None";               //name ("ace", etc)
       
        

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

         //comparison operator overloads
            friend bool operator < (const Card& C1, const Card& C2)
            {
                return (C1.cardValue < C2.cardValue);
                 
            }

            friend bool operator < (const Card& C1, const Card& C2)
            {
                return (C1.cardValue > C2.cardValue);
                 
            }

            friend bool operator == (const Card& C1, const Card& C2)
            {
                return (C1.cardValue == C2.cardValue);
                 
            }


};