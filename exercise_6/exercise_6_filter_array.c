#include <stdio.h>

/**
 * @brief Vrati pole prvkov na zaklade danej operacie (> , = , < , >= , <= , !=).
 * 
 * @param arr Ukazovatel na pole
 * @param length Dlzka pola
 * @param value Dana hodnota
 * @param operation Operacia ('>', '=', '<', '>=', '<=', '!=')
 * @param result Pole pre vysledne prvky
 * @param out_length Ukazovatel na dlzku vystupneho pola
 */
void filter_elements(int *arr, size_t length, int value, char operation[], int *result, size_t *out_length) {
    *out_length = 0;
    for (size_t i = 0; i < length; i++) {
        if ((operation[0] == '>' && operation[1] == '\0' && arr[i] > value) ||
            (operation[0] == '=' && operation[1] == '\0' && arr[i] == value) ||
            (operation[0] == '<' && operation[1] == '\0' && arr[i] < value) ||
            (operation[0] == '>' && operation[1] == '=' && arr[i] >= value) ||
            (operation[0] == '<' && operation[1] == '=' && arr[i] <= value) ||
            (operation[0] == '!' && operation[1] == '=' && arr[i] != value)) {
            result[(*out_length)++] = arr[i];
        }
    }
}

int main() {
    size_t length;
    printf("Zadajte pocet prvkov pola: ");
    scanf("%zu", &length);

    int arr[length];
    printf("Zadajte prvky pola: ");
    for (size_t i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }

    int value;
    char operation[3];
    printf("Zadajte hodnotu: ");
    scanf("%d", &value);
    printf("Zadajte operaciu ('>', '=', '<', '>=', '<=', '!='): ");
    scanf("%s", operation);

    int result[length];
    size_t out_length;
    filter_elements(arr, length, value, operation, result, &out_length);

    printf("Prvky splnajuce podmienku %s %d: \n", operation, value);
    for (size_t i = 0; i < out_length; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}