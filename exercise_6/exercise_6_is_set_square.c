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
 * @brief Zisti, ci zadana mnozina tvori stvorec.
 *
 * @param points Ukazovatel na pole bodov
 * @return int 1 ak tvori stvorec, inak 0
 */
int is_square(Point *points) {
    double distances[6];
    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            distances[k++] = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2));
        }
    }
    double side = distances[0];
    int side_count = 0, diagonal_count = 0;
    for (int i = 0; i < 6; i++) {
        if (fabs(distances[i] - side) < 1e-6) {
            side_count++;
        } else {
            diagonal_count++;
        }
    }
    return (side_count == 4 && diagonal_count == 2);
}

int main() {
    size_t length;
    printf("Zadajte pocet bodov: ");
    scanf("%zu", &length);
    if (length != 4) {
        printf("Pocet bodov musi byt 4.\n");
        return 1;
    }
    Point points[4];
    printf("Zadajte suradnice 4 bodov (x y) po kazdom bode stlacte Enter:\n");
    for (size_t i = 0; i < 4; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    if (is_square(points)) {
        printf("Mnozina tvori stvorec.\n");
    } else {
        printf("Mnozina netvori stvorec.\n");
    }
    return 0;
}