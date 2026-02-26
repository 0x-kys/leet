#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;

    s[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[0])));

    std::cout << s << std::endl;

    return 0;
}