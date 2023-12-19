/* findc_c walks str
   if ch occurs in str, return the index
   if not, return -1;
*/
int findc_c(char *str, char ch) {
    int idx = 0;
    while (*str) {
        if (*str == ch)
            return idx;
        str++;
        idx++;
    }
    return -1;
}

/* countc_c counts occurrences of ch in str
   by calling findc_c in a loop
*/
int countc_c(char *str, char ch) {
    int count = 0;
    while (*str) {
        int idx = findc_c(str, ch);
        if (idx != -1) {
            count++;
            str += idx + 1;
        } else {
            break;
        }
    }
    return count;
}
