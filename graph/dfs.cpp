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

    void dfsUtil(int vertex, bool* visited) {
        visited[vertex] = true;
        std::cout << vertex << " ";

        Node* temp = adjList[vertex].getHead();
        while (temp != nullptr) {
            int neighbor = temp->data;
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
            temp = temp->next;
        }
    }

    void depthFirstSearch(int startVertex) {
        bool* visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++) {
            visited[i] = false;
        }

        dfsUtil(startVertex, visited);

        delete[] visited;
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

    // Perform depth-first search
    int startVertex = 0;
    std::cout << "DFS traversal starting from vertex " << startVertex << ": ";
    graph.depthFirstSearch(startVertex);

    return 0;
}

