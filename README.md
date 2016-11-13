# LiarsDice

# Description
This game requires two or more players to run properly. This game will require a dice
roll function, completed once at the beginning of play for every dice. Each player gets five six-
sided dice. On each player’s turn, the player gets to view their own dice. They guess the rolled
dice value (1-6) and how many of those dice are in the whole game. The game continues until
someone inputs “Y” or "y" for "yes" when asked if they want to call liar. At this point, the game
checks to see if the guess is accurate. If the person guessed the right amount of dice and
respective value, that guesser wins. If they did not get it right, the accuser wins. After each turn,
there must be an increase in how many dice are thought to be on the table.

# Reflection
Arrays were seen as a requirement for this assignment. I deviated from arrays because
vectors were a more efficient replacement for arrays. It allowed for a varying index count, which
is why I justified this change to the program.
I learned the benefits of vectors over arrays. A big learning experience here was just adding small bits of functionality at a time, to allow for a
better testing approach. Seeding the random number generator was another big lesson learned,
which is that seeding should only happen once or bad things happen in your program. The last
lesson learned is that it is important to #include stdafx.h at or near the beginning. I had this after
my class header files, and it led to twelve errors. 