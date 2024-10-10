#include <stdio.h>

/**
 * @brief Funkcia na kontrolu, ci je hodnota v zadanom poli
 *
 * @param array Pole, v ktorom sa hlada hodnota
 * @param length Dlzka pola
 * @param value Hodnota, ktoru hladame
 * @return int Vrati 1, ak je hodnota v poli, inak vrati 0
 */
int is_in_array(int array[], int length, int value) {
    for (int index = 0; index < length; index++) {
        if (array[index] == value) {
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Hlavna funkcia programu
 *
 * @return int Vrati 0 pri uspesnom ukonceni programu
 */
int main(void) {
    int array1[5];
    int array2[5];

    printf("Zvolte %d cisel pre prve pole: \n", 5);
    for (int index = 0; index < 5; index++) {
        printf("Cislo %d:", index+1);
        scanf("%d", &array1[index]);
    }
    printf("Zvolte %d cisel pre druhe pole: \n", 5);
    for (int index = 0; index < 5; index++) {
        printf("Cislo %d:", index+1);
        scanf("%d", &array2[index]);
    }

    /**
     * @brief Pocitanie rovnakych hodnot medzi dvoma poliami bez duplicitnych hodnot
     */
    int same_count_without_duplicates = 0;
    for (int array1_index = 0; array1_index < 5; array1_index++) {
        for (int array2_index = 0; array2_index < 5; array2_index++) {
            if (array1[array1_index] == array2[array2_index]) {
                same_count_without_duplicates++;
                break;
            }
        }
    }
    printf("Pocet rovnakych hodnot: %d\n", same_count_without_duplicates);

    /**
     * @brief Pocitanie rovnakych hodnot medzi dvoma poliami s duplicitnymi hodnotami
     */
    same_count_without_duplicates = 0;
    for (int array1_index = 0; array1_index < 5; array1_index++) {
        int is_duplicate = 0;
        for (int previous_index = 0; previous_index < array1_index; previous_index++) {
            if (array1[previous_index] == array1[array1_index]) {
                is_duplicate = 1;
                break;
            }
        }
        if (is_duplicate) {
            continue;
        }

        for (int array2_index = 0; array2_index < 5; array2_index++) {
            if (array1[array1_index] == array2[array2_index]) {
                same_count_without_duplicates++;
                break;
            }
        }
    }
    printf("Pocet rovnakych hodnot: %d\n", same_count_without_duplicates);

    /**
     * @brief Pocitanie rovnakych hodnot medzi dvoma poliami s duplicitnymi hodnotami a volanim funkcie
     */
    same_count_without_duplicates = 0;
    for (int array1_index = 0; array1_index < 5; array1_index++) {
        if (is_in_array(array1, array1_index, array1[array1_index])) {
            continue;
        }

        if (is_in_array(array2, 5, array1[array1_index])) {
            same_count_without_duplicates++;
        }
    }
    printf("Pocet rovnakych hodnot: %d\n", same_count_without_duplicates);

    return 0;
}