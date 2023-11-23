#include <bits/stdc++.h>
using namespace std;
int substr(char *str, char *sub)
{
    int flag = -1;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (sub[0] == str[i])
        {
            for (int j = 0; sub[j] != '\0' && str[i + j] != '\0'; j++)
            {
                if (str[i + j] != sub[j])
                    break;
                if (sub[j + 1] == '\0')
                    flag = i;
            }
        }
    }
    if(flag==-1){
        cout<<"cannot find substr"<<endl;
        return -1;
    }
    return flag;
}
int main(){
    char a[]="iheiihelloiihelloii";
    char b[]="hello";
    cout<<substr(a,b)<<endl;
    return 0;
}