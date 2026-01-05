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

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int W;
    cin >> N >> W;
    int it;
    vector<int> prices(N);
    vector<int> canReach(W + 1, false);
    canReach[0] = true;
    for (int i = 0; i < N; i++)
    {
        cin >> it;
        prices[i] = it;
    }

    for (int i = 0; i <= W; i++)
    {

        if (canReach[i] == true)
        {
            for (int price : prices)
            {
                if (i + price <= W)
                {
                    canReach[i + price] = true;
                }
            }
        }
    }

    for (int j = W; j >= 0; j--)
    {
        if (canReach[j] == true)
        {
            cout << j << endl;
            break;
        }
    }
    return 0;
}