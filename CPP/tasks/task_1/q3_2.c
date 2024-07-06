#include <stdio.h>

void decimalToBinary(long int decimal) {
    if (decimal == 0) {
        printf("0");
        return;
    }

    int binary[64];
    int index = 0;

    while (decimal > 0) {
        binary[index] = decimal % 2;
        decimal = decimal / 2;
        index++;
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}


int main() {
    long int decimal;

    printf("Enter a decimal number: ");
    scanf("%ld", &decimal);

    printf("The binary equivalent of %ld is ", decimal);
    decimalToBinary(decimal);
    printf("\n");

    return 0;
}

