void add1_c(int *pi, int len) {
    while (len >= 0) {
        int n = *pi;
        n++;
        *pi = n;
        len--;
        pi++;
    }
}
