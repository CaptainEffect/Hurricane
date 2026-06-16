#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

int main() {
    std::vector<std::string> tree = {
        "          \\ /",
        "        -->*<--",
        "          /_\\",
        "         /_\\_\\",
        "        /_/_/_\\",
        "        /_\\_\\_\\",
        "       /_/_/_/_\\",
        "       /_\\_\\_\\_\\",
        "      /_/_/_/_/_\\",
        "      /_\\_\\_\\_\\_\\",
        "     /_/_/_/_/_/_\\",
        "     /_\\_\\_\\_\\_\\_\\",
        "    /_/_/_/_/_/_/_\\",
        "         [___]"
    };

    // Light up rows from bottom to top
    for (int lit = (int)tree.size() - 2; lit >= 2; lit--) {
        std::cout << "\033[2J\033[H"; // Clear screen

        for (int i = 0; i < (int)tree.size(); i++) {
            for (char c : tree[i]) {
                if (c == '*') {
                    std::cout << "\033[32m" << c << "\033[0m";
                } else if (c == '_') {
                    if (i >= lit)
                        std::cout << "\033[91m" << c << "\033[0m"; // Yellow light
                    else
                        std::cout << "\033[32m" << c << "\033[0m"; // Green
                } else if (c == '/' || c == '\\') {
                    std::cout << "\033[32m" << c << "\033[0m"; // Green branches
                } else {
                    std::cout << c;
                }
            }
            std::cout << '\n';
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    // Final frame: make the star yellow too
    std::cout << "\033[2J\033[H";

    for (const std::string &line : tree) {
        for (char c : line) {
            if (c == '*') {
                std::cout << "\033[93m" << c << "\033[0m";
            } else if (c == '_') {
                std::cout << "\033[93m" << c << "\033[0m";
            } else if (c == '/' || c == '\\') {
                std::cout << "\033[32m" << c << "\033[0m";
            } else {
                std::cout << c;
            }
        }
        std::cout << '\n';
    }

    return 0;
}