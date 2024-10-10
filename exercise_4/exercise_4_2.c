#include <stdio.h>

/**
 * @brief Funkcia na najdenie maximalnej hodnoty v zadanom poli celych cisel
 *
 * @param array Pole, v ktorom sa hlada maximalna hodnota
 * @param array_length Dlzka pola
 * @return int Vrati najdenu maximalnu hodnotu
 */
int get_max(int array[], int array_length) {
    int maximum_value = array[0];  // Nastavíme prvý prvok ako počiatočnú maximálnu hodnotu
    for (int index = 1; index < array_length; index++) {
        if (array[index] > maximum_value) {
            maximum_value = array[index];  // Ak nájdeme väčšiu hodnotu, aktualizujeme maximálnu hodnotu
        }
    }
    return maximum_value;
}

/**
 * @brief Funkcia na vypocitanie sucetu prvkov pola
 *
 * @param array Pole, v ktorom pocitame sučet
 * @param array_length Dlzka pola
 * @return int Vrati sucet prvkov pola
 */
int get_sum(int array[], int array_length) {
    int sum = 0;
    for (int index = 0; index < array_length; index++) {
        sum += array[index];  // Pripočítame každý prvok k súčtu
    }
    return sum;
}

/**
 * @brief Funkcia na kontrolu, ci vsetky hodnoty v prvom poli su mensie ako hodnoty na zodpovedajucich indexoch v druhom poli
 *
 * @param array1 Prve pole
 * @param array2 Druhe pole
 * @param array_length Dlzka pola
 * @return int Vrati 1, ak su vsetky hodnoty v prvom poli mensie, inak vrati 0
 */
int smaller_than(int array1[], int array2[], int array_length) {
    for (int index = 0; index < array_length; index++) {
        if (array1[index] >= array2[index]) {
            return 0;  // Ak nájdeme prvok, ktorý nie je menší, vrátime 0 (nepravda)
        }
    }
    return 1;  // Ak sú všetky prvky menšie, vrátime 1 (pravda)
}

/**
 * @brief Hlavna funkcia programu
 *
 * @return int Vrati 0 pri uspesnom ukonceni programu
 */
int main() {
    int array1[5];

    printf("Prosim, zadajte pat cisel: \n");
    for (int index = 0; index < 5; index++) {
        printf("Cislo %d:", index+1);
        scanf("%d", &array1[index]);
    }

    int maximum_value = get_max(array1, 5);
    printf("Maximalna hodnota v poli: %d\n", maximum_value);
    printf("Suctet hodnot v poli: %d\n", get_sum(array1, 5));

    int array2[5];
    printf("Prosim, zadajte dalsich pat cisel: \n");
    for (int index = 0; index < 5; index++) {
        printf("Cislo %d:", index+1);
        scanf("%d", &array2[index]);
    }

    if (smaller_than(array1, array2, 5))
        printf("Prve pole je mensie ako druhe.\n");
    else
        printf("Prve pole nie je mensie ako druhe.\n");

    return 0;
}
