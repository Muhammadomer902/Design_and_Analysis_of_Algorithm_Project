#pragma once
#include <iostream>
using namespace std;

int maxPower(int rows, int cols, int** levels)
{

    int** memoizationTable = new int* [rows];
    int i = 0;
    while (i < rows) {
        memoizationTable[i] = new int[cols] {0};
        i++;
    }

    int* maxIndexes = new int[cols];
    int* secondMaxIndexes = new int[cols];

    int j = 0;
    while (j < cols) {
        maxIndexes[j] = 0;
        secondMaxIndexes[j] = 0;
        j++;
    }

    i = 0;
    while (i < rows) {
        memoizationTable[i][0] = levels[i][0];
        i++;
    }

    int temp = 0;
    int max1 = -1, max2 = -1;
    i = 0;
    while (i < rows) {
        if (memoizationTable[i][0] > max1)
        {
            max2 = max1;
            secondMaxIndexes[0] = maxIndexes[0];
            max1 = memoizationTable[i][0];
            maxIndexes[0] = i;
        }
        else if (memoizationTable[i][0] > max2)
        {
            max2 = memoizationTable[i][0];
            secondMaxIndexes[0] = i;
        }
        i++;
    }

    i = 1;
    while (i < cols) {
        int j = 0;
        while (j < rows) {
            temp = maxIndexes[i - 1];
            switch (temp != j)
            {
            case true:
                memoizationTable[j][i] = memoizationTable[temp][i - 1] + levels[j][i];
                break;
            case false:
                temp = secondMaxIndexes[i - 1];
                memoizationTable[j][i] = memoizationTable[temp][i - 1] + levels[j][i];
                break;
            }
            j++;
        }
        int max1 = 0;
        int max2 = 0;
        int k = 0;
        while (k < rows) {
            if (memoizationTable[k][i] > max1)
            {
                max2 = max1;
                secondMaxIndexes[i] = maxIndexes[i];
                max1 = memoizationTable[k][i];
                maxIndexes[i] = k;
            }
            else if (memoizationTable[k][i] > max2)
            {
                max2 = memoizationTable[k][i];
                secondMaxIndexes[i] = k;
            }
            k++;
        }
        i++;
    }

    int finalMax = -1;
    i = 0;
    while (i < rows) {
        if (finalMax < memoizationTable[i][cols - 1])
        {
            finalMax = memoizationTable[i][cols - 1];
        }
        i++;
    }

    return finalMax;
}

int callmaxPower() {
    int numRows, numCols;
    cout << "Enter number of rows: ";
    cin >> numRows;
    cout << "Enter number of columns: ";
    cin >> numCols;
    int** powerLevels = new int* [numRows];

    int i = 0;
    while (i < numRows) {
        powerLevels[i] = new int[numCols];
        i++;
    }

    i = 0;
    while (i < numRows) {
        cout << "Enter Power in row " << i + 1 << ":\n";
        int j = 0;
        while (j < numCols) {
            cin >> powerLevels[i][j];
            j++;
        }
        i++;
    }

    if (numRows == 1)
    {
        int max = powerLevels[0][0];
        int j = 0;
        while (j < numCols) {
            if (max < powerLevels[0][j])
            {
                max = powerLevels[0][j];
            }
            j++;
        }
        cout << "Max Power is: " << max << endl;
        return 0;
    }
    else
        cout << "Max Power is: " << maxPower(numRows, numCols, powerLevels) << endl;

    return 0;
}