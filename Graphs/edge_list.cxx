#include <bits/stdc++.h>

using namespace std;

typedef struct Node
{
private:
    // Attributes
    node origin;
    node destination;
    int value;

    // Constructor(s)
    Node(node src, node dst, int val) : origin(src), destination(dst), value(val) {}

} node;

typedef struct Graph
{
    // Attributes
    vector<node> graph;

    // Constructor(s)

    // Methods
    void print() {}

    void add_node() {}

    void DFS() {}

} graph;

int main()
{

    return (0);
}
