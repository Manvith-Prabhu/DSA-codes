#include <iostream>
using namespace std;
const int INF = 50000;
const int MAXN = 100;

void dijkstra(int adjMatrix[MAXN][MAXN], int start, int dist[MAXN], int n) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    bool visited[MAXN];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++) {
        int u = -1;
        int MIN = INF;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < MIN) {
                u = j;
                MIN = dist[j];
            }
        }
        if (u == -1) return;
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && adjMatrix[u][v] != INF) {
                dist[v] = std::min(dist[v], dist[u] + adjMatrix[u][v]);
            }
        }
    }
}

int main() {
    int adjMatrix[MAXN][MAXN];
    int n;
    int start;
    int dist[MAXN];
    cout << "Enter the number of vertices:\n";
    cin >>n;
    cout << "Enter the adjacency matrix: " <<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> adjMatrix[i][j];
            if (adjMatrix[i][j] == 0) {
                adjMatrix[i][j] = INF;
            }
        }
    }
    cout << "Enter the starting vertex:\n";    
    cin >>start;
    dijkstra(adjMatrix, start, dist, n);
    std::cout << "The shortest distances from vertex " << start << " are: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << i << ": " << dist[i] << std::endl;
    }
    return 0;
}
