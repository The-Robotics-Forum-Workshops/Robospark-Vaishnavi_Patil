#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool balanced_bracket(string s)
{
    int i;
    char c;
    int n = s.length();

    stack<char> t;

    for (i = 0; i < n; i++)
    {
        c = s.at(i);

        if (t.empty())
        {
            t.push(c);
        }
        else if (t.top() == '(' && c == ')' || t.top() == '{' && c == '}' || t.top() == '[' && c == ']')
        {
            t.pop();
        }
        else
            t.push(c);
    }

    if (t.empty())
        return true;
    else
        return false;
}

int main()
{
   
    string s1 = "{{[[(())]]}}";
    string s2 = "{[(])}";

    bool b1 = balanced_bracket(s1);
    bool b2 = balanced_bracket(s2);

    if (b1)
    {
        cout  << s1 << " contains balanced bracket.\n";
    }
    else
    {
        cout  << s1 << " does not contain balanced bracket.\n";
    }

    if (b2)
    {
        cout  << s2 << " contains balanced bracket.\n";
    }
    else
    {
        cout  << s2 << " does not contain balanced bracket.\n";
    }
    
    return 0;
}