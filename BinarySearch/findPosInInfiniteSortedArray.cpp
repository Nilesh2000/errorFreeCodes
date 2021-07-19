// Program to search for an element in a sorted array of infinite numbers.
// Here, we implement the notion of the infinite array using an array whose size we are unaware of
// Hint : Use Binary Search
// Our aim first should be to we have to find the bounds on which we have to apply the binary search algorithm.

#include <iostream>

using namespace std;

int binarySearch(int Arr[], int Low, int High, int Key)
{
    int Mid = Low + (High - Low) / 2;
    if (Low <= High)
    {
        if (Arr[Mid] == Key)
        {
            return Mid;
        }
        else if (Arr[Mid] > Key)
        {
            return binarySearch(Arr, Low, Mid - 1, Key);
        }
        else if (Arr[Mid] < Key)
        {
            return binarySearch(Arr, Mid + 1, High, Key);
        }
    }
    return -1;
}

// We don't know size of arr[] and we can assume size to be infinite in this function.
// NOTE THAT THIS FUNCTION ASSUMES arr[] TO BE OF INFINITE SIZE THEREFORE, THERE IS NO INDEX OUT OF BOUND CHECKING
int findPos(int Arr[], int Key)
{
    int Low = 0, High = 1, Val = Arr[0];
    while (Val < Key)
    {
        Low = High;
        High = 2 * High;
        Val = Arr[High];
    }
    return binarySearch(Arr, Low, High, Key);
}

int main(void)
{
    int Arr[] = {20, 30, 40, 60, 75, 90, 110, 120, 135};
    int Key = 20;
    int Position = findPos(Arr, Key);
    cout << Position;
    return 0;
}
