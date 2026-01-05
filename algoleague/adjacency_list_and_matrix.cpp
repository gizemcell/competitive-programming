#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    // write your code here
    int nodeNum;
    int edgeNum;
    int u;
    int v;
    cin >> nodeNum >> edgeNum;
    vector<vector<int>> adjList(nodeNum, vector<int>());
    vector<vector<int>> adjMatrix(nodeNum, vector<int>(nodeNum, 0));
    for (int i = 0; i < edgeNum; i++)
    {
        cin >> u >> v;
        adjList[u - 1].push_back(v);
        adjList[v - 1].push_back(u);
        adjMatrix[u - 1][v - 1] = 1;
        adjMatrix[v - 1][u - 1] = 1;
    }
    for (int j = 0; j < nodeNum; j++)
    {
        int size = adjList[j].size();
        sort(adjList[j].begin(), adjList[j].end());
        for (int i = 0; i < size; i++)
        {
            cout << adjList[j][i] << " ";
        }
        cout << endl;
    }
    for (int j = 0; j < nodeNum; j++)
    {
        for (int i = 0; i < nodeNum; i++)
        {
            cout << adjMatrix[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
