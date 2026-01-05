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

int findStep(int number, int step)
{
    if (number == 1)
    {
        return step;
    }
    else
    {
        if (number % 2 == 0)
        {
            return findStep(number / 2, step + 1);
        }
        else
        {
            return findStep(3 * number + 1, step + 1);
        }
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int round;
    cin >> round;
    int number;
    int haydarWin = 0;
    int kekikWin = 0;
    bool toogle = true;
    while (round--)
    {
        cin >> number;
        int result = findStep(number, 0);
        if (result % 2 != 0)
        {
            if (toogle)
            {
                haydarWin++;
            }
            else
            {
                kekikWin++;
            }
        }
        toogle = !toogle;
    }
    if (haydarWin == kekikWin)
    {
        cout << "DRAW" << endl;
    }
    else if (haydarWin > kekikWin)
    {
        cout << "HAYDARBERK" << endl;
    }
    else
    {
        cout << "KEKIK" << endl;
    }

    return 0;
}
