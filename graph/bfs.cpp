#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* getHead() {
        return head;
    }
};

class Graph {
private:
    int numVertices;
    LinkedList* adjList;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjList = new LinkedList[numVertices];
    }

    void addEdge(int src, int dest) {
        adjList[src].insert(dest);
        adjList[dest].insert(src);
    }

    void breadthFirstSearch(int startVertex) {
        bool* visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++) {
            visited[i] = false;
        }

        visited[startVertex] = true;

        int* queue = new int[numVertices];
        int front = 0;
        int rear = 0;

        queue[rear++] = startVertex;

        while (front != rear) {
            int currentVertex = queue[front++];
            std::cout << currentVertex << " ";

            Node* temp = adjList[currentVertex].getHead();
            while (temp != nullptr) {
                int neighbor = temp->data;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue[rear++] = neighbor;
                }
                temp = temp->next;
            }
        }

        delete[] visited;
        delete[] queue;
    }
};

int main() {
    int numVertices = 5;
    Graph graph(numVertices);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Perform breadth-first search
    int startVertex = 0;
    std::cout << "BFS traversal starting from vertex " << startVertex << ": ";
    graph.breadthFirstSearch(startVertex);

    return 0;
}
