#include <stdio.h>
/**
 * @brief Vypočíta n-té Fibonacciho číslo pomocou rekurzie.
 * Vzorec:
 * - F(n) = F(n-1) + F(n-2) pre n > 1
 * - F(0) = 0
 * - F(1) = 1
 * @param n Poradie Fibonacciho čísla.
 * @return n-té Fibonacciho číslo.
 */
int fibonacci(int n) {
    // Implementácia funkcie
}

/**
 * @brief Vypočíta faktoriál daného čísla pomocou rekurzie.
 * Vzorec:
 * - n! = n * (n-1)! pre n > 0
 * - 0! = 1
 * @param n Číslo, ktorého faktoriál sa má vypočítať.
 * @return Faktoriál čísla n.
 */
int factorial(int n) {
    // Implementácia funkcie
}

/**
 * @brief Vypočíta Ackermanovu funkciu daného čísla pomocou rekurzie.
 * Vzorec:
 * - A(m, n) = n + 1 ak m = 0
 * - A(m, n) = A(m-1, 1) ak m > 0 a n = 0
 * - A(m, n) = A(m-1, A(m, n-1)) ak m > 0 a n > 0
 * @param m Prvý parameter Ackermanovej funkcie.
 * @param n Druhý parameter Ackermanovej funkcie.
 * @return Hodnota Ackermanovej funkcie pre dané m a n.
 */
int ackermann(int m, int n) {
    // Implementácia funkcie
}

int main() {
    int n = 5;
    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
    printf("Factorial(%d) = %d\n", n, factorial(n));
    printf("Ackermann(2, %d) = %d\n", n, ackermann(2, n));
    return 0;
}