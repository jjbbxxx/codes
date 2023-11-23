#include <bits/stdc++.h>
using namespace std;
int Strcmp(string s, string t)
{
    int l1 = s.length();
    int l2 = t.length();
    int a = 0, b = 0;
    while (a < l1 && b < l2)
    {
        if (s[a] > t[b])
            return 1;
        if (s[a] < t[b])
            return -1;
        if (s[a] == t[b])
        {
            a++;
            b++;
        }
    }
    if (l1 > l2)
        return 1;
    else if (l1 < l2)
        return -1;
    else
        return 0;
}
int main(){
    string a="abcde";
    string b="abcde1";
    cout<<Strcmp(a,b)<<endl;
    return 0;
}