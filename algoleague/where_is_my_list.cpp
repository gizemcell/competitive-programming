#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <deque>

using namespace std;
void includeNums(deque<int> &allNum, int a, int b)
{
    for (int i = a; i <= b; i++)
    {
        allNum.push_back(i);
    }
}

int main(int argc, char *argv[])
{
    deque<int> minFor;
    deque<int> maxFor;
    int m;
    cin >> m;
    vector<int> given(m);
    vector<int> maximum(m);
    vector<int> minimum(m);
    int element;
    for (int i = 0; i < m; i++)
    {
        cin >> element;
        given[i] = element;
    }
    maximum[0] = given[0];
    minimum[0] = given[0];
    if (given[0] != 1)
    {
        includeNums(minFor, 1, given[0] - 1);
        includeNums(maxFor, 1, given[0] - 1);
    }
    int lastMax = given[0];
    for (int i = 1; i < m; i++)
    {
        int maxNum = given[i];
        if (lastMax < maxNum)
        {
            maximum[i] = maxNum;
            minimum[i] = maxNum;
            includeNums(maxFor, lastMax + 1, maxNum - 1);
            includeNums(minFor, lastMax + 1, maxNum - 1);
            lastMax = maxNum;
        }
        else
        {
            maximum[i] = maxFor.back();
            maxFor.pop_back();
            minimum[i] = minFor.front();
            minFor.pop_front();
        }
    }
    for (int j : minimum)
    {
        cout << j << " ";
    }
    cout << endl;
    for (int j : maximum)
    {
        cout << j << " ";
    }

    return 0;
}