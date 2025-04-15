#include<stdio.h>

struct Item {
    int weight, profit;
    double ratio;
};

void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

void sortItems(struct Item items[], int n) {
    int i,j;
    for(i=0; i < n - 1; i++) {
        for(j=0; j < n - i - 1; j++) {
            if(items[j].ratio < items[j+1].ratio) {
                swap(&items[j], &items[j+1]);
            }
        }
    }
}

double fractionalKnapsack(struct Item items[], int n, int capacity, double result[]) {
    int i;
    double totalProfit = 0.0;
    sortItems(items, n);

    for(i=0; i < n; i++) {
        if(capacity >= items[i].weight) {
            capacity = capacity - items[i].weight;
            totalProfit = totalProfit + items[i].profit;
            result[i] = 1.0;
        } else {
            result[i] = (double) capacity/items[i].weight;
            totalProfit = totalProfit + (result[i] * items[i].profit);
            break;
        }
    }

    return totalProfit;
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    double result[n];
}