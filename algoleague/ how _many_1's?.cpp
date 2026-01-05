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

    int N;
    int k;
    cin >> N >> k;
    int element;
    vector<int> binaries(N);
    vector<int> indexesOnes;
    vector<int> indexesZeros;
    int zeros = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> element;
        binaries[i] = element;

        if (element == 1)
        {
            indexesOnes.push_back(i);
            indexesZeros.push_back(zeros);
            zeros = 0;
        }
        else
        {
            zeros++;
        }
    }

    indexesZeros.push_back(zeros);
    int size = indexesZeros.size();
    long long sum = 0;
    int initialIndex = 0;
    int rightZeros;
    int leftZeros;
    int lastIndex = k - 1;
    int size2 = indexesOnes.size();
    while (lastIndex < size2)
    {
        leftZeros = indexesZeros[initialIndex];
        rightZeros = indexesZeros[lastIndex + 1];
        sum = sum + (leftZeros + 1) * (rightZeros + 1);
        initialIndex = initialIndex + 1;
        lastIndex = lastIndex + 1;
    }
    cout << sum << endl;
    return 0;
}