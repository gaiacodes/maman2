/* This program receives to whole numbers separated by a space.
* It assumes the input is valid and that the second number is bigger than the first.
 *
 * Then it does the following:
 * 1) Calls the function sum_between that calculates the sum of all integers from the first to the second number.
 * 2) Calls the macro SUM_BETWEEN that calculates the sum of all integers from the first to the second number.
 * 3) Calls the function array_sum_between which prints an array that contains the two integers,
 * all integers between them and the sum of these integers.
 */

#include <stdio.h>
#include <stdlib.h>
/* receives two integers and returns the sum of all integers between them.
 * calculate the sum of the numbers between the two numbers using Gauss Sum.*/
#define SUM_BETWEEN(from, to) \
(((from) + (to)) * ((to) - (from) + 1) / 2)

/* receives a pointer to an array of integers and the array's size and prints it*/
void print_array(const int *arr, int size);

/* receives two integers and returns the sum of all integers between them.*/
int sum_between(int from_number, int to_number);

/* receives an array, two integers, the sum of all integers between them and the size of the array.
 * prints an array that contains the two integers, all integers between them and their sum.
 * returns the sum.*/
void fill_sum_array(int *arr, int from_number, int to_number, int total_elements, int sum);

/* receives two integers, prints an array that contains the two integers, all integers between them and the sum of these integers.*/
int array_sum_between(int from_number, int to_number);

int main(void) {
    int from_number, to_number;
    int sum_between_func_result;
    int sum_between_macro_result;
    int array_sum_between_func_result;

    printf("Enter a start and end number: ");
    scanf("%d %d", &from_number, &to_number);

    printf("Calling function sum_between with numbers %d and %d.\n", from_number, to_number);
    sum_between_func_result = sum_between(from_number, to_number);
    printf("The sum received from function sum_between is %d.\n", sum_between_func_result);

    printf("Calling macro SUM_BETWEEN with numbers %d and %d.\n", from_number, to_number);
    sum_between_macro_result = SUM_BETWEEN(from_number, to_number);
    printf("The sum received from macro SUM_BETWEEN is %d.\n", sum_between_macro_result);

    printf("Calling function array_sum_between with numbers %d and %d.\n", from_number, to_number);
    array_sum_between_func_result = array_sum_between(from_number, to_number);
    printf("The sum received from function array_sum_between is %d.\n", array_sum_between_func_result);

    return 0;
}

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
    /* calculate the sum of the numbers between the two numbers using Gauss Sum*/
    return (from_number + to_number) * (to_number - from_number + 1) / 2;
}

void fill_sum_array(int *arr, const int from_number, const int to_number, const int total_elements, const int sum) {
    int i;
    arr[0] = from_number;
    arr[1] = to_number;

    for (i = 2; i < total_elements - 1; i++) {
        arr[i] = from_number + (i - 2);
    }

    arr[total_elements - 1] = sum;
}

int array_sum_between(const int from_number, const int to_number) {
    int number_of_numbers_to_sum;
    int number_of_array_elements;
    int *arr;
    int sum;

    printf("The numbers received were %d and %d.\n", from_number, to_number);

    number_of_numbers_to_sum = to_number - from_number + 1;
    number_of_array_elements = number_of_numbers_to_sum + 3;

    arr = malloc(number_of_array_elements * sizeof(int));
    /* exit the program if the memory allocation failed.*/
    if (arr == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        exit(1);
    }

    sum = sum_between(from_number, to_number);
    printf("The sum between them is %d.\n", sum);
    fill_sum_array(arr, from_number, to_number, number_of_array_elements, sum);
    print_array(arr, number_of_array_elements);

    free(arr);
    return sum;
}
