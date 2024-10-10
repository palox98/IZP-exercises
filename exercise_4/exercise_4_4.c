#include <stdio.h>

/**
 * @brief Skontrolujte, ci je hodnota v zadanom mnozine
 * 
 * @param set Pole reprezentujuce mnozinu
 * @param length Dlzka pola
 * @param value Hodnota na kontrolu
 * @return int Vrati 1, ak je hodnota v mnozine, inak vrati 0
 */
int is_in_set(int set[], int length, int value) {
    for (int index = 0; index < length; index++) {
        if (set[index] == value) {
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Skontrolujte, ci pole predstavuje mnozinu, t.j. ci kazda hodnota je jedinecna
 * 
 * @param set Pole reprezentujuce mnozinu
 * @param length Dlzka pola
 * @return int Vrati 1, ak pole predstavuje mnozinu, inak vrati 0
 */
int is_set(int set[], int length) {
    for (int outerIndex = 0; outerIndex < length; outerIndex++) {
        for (int innerIndex = 0; innerIndex < length; innerIndex++) {
            if (outerIndex == innerIndex) {
                continue;
            } else if (set[outerIndex] == set[innerIndex]) {
                return 0;
            }
        }
    }
    return 1;
}

/**
 * @brief Skontrolujte, ci pole je efektivnou reprezentaciou mnoziny, t.j. ci kazda hodnota je jedinecna a hodnoty su zoradene
 *
 * @param set Pole reprezentujuce mnozinu
 * @param length Dlzka pola
 * @return int Vrati 1, ak pole je efektivnou reprezentaciou mnoziny, inak vrati 0
 */
int is_sorted_set(int set[], int length) {
    for (int index = 1; index < length; index++) {
        if (set[index - 1] >= set[index]) {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Vypiste prienik dvoch mnozin efektivnym sposobom
 *
 * @param set1 Prva mnozina
 * @param set2 Druha mnozina
 * @param set1_length Dlzka prvej mnoziny
 * @param set2_length Dlzka druhej mnoziny
 */
void print_intersection_efficient(int set1[], int set2[], int set1_length, int set2_length) {
    int first_print = 1;
    printf("{");
    for (int set1Index = 0, set2Index = 0; set1Index < set1_length && set2Index < set2_length; ) {
        if (set1[set1Index] == set2[set2Index]) {
            if (!first_print) {
                printf(", ");
            }
            printf("%d", set1[set1Index]);
            first_print = 0;
            set1Index++;
            set2Index++;
        } else if (set1[set1Index] > set2[set2Index]) {
            set2Index++;
        } else {
            set1Index++;
        }
    }
    printf("}\n");
}

/**
 * @brief Vypiste zjednotenie dvoch mnozin efektivnym sposobom
 *
 * @param set1 Prva mnozina
 * @param set2 Druha mnozina
 * @param set1_length Dlzka prvej mnoziny
 * @param set2_length Dlzka druhej mnoziny
 */
void print_union_efficient(int set1[], int set2[], int set1_length, int set2_length) {
    int first_print = 1;
    printf("{");
    for (int set1Index = 0, set2Index = 0; set1Index < set1_length || set2Index < set2_length; ) {
        if ((set1Index == set1_length && set2Index < set2_length) || set1[set1Index] > set2[set2Index]) {
            if (!first_print) {
                printf(", ");
            }
            printf("%d", set2[set2Index]);
            first_print = 0;
            set2Index++;
        } else if ((set2Index == set2_length && set1Index < set1_length) || set1[set1Index] < set2[set2Index]) {
            if (!first_print) {
                printf(", ");
            }
            printf("%d", set1[set1Index]);
            first_print = 0;
            set1Index++;
        } else {
            if (!first_print) {
                printf(", ");
            }
            printf("%d", set1[set1Index]);
            first_print = 0;
            set1Index++;
            set2Index++;
        }
    }
    printf("}\n");
}

/**
 * @brief Vypiste kartezsky sucin dvoch mnozin
 *
 * @param set1 Prva mnozina
 * @param set2 Druha mnozina
 * @param set1_length Dlzka prvej mnoziny
 * @param set2_length Dlzka druhej mnoziny
 */
void print_product(int set1[], int set2[], int set1_length, int set2_length) {
    int first_print = 1;
    printf("{");
    for (int set1Index = 0; set1Index < set1_length; set1Index++) {
        for (int set2Index = 0; set2Index < set2_length; set2Index++) {
            if (!first_print) {
                printf(", ");
            }
            printf("(%d, %d)", set1[set1Index], set2[set2Index]);
            first_print = 0;
        }
    }
    printf("}\n");
}

/**
 * @brief Hlavna funkcia programu
 *
 * @return int Vrati 0 pri uspesnom ukonceni programu
 */
int main() {
    int set1[5];
    int set2[5];

    printf("Prosim, zadajte mnozinu (%d cisel): \n", 5);
    for (int index = 0; index < 5; index++) {
        scanf("%d", &set1[index]);
        if (index == 0) printf("Mnozina 1 = {");
        printf("%d", set1[index]);
        if (index < 4) printf(", ");
        else printf("}\n");
    }


    if (!is_set(set1, 5)) {
        printf("Chyba: mnozina obsahuje duplicitne hodnoty!\n");
        return 1;
    }

    printf("Prosim, zadajte mnozinu (%d cisel): \n", 5);
    for (int index = 0; index < 5; index++) {
        scanf("%d", &set2[index]);
        if (index == 0) printf("Mnozina 2 = {");
        printf("%d", set2[index]);
        if (index < 4) printf(", ");
        else printf("}\n");
    }


    if (!is_set(set2, 5)) {
        printf("Chyba: mnozina obsahuje duplicitne hodnoty!\n");
        return 1;
    }

    if (!is_sorted_set(set1, 5)) {
        printf("Chyba: mnozina obsahuje duplicitne hodnoty alebo nie je zoradena!\n");
        return 1;
    }
    if (!is_sorted_set(set2, 5)) {
        printf("Chyba: mnozina obsahuje duplicitne hodnoty alebo nie je zoradena!\n");
        return 1;
    }
    printf("Efektivny prienik: ");
    print_intersection_efficient(set1, set2, 5, 5);

    printf("Efektivne zjednotenie: ");
    print_union_efficient(set1, set2, 5, 5);

    printf("Sucin mnozin: ");
    print_product(set1, set2, 5, 5);

    return 0;
}