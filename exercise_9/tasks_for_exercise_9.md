# Úlohy pre 9. cvičenie

- Pre úlohy 1-2 používame kostru ```person_array.c```.

- Pre úlohy 3-5 používame kostru ```recursion.c```

**Spoločne na cvičení<a name="cite_ref-1"></a>[<sup>[1]</sup>](#cite_note-1)**: Opravte kód kostry ```person_array.c```, pre identifikáciu môžete použiť valgrind (na unix systémoch), ale z komentáru by malo byť jasné, v čom je problém.

1. **Implementujte funkciu `array_find_min()`**: Nájde osobu v poli, ktorá má najmenší rok (sekundárne<a name="cite_ref-2"></a>[<sup>[2]</sup>](#cite_note-2) prvý v abecede). Hľadá minimum počnúc indexom `idx`. Ak chcete prehľadať celé pole, zadajte index 0. Použite funkciu `person_cmp`.

   **Hlavička funkcie**:
   ```c
   unsigned int array_find_min(PersonArray *a, int idx);
2. **Implementujte funkciu `array_sort()`**, ktorá zoradí osoby v poli podľa ich roku (sekundárne<a name="cite_ref-2"></a>[<sup>[2]</sup>](#cite_note-2) mena).
   
    **Hlavička funkcie**:
   ```c
   void array_sort(PersonArray *a)
3. **Implementujte funkciu `fibonacci()`** na výpočet **Fibonacciho čísel** pomocou rekurzie.
   **Hlavička funkcie**:
    ```c
    int fibonacci(int n);
    ```
   **Vzorec pre Fibonacciho čísla**:
    $$ F(n) = F(n-1) + F(n-2) \quad \text{pre} \quad n > 1 $$
    $$ F(0) = 0 $$
    $$ F(1) = 1 $$

4. **Implementujte funkciu `factorial()`**, ktorá pomocou rekurzie vypočíta **faktoriál** daného čísla.
   **Hlavička funkcie**:
    ```c
    int factorial(int n);
   ```
   **Vzorec pre faktoriál**:
    $$ n! = n \times (n-1)! \quad \text{pre} \quad n > 0 $$
    $$ 0! = 1 $$
5. **Implementujte funkciu `ackermann()`**, ktorá pomocou rekurzie vypočíta **Ackermanovú funkciu** daného čísla.
   **Hlavička funkcie**:
    ```c
    int ackermann(int m, int n);
   ```
   **Vzorec pre Ackermanovu funkciu**:

    $$ A(m, n) =
    \begin{cases}
    n + 1 & \text{ak} \quad m = 0 \\
    A(m-1, 1) & \text{ak} \quad m > 0 \quad \text{a} \quad n = 0 \\
    A(m-1, A(m, n-1)) & \text{ak} \quad m > 0 \quad \text{a} \quad n > 0
    \end{cases}
    $$

<a name="cite_note-1"></a>1. [^](#cite_ref-1) Riešenie tejto úlohy si budeme ukazovať na cvičení spoločne. Za správnu identifikáciu chyby, správne určenie dôvodov jej vzniku a náčrt jej riešenia je možný zisk čiarky.

<a name="cite_note-2"></a>2. [^](#cite_ref-2) Sekundárne v tomto prípade znamená, že v prípade, že sú prvky **zhodné** v parametri rok, použije sa druhý parameter meno.