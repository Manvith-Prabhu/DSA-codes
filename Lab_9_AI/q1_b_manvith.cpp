//M Manvith Prabhu
//211EC228
#include <iostream>
#include <queue>
using namespace std;
const int N = 52;  


int mapping[N][N];


int visited[N];


void bfs(char start, int n) {
  queue<char> q; 
  int startIndex = start - 'a';
  q.push(start);
  visited[start] = 1;

  while (!q.empty()) {
    char node = q.front();
    q.pop();
    cout << node << " ";
     int nodeIndex = node - 'a';
    for (int i = 0; i < n; i++) {
      if (mapping[nodeIndex][i] && !visited[i]) {
        q.push(i+'a');
        visited[i] = 1;
      }
    }
  }
}

int main() {
  
  mapping[0][1] = 1;//a-b
  mapping[0][3] = 1;//a-d
  mapping[0][4] = 1;//a-e
  mapping[1][2] = 1;//b-c
  mapping[1][4] = 1;//b-e
  mapping[3][4] = 1;//d-e
  mapping[4][2] = 1;//e-c
  mapping[2][5] = 1;//c-f
  mapping[4][5] = 1;//e-f
  mapping[2][6] = 1;//c-g
  mapping[5][6] = 1;//f-g
  
  cout<<"BFS traversal gives:\n";
  bfs('a', 7);

  return 0;
}
