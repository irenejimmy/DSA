#include <stdio.h>
#define MAXV 100  

int adj[MAXV][MAXV]; 
int visited[MAXV];
int queue[MAXV];
int front, rear;
int n; 

void init_queue() {
    front = 0;
    rear = -1;
}

void enqueue(int v) {
    if (rear < MAXV - 1) {
        queue[++rear] = v;
    }
}

int dequeue() {
    if (front <= rear) {
        return queue[front++];
    }
    return -1;
}

void bfs(int start) {
    int u, v;

    for (u = 0; u < n; u++) {
        visited[u] = 0;
    }

    init_queue();

    visited[start] = 1;
    enqueue(start);

    while (front <= rear) {  // directly checking queue condition
        u = dequeue();
        printf("%d ", u);

        for (v = 0; v < n; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = 1;
                enqueue(v);
            }
        }
    }
}

int main() {
    int i, j;
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d×%d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("BFS traversal from vertex %d:\n", start);
    bfs(start);
    printf("\n");

    return 0;
}
