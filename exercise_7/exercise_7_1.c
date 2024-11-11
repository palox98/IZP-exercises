#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Alokuje nové pole celých čísel a naplní ho násobkom dvoch vstupných polí rovnakej dĺžky.
 *
 * @param arr1 Prvé vstupné pole.
 * @param arr2 Druhé vstupné pole.
 * @param length Dĺžka vstupných polí.
 * @return int* Ukazovateľ na nové pole alebo NULL, ak alokácia zlyhá.
 */
int* mul(int* arr1, int* arr2, int length) {
    // Alokácia pamäte pre nové pole
    int* result = (int*)malloc(length * sizeof(int));
    if (result == NULL) {
        return NULL; // Ak alokácia zlyhá, vráti NULL
    }

    // Naplnenie nového poľa násobkom prvkov vstupných polí
    for (int i = 0; i < length; i++) {
        result[i] = arr1[i] * arr2[i];
    }

    return result; // Vráti ukazovateľ na nové pole
}


/**
 * @brief Alokuje nové pole znakov a naplní ho konkatenáciou dvoch reťazcov bez použitia funkcie `strcat`.
 *
 * @param str1 Prvý vstupný reťazec.
 * @param str2 Druhý vstupný reťazec.
 * @return char* Ukazovateľ na nové pole znakov alebo NULL, ak alokácia zlyhá.
 */
char* concatenate(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int total_len = len1 + len2 + 1; // +1 pre nulový terminátor

    // Alokácia pamäte pre nové pole znakov
    char* result = (char*)malloc(total_len * sizeof(char));
    if (result == NULL) {
        return NULL; // Ak alokácia zlyhá, vráti NULL
    }

    // Skopírovanie prvého reťazca do nového poľa
    strcpy(result, str1);
    // Skopírovanie druhého reťazca do nového poľa
    strcpy(result + len1, str2);

    return result; // Vráti ukazovateľ na nové pole znakov
}

/**
 * @brief Alokuje nové pole znakov a naplní ho konkatenáciou dvoch reťazcov bez použitia funkcie `strcat`, a následne tento reťazec iteruje x-krát.
 *
 * @param str1 Prvý vstupný reťazec.
 * @param str2 Druhý vstupný reťazec.
 * @param times Počet iterácií.
 * @return char* Ukazovateľ na nové pole znakov alebo NULL, ak alokácia zlyhá.
 */
char* concatenate_and_iterate(const char* str1, const char* str2, int times) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int total_len = (len1 + len2) * times + 1; // +1 pre nulový terminátor

    // Alokácia pamäte pre nové pole znakov
    char* result = (char*)malloc(total_len * sizeof(char));
    if (result == NULL) {
        return NULL; // Ak alokácia zlyhá, vráti NULL
    }

    char* ptr = result;
    // Iterácia a konkatenácia reťazcov
    for (int i = 0; i < times; i++) {
        strcpy(ptr, str1);
        ptr += len1;
        strcpy(ptr, str2);
        ptr += len2;
    }
    *ptr = '\0'; // Pridanie nulového terminátora

    return result; // Vráti ukazovateľ na nové pole znakov
}


/**
 * @brief Štruktúra reprezentujúca dynamické pole.
 */
typedef struct {
    int *items;          // Ukazovateľ na pole položiek.
    unsigned int size;   // Aktuálny počet položiek v poli.
    unsigned int capacity; // Kapacita poľa (maximálny počet položiek, ktoré môže pole obsahovať).
} dynamic_array_t;


/**
 * @brief Vytvorí nové dynamické pole s počiatočnou kapacitou.
 *
 * @param initial_capacity Počiatočná kapacita poľa.
 * @return dynamic_array_t* Ukazovateľ na vytvorené dynamické pole alebo NULL, ak alokácia zlyhá.
 */
