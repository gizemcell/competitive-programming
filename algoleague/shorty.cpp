#include <set>
#include <iostream>

using namespace std;

int main()
{
    // write your code here

    int N;
    cin >> N;
    int K;
    cin >> K;
    int x;
    int sum = 0;
    set<int> numbers;
    while (N--)
    {
        cin >> x;
        sum = sum + x;
        numbers.insert(x);
    }
    int required = K - (sum % K);
    while (true)
    {
        if (!numbers.count(required))
        {
            cout << required;
            break;
        }
        else
        {
            required = required + K;
        }
    }

    return 0;
}
