/*
Name: Black Jack function
Author: Cole Wilson
Date: 10-30-22
Purpose: run a black jack game for the user
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    char runProg;

    // run as often as desired
    do
    {
        // variables
        char drawCard = 'y';

        // initialize variables
        srand(time(0));
        int playerTotal = 0, dealerTotal = 0;
        int rnum = 0;
        int card = 0;

        string cardName[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Jack", "Queen", "King"};

        cout << "\n\nWelcome to the Blackjack Program!\n\n";

        // loop so user gets 2 cards at start
        for (int i = 0; i < 2; i++)
        {
            // generate random number up to 13 (ace, 2-10, jack, queen, king)
            rnum = 0;
            card = 0;
            rnum = (rand() % 13 + 1);
            card = rnum;

            // jack, queen, and king = 10
            if (card == 11 || card == 12 || card == 13)
                card = 10;

            // running total
            playerTotal += card;

            // output card and total
            cout << "\nYour card: " << cardName[card - 1];
        }

        cout << "\nYour total: " << playerTotal;

        if (playerTotal < 21)
        {
            // ask user if they want to draw more cards
            cout << "\n\nWould you like to draw another card? (Y/N)   ";
            cin >> drawCard;
            cin.ignore();

            // repeat card generation process as long as user wants without busting/getting perfect score
            while (drawCard == 'y' || drawCard == 'Y')
            {
                // generate random number up to 13 (ace, 2-10, jack, queen, king)
                rnum = 0;
                card = 0;
                rnum = (rand() % 13 + 1);
                card = rnum;

                // jack, queen, and king = 10
                if (card == 11 || card == 12 || card == 13)
                    card = 10;

                // running total
                playerTotal += card;

                // output card and total
                cout << "\nYour card: " << cardName[card - 1];
                cout << "\nYour total: " << playerTotal;

                // validate if
                if (playerTotal < 21)
                {
                    // ask user if they want to draw more cards
                    cout << "\n\nWould you like to draw another card? (Y/N)   ";
                    cin >> drawCard;
                    cin.ignore();
                }

                else if (playerTotal == 21)
                {
                    // congratulate player
                    cout << "\n\nYou got a perfect score!\n\n";

                    // exit loop and continue game
                    drawCard = 'n';
                }

                else if (playerTotal > 21)
                {
                    // make fun of player
                    cout << "\n\nYou busted! Better luck next time!\n\n";

                    // exit loop and continue game
                    drawCard = 'n';
                }
            }
        }

        cout << "\nYou had a final total of " << playerTotal << "\n\n";

        // dealer's turn

        // only run if player did not bust
        if (playerTotal <= 21)
        {
            // messsage explaining
            cout << "\n\nNow the dealer will draw his cards\n\n";

            // loop so user gets 2 cards at start
            for (int i = 0; i < 2; i++)
            {
                // generate random number up to 13 (ace, 2-10, jack, queen, king)
                rnum = 0;
                card = 0;
                rnum = (rand() % 13 + 1);
                card = rnum;

                // jack, queen, and king = 10
                if (card == 11 || card == 12 || card == 13)
                    card = 10;

                // running total
                dealerTotal += card;

                // output card and total
                cout << "\nDealer's card: " << cardName[card - 1];
            }

            // dealer's starting total
            cout << "\nDealer's total: " << dealerTotal;

            // dealer tries to beat player
            if (dealerTotal < playerTotal)
            {
                // generate random number up to 13 (ace, 2-10, jack, queen, king)
                rnum = 0;
                card = 0;
                rnum = (rand() % 13 + 1);
                card = rnum;

                // jack, queen, and king = 10
                if (card == 11 || card == 12 || card == 13)
                    card = 10;

                // running total
                dealerTotal += card;

                // output card and total
                cout << "\nDealer's card: " << cardName[card - 1];
                cout << "\nDealer's total: " << dealerTotal;

                // repeat until beat player or lose
                while (dealerTotal < playerTotal && dealerTotal < 21)
                {
                    // generate random number up to 13 (ace, 2-10, jack, queen, king)
                    rnum = 0;
                    card = 0;
                    rnum = (rand() % 13 + 1);
                    card = rnum;

                    // jack, queen, and king = 10
                    if (card == 11 || card == 12 || card == 13)
                        card = 10;

                    // running total
                    dealerTotal += card;

                    // output card and total
                    cout << "\nDealer's card: " << cardName[card - 1];
                    cout << "\nDealer's total: " << dealerTotal;
                }

                // checking to see who won
                if (dealerTotal == playerTotal)
                {
                    cout << "\n\nYou and the dealer tied. Better luck next time!\n\n";
                }

                else if (dealerTotal > playerTotal && dealerTotal <= 21)
                {
                    cout << "\n\nThe dealer won! Better luck next time!\n\n";
                }

                else if (dealerTotal == 21)
                {
                    cout << "\n\nThe dealer got a perfect score! Better luck next time!\n\n";
                }

                else if (dealerTotal > 21)
                {
                    cout << "\n\nThe dealer busted. Congratualtions! You won!\n\n";
                }
            }

            // checking to see who won
            else if (dealerTotal == playerTotal)
            {
                cout << "\n\nYou and the dealer tied. Better luck next time!\n\n";
            }

            else if (dealerTotal > playerTotal && dealerTotal <= 21)
            {
                cout << "\n\nThe dealer won! Better luck next time!\n\n";
            }

            else if (dealerTotal == 21)
            {
                cout << "\n\nThe dealer got a perfect score! Better luck next time!\n\n";
            }
        }

        cout << "\n\nWould you like to play again? (Y/N)    ";
        cin >> runProg;

    } while (runProg == 'y' || runProg == 'Y');

    return 0;
}