#include <bits/stdc++.h>
using namespace std;
//
class myString
{
protected:
    char *pStr = NULL;

public:
    myString(char *str = NULL);
    ~myString();
    myString(const myString &m_str);
    void set(char *str);
    void print();
};
myString::myString(char *str)
{
    if (str != NULL)
    {
        pStr = new char[strlen(str) + 1];
        strcpy(pStr, str);
    }
}
myString::~myString()
{
    delete[] pStr;
}
myString::myString(const myString &m_str)
{
    if (pStr != NULL)
    {
        delete[] pStr;
    }
    pStr = new char[strlen(m_str.pStr) + 1];
    strcpy(pStr, m_str.pStr);
}
void myString::set(char *str)
{
    if (pStr != NULL)
    {
        delete[] pStr;
    }
    pStr = new char[strlen(str) + 1];
    strcpy(pStr, str);
}
void myString::print()
{
    cout << pStr;
}
//
class String1 :public myString
{
public:
    String1(char *c = NULL) : myString(c) {}

    String1(const String1 &str) : myString(str) {}

    int getLen();
    char *getStr();
    String1 connect(const char *c);
    int compare(const char *c);
    bool find(char *c);
    String1 get(int start, int end);
};
int String1::getLen()
{
    char *ptr = pStr;
    int len = 0;
    while (*ptr != '\0')
    {
        len++;
        ptr++;
    }
    return len;
}
char *String1::getStr()
{
    char *ptr = new char[getLen() + 1];
    for (int i = 0; i < getLen() + 1; i++)
    {
        ptr[i] = pStr[i];
    }
    return ptr;
}
String1 String1::connect(const char *c)
{
    int len = getLen();
    char *p = new char[len + strlen(c) + 1];
    for (int i = 0; i < len; i++)
    {
        p[i] = pStr[i];
    }
    for (int i = 0; i < strlen(c) + 1; i++)
    {
        p[i + len] = c[i];
    }
    String1 str(p);
    return str;
}
int String1::compare(const char *c)
{
    int i;
    for (i = 0; i < min(this->getLen(), (int)strlen(c)); i++)
    {
        if (pStr[i] != c[i])
        {
            if(pStr[i]>c[i])return 1;
            else return -1;
        }
    }
    return 0;
}
bool String1::find(char *c)
{
    int len = strlen(c);
    for (int i = 0; i < getLen() - len; i++)
    {
        bool flag = true;
        for (int j = 0; j < len; j++)
        {
            if (pStr[i + j] != c[j])
                flag = false;
        }
        if (flag)
            return true;
    }
    return false;
}
//
class String2 : public String1
{
public:
    String2(char *c) : String1(c) {}
    String2(const String2 &str) : String1(str) {}
    bool insert(int index, char *c);
    bool Delete(char c);
    bool replace(char oc,char nc);
};
bool String2::insert(int index, char *c)
    {
        if (index < 0 || index > getLen())
        {
            return false;
        }
        int len = strlen(c);
        char *ptr = new char[getLen() + len + 1];
        if (index == 0)
        {
            for (int i = 0; i < len; i++)
            {
                ptr[i] = c[i];
            }
            for (int i = 0; i < getLen() + 1; i++)
            {
                ptr[len + i] = pStr[i];
            }
        }
        else
        {
            int i;
            for (i = 0; i < index; i++)
            {
                ptr[i] = pStr[i];
            }
            for (int i = 0; i < len; i++)
            {
                ptr[i + index] = c[i];
            }
            for (int i = index; i < getLen() + 1; i++)
            {
                ptr[len + i] = pStr[i];
            }
        }
        delete[] pStr;
        pStr = ptr;
        return true;
    }
bool String2::Delete(char c)
{
    bool flag = false;
    for (int i = 0; i < getLen(); i++)
    {
        if (pStr[i] == c)
        {
            for (int j = i + 1; j < getLen() + 1; j++)
            {
                pStr[j - 1] = pStr[j];
            }
            flag = true;
        }
    }
    return flag;
}
bool String2::replace(char oc,char nc){
    bool res=false;
    for(int i=0;i<getLen();i++){
        if(pStr[i]==oc){
            pStr[i]=nc;
            res=true;
        }
    }
    return res;
}
//
int main()
{
    char *c = "hello";
    String1 a(c);
    a.set(c);
    a.print();
    cout<<endl;
    cout << (a.connect("nihao")).getStr()<<endl;
    cout<<a.compare("hella")<<' '<<a.compare("hellz")<<endl;
    cout<<a.find("ll")<<endl;
    cout<<endl;
    
    String2 b("stringstring");
    cout<<b.replace('g','a')<<endl;
    cout<<b.insert(6," haha ")<<endl;
    b.print();
    cout<<endl;
    cout<<b.Delete('s')<<endl;
    b.print();
    return 0;
}