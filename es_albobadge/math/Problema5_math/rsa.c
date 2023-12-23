#include <math.h>

void decifra(int N, int d, int L, int* messaggio, char* plaintext) {
    // Esempio di implementazione con un solo carattere da decifrare.
    // Mettiamo il risultato della decifrazione in plaintext[0] e il
    // carattere di fine stringa in plaintext[1].
    int i;
    for(i = 0; i < L; i++) {
        plaintext[i] = ((long long int)powl(messaggio[i], d)) % N;
    }
    plaintext[i] = '\0';
}