#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double min;
    double max;
    double avg;
} Stats;

Stats get_stats_from_array(double array[], int size) {
    Stats s = {.min = 100, .max = 0, .avg = 0.0};

    for (int i = 0; i < size; ++i) {
        if (array[i] < s.min) s.min = array[i];
        if (array[i] > s.max) s.max = array[i];
        s.avg += array[i];
    }
    s.avg /= size;
    return s;
}

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

    Stats s = get_stats_from_array(scores, count);

    printf("\n---------------------------------------------------------------\n");
    printf("Count: %d\n", count);
    printf("Minimum: %f\n", s.min);
    printf("Maximum: %f\n", s.max);
    printf("Average: %f\n", s.avg);
    printf("Letter grade for average: ");
    if (s.avg >= 90.00 && s.avg <= 100.00) printf("A");
    else if (s.avg >= 80.00 && s.avg < 90.00) printf("B");
    else if (s.avg >= 70.00 && s.avg < 80.00) printf("C");
    else if (s.avg >= 60.00 && s.avg < 70.00) printf("D");
    else printf("F");

    return 0;
}
