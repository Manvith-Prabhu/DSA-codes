//M Manvith Prabhu
//211EC228
#include <iostream>
#include <stack>
using namespace std;
const int N = 52;  


int mapping[N][N];


int visited[N];


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

  mapping[0][2] = 1;//a-c
  mapping[2][1] = 1;//c-b
  mapping[0][3] = 1;//a-d
  mapping[0][5] = 1;//a-f
  mapping[0][4] = 1;//a-e
  mapping[3][5] = 1;//d-f
  mapping[3][4] = 1;//d-e
  mapping[4][5] = 1;//e-f


  mapping[2][0] = 1;//c-a
  mapping[1][2] = 1;//b-a
  mapping[3][0] = 1;//d-a
  mapping[5][0] = 1;//f-a
  mapping[4][0]= 1;//e-a
  mapping[5][3] = 1;//f-d
  mapping[5][3] = 1;//e-d
  mapping[5][4] = 1;//f-e
  
  cout<<"DFS traversal gives:\n";
  dfs('a', 6);

  return 0;
}
