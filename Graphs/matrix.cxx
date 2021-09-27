#include <bits/stdc++.h>
#define inf 1e5

using namespace std;

typedef struct Graph
{
private:
    // Attributes
    vector<vector<int>> graph;

public:
    // Constructor(s)
    Graph(int nodes)
    {
        this->graph = vector<vector<int>>(nodes + 1, vector<int>(nodes + 1, NULL));
    }

    // Methods
    void print()
    {
        for (int i = 1; i < this->graph.size(); ++i)
        {
            for (int j = 1; j < this->graph[i].size(); ++j)
                cout << setw(3) << this->graph[i][j] << " ";
            cout << endl;
        }
    }

    void add_node(int src, int dst)
    {
        // The graph will be undirected, so the edge will exist in both directions
        this->graph[src][dst]++;
        this->graph[dst][src]++;
    }

    vector<int> vecinos(int vertex)
    {
        vector<int> _vecinos;
        for (int i = 1; i < this->graph[vertex].size(); ++i)
        {
            if (this->graph[vertex][i] != 0)
                _vecinos.push_back(i);
        }
        return _vecinos;
    }

    void dfs();

} graph;

int main()
{
    // Create graph
    graph matrix(5);

    // Add nodes to the graph
    matrix.add_node(1, 2);
    matrix.add_node(1, 5);
    matrix.add_node(2, 5);
    matrix.add_node(2, 4);
    matrix.add_node(2, 3);
    matrix.add_node(3, 4);
    matrix.add_node(4, 5);

    // Print graph
    matrix.print();

    return (0);
}
