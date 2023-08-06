// Author: Mina Magdy

// Define a constant integer 'N' and 'MOD' for calculations
#define ll long long
const int N = 105, MOD = 1e9 + 7;

// Define a class Solution
class Solution {
public:
    // Declare vectors 'fact' and 'invFact' for factorial and inverse factorial calculations
    vector<ll> fact, invFact;
    
    // Constructor to initialize 'fact' and 'invFact' vectors
    Solution() {
        fact.resize(N);
        invFact.resize(N);
        fact[0] = invFact[0] = 1;
        
        // Calculate factorial and inverse factorial values for 1 to N-1
        for (int i = 1; i < N; i++) {
            fact[i] = fact[i - 1] * i % MOD;
            invFact[i] = invFact[i - 1] * powmod(i, MOD - 2) % MOD;
        }
    }
    
    // Function to calculate power (b^e) modulo MOD using binary exponentiation
    ll powmod(ll b, ll e) {
        ll prod = 1;
        while (e) {
            if (e & 1)
                prod = prod * b % MOD;
            e >>= 1;
            b = b * b % MOD;
        }
        return prod;
    }
    
    // the total number of different playlists of length goal of a set of i unique songs, and i could be any number from k to n (inclusive).
    ll F(ll n, ll goal, ll k) {
        return fact[n] * invFact[n - k] % MOD * powmod(n - k, goal - k) % MOD;
    }
    
    // Function to calculate the number of combinations (nCk)
    ll C(ll n, ll r) {
        return fact[n] * invFact[n - r] % MOD * invFact[r] % MOD;
    }
    
    // Function to calculate the number of possible music playlists
    int numMusicPlaylists(int n, int goal, int k) {
        ll ans = 0;
        // Iterate from 'k' to 'n'
        for (int i = k; i <= n; i++) {
            // Calculate the number of permutations and combinations
            // Subtract the previous answer from the new calculation
            ans = C(n, i) * F(i, goal, k) % MOD - ans;
            // Make sure the answer is non-negative
            ans += MOD;
            ans %= MOD;
        }
        // Return the final answer
        return ans;
    }
};
