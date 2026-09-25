// 1. https://www.geeksforgeeks.org/dsa/maximum-and-minimum-in-an-array/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    int arr[] = {3, 5, 4, 1, 9};
    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    cout << min << " " << max;
}