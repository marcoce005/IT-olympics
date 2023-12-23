//#include <utility>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Declaring variables
static int R = 0, n_bastioni;
static vector<int> risultato1;
static vector<int> risultato2;

static vector<int> bastioni;


void inizializza(int N, vector<int> H) {
    bastioni = H;
    n_bastioni = N;
}

int dx(int x) {
    for (int i = x; i < n_bastioni; i++)
        if (bastioni[i] > bastioni[x])
            return i;
    return n_bastioni - 1;
}

int sx(int x) {
    for (int i = x; i >= 0; i--)
        if (bastioni[i] > bastioni[x])
            return i;
    return 0;
}

pair<int, int> chiedi(int x) {
    int end_dx, end_sx;
    if (x == 0) {
        end_sx = 0;
        end_dx = dx(x);
    } else if (x == n_bastioni - 1) {
        end_dx = n_bastioni - 1;
        end_sx = sx(x);
    } else {
        end_dx = dx(x);
        end_sx = sx(x);
    }   
    return make_pair(end_sx, end_dx);
}

void cambia(int x, int h) {
    bastioni[x] = h;
}

void leggi_eventi(int M) {
    for (int i = 0; i < M; i++) {
        char tipo;
        cin >> tipo;

        if (tipo == 'Q') {
            int x;
            cin >> x;
            pair<int, int> risultato = chiedi(x);
            risultato1[R] = risultato.first;
            risultato2[R] = risultato.second;
            R++;
        } else {
            int x, h;
            cin >> x >> h;
            cambia(x, h);
        }
    }
}


int main() {
    freopen("input27.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Reading input
    int N, M;
    cin >> N >> M;

    vector<int> H(N);
    risultato1.resize(M);
    risultato2.resize(M);

    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    // Calling functions
    inizializza(N, H);
    leggi_eventi(M);

    // Writing output
    for (int i = 0; i < R; i++) {
        cout << risultato1[i] << ' ' << risultato2[i] << '\n';
    }

    return 0;
}
