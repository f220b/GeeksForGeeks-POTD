class Solution:
    def prefixStrings(self, n: int) -> int:
        MOD = 10**9 + 7
    
        if n == 0:
            return 1  # empty string is trivially valid
    
        N = 2 * n
    
        # Precompute factorials mod p
        fact = [1] * (N + 1)
        for i in range(1, N + 1):
            fact[i] = fact[i - 1] * i % MOD
    
        # Precompute inverse factorials mod p (Fermat's little theorem)
        inv_fact = [1] * (N + 1)
        inv_fact[N] = pow(fact[N], MOD - 2, MOD)
        for i in range(N, 0, -1):
            inv_fact[i - 1] = inv_fact[i] * i % MOD
    
        # C(2n, n) mod p
        binom = fact[N] * inv_fact[n] % MOD * inv_fact[n] % MOD
    
        # Catalan number: C(2n, n) / (n + 1)
        inv_n_plus_1 = pow(n + 1, MOD - 2, MOD)
        catalan = binom * inv_n_plus_1 % MOD
    
        return catalan