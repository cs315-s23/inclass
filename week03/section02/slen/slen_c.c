int slen_c(char *s) {
    int len = 0;

    while (*s) {
        len++;
        s++;
    }

    return len;
}
