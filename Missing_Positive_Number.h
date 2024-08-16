#pragma once
#include <iostream>
#include <cmath>
using namespace std;

void missing_positive_number()
{
    const int arraySize = 5;
    int arr[arraySize];

    // Taking input for the array
    cout << "Enter " << arraySize << " elements for the array:" << endl;
    for (int i = 0; i < arraySize; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int maxValue = arr[0];
    int i = 1;
    while (i < arraySize)
    {
        if (arr[i] > maxValue)
        {
            maxValue = arr[i];
        }
        i++;
    }
    maxValue += 1;
    int* frequency = new int[maxValue + 1] {0};
    int j = 0;
    while (j < arraySize)
    {
        frequency[arr[j]]++;
        j++;
    }
    int missingPositiveNumber = -1;
    int k = 0;
    while (k < maxValue + 1)
    {
        if (frequency[k] == 0)
        {
            missingPositiveNumber = k;
            break;
        }
        k++;
    }

    if (missingPositiveNumber != -1)
    {

        int start = 1, end = 1;
        bool check = false;
        int l = 0;
        while (l < arraySize)
        {
            if (arr[l] > missingPositiveNumber)
            {
                end = l + 1;
                break;
            }
            else if (arr[l] == maxValue - 1)
            {
                end = l + 1;
                check = true;
                break;
            }
            l++;
        }
        if (check)
        {
            int m = end;
            while (m < arraySize)
            {
                if (arr[m] == maxValue - 1)
                {
                    check = false;
                    break;
                }
                m++;
            }
        }
        if (!check)
        {
            cout << "Segments: " << endl;
            cout << start << " " << end << endl;
            cout << end + 1 << " " << arraySize << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    else
    {
        cout << missingPositiveNumber << endl;
    }
    delete[] frequency;
}
