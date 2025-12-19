#include <stdio.h>
#define SUM_BETWEEN(from, to) \
(((long long)(from) + (to)) * ((to) - (from) + 1) / 2)

long long sum_between(const int from_number, const int to_number) {
    return ((long long) from_number + to_number) * (to_number - from_number + 1) / 2;
}

int main(void) {
    printf("%lld\n", sum_between(-19, 112));
    return 0;
}
