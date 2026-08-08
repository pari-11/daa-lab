#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;

    cout << "Enter the first string: ";
    cin >> s1;

    cout << "Enter the second string: ";
    cin >> s2;

    if (s1.length() != s2.length()) {
        cout << "The strings are not anagrams.";
        return 0;
    }

    int count[256] = {0};

    for (int i = 0; i < s1.length(); i++) {
        count[s1[i]]++;
        count[s2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            cout << "The strings are not anagrams.";
            return 0;
        }
    }

    cout << "The strings are anagrams.";

    return 0;
}