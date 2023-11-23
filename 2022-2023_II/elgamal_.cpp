#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <cmath>

using namespace std;

int find_generator(int p) {
    for (int g = 2; g < p; g++) {
        if (fmod(pow(g, p - 1) ,p) == 1) {
            vector<int> order(p - 1);
            for (int i = 1; i <= p - 1; i++) {
                order[i - 1] = fmod(pow(g, i) , p);
            }
            sort(order.begin(), order.end());
            if (unique(order.begin(), order.end()) == order.end()) {
                return g;
            }
        }
    }
    throw invalid_argument("No generator found for the given prime p.");
}

pair<pair<int, int>, int> key_generation(int p) {
    int g = find_generator(p);
    int x = rand() % (p - 2) + 2;
    int y = fmod(pow(g, x) , p);
    return make_pair(make_pair(p, g), y), x;
}

pair<int, int> elgamal_encrypt(pair<pair<int, int>, int> pk, int m) {
    int p = pk.first.first;
    int g = pk.first.second;
    int y = pk.second;
    int k = rand() % (p - 2) + 2;
    int c1 = fmod(pow(g, k) , p);
    int c2 = fmod((m * pow(y, k)) , p);
    return make_pair(c1, c2);
}

int elgamal_decrypt(pair<int, int> sk, pair<int, int> c) {
    int p = sk.first;
    int x = sk.second;
    int c1 = c.first;
    int c2 = c.second;
    int s = fmod(pow(c1, x) , p);
    int s_inv = fmod(pow(s, p - 2), p);
    return (c2 * s_inv) % p;
}

pair<int, int> homomorphic_addition(pair<int, int> c1, pair<int, int> c2, int p) {
    return make_pair((c1.first * c2.first) % p, (c1.second * c2.second) % p);
}

int main() {
    srand(chrono::system_clock::now().time_since_epoch().count());
    
    // Example
    int p = pow(2, 16) + 1; // prime number
    auto [pk, sk] = key_generation(p);
     
    // Encryption
    auto m1 = 42;
    auto m2 = 23;
    
    auto c1 = elgamal_encrypt(pk, m1);
    auto c2 = elgamal_encrypt(pk, m2);
    
    // Homomorphic addition
    auto c3 = homomorphic_addition(c1, c2, p);
    
    // Decryption
    auto m3 = elgamal_decrypt(sk, c3);
    
    if (m3 == (m1 * m2) % p) {
        cout << "Verification succeeded: The result of homomorphic multiplication is correct." << endl;
    } else {
        cout << "Verification failed: The result of homomorphic multiplication is incorrect." << endl;
    }
}