#include <vector>
#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

int main(int argc, char *argv[])
{
    int size;
    cin >> size;
    vector<long long> memory(size);
    memory[0] = 1;
    memory[1] = 1;
    for (int i = 2; i < size; i++)
    {
        memory[i] = (memory[i - 1] + memory[i - 2]) % MOD;
    }

    cout << memory[size - 1];

    return 0;
}
