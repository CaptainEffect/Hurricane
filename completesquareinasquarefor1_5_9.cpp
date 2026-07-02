int n; std::cin >> n;

std::set<int> st;

std::vector<std::vector<char>> mat;

int A = 1, B = n;
for (int i = 1; i <= ((n + 1) / 2); i++) {

    std::vector<char> row;

    if (i % 2 != 0) {
        for (int z = 1; z < A; z++) {
            if (z % 2 != 0) {
                std::cout << "*";
                row.push_back('*');
            } else {
                std::cout << " ";
                row.push_back(' ');
            }
        }

        for (int j = A; j <= B; j++) {
            std::cout << "*";
            row.push_back('*');
        }

        for (int y = B + 1; y <= n; y++) {
            if (y % 2 != 0) {
                std::cout << "*";
                row.push_back('*');
            } else {
                std::cout << " ";
                row.push_back(' ');
            }
        }

        st.insert(A);
        st.insert(B);
        A = A + 2;
        B = B - 2;
    }
    else { // correctly work for even rows.
        for (int j = 1; j <= n; j++) {
            if (st.count(j)) {
                std::cout << "*";
                row.push_back('*');
            } else {
                std::cout << " ";
                row.push_back(' ');
            }
        }
    }

    mat.push_back(row);

    std::cout << "\n";
}

for (int i = mat.size() - 2; i >= 0; i--) {
    for (char c : mat[i])
        std::cout << c;
    std::cout << "\n";
}
