#include <stdio.h>

int main(void) {
    int mitukohta = 0;
    int kaik = 0;
    int i;

    printf("Sisesta mitu kohta mängulaual: ");
    scanf("%d", &mitukohta);

    printf("Mitu käiku teed? 1 või 2: ");
    scanf("%d", &kaik);

    int mangulaud[mitukohta];

    for (i = 0; i < mitukohta; i++) {
        mangulaud[i] = '_';
    }

    for (i = 1; i <= kaik; i++) {
        int koht = i + kaik;
            mangulaud[koht] = 'X';
    }

    for (i = 0; i < mitukohta; i++) {
        printf("%c", mangulaud[i]);
    }
    printf("\n");
    printf("Mitu käiku teed? 1 või 2: ");
    scanf("%d", &kaik);

    return 0;
}
