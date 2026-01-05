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

long long quickMod(long long base, long long y)
{
    long long result = 1;
    long long exp = base;
    base = base % y;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = result * base % y;
        }
        base = base * base % y;
        exp = exp / 2;
    }

    return result;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long x, y;
    cin >> x >> y;
    long long x1 = x % y;
    long long newCheck;
    set<long long> visited;

    while (true)
    {
        if (visited.count(x1))
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        newCheck = quickMod(x1, y);
        visited.insert(x1);
        if (newCheck == x1 || newCheck == 0)
        {
            cout << newCheck << endl;
            return 0;
        }
        x1 = newCheck;
    }
    return 0;
}
