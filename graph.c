#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int traversal[50];
int traversal_index = 0;

struct node 
{
    int vertex;
    struct node* next;
};

struct graph 
{
    struct node* adj[SIZE];
    int numVertices;
};

struct node* createNode(int v) 
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct graph* createGraph(int v) 
{
    struct graph* graph = (struct graph*)malloc(sizeof(struct graph));
    graph->numVertices = v;
    for (int i = 0; i < SIZE; i++) 
    {
        graph->adj[i] = NULL;
    }
    return graph;
}

void addEdge(struct graph* graph, int x, int y) 
{
    struct node* n = createNode(y);
    n->next = graph->adj[x];
    graph->adj[x] = n;

    n = createNode(x);
    n->next = graph->adj[y];
    graph->adj[y] = n;
}

void adj_print(struct graph* graph) 
{
    int mat[SIZE][SIZE] = {0};
    for (int i = 0; i < graph->numVertices; i++) 
    {
        struct node* temp = graph->adj[i];
        while (temp) {
            mat[i][temp->vertex] = 1;
            temp = temp->next;
        }
    }
    printf("\nPrinting adjacency matrix:\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        for (int j = 0; j < graph->numVertices; j++) 
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void dfs(struct graph* graph, int startVertex) 
{
    int visited[SIZE] = {0};
    int stack[SIZE]; 
    int top = -1;
    int startTime[SIZE] = {0};
    int endTime[SIZE] = {0};
    int time = 0;

    stack[++top] = startVertex;

    while (top != -1) 
    {
        int vertex = stack[top];

        if (!visited[vertex]) 
        {
            visited[vertex] = 1;
            time++;
            startTime[vertex] = time;
            traversal[traversal_index++] = vertex;

            struct node* t = graph->adj[vertex];
            while (t) 
            {
                int connectedVertex = t->vertex;
                if (!visited[connectedVertex]) 
                {
                    printf("Pushed: %d\n", stack[top]);
                    stack[++top] = connectedVertex; 
                }
                t = t->next;
            }
        } 
        else 
        {
            printf("Popped: %d\n", stack[top]);
            top--;
            time++;
            endTime[vertex] = time;
        }
    }

    for (int i = 0; i < graph->numVertices; i++) 
    {
        printf("Start time for vertex %d: %d\n", i, startTime[i]);
        printf("End time for vertex %d: %d\n", i, endTime[i]);
    }
}


void bfs(struct graph* graph, int startVertex) 
{
    int visited[SIZE] = {0};
    int queue[SIZE];
    int front = 0, rear = 0;
    int level[SIZE];
    int bfst[SIZE];
    int t = 0;

    for (int i = 0; i < graph->numVertices; i++) 
    {
        level[i] = -1;
    }

    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    level[startVertex] = 0;

    printf("BFS Traversal starting node %d:\n", startVertex);

    while (front < rear) 
    {
        int currentVertex = queue[front++];
        printf("Dequeued: %d\n", currentVertex);
        bfst[t++] = currentVertex;
        struct node* adjList[SIZE];
        struct node* temp = graph->adj[currentVertex];
        int adjCount = 0;
        while (temp) {
            adjList[adjCount++] = temp;
            temp = temp->next;
        }
        for (int i = 0; i < adjCount - 1; i++) {
            for (int j = i + 1; j < adjCount; j++) {
                if (adjList[i]->vertex > adjList[j]->vertex) {
                    struct node* swap = adjList[i];
                    adjList[i] = adjList[j];
                    adjList[j] = swap;
                }
            }
        }
        for (int i = 0; i < adjCount; i++) {
            int adjVertex = adjList[i]->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
                level[adjVertex] = level[currentVertex] + 1;
                printf("Enqueued: %d\n", adjVertex);
            }
        }
    }

    printf("\nLevels:\n");
    for (int i = 0; i < graph->numVertices; i++) 
    {
        if (level[i] != -1) 
        {
            printf("The level of Vertex %d is %d\n", i, level[i]);
        } 
        else 
        {
            printf("Vertex %d is Not reachable\n", i);
        }
    }

    printf("\nBFS Traversal: ");
    for (int i = 0; i < t; i++) 
    {
        printf("%d ", bfst[i]);
    }
    printf("\n");
}


int main() 
{
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    struct graph* graph = createGraph(vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    adj_print(graph);
    for (int i = 0; i < edges; i++) 
    {
        int x, y;
        printf("Enter edge %d, both the vertices (a b): ", i + 1);
        scanf("%d %d", &x, &y);
        if (x >= 0 && x < vertices && y >= 0 && y < vertices) 
        {
            addEdge(graph, x, y);
        }
        else 
        {
            printf("Vertices must be between 0 and %d.\n", vertices - 1);
            i--;
        }
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);
    if (startVertex >= 0 && startVertex < vertices) 
    {
        printf("DFS Traversal starting from node %d:\n", startVertex);
        dfs(graph, startVertex);
        adj_print(graph);
    } 
    else 
    {
        printf("Invalid starting vertex for DFS!\n");
    }
    printf("\nDFS Traversal Order:\n");
    for (int i = 0; i < traversal_index; i++) 
    {
        printf("%d ", traversal[i]);
    }

    printf("\n");
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);
    if (startVertex >= 0 && startVertex < vertices) 
    {
        bfs(graph, startVertex);
    } 
    else 
    {
        printf("Invalid starting vertex!\n");
    }
    return 0;
}