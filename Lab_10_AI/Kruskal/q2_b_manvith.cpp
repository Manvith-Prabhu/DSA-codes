//M Manvith Prabhu
//211EC228
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
 
using namespace std;
 
struct Edge
{
    int beg, end, weight;
};

struct Graph
{
        int V, E;
        struct Edge* edge;
};
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
 
    return graph;
}

struct subset
{
        int parent;
        int rank;
};

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*) a;
    struct Edge* b1 = (struct Edge*) b;
    return a1->weight > b1->weight;
}
 

void KruskalMST(struct Graph* graph)
{
    int V = graph->V;
    struct Edge result[V]; 
    int e = 0;
    int i = 0;
 
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    struct subset* subsets = new subset;
 

    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
 
 
    while (e < V - 1)
    {
        
        struct Edge next_edge = graph->edge[i++];
 
        int x = find(subsets, next_edge.beg);
        int y = find(subsets, next_edge.end);
  
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    cout<<"MST is:\n Edge \t Weight\n";
    for (i = 0; i < e; ++i)
    cout<<(char)(result[i].beg+'A')<<" - "<<(char)(result[i].end+'A')<<" \t "<<result[i].weight<<'\n' ;
    return;
}

int main()
{
    int V = 9; // Number of vertices in graph
    int E = 14; // Number of edges in graph
    struct Graph* graph = createGraph(V, E);
 
    // add edge A-B
    graph->edge[0].beg = 0;
    graph->edge[0].end = 1;
    graph->edge[0].weight = 4;
 
    // add edge A-H
    graph->edge[1].beg = 0;
    graph->edge[1].end = 7;
    graph->edge[1].weight = 8;
 
    // add edge B-C
    graph->edge[2].beg = 1;
    graph->edge[2].end = 2;
    graph->edge[2].weight = 8;
 
    // add edge B-H
    graph->edge[3].beg = 1;
    graph->edge[3].end = 7;
    graph->edge[3].weight = 11;
 
    // add edge C-D
    graph->edge[4].beg = 2;
    graph->edge[4].end = 3;
    graph->edge[4].weight = 7;

    // add edge C-F
    graph->edge[5].beg = 2;
    graph->edge[5].end = 5;
    graph->edge[5].weight = 4;

    // add edge C-I
    graph->edge[6].beg = 2;
    graph->edge[6].end = 8;
    graph->edge[6].weight = 2;

    // add edge D-E
    graph->edge[7].beg = 3;
    graph->edge[7].end = 4;
    graph->edge[7].weight = 9;

     // add edge D-E
    graph->edge[8].beg = 1;
    graph->edge[8].end = 4;
    graph->edge[8].weight = 14;

    // add edge E-F
    graph->edge[9].beg = 4;
    graph->edge[9].end = 5;
    graph->edge[9].weight = 10;

    // add edge F-G
    graph->edge[10].beg = 5;
    graph->edge[10].end = 6;
    graph->edge[10].weight = 2;

    // add edge G-H
    graph->edge[11].beg = 6;
    graph->edge[11].end = 7;
    graph->edge[11].weight = 1;

    // add edge G-I
    graph->edge[12].beg = 6;
    graph->edge[12].end = 8;
    graph->edge[12].weight = 6;

    // add edge H-I
    graph->edge[8].beg = 7;
    graph->edge[8].end = 8;
    graph->edge[8].weight = 7;

    KruskalMST(graph);
 
    return 0;
}