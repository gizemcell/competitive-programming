#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <deque>
#include <iomanip>
#include <cstdio>

using namespace std;

vector<int> visited(1000000, false);
int maxDepth = 0;

void dfs(int node, int depth, vector<int> graph[])
{
    visited[node] = true;
    for (int node2 : graph[node])
    {
        if (!visited[node2])
        {
            dfs(node2, depth + 1, graph);
        }
    }
    if (depth > maxDepth)
    {
        maxDepth = depth;
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int T;
    cin >> N >> T;
    vector<int> graph[N];
    int node;
    int node2;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> node >> node2;
        graph[node - 1].push_back(node2 - 1);
    }
    dfs(0, 0, graph);
    cout << maxDepth * T << endl;

    return 0;
}
