#include <iostream>
#include <vector>

using namespace std;
bool isValidIndex(int row, int col, int indexRow, int indexCol)
{
    if (indexRow >= row || indexRow < 0 || indexCol < 0 || indexCol >= col)
    {
        return false;
    }
    return true;
}
bool isThereInCol(int indexRow, int indexCol, const vector<vector<int>> &arr, int number, int row, int col)
{
    if (isValidIndex(row, col, indexRow, indexCol + 1))
    {
        if (arr[indexRow][indexCol + 1] == number)
        {
            return true;
        }
    }
    if (isValidIndex(row, col, indexRow, indexCol - 1))
    {

        if (arr[indexRow][indexCol - 1] == number)
        {
            return true;
        }
    }
    return false;
}
bool isThereInRow(int indexRow, int indexCol, const vector<vector<int>> &arr, int number, int row, int col)
{
    if (isValidIndex(row, col, indexRow + 1, indexCol))
    {
        if (arr[indexRow + 1][indexCol] == number || isThereInCol(indexRow + 1, indexCol, arr, number, row, col))
        {
            return true;
        }
    }
    if (isValidIndex(row, col, indexRow - 1, indexCol))
    {
        if (arr[indexRow - 1][indexCol] == number || isThereInCol(indexRow - 1, indexCol, arr, number, row, col))
        {
            return true;
        }
    }
    if (isThereInCol(indexRow, indexCol, arr, number, row, col))
    {
        return true;
    }

    return false;
}

int main(int argc, char *argv[])
{
    int row;
    int col;
    cin >> row >> col;
    vector<vector<int>> original(row, vector<int>(col));
    vector<vector<int>> second(row, vector<int>(col, 0));
    int element;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> element;
            original[i][j] = element;
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (original[i][j] == 23)
            {
                if (!isThereInRow(i, j, original, 23, row, col))
                {

                    second[i][j] = 35;
                }
                else
                {
                    second[i][j] = 23;
                }
            }
            else if (original[i][j] == 35)
            {

                if (!isThereInRow(i, j, original, 35, row, col))
                {
                    second[i][j] = 23;
                }
                else
                {
                    second[i][j] = 35;
                }
            }
            else
            {
                second[i][j] = original[i][j];
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << second[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
