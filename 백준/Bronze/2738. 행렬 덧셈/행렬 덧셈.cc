#include <iostream>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int map1[101][101];
  int map2[101][101];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> map1[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> map2[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << map1[i][j] + map2[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}