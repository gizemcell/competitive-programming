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
    int M;
    int N;
    cin >> N >> M;
    vector<pair<int, int>> species(N);
    int amount;
    int cost;
    for (int i = 0; i < N; i++)
    {
        cin >> amount >> cost;
        species[i] = {cost, amount};
    }
    int num = 0;
    sort(species.begin(), species.end());
    for (int i = 0; i < N; i++)
    {
        if (species[i].first * species[i].second <= M)
        {
            M = M - species[i].first * species[i].second;
            num = num + species[i].second;
        }
        else
        {
            int k = M / species[i].first;
            if (k > 0)
            {
                M = M - species[i].first * k;
                num = num + k;
                break;
            }
        }
    }
    cout << num << endl;

    return 0;
}
