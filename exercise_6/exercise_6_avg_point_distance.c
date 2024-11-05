#include <stdio.h>
#include <math.h>

/**
 * @brief Struktura pre bod.
 */
typedef struct {
    int x;
    int y;
} Point;

/**
 * @brief Spocita priemernu vzdialenost vsetkych bodov mnoziny.
 *
 * @param points Ukazovatel na pole bodov
 * @param length Dlzka pola
 * @return double Priemerna vzdialenost
 */
double average_distance(Point *points, size_t length) {
    double total_distance = 0.0;
    for (size_t i = 0; i < length; i++) {
        for (size_t j = i + 1; j < length; j++) {
            double distance = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2));
            total_distance += distance;
        }
    }
    return total_distance / (length * (length - 1) / 2);
}

int main() {
    size_t length;
    printf("Zadajte pocet bodov: ");
    scanf("%zu", &length);

    Point points[length];
    printf("Zadajte suradnice bodov (x y) po kazdom bode stlacte Enter:\n");
    for (size_t i = 0; i < length; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    double avg_distance = average_distance(points, length);
    printf("Priemerna vzdialenost je: %.2f\n", avg_distance);

    return 0;
}



