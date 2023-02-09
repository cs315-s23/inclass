#include <string.h>

/* findc_c takes a string and a char
   returns the index of char in string or -1 if char doesn't occur
*/
int findc_c(char *str, char ch) {
    for (int i = 0; i < (int) strlen(str); i++) {
        // if (str[i] == ch)
        if (*(str + i) == ch)
            return i;
    }
    return -1;
}

/* countc_c takes a string and a char
   returns the count of ch occurrences in str
*/
int countc_c(char *str, char ch) {
    int count = 0;
    int index;

    while ((index = findc_c(str, ch)) != -1) {
        str += index + 1;
        count++;
    }

    return count;
}
