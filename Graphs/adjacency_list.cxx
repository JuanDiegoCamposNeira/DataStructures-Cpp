#include <bits/stdc++.h>

using namespace std;

/*-------------------------------------------------------------------------------------------
------------------------------------   Vertex Class   ----------------------------------------
-------------------------------------------------------------------------------------------*/
typedef struct Vertex
{
    // Attributes
    int id;
    int marca;

    // Constructor(s)
    Vertex(int _id) : id(_id), marca(0) {}

} vertex;

/*-------------------------------------------------------------------------------------------
------------------------------------   Graph Class   ----------------------------------------
-------------------------------------------------------------------------------------------*/
typedef struct Graph
{
private:
    // Attributes
    vector<vector<vertex>> graph;
    // vector<int> visited;

public:
    // Constructor(s)
    Graph(int vertices)
    {
        this->graph = vector<vector<vertex>>(vertices + 1, vector<vertex>());
        // this->visited = vector<int>(vertices + 1, 0);
    }

    // Methods
    void print()
    {
        for (int i = 1; i < this->graph.size(); ++i)
        {
            cout << setw(2) << i << " -> ";
            for (int j = 0; j < this->graph[i].size(); ++j)
                cout << this->graph[i][j].id << " -> ";
            cout << "null" << endl;
        }
    }

    void add_vertex(int src, int dst)
    {
        // Add both edges between vertex
        this->graph[src].push_back(vertex(dst));
        this->graph[dst].push_back(vertex(src));
    }

    void DFS(int start_vertex)
    {
    }
    void visit(int vertex)
    {
    }

} graph;

int main()
{
    // Create the new graph
    graph adjacency_list(5);

    // Add vertices
    adjacency_list.add_vertex(1, 2);
    adjacency_list.add_vertex(1, 5);
    adjacency_list.add_vertex(2, 3);
    adjacency_list.add_vertex(2, 4);
    adjacency_list.add_vertex(2, 5);
    adjacency_list.add_vertex(3, 4);
    adjacency_list.add_vertex(4, 5);

    // Print graph
    adjacency_list.print();

    // Make Depth First Search
    adjacency_list.DFS(1);

    return (0);
}
