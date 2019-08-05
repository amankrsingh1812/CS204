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

pair<vector<int>, vector<int>> divide(vector<int> v1, vector<int> v2)
{
    vector<int> v3 = {};
    while (com(v1, v2))
    {
        vector<int> v4 = v2, v5 = v2, v6 = {};

        while (com(v1, v4))
        {
            v4.push_back(0);
            v5.push_back(0);
            v6.insert(v6.begin(), 0);
        }
        v4.pop_back();
        v5.pop_back();
        v6.pop_back();
        int d = 0;
        while (com(v1, v4))
        {
            v4 = add(v4, v5);
            d++;
            //cout<<com(v1,v4);
        }
        v6.insert(v6.begin(), d);
        if (v3.empty())
            v3 = v6;
        else
            v3 = add(v3, v6);
        v1 = subtract(v1, subtract(v4, v5));
    }
    return make_pair(v3, v1);
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
        pair<vector<int>, vector<int>> d;
        if (com(v1, v2))
        {

            d = divide(v1, v2);
            vector<int> v3 = d.first, v4 = d.second;
            for (auto v : v3)
                cout << v;
            cout<<endl;
            for (auto v : v4)
                cout << v;
        }
        else
        {
            
            cout<<0<<endl;
            for(auto v:v1)
                cout<<v;
        }
        cout << endl;
    }
}
