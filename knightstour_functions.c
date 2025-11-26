#include "KnightsTour.h"

void generate_and_print_board(bool board[SIZE][SIZE]){ //Parametre for funktionen w og h er width og height
    for (int row = 0; row < SIZE; row++) { // Generer rows
        for (int column = 0; column < SIZE; column++) // Generer columns 
            printf("%d%d ", row, column); //printer rows og columns 
        printf("\n"); // Ny linje efter hver række på boardet
    }
}

const int MOVES_X[MOVE_COUNT] = {2, 1, -1, -2, -2, -1, 1, 2}; // Possible moves in x direction 
const int MOVES_Y[MOVE_COUNT] = {1, 2, 2, 1, -1, -2, -2, -1}; // Possible moves in y direction 

bool make_a_move(size_t move_id, int x,int y, bool board[SIZE][SIZE]){ //parametre for funktionen move_id angiver hvilket af springerens træk der skal udføres

    int new_x = x + MOVES_X[move_id]; // Beregner ny position af springer ud fra hvilket træk fra array der er udført
    int new_y = y + MOVES_Y[move_id]; // 
    if (new_x >= 0 && new_x < SIZE && new_y >= 0 && new_y < SIZE && board[new_x][new_y] == false){ //new < size sørger for at vi er inde for brættets grænser, new >= 0 sikrer at vi ikke får negative koordinater, board = false sikrer at feltet ikke er besøgt
        board[new_x][new_y] = true; //udfører trækket
        return true;
    } else {
        return false; //udfører ikke trækket
    }

}

int tour_greedy(size_t start_x, size_t start_y, bool board[SIZE][SIZE]) { //startposition på boardet
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            board[i][j] = false; //Alle felter sættes til "ikke besøgt"

    int current_x = start_x; // Ændrer startposition til den nye position efter et move er udført
    int current_y = start_y;
    board[current_x][current_y] = true; //Markerer et felt som besøgt
    int visited = 1; // Starter tæller for antal besøgte felter

    while (true) {
        int found_move = 0; // Til at kontrollere om vi har et gyldigt træk
        for (size_t move_id = 0; move_id < MOVE_COUNT; move_id++) { //prøver alle mulige træk i rækkefølge
            if (make_a_move(move_id, current_x, current_y, board)) { //Prøver at udføre træk nr move_id fra nuværende position
                current_x += MOVES_X[move_id]; //opdaterer position
                current_y += MOVES_Y[move_id]; //opdaterer position
                visited++; //øger tæller for antal af besøgte felter
                found_move = 1; //Sikrer at kun 1 træk bliver udført
                break;
            }
        }
        if (!found_move) //Bryder ud af løkken hvis der ikke er nogle mulige træk
            break;
    }
    return visited; //returnerer det samlede antal felter springeren har besøgt
}

void greedy_tour_from_each_square() { //Beregner for hver startposition hvor mange felter springeren kan besøge
    bool board[SIZE][SIZE]; //Opretter brættet
    printf("\nGreedy:\n");
    for(int i = 0; i < SIZE; i++) { //Gennemgår alle felter
        for(int j = 0; j < SIZE; j++) { //Gennemgår alle felter
            int can_visit = tour_greedy(i, j, board); //bruger tour_greedy med startposition i og j på brættet, can_visit giver antallet af felter der kan besøges fra denne position 
            printf("%2d ", can_visit); //Printer boardet med antal mulige felter 
        }
        printf("\n");
    }
}

