#include <vector>
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
    int Q;
    cin >> Q;
    set<int> wounders;
    int a;
    int b;

    while (Q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cin >> a;
            wounders.insert(a);
        }
        else if (type == 2)
        {
            cin >> a >> b;
            if (wounders.count(a) && wounders.count(a - b) && wounders.count(a + b))
            {
                cout << "GG EZ" << endl;
            }
            else
            {
                cout << "GLHF" << endl;
            }
        }
    }
    return 0;
}
