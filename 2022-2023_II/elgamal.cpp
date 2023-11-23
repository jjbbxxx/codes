//����ѧʵ��
//ElGamal ��Կ�����㷨
#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int pow_mod(int a, int b, int p);//Ԥ����
//�����㷨
void encryption(int m, int pub, int p, int g, int* c1, int* c2) {
    int k = 5;
    *c1 = pow_mod(g, k, p);
    *c2 = m * pow_mod(pub, k, p) % p;
}
//�����㷨
int decryption(int c1, int c2, int pri, int p, int g) {
    int m;
    int c1_ = pow_mod(c1, p - 2, p);
    m = c2 * pow_mod(c1_, pri, p) % p;
    return m;
}
//�ж��Ƿ�Ϊ����
int is_prime(int p) {
    int i;
    for (i = 2; i <= sqrt(p); i++) {
        if (p % i == 0)
            return 0;
    }
    return 1;
}

//��Կ�����㷨
int pow_mod(int a, int b, int p) {
    int ans = 1;
    int tmp = a % p;
    while (b) {
        if (b & 1)
            ans = ans * tmp % p;
        b >>= 1;
        tmp = tmp * tmp % p;
    }
    return ans % p;
}

//���Լӽ����㷨
int main() {
    int p;//����
    int g = 2;

    do {
        cout << "Please enter a prime number:" << endl;
        cin >> p;
    } while (!is_prime(p));
    cout << endl;

    cout << "Enter the private key of user A:" << endl;;
    int pri;
    cin >> pri;
    cout << endl;

    int pub;
    pub = pow_mod(g, pri, p);

    cout << "the public key of user A:" << endl << pub << endl;

    cout << "Input plaintext(smaller than " << p << ":" << endl;
    int m;
    cin >> m;

    int c1, c2;
    encryption(m, pub, p, g, &c1, &c2);
    cout << "The ciphertext encrypted with the public key is:" << endl << "c1= " << c1 << "    " << "c2= " << c2 << endl;;

    int m_ = decryption(c1, c2, pri, p, g);
    cout << "Plaintext decrypted with private key:" << m_;

    system("pause");
}

