//M Manvith Prabhu
//211EC228
#include <iostream>
#include <stack>
using namespace std;
const int N = 52;  


int mapping[N][N];




void dfs(char start, int n) {
  bool visited[n]={0}; 
  stack<char> s;
  s.push(start);

  while(!s.empty()){
    char node=s.top();
    int index=node-'a';
    s.pop();
    if(!visited[index]){
      visited[index]=1;
      cout<<node<<" ";
    }
    for(int i=0;i<n;i++){
      if(mapping[index][i] && !visited[i])
      s.push((char)(i+'a'));
    }
  }
}

int main() {
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      mapping[i][j] = 0;
    }
  }
  mapping[0][4] = 1;//a-e
  mapping[0][3] = 1;//a-d
  mapping[0][1] = 1;//a-b
  mapping[1][2] = 1;//b-c
  mapping[1][4] = 1;//b-e
  mapping[3][4] = 1;//d-e
  mapping[4][2] = 1;//e-c
  mapping[2][5] = 1;//c-f
  mapping[4][5] = 1;//e-f
  mapping[2][6] = 1;//c-g
  mapping[5][6] = 1;//f-g

  mapping[4][0] = 1;//e-a
  mapping[3][0] = 1;//d-a
  mapping[1][0] = 1;//b-a
  mapping[2][1] = 1;//c-b
  mapping[4][1] = 1;//e-b
  mapping[4][3] = 1;//e-d
  mapping[2][4] = 1;//c-e
  mapping[5][2] = 1;//f-c
  mapping[5][4] = 1;//f-e
  mapping[6][2] = 1;//g-c
  mapping[6][5] = 1;//g-f
  
  cout<<"DFS traversal gives:\n";
  dfs('a', 7);

  return 0;
}
