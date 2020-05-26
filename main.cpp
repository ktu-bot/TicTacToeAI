#include <iostream>
#include <string>
#include <stdlib.h>

#define GRID_SIZE 3

using namespace std;

class Game{

    private:
        char grid[GRID_SIZE][GRID_SIZE];


    public:

    void check_for_wins() {

        const char* winning_moves[8] = {
            "123",
            "456",
            "789",
            "147",
            "258",
            "369",
            "159",
            "753",
        };

        for (int i = 0; i < 8; i++) {

            bool winner = true;
            char previous_grid = '0';
            const char* winning_move = winning_moves[i];

            for (int index = 0; index < 3; index++) {
                char character = winning_move[index];

                int entered_number = character - '0';
                int grid_space = entered_number - 1;

                int row = grid_space / GRID_SIZE;
                int col = grid_space % GRID_SIZE;

                char grid_char = grid[row][col];

                if (previous_grid == '0') {
                    previous_grid = grid_char;
                } else if (previous_grid == grid_char) {
                    continue;
                } else {
                    winner = false;
                    break;
                }

            }

            if (winner) {
                puts("WINNER WINNER CHICKEN DINNER!!!!");
                printf("%c has won! Congratulations!\n", previous_grid);

                exit(0);
                break;
            }


        }

    }

    void ask_turn(){

        string input;

        while (true) {

            puts("Where would you like to play?");
            getline(cin, input);

            if (input != "") {
                char entered = input.c_str()[0];

                if (entered >= '1' && entered <= '9') {
                    int entered_number = entered - '0';
                    int index = entered_number - 1;

                    int row = index / 3;
                    int col = index % 3;

                    char grid_position = grid[row][col];

                    if (grid_position == 'X' || grid_position == 'O') {
                        puts("That position is already taken!");
                    } else {
                        grid[row][col] = 'X';
                        break;
                    }
                } else {
                    puts("You have to enter a number from 1-9");
                }
            } else {
                puts("You must enter something!");
            }
        }
    }

    int winning_moves() {
        const char* winning_moves[8] = {
            "123",
            "456",
            "789",
            "147",
            "258",
            "369",
            "159",
            "753",
        };

        for (int i = 0; i < 8; i++) {
            int encounterd = 0;
            const char* winning_move = winning_moves[i];

            for (int index = 0; index < 3; index++) {
                char character = winning_move[index];

                int entered_number = character - '0';
                int grid_space = entered_number - 1;

                int row = grid_space / GRID_SIZE;
                int col = grid_space % GRID_SIZE;

                char grid_char = grid[row][col];

                if (grid_char == 'O') {
                    encounterd++;
                } 
                
                if (encounterd == 2) {
                    cout<< "encountered 2" << endl;
                    for (int j = 0; j < 3; j++) {
                        char character0 = winning_move[j];

                        int entered_number0 = character0 - '0';
                        int grid_space0 = entered_number0 - 1;

                        int row = grid_space0 / GRID_SIZE;
                        int col = grid_space0 % GRID_SIZE;

                        char grid_char0 = grid[row][col];

                        if (grid_char0 != 'O' && grid_char0 != 'X') return entered_number0;
                    
                    }
                }
            }
        }
            cout<< "returned 0" << endl;  
            return 0;
    }

    int block_wins() {
       
        const char* winning_moves[8] = {
            "123",
            "456",
            "789",
            "147",
            "258",
            "369",
            "159",
            "753",
        };

        for (int i = 0; i < 8; i++) {
            int encounterd = 0;
            const char* winning_move = winning_moves[i];

            for (int index = 0; index < 3; index++) {
                char character = winning_move[index];

                int entered_number = character - '0';
                int grid_space = entered_number - 1;

                int row = grid_space / GRID_SIZE;
                int col = grid_space % GRID_SIZE;

                char grid_char = grid[row][col];

                if (grid_char == 'X') {
                    encounterd++;
                } 
                
                if (encounterd == 2) {
                    cout<< "encountered 2" << endl;
                    for (int j = 0; j < 3; j++) {
                        char character0 = winning_move[j];

                        int entered_number0 = character0 - '0';
                        int grid_space0 = entered_number0 - 1;

                        int row = grid_space0 / GRID_SIZE;
                        int col = grid_space0 % GRID_SIZE;

                        char grid_char0 = grid[row][col];

                        if (grid_char0 != 'O' && grid_char0 != 'X') return entered_number0;
                    
                    }
                }
            }
        }
            cout<< "returned 0" << endl;  
            return 0;
    }

    void computer_player_turn(){
        
        int computer_choice;
        const char* spots[1] = {"513792468"};
        int count = 0;

        while (true) {
            if (winning_moves() != 0) {
                computer_choice = winning_moves();
                cout<< "get win" << computer_choice << endl;
            } else if (block_wins() != 0) {
                computer_choice = block_wins();
            } else {

                const char* b = spots[0];
                char a = b[count]; 
                int entered_number = a - '0';
                count++;
                computer_choice = entered_number;
            }
                
            int row = (computer_choice - 1) / 3;
            int col = (computer_choice - 1) % 3;

            char grid_position = grid[row][col];

            if (grid_position == 'X' || grid_position == 'O') {
                continue;
            } else {
                printf("The computer will play at %d. \n", computer_choice);
                grid[row][col] = 'O';
                break;
            }
        }
        
    }


    void full_board() {
         for (int i = 0; i < 8; i++) {
            int row = i / GRID_SIZE;
            int col = i % GRID_SIZE;

            char grid_char = grid[row][col];

            if (grid_char != 'O' || grid_char != 'X') {
                return;
            } 
        }

            cout<< "Good game! It's a draw!" <<endl;
            return;
    }


    void generate_grid() {
        
    int number = 1;
        for (int x = 0; x < GRID_SIZE; x++) {

            for (int y = 0; y < GRID_SIZE; y++) {
                grid[x][y] = to_string(number).c_str()[0];
                number += 1;
            }
        }
    }

    void show_grid() {
        
        for (int x = 0; x < GRID_SIZE; x++) {
             printf("|");
            for (int y = 0; y < GRID_SIZE; y++) {
                printf(" %c |", grid[x][y]);
            }
            printf("\n-------------\n");
        }
    }

    Game() {
        generate_grid();
        show_grid();
        check_for_wins();
        while (true) {
            ask_turn();
            check_for_wins();
            full_board();
            
            computer_player_turn();
            show_grid();
            check_for_wins();
            full_board();
        }
        show_grid();
    }

};

int main (int argc, char *argv[]) {

    Game game;

    return 0;
}