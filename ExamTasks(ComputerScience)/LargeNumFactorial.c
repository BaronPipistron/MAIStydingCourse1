#include <stdio.h>
#include <inttypes.h>

int main()
{
    int64_t num[1000] = {0};
    num[0] = 1;
    int64_t len = 1;
    int64_t factorial = 150;
    int64_t carry;

    for (int64_t i = 1; i <= factorial; ++i) {
        carry = 0;

        for (int64_t j = 0; j < len; ++j) {
            num[j] = num[j] * i + carry;

            carry = num[j] / 10;
            num[j] = num[j] % 10;
        }

        while (carry != 0) {
            num[len] = carry % 10;
            carry = carry / 10;
            ++len;
        }
        printf("\n");
    }

    printf("%lld! = ", factorial);
    --len;
    while (len >= 0) {
        printf("%lld", num[len]);
        --len;
    }

    return 0;
}