#include <stdio.h>
#include <stddef.h>

/**
 * @brief Vrati adresu hodnoty medianu v nacitanom poli zoradenych celych cisel neparnej dlzky alebo NULL.
 *
 * @param arr Ukazovatel na pole
 * @param length Dlzka pola
 * @return int* Adresa medianu alebo NULL
 */
int* find_median(int *arr, size_t length) {
    if (length == 0 || length % 2 == 0) return NULL;

    for (size_t i = 1; i < length; i++) {
        if (arr[i] < arr[i - 1]) return NULL;
    }

    return &arr[length / 2];
}

int main() {
    size_t length;
    printf("Zadajte pocet prvkov pola: ");
    scanf("%zu", &length);

    if (length == 0) {
        printf("Error - Pole je prazdne.\n");
        return 1;
    }
    else if (length % 2 == 0) {
        printf("Error - Pole ma parnu dlzku.\n");
        return 1;
    }

    int arr[length];
    printf("Zadajte prvky pola: ");
    for (size_t i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }

    int *median = find_median(arr, length);
    if (median) {
        printf("Median je: %d\n", *median);
    } else {
        printf("Error - Pole nie je zoradene.\n");
    }
    return 0;
}