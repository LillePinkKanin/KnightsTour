#include "KnightsTour.h"

int main(){ 
    
    char userInput = '\0';

    printf("***WELCOME TO THE KNIGHTS TOUR***\n"); //startmenu
    printf("Would you like to begin? (Y for Yes): " );
    scanf("%c", &userInput);
    printf("\n");
 
    if(userInput != 'Y' && userInput != 'y'){
        printf("Goodbye!\n");
        return 0;
    }
    else{
        bool board[SIZE][SIZE] = {0}; // Opret brættet
        
        printf("\nStarting greedy tour from (0,0):\n");
        int visited = tour_greedy(0, 0, board); //kører greedy funktionen
        printf("Knight visited %d squares.\n", visited);
        
        // Show the final board state
        generate_and_print_board(board);
        
        // Show results from all starting positions
        greedy_tour_from_each_square(); //printer board med antal mulige felter
    }


 return 0;
}