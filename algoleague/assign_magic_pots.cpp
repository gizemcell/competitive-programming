#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int m;
    int p;
    cin >> m >> p;
    vector<int> tolerance(m);
    int k;
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        tolerance[i] = k;
    }
    vector<int> level(p);
    for (int i = 0; i < p; i++)
    {
        cin >> k;
        level[i] = k;
    }
    sort(tolerance.begin(), tolerance.end());
    sort(level.begin(), level.end());
    int i = 0;
    int result = 0;
    for (int j = 0; j < p; j++)
    {
        if (level[j] >= tolerance[i])
        {
            result++;
            i++;
        }
        if (i == m)
        {
            break;
        }
    }
    cout << result;

    return 0;
}