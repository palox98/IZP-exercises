#include <stdio.h>

/**
 * @brief Zisti dlzku retazca vyuzitim ukazovatelov.
 * 
 * @param str Ukazovatel na retazec
 * @return size_t Dlzka retazca
 */
size_t str_length(const char *str) {
    const char *s = str;
    while (*s) {
        s++;
    }
    return s - str;
}

int main() {
    char str[100];
    printf("Zadajte retazec ktoreho dlzku chcete zistit: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Nepodarilo sa nacitat retazec zo standardneho vstupu.\n");
        return 1;
    }

    size_t length = str_length(str);
    printf("Dlzka retazca je: %zu\n", length);
    return 0;
}