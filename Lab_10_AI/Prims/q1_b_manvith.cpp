//M Manvith Prabhu
//211EC228
#include <bits/stdc++.h>
using namespace std;
 
#define V 9
#define max_int 100
int minweight(int weight[], bool mstSet[])
{
    int min = max_int, min_index;
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && weight[v] < min)
            {min = weight[v];
            min_index = v;}
 
    return min_index;
}
 

void printMST(int mst[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << (char)(mst[i]+'A') << " - " << (char)(i+'A') << " \t"
             << graph[i][mst[i]] << " \n";
}
 
void primMST(int graph[V][V])
{
    int mst[V];
    int weight[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
        {weight[i] = max_int;
        mstSet[i] = false;}

    weight[0] = 0;
    mst[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int u = minweight(weight, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < weight[v])
                {mst[v] = u;
                weight[v] = graph[u][v];}
    }
    printMST(mst, graph);
}
 
int main()
{
//                        A  B  C  D  E  F  G  H  I
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0},    //A
                        { 4, 0, 8, 0, 0, 0, 0,11, 0},    //B
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2},    //C
                        { 0, 0, 7, 0, 9,14, 0, 0, 0},    //D
                        { 0, 0, 0, 9, 0,10, 0, 0, 0},    //E
                        { 0, 0, 4,14,10, 0, 2, 0, 0},    //F 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6},    //G
                        { 8,11, 0, 0, 0, 0, 1, 0, 7},    //H
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0}     //I
                        };
 

    primMST(graph);
 
    return 0;
}