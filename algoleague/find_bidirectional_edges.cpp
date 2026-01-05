#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;
bool isThereConnection(vector<set<int>> &adjList, int node1, int node2)
{
    if (adjList[node2].count(node1))
    {
        return true;
    }
    return false;
}
int main(int argc, char *argv[])
{
    int node;
    int edges;
    cin >> node >> edges;
    vector<set<int>> adjList(node);
    set<pair<int, int>> result;
    int u;
    int v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        adjList[u - 1].insert(v - 1);
    }
    for (int i = 0; i < node; i++)
    {
        for (int node2 : adjList[i])
        {
            if (isThereConnection(adjList, i, node2))
            {
                result.insert({min(i + 1, node2 + 1), max(i + 1, node2 + 1)});
            }
        }
    }
    int size = result.size();
    cout << size << endl;
    for (auto p : result)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}