#include<stdio.h>

int V;

void dijkstra(int graph[V][V], int src) {
    int i,v,count;
    int inf = 99999;
    int dist[V];
    int visited[V];

    for(i=0; i < V; i++) {
        dist[i] = inf;
        visited[i]=0;
    }

    dist[src] = 0;

    for(count = 0; count < V-1; count++) {
        int min = inf, min_index = -1;
        for (v=0; v < V; v++) {
            if(!visited[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }

        if (min_index == -1) {
            break;
        }

        visited[min_index] = 1;

        for(v = 0; v < V; v++) {
            if(!visited[v] && graph[min_index][v] && dist[min_index] != inf && dist[min_index] + graph[min_index][v]) {
                dist[v] = dist[min_index] + graph[min_index][v];
            }
        }
    }

    printf("Vertex   Distance from Source (0)\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);

}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    int graph[V][V];
    printf("Enter the adjacency matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    dijkstra(graph, 0); // Source vertex is 0
    return 0;
}
