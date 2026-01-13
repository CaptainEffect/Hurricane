#include <iostream>

int main() {
    int n;
    std::cin >> n;

    if (n <= 1) {
        std::cout << "Not Prime";
        return 0;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            std::cout << "Not Prime";
            return 0;
        }
    }

    std::cout << "Prime";
    return 0;
}
