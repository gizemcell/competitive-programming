#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int N;
    int k;
    int t;
    cin >> N >> k >> t;
    int takeTime = (k + 1) * 32;
    if (takeTime <= (t - 240))
    {
        cout << takeTime - 1;
    }
    else
    {
        int extraTime = 0;
        int firstPart = t - 240;
        int done = (firstPart / 32);
        int infront = k - done;
        if (firstPart % 32 > 2)
        {
            extraTime = 32 - (firstPart % 32);
            infront = infront - 1;
            done++;
        }
        int result = ((N - done) * 2) + firstPart + extraTime + (infront + 1) * 31 - 1;
        if (firstPart % 32 > 0 && firstPart % 32 <= 2)
        {
            result = result - 1;
        }
        cout << result;
    }

    return 0;
}
