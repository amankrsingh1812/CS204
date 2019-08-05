#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> subtract(vector<int> v1, vector<int> v2)
{
    vector<int> v3;
    int c = 0;
    for (long long int i = v1.size() - 1; i >= 0; i--)
    {
        //cout<<v1.back();
        if (!v2.empty())
        {
            if (v1.back() >= v2.back() + c)
            {
                v3.insert(v3.begin(), v1.back() - v2.back() - c);
                c = 0;
            }
            else
            {
                v3.insert(v3.begin(), v1.back() + 10 - v2.back() - c);
                c = 1;
            }
            v2.pop_back();
        }
        else
        {
            if (v1.back() >= c)
            {
                v3.insert(v3.begin(), v1.back() - c);
                c = 0;
            }
            else
            {
                v3.insert(v3.begin(), v1.back() + 10 - c);
                c = 1;
            }
        }
        v1.pop_back();
    }
    while (v3.size() > 1 && *v3.begin() == 0)
        v3.erase(v3.begin());
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
        {
            a = subtract(v1, v2);
            for (auto v : a)
                cout << v;
        }
        else
        {
            a = subtract(v2, v1);
            cout << "-";
            for (auto v : a)
                cout << v;
        }
        cout << endl;
    }
}
