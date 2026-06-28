#include <stdio.h>
#include <stdlib.h>

int read_number_in_range(bool convertingInt, int min, int max, void *out) {
    if (min > max) {
        printf("ERROR: min must not be greater than max\n");
        return 0;
    }

    char input[256];

    while (1) {
        if (!fgets(input, sizeof(input), stdin)) return 0;

        char *p_err;
        long v = strtol(input, &p_err, 10);


        if (v > max || v < min || p_err == input || (*p_err != '\0' && *p_err != '\n')) {
            printf("Invalid. Try again\n");
            continue;
        }

        if (convertingInt) *(int *) out = (int) v;
        else *(double *) out = (double) v;

        return 1;
    }
}

int main() {
    double scores[100];

    int count = 0;
    printf("How many scores do you want to enter? (1–100)\n");

    read_number_in_range(1, 1, 100, &count);

    for (int i = 0; i < count; i++) {
        printf("Enter score #%d:\n", i + 1);
        read_number_in_range(0, 1, 100, &scores[i]);
        // printf("%d: %.10f\n", i, scores[i]);
    }

    return 0;
}
