#include <stdio.h>
#include <stdlib.h>
#define SUM_BETWEEN(from, to) \
(((from) + (to)) * ((to) - (from) + 1) / 2)


void print_array(const int *arr, const int size) {
    int i;
    printf("The array contents are : ");
    for (i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
    printf("\n");
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
    printf("The numbers received were %d and %d.\n", from_number, to_number);

    const int number_of_numbers_to_sum = to_number - from_number + 1;
    const int number_of_array_elements = number_of_numbers_to_sum + 3;

    int *arr = malloc(number_of_array_elements * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        exit(1);
    }

    const int sum = sum_between(from_number, to_number);
    printf("The sum between them is %d.\n", sum);
    fill_sum_array(arr, from_number, to_number, number_of_array_elements, sum);
    print_array(arr, number_of_array_elements);

    free(arr);
    return sum;
}

int main(void) {
    int from_number, to_number;
    printf("Enter a start and end number: ");
    scanf("%d %d", &from_number, &to_number);

    printf("Calling function sum_between with numbers %d and %d.\n", from_number, to_number);
    const int sum_between_func_result = sum_between(from_number, to_number);
    printf("The sum received from function sum_between is %d.\n", sum_between_func_result);

    printf("Calling macro SUM_BETWEEN with numbers %d and %d.\n", from_number, to_number);
    const int sum_between_macro_result = SUM_BETWEEN(from_number, to_number);
    printf("The sum received from macro SUM_BETWEEN is %d.\n", sum_between_macro_result);

    printf("Calling function array_sum_between with numbers %d and %d.\n", from_number, to_number);
    const int array_sum_between_func_result = array_sum_between(from_number, to_number);
    printf("The sum received from function array_sum_between is %d.\n", array_sum_between_func_result);

    return 0;
}
