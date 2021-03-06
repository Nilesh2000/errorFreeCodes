// A program to implement the Sieve Of Eratosthenes algorithm.
//Time Complexity : O(n log n log n)
#include <iostream>
#include <string.h>

using namespace std;

int sieveOfEratosthenes(int n)
{
    bool Prime[n + 1];                  //Define a boolean variable Prime of size n+1. Size is n+1 because it consists of elements from 0 to n.
    memset(Prime, true, sizeof(Prime)); //Iniialize all entries to true in the boolean array.
    for (int i = 2; i * i <= n; i++)
    {
        if (Prime[i] == true) //If the number is prime, set all it's multiples to not prime.
        {
            //The reason we start from j = i * i and not j = i is that all multiples of i smaller than i * i have already been marked by the previous prime numbers.
            for (int j = i * i; j <= n; j += i)
            {
                Prime[j] = false;
            }
        }
    }
    //Print all the prime numbers
    for (int i = 2; i <= n; i++)
    {
        if (Prime[i])
        {
            cout << i << " ";
        }
    }
}

int main(void) //Driver function
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    cout << "\nPrime numbers from 1 to " << n << " are:-\n";
    sieveOfEratosthenes(n);
    cout << "\n";
    return 0;
}