dynamic_array_t* create_array(unsigned int initial_capacity) {
    // Alokácia pamäte pre štruktúru dynamického poľa
    dynamic_array_t* array = (dynamic_array_t*)malloc(sizeof(dynamic_array_t));
    if (array == NULL) {
        return NULL; // Ak alokácia zlyhá, vráti NULL
    }

    // Alokácia pamäte pre položky poľa
    array->items = (int*)malloc(initial_capacity * sizeof(int));
    if (array->items == NULL) {
        free(array); // Ak alokácia zlyhá, uvoľní pamäť pre štruktúru
        return NULL;
    }

    array->size = 0; // Nastavenie počiatočnej veľkosti na 0
    array->capacity = initial_capacity; // Nastavenie počiatočnej kapacity
    return array; // Vráti ukazovateľ na vytvorené dynamické pole
}

/**
 * @brief Pridá novú položku do dynamického poľa.
 *
 * @param array Ukazovateľ na dynamické pole.
 * @param item Položka, ktorá sa má pridať.
 * @return int 1, ak sa položka úspešne pridá, inak 0.
 */
int add_item(dynamic_array_t* array, int item) {
    // Skontroluje, či je pole plné
    if (array->size == array->capacity) {
        // Zdvojnásobí kapacitu poľa
        int* new_items = (int*)realloc(array->items, array->capacity * 2 * sizeof(int));
        if (new_items == NULL) {
            return 0; // Ak alokácia zlyhá, vráti 0
        }
        array->items = new_items;
        array->capacity *= 2;
    }

    // Pridá novú položku do poľa
    array->items[array->size++] = item;
    return 1; // Vráti 1, ak sa položka úspešne pridá
}

/**
 * @brief Odstráni položku z dynamického poľa na zadanom indexe.
 *
 * @param array Ukazovateľ na dynamické pole.
 * @param index Index položky, ktorá sa má odstrániť.
 */
void remove_item(dynamic_array_t* array, unsigned int index) {
    // Skontroluje, či je index platný
    if (index < array->size) {
        // Posunie zvyšné položky doľava
        for (unsigned int i = index; i < array->size - 1; i++) {
            array->items[i] = array->items[i + 1];
        }
        array->size--; // Zníži veľkosť poľa
    }
}

/**
 * @brief Vyhľadá položku v dynamickom poli a vráti jej index.
 *
 * @param array Ukazovateľ na dynamické pole.
 * @param item Položka, ktorá sa má vyhľadať.
 * @return int Index položky, ak je nájdená, inak -1.
 */
int find_item(dynamic_array_t* array, int item) {
    // Prechádza všetky položky v poli
    for (unsigned int i = 0; i < array->size; i++) {
        if (array->items[i] == item) {
            return i; // Vráti index položky, ak je nájdená
        }
    }
    return -1; // Vráti -1, ak položka nie je nájdená
}

/**
 * @brief Uvoľní pamäť dynamického poľa a samotného poľa.
 *
 * @param array Ukazovateľ na dynamické pole.
 */
void free_array(dynamic_array_t* array) {
    if (array != NULL) {
        free(array->items); // Uvoľní pamäť pre položky
        free(array); // Uvoľní pamäť pre štruktúru poľa
    }
}


