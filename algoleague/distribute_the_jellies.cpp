#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int partition(vector<int> &v, int low, int high)
{
    int leftPoint = low;
    int rightPoint = high;
    int pivot = v[low];

    while (leftPoint <= rightPoint)
    {
        leftPoint++;
        if (v[leftPoint] >= pivot)
        {
            while (v[rightPoint] >= pivot && rightPoint > low)
            {
                rightPoint--;
            }
            // swap
            if (leftPoint < rightPoint)
            {
                swap(v[leftPoint], v[rightPoint]);
            }
        }
    }
    if (v[low] > v[rightPoint])
    {
        swap(v[low], v[rightPoint]);
    }
    return rightPoint;
}
void sort(vector<int> &v, int low, int high)
{
    if (high <= low)
    {
        return;
    }
    int j = partition(v, low, high);
    sort(v, low, j - 1);
    sort(v, j + 1, high);
}

int main()
{
    int gSize;
    int sSize;
    cin >> gSize >> sSize;
    vector<int> g(gSize);
    vector<int> s(sSize);
    for (int i = 0; i < gSize; i++)
    {
        cin >> g[i];
    }
    for (int i = 0; i < sSize; i++)
    {
        cin >> s[i];
    }
    vector<int> assigns(gSize, 0);
    sort(g, 0, gSize - 1);
    sort(s, 0, sSize - 1);
    int k = -1;
    for (int j = 0; j < gSize; j++)
    {
        while (k < sSize - 1)
        {
            k++;
            if (s[k] >= g[j])
            {
                assigns[j] = s[k];
                break;
            }
        }
        if (k == sSize - 1)
        {
            break;
        }
    }
    int result = 0;
    for (int i = 0; i < gSize; i++)
    {
        if (assigns[i] != 0)
        {
            result++;
        }
    }
    cout << result;
    return 0;
}
