#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // write your code here
    int round;
    cin >> round;
    long long limit;
    long long result;
    while (round)
    {
        cin >> limit;
        if (limit % 11 == 0)
        {
            cout << (limit / 11) * 5 + 1 << endl;
        }
        else
        {
            long long x = limit / 11;
            result = x * 5;
            if (limit >= 11)
            {
                result++;
            }
            for (long long i = 11 * x + 1; i <= limit; i++)
            {
                if (i % 11 <= 5)
                {
                    result++;
                }
            }
            cout << result << endl;
        }

        round--;
    }
    return 0;
}
