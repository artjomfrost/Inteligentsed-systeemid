#include <stdio.h>

int main(void) {
    int A, B, C, D, i;
    int leitudPaar[100][4];

    A = 0;
    B = 0;
    C = 0;
    D = 0;

    for(i = 0; i < 8; i++) {
        A = i; 
        B = 5 - A; 
        C = 6 - A;
        D = 8 - A;

        if(A + B == 5 && A + C == 6 && C + D == 8 && B + D == 7) {
            leitudPaar[i][0] = A;
            leitudPaar[i][1] = B;
            leitudPaar[i][2] = C;
            leitudPaar[i][3] = D;
        }

        printf("Võimalik paar: A = %d, B = %d, C = %d, D = %d\n", A, B, C, D);
    }

    return 0;
}
