//M Manvith Prabhu
//211EC228
#include <bits/stdc++.h>
using namespace std;
 
#define V 6
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
   
    int graph[V][V] = { { 0, 7, 8, 0, 0, 0 },
                        { 7, 0, 3, 6, 0, 0 },
                        { 8, 3, 0, 4, 3, 0 },
                        { 0, 6, 4, 0, 2, 5 },
                        { 0, 0, 3, 2, 0, 2 },
                        { 0, 0, 0, 5, 2, 0 } };
 

    primMST(graph);
 
    return 0;
}