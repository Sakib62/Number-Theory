#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void primeFactorization(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            int cnt = 0;
            while(n % i == 0) {
                cnt++;
                n /= i;
            }
            cout << i << " times " << cnt << "\n";
        }
    }
    if(n != 1) cout << n << " times 1\n";
}

void primeFactorizationOptimized(int n) {
    //keep smallest prime factor in each number.
    //first keep i to a[i], so that primes greater than i * i will hold their own value
    
    vector<int> spf(n + 1);
    for(int i = 2; i <= n; i++) {
        if(i & 1) spf[i] = i;
        else spf[i] = 2; //spf of even number is 2
    }
    
    for(int i = 3; i * i <= n; i++) {
        for(int j = i * i; j <= n; j += 2 * i) {
            if(spf[j] == j) //if the value is unchanged. // we only want to store the smallest factor.
                spf[j] = i;
        }
    }
        
    for(int i = 2; i <= n; i++) {
        int tmp = i;
        cout << i << ": ";
        while(tmp > 1) {
            cout << spf[tmp] << " ";
            tmp /= spf[tmp];
        }
        cout << "\n";
    }
}

int main() {
    
    int n = 40;
    //primeFactorization(n);
    primeFactorizationOptimized(n);


    return 0;
}
