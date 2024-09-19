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
int aceCheck(int, int, int); 
void dealPlayerCards(int); 
void dealDealerCards (int, int); 