#include <stdio.h>
#include <stdlib.h>

int read_int_in_range(int min, int max, int *out) {
    if (min > max) {
        printf("ERROR: min must not be greater than max\n");
        return 0;
    }

    char input[256];

    while (1) {
        printf("Please enter a valid number between %d and %d\n", min, max);

        if (!fgets(input, sizeof(input), stdin)) return 0;

        char *p_err;
        long v = strtol(input, &p_err, 10);


        if (v > max || v < min || p_err == input || (*p_err != '\0' && *p_err != '\n')) {
            printf("Invalid\n\n");
            continue;
        }

        *out = (int) v;
        return 1;
    }
}

int main() {
    double scores[100];

    int count = 0;
    printf("how many scores do you want to enter? (1–100)\n");

    if (!read_int_in_range(1, 100, &count)) return 0;

    // for (int i = 0; i < count; i++) {
    //
    // }
    return 0;
}
