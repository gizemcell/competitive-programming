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

int findEnd(vector<long long> &ps, int start, int requiredMax)
{
    int size = ps.size();
    for (int i = start; i < size; i++)
    {
        if (ps[i] > requiredMax)
        {
            return i - 1;
        }
    }
    return size - 1;
}
int findBegin(vector<long long> &ps, int start, int requiredMax, int V)
{
    int size = ps.size();
    for (int i = start; i < size; i++)
    {
        if (ps[i] <= requiredMax)
        {
            return i;
        }
        requiredMax = V + ps[i];
    }
    return -1;
}
int main(int argc, char *argv[])
{
    int N;
    int V;
    cin >> N >> V;
    vector<int> sizes(N);
    vector<long long> ps(N);
    int begin = 0;
    int end = 0;
    int element;
    for (int i = 0; i < N; i++)
    {
        cin >> element;
        sizes[i] = element;
        if (i == 0)
        {
            ps[0] = element;
        }
        else
        {
            ps[i] = element + ps[i - 1];
        }
    }
    int cookieNum;
    int maxNum = 0;
    int requiredMax = V;
    int start = 0;
    while (end < N - 1)
    {
        begin = findBegin(ps, start, requiredMax, V);
        if (begin == -1)
        {
            break;
        }
        if (begin != 0)
        {
            requiredMax = V + ps[begin - 1];
        }
        end = findEnd(ps, begin, requiredMax);
        cookieNum = end - begin + 1;
        maxNum = max(maxNum, cookieNum);
        start = begin + 1;
    }
    cout << maxNum;

    return 0;
}