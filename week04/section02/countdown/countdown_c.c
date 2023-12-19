int countdown_c(int n) {
    if (n == 0) 
        return n;

    return countdown_c(n - 1);
}
