#include <stdio.h>

/**
 * @brief Skontrolujte, ci je znak abecedny
 *
 * @param character Znak na kontrolu
 * @return int Vrati 1, ak je znak abecedny, inak vrati 0
 */
int is_alpha(char character) {
    // Je možné použiť aj int hodnoty z ascii tabulky
    return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z');
}

/**
 * @brief Skontrolujte, ci zadane meno obsahuje iba abecedne znaky
 *
 * @param array Pole znakov (retazec), ktore predstavuje meno
 * @return int Vrati 1, ak meno obsahuje iba abecedne znaky, inak vrati 0
 */
int is_name(char array[]) {
    int index = 0;
    while(array[index] != '\0') {
        if (!is_alpha(array[index])) {
            return 0;
        }
        index++;
    }
    return 1;
}

/**
 * @brief Hlavna funkcia programu
 *
 * @return int Vrati 0 pri uspesnom ukonceni programu
 */
int main() {
    char name[21];
    char surname[21];
    printf("===Solution 4_1===\n");
    printf("Prosim, zadajte svoje meno: \n");
    scanf("%20s", name);
    // Ak meno obsahuje neabecedne znaky, skonci chybou
    if(!is_name(name)) {
        printf("Chyba - Zadane meno obsahuje neabecedne znaky!\n");
        return -1;
    }
    printf("Prosim, zadajte svoje priezvisko: \n");
    scanf("%20s", surname);
    // Ak priezvisko obsahuje neabecedne znaky, skonci chybou
    if(!is_name(surname)) {
        printf("Chyba - Zadane priezvisko obsahuje neabecedne znaky!\n");
        return -1;
    }
    printf("Vase cele meno je: %s %s\n", name, surname);
    return 0;
}