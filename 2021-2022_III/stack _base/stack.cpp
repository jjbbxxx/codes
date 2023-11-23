#include "stack.h"
Stack::Stack()
{
    sdata.init();
    len = 0;
}
int Stack::empty()
{
    return sdata.empty();
}
int Stack::push(Mydata md)
{
    Node *p = new Node;
    p->data = md;
    sdata.add(p);
    return 1;
}
int Stack::pop(Mydata &md)
{
    if (sdata.getfirst(md))
    {
        sdata.del(md);
        return 1;
    }
    else
        return 0;
}
void Stack::print()
{
    sdata.print();
}
int Stack::write(const char c[])
{
    for (int i = strlen(c); i >= 0; i--)
    {
        push(*(c + i));
    }
    len = strlen(c);
    return 1;
}
Stack Stack::encode()
{
    const char *table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    long nlen;
    if (len % 3 == 0)
        nlen = (len / 3) * 4;
    else
        nlen = (len / 3 + 1) * 4;
    char *res = new char[nlen + 1];
    for (int i = 0, j = 0; i < nlen - 2; j += 3, i += 4)
    {
        res[i] = table[sdata.get(j) >> 2];
        res[i + 1] = table[(sdata.get(j) & 0x3) << 4 | (sdata.get(j + 1) >> 4)];
        res[i + 2] = table[(sdata.get(j + 1) & 0xf) << 2 | (sdata.get(j + 2) >> 6)];
        res[i + 3] = table[sdata.get(j + 2) & 0x3f];
    }
    if (len % 3 == 2)
        res[nlen - 1] = '=';
    if (len % 3 == 1)
    {
        res[nlen - 1] = '=';
        res[nlen - 2] = '=';
    }
    Stack s;
    s.write(res);
    delete[] res;
    return s;
}

Stack Stack::decode()
{
    const int table[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 62, 0, 0, 0,
                         63, 52, 53, 54, 55, 56, 57, 58,
                         59, 60, 61, 0, 0, 0, 0, 0, 0, 0, 0,
                         1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
                         13, 14, 15, 16, 17, 18, 19, 20, 21,
                         22, 23, 24, 25, 0, 0, 0, 0, 0, 0, 26,
                         27, 28, 29, 30, 31, 32, 33, 34, 35,
                         36, 37, 38, 39, 40, 41, 42, 43, 44,
                         45, 46, 47, 48, 49, 50, 51};
    long nlen;
    if (sdata.get(len - 1) == '=' && sdata.get(len - 2) == '=')
        nlen = (len / 4) * 3 - 2;
    else if (sdata.get(len - 1) == '=' && sdata.get(len - 2) != '=')
        nlen = (len / 4) * 3 - 1;
    else
        nlen = len / 4 * 3;
    char *res = new char[nlen + 1];

    for (int i = 0, j = 0; i < len - 2; j += 3, i += 4)
    {
        res[j] = ((char)table[sdata.get(i)]) << 2 | (((char)table[sdata.get(i + 1)]) >> 4);
        res[j + 1] = (((char)table[sdata.get(i + 1)]) << 4) | (((char)table[sdata.get(i + 2)]) >> 2);
        res[j + 2] = (((char)table[sdata.get(i + 2)]) << 6) | ((char)table[sdata.get(i + 3)]);
    }
    Stack s;
    s.write(res);
    delete[] res;
    return s;
}