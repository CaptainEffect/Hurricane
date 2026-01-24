/*c a p t a i n k h a n*/
#include <bits/stdc++.h>
 
using i64 = long long;

bool isPrime(long long n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (long long i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

typedef struct {
    int left;
    int right;
} santa;
 
void solve() {
    i64 n;
    std::cin >> n;
    
    if (isPrime(n)) {
        std::cout << n << "\n";
    } else {
        std::vector<int> M;
        for (int i = 2; (long long)i * i <= n; i++)
        {
            if (n % i == 0)
            {
                M.push_back(i);
                if (i != n / i)
                    M.push_back(n / i);
            }
        }
        
        std::vector<santa> s(M.size());
        //santa arr[M.size()];
        for (int i= 0; i < M.size(); i++) {
            int divs = 0;
            // for (int j = 1; j <= M[i]; j++) {
            //     if (M[i] % j == 0) {
            //         divs++;
            //     }
            // }
            for (int j = 1; (long long)j * j <= M[i]; j++) {
                if (M[i] % j == 0) {
                    divs++;
                    if (j != M[i] / j)
                        divs++;
                }
            }
            s[i].left = M[i];
            s[i].right = divs;
        }
        std::sort(s.begin(), s.end(), [](const santa &a, const santa &b) {
            return a.right < b.right;
        });
        
        std::cout << n / s[M.size() - 1].left << "\n";
    }
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t; 
    std::cin >> t;
    
    while (t--) {
        solve();
    }
 
    return 0;
}
