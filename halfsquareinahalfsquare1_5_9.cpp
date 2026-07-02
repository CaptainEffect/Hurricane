int n; std::cin >> n;
    
std::set<int> st;

int A = 1, B = n;
for (int i = 1; i <= ((n + 1) / 2); i++) {
    if (i % 2 != 0) {
        for (int z = 1; z < A; z++) {
            if (z % 2 != 0) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        
        for (int j = A; j <= B; j++) {
            std::cout << "*";
        }
        
        for (int y = B + 1; y <= n; y++) {
            if (y % 2 != 0) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        st.insert(A); st.insert(B);
        A = A + 2; B = B - 2;
    } else {//correctly work for even rows.
        for (int j = 1; j <= n; j++) {
            if (st.count(j)) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
    }
    
    std::cout << "\n";
}
