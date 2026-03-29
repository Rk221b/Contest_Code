#include <iostream>
#include <vector>

using namespace std;

/**
 * Binary Exponentiation
 * Computes (base^exp) % mod in O(log exp) time.
 */
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

/**
 * Multiplicative Modulo Inverse
 * Uses Fermat's Little Theorem: a^(p-2) % p
 * Only works when mod is prime and a is not a multiple of mod.
 */
long long modInverse(long long n, long long mod) {
    return power(n, mod - 2, mod);
}

// Global arrays for O(1) nCr lookup after precomputation
const int MAXN = 1000005; 
long long fact[MAXN];
long long invFact[MAXN];

/**
 * Precompute Factorials and Inverse Factorials
 * Time Complexity: O(N + log MOD)
 */
void precompute(int n, long long mod) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    // Step 1: Compute inverse of the LAST factorial using power()
    invFact[n] = modInverse(fact[n], mod);

    // Step 2: Fill backwards in O(N)
    // Formula: invFact[i] = invFact[i+1] * (i+1)
    for (int i = n - 1; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
    }
}

/**
 * nCr Function
 * Formula: n! / (r! * (n-r)!)
 */
long long nCr(int n, int r, long long mod) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % mod) * invFact[n - r]) % mod;
}

int main() {
    long long MOD = 1e9 + 7;
    int N_limit = 1000000;

    // Initialize the tables
    precompute(N_limit, MOD);

    // Example queries
    cout << "5C2 mod 10^9+7: " << nCr(5, 2, MOD) << endl;    // Output: 10
    cout << "10C3 mod 10^9+7: " << nCr(10, 3, MOD) << endl;  // Output: 120
    cout << "50C25 mod 10^9+7: " << nCr(50, 25, MOD) << endl;

    return 0;
}
