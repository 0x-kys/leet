#include <bits/stdc++.h>

std::string chatSignal(std::string s) {
    std::unordered_set<char> set;
    std::string CHAT = "CHAT WITH HER!";
    std::string IGNORE = "IGNORE HIM!";

    for (char c : s) {
        set.insert(c);
    }

    if (set.size() % 2 == 0) {
        return CHAT;
    } else {
        return IGNORE;
    }
}

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;

    std::cout << chatSignal(s) << std::endl;

    return 0;
}