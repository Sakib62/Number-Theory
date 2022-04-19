#include <iostream>
using namespace std;

#define p 1000000007

long long binaryExponentiation(long long a, long long n) {
    //a^n
    long long res = 1;
    while(n) {
        if(n % 2) res = (res * a) % p;
        a = (a * a) % p;
        n >>= 1;
    }
    return res;
}

int main() {

    cout << binaryExponentiation(101398479183, 1102739012);
}

//Time Complexity: o(logn)

/* find 2^13
  Res   Base    Power
  1     2       13
  2     2       12
  2     4       6
  2     16      3
  32    16      2
  32    256     1
  8192  256     0
  
  If power is even, we split power by 2, increase base by itself. Basically 2^12 == 2^2*6 == 4^6
  If power is odd, we multiply res by base, decrease power by 1. So when division is not equal, we give extra portion to res. Then in next step division becomes equal.
  
  Here we don't need to decrease power by 1, as in next steps it will automatically be divided by integer division.
  Also, we don't need to write else for even power. Then, we will only increase total iteration of while loop. 
  Just after handling odd case, we can continue with out dividing process.
  
  For Modular Binary Exponentiation, we just need to handle multiplication statements.
  Also, use of Bitwise operator helps execute the code faster. Hence, we use n >>= 1 instead of n /= 2

*/