int main() {
    int choice;
    // Zobrazenie možností menu
    printf("Vyberte si ulohu (1-4):\n");
    printf("1. Nasobenie dvoch poli\n");
    printf("2. Konkatenacia dvoch retazcov\n");
    printf("3. Konkatenacia a iteracia dvoch retazcov\n");
    printf("4. Dynamicke pole\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int length;
            // Požiadanie používateľa o dĺžku polí
            printf("Zadajte dlzku poli: ");
            scanf("%d", &length);

            // Alokácia pamäte pre polia
            int *arr1 = (int*)malloc(length * sizeof(int));
            int *arr2 = (int*)malloc(length * sizeof(int));

            // Získanie prvého poľa od používateľa
            printf("Zadajte prve pole: ");
            for (int i = 0; i < length; i++) {
                scanf("%d", &arr1[i]);
            }

            // Získanie druhého poľa od používateľa
            printf("Zadajte druhe pole: ");
            for (int i = 0; i < length; i++) {
                scanf("%d", &arr2[i]);
            }

            // Násobenie polí
            int *result = mul(arr1, arr2, length);
            if (result != NULL) {
                // Vytlačenie výsledného poľa
                printf("Vysledne pole: ");
                for (int i = 0; i < length; i++) {
                    printf("%d ", result[i]);
                }
                printf("\n");
                free(result);
            }

            // Uvoľnenie alokovanej pamäte
            free(arr1);
            free(arr2);
            break;
        }
        case 2: {
            char str1[100], str2[100];
            // Získanie prvého reťazca od používateľa
            printf("Zadajte prvy retazec: ");
            scanf("%s", str1);
            // Získanie druhého reťazca od používateľa
            printf("Zadajte druhy retazec: ");
            scanf("%s", str2);

            // Konkatenácia reťazcov
            char *result = concatenate(str1, str2);
            if (result != NULL) {
                // Vytlačenie výsledného reťazca
                printf("Vysledny retazec: %s\n", result);
                free(result);
            }
            break;
        }
        case 3: {
            char str1[100], str2[100];
            int times;
            // Získanie prvého reťazca od používateľa
            printf("Zadajte prvy retazec: ");
            scanf("%s", str1);
            // Získanie druhého reťazca od používateľa
            printf("Zadajte druhy retazec: ");
            scanf("%s", str2);
            // Získanie počtu iterácií od používateľa
            printf("Zadajte pocet iteracii: ");
            scanf("%d", &times);

            // Konkatenácia a iterácia reťazcov
            char *result = concatenate_and_iterate(str1, str2, times);
            if (result != NULL) {
                // Vytlačenie výsledného reťazca
                printf("Vysledny retazec: %s\n", result);
                free(result);
            }
            break;
        }
        case 4: {
            unsigned int initial_capacity;
            // Získanie počiatočnej kapacity pre dynamické pole
            printf("Zadajte pociatocnu kapacitu dynamickeho pola: ");
            scanf("%u", &initial_capacity);

            // Vytvorenie dynamického poľa
            dynamic_array_t *array = create_array(initial_capacity);
            if (array == NULL) {
                printf("Alokacia pamate zlyhala\n");
                return 1;
            }

            int operation;
            do {
                // Zobrazenie menu operácií
                printf("Vyberte operaciu (1-pridat, 2-odstranit, 3-najst, 4-vypis, 0-koniec): ");
                scanf("%d", &operation);

                switch (operation) {
                    case 1: {
                        int item;
                        // Získanie položky na pridanie
                        printf("Zadajte polozku na pridanie: ");
                        scanf("%d", &item);
                        if (!add_item(array, item)) {
                            printf("Pridanie polozky zlyhalo\n");
                        }
                        break;
                    }
                    case 2: {
                        unsigned int index;
                        // Získanie indexu na odstránenie
                        printf("Zadajte index na odstranenie: ");
                        scanf("%u", &index);
                        remove_item(array, index);
                        break;
                    }
                    case 3: {
                        int item;
                        // Získanie položky na nájdenie
                        printf("Zadajte polozku na najdenie: ");
                        scanf("%d", &item);
                        int index = find_item(array, item);
                        if (index != -1) {
                            printf("Polozka najdena na indexe: %d\n", index);
                        } else {
                            printf("Polozka nebola najdena\n");
                        }
                        break;
                    }
                    case 4: {
                        // Vytlačenie všetkých položiek v poli
                        printf("Polozky v poli: ");
                        for (unsigned int i = 0; i < array->size; i++) {
                            printf("%d ", array->items[i]);
                        }
                        printf("\n");
                        break;
                    }
                }
            } while (operation != 0);

            // Uvoľnenie dynamického poľa
            free_array(array);
            break;
        }
        default:
            // Ošetrenie neplatnej voľby
            printf("Neplatna volba\n");
            break;
    }

    return 0;
}