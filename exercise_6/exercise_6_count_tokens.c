#include <stdio.h>
#include <ctype.h>

/**
 * @brief Zisti pocet pismen, slov a viet v retazci pomocou ukazovatelov.
 * 
 * @param str Ukazovatel na retazec
 * @param letters Ukazovatel na pocet pismen
 * @param words Ukazovatel na pocet slov
 * @param sentences Ukazovatel na pocet viet
 */
void count_elements(const char *str, int *letters, int *words, int *sentences) {
    *letters = *words = *sentences = 0;
    int in_word = 0;

    while (*str) {
        if (isalpha(*str)) {
            (*letters)++;
            in_word = 1;
        } else if (isspace(*str)) {
            if (in_word) {
                (*words)++;
                in_word = 0;
            }
        } else if (*str == '.') {
            (*sentences)++;
            if (in_word) {
                (*words)++;
                in_word = 0;
            }
        }
        str++;
    }
}

int main() {
    char text[101];
    printf("Zadajte retazec: ");
    scanf("%100[^\n]", text);

    int letters, words, sentences;
    count_elements(text, &letters, &words, &sentences);
    printf("Pocet pismen: %d\n", letters);
    printf("Pocet slov: %d\n", words);
    printf("Pocet viet: %d\n", sentences);
    return 0;
}