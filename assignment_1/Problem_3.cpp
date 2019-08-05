#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> add(vector<int> v1, vector<int> v2)
{
    vector<int> v3;
    int c = 0;
    for (long long int i = v1.size() - 1; i >= 0; i--)
    {
        //cout<<v1.back();
        if (!v2.empty())
        {
            v3.insert(v3.begin(), (v1.back() + v2.back() + c) % 10);
            c = (v1.back() + v2.back() + c) / 10;
            v2.pop_back();
        }
        else
        {
            v3.insert(v3.begin(), (v1.back() + c) % 10);
            c = (v1.back() + v2.back() + c) / 10;
        }
        v1.pop_back();
    }
    if (c != 0)
        v3.insert(v3.begin(), c);
    return v3;
}
vector<int> dmultiply(vector<int> v1, int d, long long int n)
{
    vector<int> v3;
    int c = 0;
    for (long long int i = v1.size() - 1; i >= 0; i--)
    {
        //cout<<v1.back();
        v3.insert(v3.begin(), (v1.back() * d + c) % 10);
        c = (v1.back() * d + c) / 10;
        v1.pop_back();
    }
    if (c != 0)
        v3.insert(v3.begin(), c);
    for (long long int i = 0; i < n; i++)
        v3.push_back(0);
    return v3;
}
bool com(vector<int> v1, vector<int> v2)
{
    if (v1.size() > v2.size())
        return true;
    else if (v2.size() > v1.size())
        return false;
    else
    {
        for (long long int i = 0; i < v1.size(); i++)
        {

            if (v1[i] > v2[i])
                return true;
            else if (v2[i] > v1[i])
                return false;
            else
                continue;
        }
    }
    return true;
}
vector<int> multiply(vector<int> v1, vector<int> v2)
{
    vector<int> v3 = {0};
    long long int n = v2.size();
    for (long long int i = v2.size() - 1; i >= 0; i--)
    {

        //cout<<v2.size()-i-1<<endl;
        v3 = add(dmultiply(v1, v2.back(), n - i - 1), v3);
        v2.pop_back();
    }
    return v3;
}
int main()
{
    long int t;
    cin >> t;
    while (t--)
    {
        vector<int> v1, v2;
        string s1, s2;
        cin >> s1 >> s2;
        // cout<<s2[0];
        for (int i = 0; i < s1.size(); i++)
        {
            if (i == 0)
            {
                while (s1[i] == '0')
                    i++;
            }
            v1.push_back(s1[i] - '0');
        }
        for (int i = 0; i < s2.size(); i++)
        {
            if (i == 0)
            {
                while (s2[i] == '0')
                    i++;
            }
            v2.push_back(s2[i] - '0');
        }
        vector<int> a;
        if (com(v1, v2))
            a = multiply(v1, v2);
        else
            a = multiply(v2, v1);
            
        for (auto v : a)
            cout << v;
        cout << endl;
    }
}
