#include <bits/stdc++.h>
using namespace std;
int n = 13;
void print(int data[])
{
    int i = 0;
    while (i < n)
    {
        cout << data[i] << " ";
        i++;
    }
    cout << endl;
}
void ins(int data[], int n)
{
    int i;

    for (int p = 1; p < n; p++)
    {
        int temp = data[p];
        i = p - 1;
        while (i >= 0 && data[i] > temp)
        {
            data[i + 1] = data[i];
            i--;
        }
        data[i + 1] = temp;
        cout << p << ": ";
        print(data);
    }
}
void binins(int data[], int n)
{

    int l, m, r;
    for (int p = 1; p < n; p++)
    {
        int temp = data[p];
        l = 0;
        r = p - 1;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (data[m] > temp)
                r = m - 1;
            else
                l = m + 1;
        }
        for (int i = p - 1; i >= l; i--)
        {
            data[i + 1] = data[i];
        }
        data[l] = temp;
        cout << p << ": ";
        print(data);
    }
}
void shell(int data[], int n)
{

    int d = n / 2, t = 1;
    while (d >= 1)
    {
        cout << "d=" << d << " ";
        for (int k = 0; k < d; k++)
        {
            for (int i = k + d; i < n; i += d)
            {
                int temp = data[i];
                int j = i - d;
                while (j >= k && data[j] > temp)
                {
                    data[j + d] = data[j];
                    j -= d;
                }
                data[j + d] = temp;
            }
        }
        d /= 2;
        cout << t << ": ";
        print(data);
        t++;
    }
}
void bubble(int data[], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            if (data[j] < data[j - 1])
            {
                int t = data[j];
                data[j] = data[j - 1];
                data[j - 1] = t;
            }
        }
        cout << i + 1 << ": ";
        print(data);
    }
}

int part(int data[], int left, int right)
{
    int p = data[left];
    while (left < right)
    {
        while (left < right && data[right] > p)
            right--;
        data[left] = data[right];
        while (left < right && data[left] <= p)
            left++;
        data[right] = data[left];
    }
    data[left] = p;
    cout << p << ": ";
    print(data);
    return left;
}
void quick(int data[], int left, int right)
{
    if (right <= left)
        return;
    if (left < right)
    {
        int p = part(data, left, right);
        quick(data, left, p - 1);
        quick(data, p + 1, right);
    }
}
void select(int data[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int k = i - 1;
        for (int j = i; j < n; j++)
        {
            if (data[j] < data[k])
                k = j;
        }
        if (k != i - 1)
        {
            int t = data[k];
            data[k] = data[i - 1];
            data[i - 1] = t;
        }
        cout << i << ": ";
        print(data);
    }
}

void siftdown(int data[], int i, int n)
{
    int l = 2 * i + 1, r = 2 * i + 2, min = i;
    if (l < n && data[min] < data[l])
        min = l;
    if (r < n && data[min] < data[r])
        min = r;
    if (min != i)
    {
        int t = data[min];
        data[min] = data[i];
        data[i] = t;
        siftdown(data, min, n);
    }
}

void buildheap(int data[], int n)
{
    int p = n / 2 - 1;
    for (int i = p; i >= 0; i--)
    {
        siftdown(data, i, n);
    }
}

void heapsort(int data[], int n)
{
    buildheap(data, n);
    int x = 1;
    for (int i = n - 1; i > 0; i--)
    {
        int t = data[0];
        data[0] = data[i];
        data[i] = t;
        siftdown(data, 0, i);
        cout << x << ": ";
        print(data);
        x++;
    }
}

void mge(int data[], int start, int mid, int end)
{
    int len1 = mid - start + 1, len2 = end - mid;
    int i, j, k;
    int *left = new int[len1];
    int *right = new int[len2];
    for (i = 0; i < len1; i++)
        left[i] = data[i + start];
    for (i = 0; i < len2; i++)
        right[i] = data[i + mid + 1];
    i = 0, j = 0;
    for (k = start; k < end; k++)
    {
        if (i == len1 || j == len2)
            break;
        if (left[i] <= right[j])
            data[k] = left[i++];
        else
            data[k] = right[j++];
    }
    while (i < len1)
        data[k++] = left[i++];
    while (j < len2)
        data[k++] = right[j++];
    delete[] left;
    delete[] right;
}
int mergex = 1;
void merge(int data[], int start, int end)
{
    int n = end - start + 1;
    if (end <= start)
        return;
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge(data, start, mid);
        merge(data, mid + 1, end);
        mge(data, start, mid, end);
        cout << mergex++ << ": ";
        print(data);
    }
}
const int RADIX = 10;
template <class T>
struct LinkNode
{
    T data;
    LinkNode *next;
};
template <class T>
struct TubNode
{
    LinkNode<T> *rear;
    LinkNode<T> *front;
};
template <class T>
TubNode<T> *Distribute(T data[], int n, int ith)
{
    TubNode<T> *tube = new TubNode<T>[RADIX];
    memset(tube, 0, sizeof(TubNode<T>) * RADIX);
    LinkNode<T> *t;
    for (int i = 0; i < n; i++)
    {
        T v = data[i];
        int j = ith - 1;
        while (j--)
            v = v / RADIX;
        v = v % RADIX;
        t = new LinkNode<T>;
        t->data = data[i];
        t->next = NULL;
        if (tube[v].front)
        {
            tube[v].rear->next = t;
            tube[v].rear = t;
        }
        else
        {
            tube[v].front = tube[v].rear = t;
        }
    }
    return tube;
}

template <class T>
void Collect(T Data[], TubNode<T> *tube)
{
    LinkNode<T> *t, *p;
    int index = 0;
    for (int i = 0; i < RADIX; i++)
    {
        p = t = tube[i].front;
        while (t)
        {
            Data[index++] = t->data;
            t = t->next;
            delete p;
            p = t;
        }
    }
    delete[] tube;
}
template <class T>
void RadixSort(T Data[], int n, int keys)
{
    TubNode<T> *tube;
    for (int i = 0; i < keys; i++)
    {
        tube = Distribute<T>(Data, n, i + 1);
        Collect<T>(Data, tube);
        cout << i + 1 << ": ";
        for (int j = 0; j < n; j++)
            cout << Data[j] << " ";
        cout << endl;
    }
}

int main()
{
    /*srand((unsigned)time(NULL));
    int num[n];
    cout << "numbers:";
    for (int i = 0; i < n; i++)
    {
        num[i] = rand() % 100;
        cout << num[i] << " ";
    }
    cout << endl;*/
    int num[]={60,40,120,185,20,135,150,130,45};
    n=9;
    //cout << "²åÈëÅÅÐò£º" << endl;
    //ins(num, n);
    //cout << "ÕÛ°ë²åÈë£º" << endl;
    //binins(num, n);
    //cout << "Ï£¶ûÅÅÐò£º" << endl;
    //shell(num, n);
    //cout << "Ã°ÅÝÅÅÐò£º" << endl;
    //bubble(num, n);
    //cout << "¿ìËÙÅÅÐò£º" << endl;
    //quick(num, 0, n - 1);
    //cout << "¼òµ¥Ñ¡Ôñ£º" << endl;
    //select(num, n);
    //cout << "¶ÑÅÅÐò£º" << endl;
    //heapsort(num, n);
    //cout << "¹é²¢ÅÅÐò" << endl;
    merge(num, 0, n - 1);
    //cout << "»ùÊýÅÅÐò£º" << endl;
    //RadixSort(num, n, 2);
    return 0;
}