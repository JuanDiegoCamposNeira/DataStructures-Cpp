#include <bits/stdc++.h>
using namespace std;

// Functions
bool bfs(vector<vector<string>> &graph, pair<int, int> node);
void print(vector<vector<string>> &graph, pair<int, int> start_node, pair<int, int> goal)
{
    cout << endl;
    for (int i = 0; i < graph.size(); ++i)
    {
        for (int j = 0; j < graph[i].size(); ++j)
        {
            if (i == start_node.first && j == start_node.second)
                cout << "X";
            else if (graph[i][j] == "1" || graph[i][j] == "0")
                cout << " ";
            else if (i == goal.first && j == goal.second)
                cout << "O";
            else
                cout << graph[i][j];
            cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Create the graph
    vector<vector<string>> graph = {
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        {"#", "1", "O", "1", "1", "1", "#", "#", "1", "#"},
        {"#", "#", "#", "1", "#", "#", "#", "1", "1", "#"},
        {"#", "#", "#", "1", "1", "1", "#", "1", "#", "#"},
        {"#", "#", "#", "1", "#", "1", "#", "1", "#", "#"},
        {"#", "#", "#", "1", "#", "1", "X", "1", "1", "#"},
        {"#", "#", "1", "1", "#", "1", "#", "#", "1", "#"},
        {"#", "#", "1", "#", "1", "#", "1", "1", "1", "#"},
        {"#", "#", "1", "1", "1", "1", "1", "#", "#", "#"},
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
    };

    // Find 'X' to excecute algorithm -> O(n^2)
    pair<int, int> start_node, goal;
    for (int i = 0; i < graph.size(); ++i)
    {
        for (int j = 0; j < graph[i].size(); ++j)
        {
            if (graph[i][j] == "X")
                start_node = make_pair(i, j);
            else if (graph[i][j] == "O")
                goal = make_pair(i, j);
        }
    }

    // Print initial state of the graph -> O(n^2)
    print(graph, start_node, goal);

    // Find path (BFS) -> O(v) where v = # of vertixes
    bool path = bfs(graph, start_node); // If true, there is a path

    // Check if a path exists
    if (!path)
        cout << "No path between nodes\n";
    // Print new graph
    else
        print(graph, start_node, goal);

    // Return value
    return 0;
}

bool bfs(vector<vector<string>> &graph, pair<int, int> node)
{
    // Check if the node could be processed
    int i = node.first, j = node.second;
    if (graph[i][j] == "#" || graph[i][j] == "0")
    {
        return false;
    }

    // If target value is found
    if (graph[i][j] == "O")
        return true;
    else
        graph[i][j] = "0";

    // BFS on neightboors
    // Return true on the neightbor that have a path
    pair<int, int> left(i, j - 1), right(i, j + 1), up(i + 1, j), down(i - 1, j);
    if (bfs(graph, left))
    {
        graph[left.first][left.second] = "_";
        return true;
    }
    else if (bfs(graph, right))
    {
        graph[right.first][right.second] = "_";
        return true;
    }
    else if (bfs(graph, up))
    {
        graph[up.first][up.second] = "_";
        return true;
    }
    else if (bfs(graph, down))
    {
        graph[down.first][down.second] = "_";
        return true;
    }
    // If none of the neightbors have a path, return false
    else
        return false;
}