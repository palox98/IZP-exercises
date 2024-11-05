#include <stdio.h>

/**
 * @brief Vrati N cisel danej parity s danym pociatocnym prvkom.
 * 
 * @param start Pociatocny prvok
 * @param n Pocet cisel
 * @param parity Parita (0 pre parne, 1 pre neparne)
 * @param result Pole pre vysledne cisla
 * @return int 1 ak je pociatocny prvok kompatibilny s paritou, inak 0
 */
int generate_numbers(int start, int n, int parity, int result[]) {
    if (start % 2 != parity) {
        printf("Pociatocny prvok nie je kompatibilny s paritou.\n");
        return 0;
    }

    int count = 0;
    while (count < n) {
        if (start % 2 == parity) {
            result[count++] = start;
        }
        start++;
    }
    return 1;
}

int main() {
    int start, n, parity;

    printf("Zadajte pociatocny prvok: ");
    scanf("%d", &start);

    printf("Zadajte pocet cisel: ");
    scanf("%d", &n);

    printf("Zadajte paritu (0 pre parne, 1 pre neparne): ");
    scanf("%d", &parity);

    int result[n];
    if (generate_numbers(start, n, parity, result)) {
        printf("Generovane cisla: \n");
        for (int i = 0; i < n; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }

    return 0;
}