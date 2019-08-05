#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isprime(long long int n)
{
    for (long long int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    long int t;
    cin >> t;
    while (t--)
    {
        long long int x;
        cin >> x;
        if(isprime(x))
            cout<<"Prime";
        else 
            cout<<"Not a Prime";
        cout << endl;
    }
}
