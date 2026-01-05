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

void preProcess(map<char, set<int>> &sIndexes, string word)
{
    int size = word.size();
    for (int i = 0; i < size; i++)
    {
        sIndexes[word[i]].insert(i);
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<char, set<int>> sIndexes;
    map<char, set<int>> tIndexes;
    string s;
    string t;
    cin >> s;
    cin.ignore();
    cin >> t;
    preProcess(sIndexes, s);
    preProcess(tIndexes, t);
    map<char, char> assigns;
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        if (assigns.count(s[i]))
        {
            continue;
        }
        if (sIndexes[s[i]] == tIndexes[t[i]])
        {
            assigns[s[i]] = t[i];
        }
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
