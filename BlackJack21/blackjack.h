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
        int cardValue = 0;                      //face value, 1-9 or 10
        string cardName = "None";               //name ("ace", etc)
        int numAces = 0;                        //to track aces cause they special (1 or 10)
        int playerTotal, dealerTotal = 0;       //to track player and dealer's totals seperately 
        

    public: 

        //getters 
        int getCardValue(){return cardValue;}
        string getCardName(){return cardName;}
        int getNumAces(){return numAces;}
        int getPlayerTotal(){return playerTotal;}
        int getDealerTotal(){return dealerTotal;}
        

        //setters 
        void setCardValue(int newCardValue){cardValue = newCardValue;}
        void setCardName(string newCardName){cardName = newCardName;}
        void setNumAces(int newNumAces){numAces = newNumAces;}
        void setPlayerTotal(int newPlayerTotal){playerTotal = newPlayerTotal;}
        void setDealerTotal(int newDealerTotal){dealerTotal = newDealerTotal;}
       

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


        //Constructor 
        void DeckofCards()
        {
            //names for the cards 
            string cardName[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

            Card deck; 

            //initialize deck of cards with names and values 
            for(int i = 0; i < 13; i++)
            {
                deck.setCardName(cardName[i]); 

                if(i < 10)
                {
                    deck.setCardValue(i);           //values for Ace (special, but initally 1) and 2-9 
                    numAces++;                      //updating values of aces 
                }
                    
                else if(i > 10)
                    deck.setCardValue(10);          //values for jack, queen, king all 10
            }

        }



};