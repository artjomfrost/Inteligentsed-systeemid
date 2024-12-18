#include <stdio.h>

int main(void) {
    int mitukohta = 0;
    int kaik, arvuti = 0;
    int i, current_position = 0;

    printf("Sisesta mitu kohta mängulaual: ");
    scanf("%d", &mitukohta);

    char mangulaud[mitukohta];
    for (i = 0; i < mitukohta; i++) {
        mangulaud[i] = '_';
    }

    mangulaud[current_position] = 'X';

    for (i = 0; i < mitukohta; i++) {
        printf("%c", mangulaud[i]);
    }
    printf("\n");

    printf("Mitu käiku teed? 1 või 2: ");
    scanf("%d", &kaik);

    if (kaik == 1 || kaik == 2) {
        mangulaud[current_position] = '_';
        current_position += kaik;

        if (current_position >= mitukohta) {
            current_position = mitukohta - 1;
        }

        mangulaud[current_position] = 'X';


    } else {
        printf("Vale käik, palun sisesta 1 või 2.\n");
    }

    for (i = 0; i < mitukohta; i++) {
        printf("%c", mangulaud[i]);
    }

    if ((mitukohta - current_position + 1) % 2 == 0){
        mangulaud[current_position] = '_';
        current_position += 2;
    } else {
        
        mangulaud[current_position] = '_';
        current_position += 1;

    }
    printf("%d\n", current_position);
    mangulaud[current_position] = 'X';
    
    for (i = 0; i < mitukohta; i++) {
        printf("%c", mangulaud[i]);
    }
    printf("\n");
    printf("%d\n", current_position);

    

    return 0;
}
