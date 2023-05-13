# Hydra

# An implementation of the basic functionality of the Hydra Card Game, rules explained here: http://www.gamecabinet.com/rules/Hydra.html

# Instructions: 
Start by issuing the make command to compile the project. 
Below are instructions on the provided input files and the program functionalities they will highlight: 
 
EOF Testing:  ./hydra < players_eof.txt (1)  ./hydra < moves_eof.txt (2) 
These tests showcase the program’s abilities to handle the end of files such that the program does not run forever. (1) showcases EOF for handling incorrect input for the ‘How many players?” prompt and (2) showcases EOF for handling incorrect head selection during a player’s turn. 
 
Game Creation Testing:  ./hydra < creation1.txt (3)  ./hydra < creation2.txt (4) 
These tests showcase the program’s abilities to handle a multitude of different amounts of players 
 
All Inclusive Big Test:  ./hydra < big_test.txt 
This test showcases the entire of the program including the input error handling, head cutting, continuous rounds, and end of file handling 
 
// Please feel run and test an instance of the game yourself with the ./hydra command. 
