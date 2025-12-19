#include <stdio.h>
#include <stdlib.h>
#define SUM_BETWEEN(from, to) \
(((from) + (to)) * ((to) - (from) + 1) / 2)


void print_array(const int *arr, const int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
}

int sum_between(const int from_number, const int to_number) {
    return (from_number + to_number) * (to_number - from_number + 1) / 2;
}

void fill_sum_array(int *arr, const int from_number, const int to_number, const int total_elements, const int sum) {
    arr[0] = from_number;
    arr[1] = to_number;

    int i;
    for (i = 2; i < total_elements - 1; i++) {
        arr[i] = from_number + (i - 2);
    }

    arr[total_elements - 1] = sum;
}

int array_sum_between(const int from_number, const int to_number) {
    const int number_of_numbers_to_sum = to_number - from_number + 1;
    const int number_of_array_elements = number_of_numbers_to_sum + 3;

    int *arr = malloc(number_of_array_elements * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        exit(1);
    }

    const int sum = sum_between(from_number, to_number);
    fill_sum_array(arr, from_number, to_number, number_of_array_elements, sum);
    print_array(arr, number_of_array_elements);

    free(arr);
    return sum;
}

int main(void) {
    printf("%d\n", array_sum_between(-19, 112));
    return 0;
}
