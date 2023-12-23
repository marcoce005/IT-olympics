#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#define d(x)
using namespace std;

// Declaring variables
static int R = 0, n_bastioni;
static vector<int> risultato1;
static vector<int> risultato2;

vector<int> ST;
int dimensione;
int elementi;
int counter = 0;

template <typename T>
ostream& operator<<(ostream& o, const vector<T>& v){
  int c = -1;
  int limit = 1;
  o << "\n";
  for(auto i: v){
    if(c == limit){
      limit *= 2;
      c = 0;
      o << "\n";
    }
    o << i << " ";
    c++;
  }
  return o;
};

struct Node{
  int index;
  pair<int, int> range;

  int centrale(){
    return (this -> range.first + this -> range.second)/2;
  }
};


ostream& operator<<(ostream& o, const Node& v){
  o << v.index << " {" << v.range.first << ", " << v.range.second << "}";
  return o;
}

int limite_sinistra(int h, int x){
  stack<Node> S;
  S.push({1, {0, dimensione-1}});


  static int R = 0, n_bastioni;
  static vector<int> risultato1;
  static vector<int> risultato2;
  Node curr;

  while (not S.empty()){
    curr = S.top();
    S.pop();

    if(curr.index >= 2*dimensione) continue;

    if(ST[curr.index] <= h){
      continue;
    }else if(x <= curr.range.first){
      continue;
    }else if(curr.range.second <= x){
      while(curr.range.first != curr.range.second){
        int middle = curr.centrale();
        if(ST[2*curr.index + 1] > h){
          curr = {2*curr.index + 1, {middle + 1, curr.range.second}};
        }else{
          curr = {2*curr.index, {curr.range.first, middle}};
        }
      }
      if(ST[curr.index] > h){
        return curr.range.first;
      }
    }
    int middle = curr.centrale();
    S.push({2*curr.index, {curr.range.first, middle}});
    S.push({2*curr.index + 1, {middle + 1, curr.range.second}});
  }
  return 0;
}

int limite_destra(int const h, int const x){
  stack<Node> S;
  S.push({1, {0, dimensione-1}});

  Node curr;

  while (not S.empty()){
    curr = S.top();
    S.pop();
    
    if(curr.index >= 2*dimensione) continue;

    if(ST[curr.index] <= h){
      continue;
    }else if(curr.range.second <= x){
      continue;
    }else if(x <= curr.range.first){
      while(curr.range.first != curr.range.second){
        int middle = curr.centrale();
        if(ST[2*curr.index] > h){
          curr = {2*curr.index, {curr.range.first, middle}};
        }else{
          curr = {2*curr.index + 1, {middle + 1, curr.range.second}};
        }
      }
      if(ST[curr.index] > h){
        return curr.range.first;
      }
    }else{
      int middle = curr.centrale();
      S.push({2*curr.index + 1, {middle + 1, curr.range.second}});
      S.push({2*curr.index, {curr.range.first, middle}});
    }
  }
  return elementi - 1;
}

pair<int, int> chiedi(int x) {
  counter++;
  int rx = dimensione + x;
  int h = ST[rx];

  return {limite_sinistra(h, x), limite_destra(h, x)};
}

void cambia(Node n, int x, int h){
  if(n.range.first == n.range.second){
    ST[n.index] = h;
  }
  else{
    int middle = n.centrale();
    if(x <= middle){
      cambia({n.index*2, {n.range.first, middle}}, x, h);
    }else{
      cambia({n.index*2+1, {middle+1, n.range.second}}, x, h);
    }

    ST[n.index] = max(ST[n.index*2], ST[n.index*2+1]);
  }
}


void cambia(int x, int h) {
  int pos = dimensione + x;

  cambia({1, {0, dimensione - 1}}, x, h);

  return;
}

void inizializza(int N, vector<int> H) {
  elementi = H.size();
  dimensione = 2 << ((int)ceil(log2(elementi)) - 1);
  ST = vector<int>(2*dimensione, numeric_limits<int>::min());
  copy(H.begin(), H.end(), ST.begin()+dimensione);

  int i = (dimensione + elementi)/2;
  do{
    ST[i] = max(ST[2*i], ST[2*i+1]);
    i--;
  }while(i > 0);

  return;
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
    freopen("input08.txt", "r", stdin);
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
