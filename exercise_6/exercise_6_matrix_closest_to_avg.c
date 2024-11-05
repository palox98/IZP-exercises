#include <stdio.h>
#include <math.h>

/**
 * @brief Vrati adresu prvku matice, ktory je najblizsi priemeru vsetkych prvkov matice.
 * 
 * @param matrix Ukazovatel na maticu
 * @param rows Pocet riadkov
 * @param cols Pocet stlpcov
 * @return int* Adresa prvku najblizsieho priemeru
 */
int* closest_to_average(int matrix[][100], size_t rows, size_t cols) {
    if (rows == 0 || cols == 0) return NULL;

    int sum = 0, count = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            sum += matrix[i][j];
            count++;
        }
    }

    double average = (double)sum / count;
    int *closest = &matrix[0][0];
    double min_diff = fabs(matrix[0][0] - average);

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            double diff = fabs(matrix[i][j] - average);
            if (diff < min_diff) {
                min_diff = diff;
                closest = &matrix[i][j];
            }
        }
    }
    return closest;
}

int main() {
    size_t rows, cols;
    printf("Zadajte pocet riadkov a stlpcov matice: ");
    scanf("%zu %zu", &rows, &cols);

    int matrix[100][100];
    printf("Zadajte prvky matice (po kazdom riadku stlacte Enter):\n");
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int *closest = closest_to_average(matrix, rows, cols);
    if (closest) {
        printf("Prvok najblizsi priemeru je: %d\n", *closest);
    }
    return 0;
}