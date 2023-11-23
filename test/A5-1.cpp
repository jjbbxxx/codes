#include <bits/stdc++.h>

using namespace std;

int stringlength(const char *str)
{
    int counter = 0;
    while (*str != '\0')
    {
        counter++;
        str++;
    }
    return counter;
}

class myString
{
protected:
    char *pStr = NULL;

public:
    myString(char *str = NULL)
    {
        if (str != NULL)
        {
            pStr = new char[strlen(str) + 1];
            strcpy(pStr, str);
        }
    }
    ~myString()
    {
        delete[] pStr;
    }

    myString(const myString &m_str)
    {
        if (pStr != NULL)
        {
            delete[] pStr;
        }
        pStr = new char[strlen(m_str.pStr) + 1];
        strcpy(pStr, m_str.pStr);
    }

    void set(char *str)
    {
        if (pStr != NULL)
        {
            delete[] pStr;
        }
        pStr = new char[strlen(str) + 1];
        strcpy(pStr, str);
    }

    void print()
    {
        cout << pStr;
    }
};

class String1 : public myString
{
public:
    String1(char *c = NULL) : myString(c) {}

    String1(const String1 &str) : myString(str) {}

    int getLen() const
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

    char *getStr() const
    {
        char *ptr = new char[getLen() + 1];
        for (int i = 0; i < getLen() + 1; i++)
        {
            ptr[i] = pStr[i];
        }
        return ptr;
    }

    String1 connect(const char *c) const
    {
        int len = getLen();
        char *ptr = new char[len + stringlength(c) + 1];
        for (int i = 0; i < len; i++)
        {
            ptr[i] = pStr[i];
        }
        for (int i = 0; i < stringlength(c) + 1; i++)
        {
            ptr[i + len] = pStr[i];
        }
        String1 str(ptr);
        return str;
    }

    int compare(const char *c) const
    {
        int i;
        for (i = 0; i < min(getLen(), stringlength(c)); i++)
        {
            if (pStr[i] != c[i])
            {
                return pStr[i] - c[i];
            }
        }
        return pStr[i] - c[i];
    }

    bool find(char *c) const
    {
        int len = stringlength(c);
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

    String1 get(int start, int end)
    {
    }
};

class String2 : public String1
{
public:
    String2(char *c) : String1(c) {}
    String2(const String2 &str) : String1(str) {}

    bool insert(int index, char *c)
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
            for (int i = 0; i < getLen(); i++)
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
            for (int i = index; i < getLen(); i++)
            {
                ptr[len + i] = pStr[i];
            }
        }
        delete[] pStr;
        pStr = ptr;
        return true;
    }

    bool Delete(char c)
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
};

int main()
{
    cout << 0;
    String1 a;
    cout << 1;
    String1 b("abc");
    const char *c = "abc";
    char *d = "hello";
    a.set(d);
    cout << 1;
    cout << (a.connect(c)).getStr();
}