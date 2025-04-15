#include <stdio.h>
#include <conio.h>
#define MAX_VERTICES 10
int graph[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
int colors[MAX_VERTICES]; // Stores assigned colors
int numVertices, numColors;
// Function prototypes
void graphColoring(int vertex);
int checkVertex(int vertex, int color);
void main() {
int i, j;
clrsc();
printf("Enter the number of vertices in the graph: ");
scanf("%d", &numVertices);
printf("Enter the adjacency matrix of the graph:\n");
for (i = 0; i < numVertices; i++) {
for (j = 0; j < numVertices; j++) {
scanf("%d", &graph[i][j]);
}
}
printf("Enter the number of colors available: ");
scanf("%d", &numColors);
printf("Coloring the graph...\n");
graphColoring(0);
getch(); }
// Function to color the graph using backtracking
void graphColoring(int vertex) {
int colorIndex, i;
if (vertex == numVertices) { // If all vertices are colored
printf("Solution found:\n");
for (i = 0; i < numVertices; i++) {
printf("Vertex %d --> Color %d\n", i, colors[i]);
}
printf("\n");
return;
}
for (colorIndex = 1; colorIndex <= numColors; colorIndex++) {
if (checkVertex(vertex, colorIndex)) { // Check if color is safe
colors[vertex] = colorIndex;
graphColoring(vertex + 1); // Recur for next vertex
colors[vertex] = 0; // Backtrack
}
}
}
// Function to check if it's safe to color a vertex with a specific color
int checkVertex(int vertex, int color) {
int i;
for (i = 0; i < numVertices; i++) {
if (graph[vertex][i] && colors[i] == color) {
return 0; // Adjacent vertex has the same color
}
}
return 1;
}