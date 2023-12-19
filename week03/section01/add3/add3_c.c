int add2_c(int a, int b) {
    int sum = a + b;
    return sum;
}

int add3_c(int a, int b, int c) {
    int ab = add2_c(a, b);
    int abc = add2_c(ab, c);
    return abc;
}
