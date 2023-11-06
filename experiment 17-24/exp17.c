#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// This struct represents a directed graph using
// adjacency list representation
typedef struct Graph_t {

	// No. of vertexertices
	int vertex;
	bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Constructor
Graph* Graph_create(int vertex)
{
	Graph* g = malloc(sizeof(Graph));
	g->vertex = vertex;

	for (int i = 0; i < vertex; i++) {
		for (int j = 0; j < vertex; j++) {
			g->adj[i][j] = false;
		}
	}

	return g;
}

// Destructor
void Graph_destroy(Graph* g) { free(g); }

// Function to add an edge to graph
void Graph_addEdge(Graph* g, int vertex, int w)
{
	// Add w to vertex’s list.
	g->adj[vertex][w] = true;
}

// Prints BFS traversal from a given source s
void Graph_BFS(Graph* g, int s)
{
	// Mark all the vertexertices as not vertexisited
	bool visited[MAX_VERTICES];
	for (int i = 0; i < g->vertex; i++) {
		visited[i] = false;
	}

	// Create a queue for BFS
	int queue[MAX_VERTICES];
	int front = 0, rear = 0;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue[rear++] = s;

	while (front != rear) {

		// Dequeue a vertex from queue and print it
		s = queue[front++];
		printf("%d ", s);

		// Get all adjacent vertices of the dequeued
		// vertexertex s.
		// If an adjacent has not been visited,
		// then mark it visited and enqueue it
		for (int adjacent = 0; adjacent < g->vertex; adjacent++) {
			if (g->adj[s][adjacent] && !visited[adjacent]) {
				visited[adjacent] = true;
				queue[rear++] = adjacent;
			}
		}
	}
}

// Driver code
int main()
{
	// Create a graph
	Graph* g = Graph_create(4);
	Graph_addEdge(g, 0, 1);
	Graph_addEdge(g, 0, 2);
	Graph_addEdge(g, 1, 2);
	Graph_addEdge(g, 2, 0);
	Graph_addEdge(g, 2, 3);
	Graph_addEdge(g, 3, 3);

	printf("Following is Breadth First Traversal "
		"(starting from vertex 2) \n");
	Graph_BFS(g, 2);
	Graph_destroy(g);

	return 0;
}
