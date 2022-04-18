#include <iostream>
#include<vector>
using namespace std;
#define max 86028121

bool isPrime[86028122];
vector<int> prime;

void sieve() {
    
    isPrime[0] = isPrime[1] = true; //not prime
    for(int i = 4; i <= max; i += 2) 
        isPrime[i] = true;
        
    for(int i = 3; i * i <= max; i += 2) {
        if(!isPrime[i]) {
            for(int j = i * i; j <= max; j += 2*i) {
                isPrime[j] = true;
            }
        }
    }
    
    prime.push_back(2);
    for(int i = 3; i <= max; i += 2) {
        if(!isPrime[i]) prime.push_back(i);
    }
}


int main() {

    sieve();
    int t, n;
    cin >> t;
    while(t--) 
        cin >> n, cout << prime[n - 1] << "\n";
    
    return 0;
}
