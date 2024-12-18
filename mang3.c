#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int mitukohta = 0;
    int kaik, arvuti, i, current_position = 0;

    // Get board size from the user
    printf("Sisesta mitu kohta mängulaual: ");
    scanf("%d", &mitukohta);

    // Initialize the game board
    char mangulaud[mitukohta];
    for (i = 0; i < mitukohta; i++) {
        mangulaud[i] = '_';
    }

    mangulaud[current_position] = 'X';

    // Seed the random number generator for the computer's move
    srand(time(NULL));

    // Game loop
    while (current_position < mitukohta - 1) {
        // Print the current board state
        for (i = 0; i < mitukohta; i++) {
            printf("%c", mangulaud[i]);
        }
        printf("\n");

        // USER TURN
        printf("Mitu käiku teed? 1 või 2: ");
        scanf("%d", &kaik);

        // Validate user input
        if (kaik != 1 && kaik != 2) {
            printf("Vale käik, palun sisesta 1 või 2.\n");
            continue;
        }

        // Move the 'X' for the user
        mangulaud[current_position] = '_';
        current_position += kaik;

        // Prevent moving out of bounds
        if (current_position >= mitukohta) {
            current_position = mitukohta - 1;
        }

        mangulaud[current_position] = 'X';

        // Check if the user won
        if (current_position == mitukohta - 1) {
            printf("Palju õnne! Sina võitsid!\n");
            break;
        }

        // Print the updated board after user move
        for (i = 0; i < mitukohta; i++) {
            printf("%c", mangulaud[i]);
        }
        printf("\n");

        // COMPUTER TURN
        arvuti = rand() % 2 + 1;  // Random move: 1 or 2 steps

        printf("Arvuti käik: %d\n", arvuti);

        mangulaud[current_position] = '_';
        current_position += arvuti;

        // Prevent moving out of bounds
        if (current_position >= mitukohta) {
            current_position = mitukohta - 1;
        }

        mangulaud[current_position] = 'X';

        // Check if the computer won
        if (current_position == mitukohta - 1) {
            printf("Arvuti võitis! Proovi uuesti.\n");
            break;
        }
    }

    // Final board state
    for (i = 0; i < mitukohta; i++) {
        printf("%c", mangulaud[i]);
    }
    printf("\n");

    return 0;
}
