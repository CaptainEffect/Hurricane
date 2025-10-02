#include <bits/stdc++.h>
using namespace std;

int power(int base, int exp) {
    int res = 1;
    while (exp--) res *= base;
    return res;
}

int main() {
    string n;
    cin >> n;

    int mra = stoi(n); 
    int q = n.size();
    int arm = 0;

    for (int i = 0; i < q; i++) {
        int t = n[i] - '0';  
        arm += power(t, q);  // avoid floating-point pow()
    }

    cout << arm << " " << mra << endl;

    if (arm == mra) cout << "yes" << endl;
    else cout << "no" << endl;
}
