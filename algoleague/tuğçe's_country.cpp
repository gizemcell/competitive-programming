#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

void dfs(vector<bool> &visited, vector<int> adjList[], int node)
{
    visited[node] = true;
    for (int n : adjList[node])
    {
        if (!visited[n])
        {
            dfs(visited, adjList, n);
        }
    }
}
int main(int argc, char *argv[])
{
    int node;
    int edges;
    cin >> node >> edges;
    vector<int> adjList[node];
    vector<bool> visited(node, false);
    int u;
    int v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        adjList[u - 1].push_back(v - 1);
        adjList[v - 1].push_back(u - 1);
    }
    int count = 0;

    for (int i = 0; i < node; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(visited, adjList, i);
        }
    }
    cout << count;

    return 0;
}