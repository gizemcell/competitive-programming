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

bool isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o')
    {
        return true;
    }
    return false;
}

string preprocess(string str)
{
    int size = str.size();
    int i = 1;
    string newStr = string("") + str[0];
    while (i < size)
    {
        if (isVowel(str[i]))
        {
            if (str[i] != str[i - 1])
            {
                newStr = newStr + str[i];
            }
        }
        else
        {
            newStr = newStr + str[i];
        }
        i++;
    }
    return newStr;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    string keyword;
    cin >> str;
    cin.ignore();
    cin >> keyword;
    int size = str.size();
    string newStr = preprocess(str);
    string newKeyword = preprocess(keyword);
    int pointer = 0;
    bool found = false;
    int keySize = newKeyword.size();
    int strSize = newStr.size();
    for (int i = 0; i < strSize; i++)
    {
        if (newStr[i] == newKeyword[pointer])
        {
            pointer++;
        }
        else
        {
            pointer = 0;
            if (newStr[i] == newKeyword[pointer])
            {
                pointer++;
            }
        }
        if (pointer == keySize)
        {
            cout << "yes" << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "no" << endl;
    }
    return 0;
}
