char* pangrams(char* s) {
    int letters[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c >= 'A' && c <= 'Z') {
            letters[c - 'A'] = 1;
        } else if (c >= 'a' && c <= 'z') {
            letters[c - 'a'] = 1;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (letters[i] == 0) {
            return "not pangram";
        }
    }
    return "pangram";
}
