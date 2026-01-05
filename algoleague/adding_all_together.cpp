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

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<long long> prefixSum(n);
    vector<long long> prePreSum(n);
    for (int j = 0; j < n; j++)
    {
        if (j == 0)
        {
            cin >> prefixSum[j];
            prePreSum[j] = prefixSum[j];
        }
        else
        {
            cin >> prefixSum[j];
            prefixSum[j] = prefixSum[j] + prefixSum[j - 1];
            prePreSum[j] = prefixSum[j] + prePreSum[j - 1];
        }
    }
    long long sum = prePreSum[n - 1];
    for (int k = 1; k < n; k++)
    {
        sum = sum + prePreSum[n - 1] - prePreSum[k - 1] - prefixSum[k - 1] * (n - k);
    }
    cout << sum << endl;

    return 0;
}
