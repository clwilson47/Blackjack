# Blackjack


## Purpose 
This a side project I began working on after taking a introductory C++ class (CSC 1300). I made an initial prototype in my free time near the end of that course in 
Fall 2022. This has been worked on fairly irregularly since then, mostly to refresh my memory of C++ coding and try to fix some problems in my prototype (e.g. the inability to properly read Aces as having a value
of 1 or 10. I have updated it since then using some knowledge I gained in another C++ class (CSC 1310) I took in Fall 2024. 


## Prototype
This is the initial work and has remained unmodified since Fall 2022. 

The prototype lacks any header files and runs all the code in one file. 

Essentially, it assigns a name and a value to cards using an array of strings and a random number generator to generate a value between 0 and 13 (Ace - 10, Jack, Queen, King => 13 cards total). 

  For Ace - 10, it uses the array to assign the name and the cardValue stays the same as the random number. 

  For Jack, Queen, and King same thing except the cardValue is 10. It keeps a running total of the player and the dealer to figure out who wins or if it is a draw. 
  
It outputs your initial two cards, their total, and from there it only outputs the new card and the new total value. It does not have much memory capabilities outside and the total values of the cards. 


## BlackJack21
This folder contains some of my new work. A lot of the initial commits to it were oriented for a late CSC 1300 approach using a header, functions.cpp, and driver.cpp

This has changed over time as I have learned new or better techniques durign my CSC 1310 class. 

Still a work in progress!
