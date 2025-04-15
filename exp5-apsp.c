#include<stdio.h>

int inf = 9999;
int nV;


void printMatrix(int matrix[nV][nV]) {
    int i, j;
    for(i=0; i < nV; i++) {
        for(j=0; j < nV; j++) {
            if(matrix[i][j] == inf) {
                printf("%4s", "INF");
            } else {
                printf("%4d", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void floydWarshal(int graph[nV][nV], int nV) {
    int matrix[50][50], i, j, k;
     for(i=0; i < nV; i++) {
        for(j=0; j < nV; j++) {
            matrix[i][j] = graph[i][j];
        }
     }

     for(k=0; k < nV; k++) {
        for(i=0; i< nV; i++) {
            for(j=0; j < nV; j++) {
                if(matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
     }

     printMatrix(matrix);
}



int main() {
    int i,j;
    printf("Enter the no of vertices: ");
    scanf("%d", &nV);

    int graph[50][50];

    printf("Enter the adjacancy matrix");
    for(i=0; i < nV; i++) {
        for(j=0; j < nV; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshal(graph, nV);
    return 0;
}