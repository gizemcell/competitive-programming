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

const int MAX_N = 1e6 + 5;
int factor[MAX_N];

void precalculation()
{
    for (int i = 1; i < MAX_N; i++)
    {
        for (int j = i; j < MAX_N; j = j + i)
        {
            factor[j]++;
        }
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int round;
    cin >> round;
    precalculation();
    int nazif;
    int osman;
    int result;
    while (round--)
    {
        cin >> nazif >> osman;
        result = factor[nazif] - factor[osman];
        if (result == 0)
        {
            cout << "tie" << endl;
        }
        else if (result > 0)
        {
            cout << "nazif" << endl;
        }
        else
        {
            cout << "osman" << endl;
        }
    }

    return 0;
}