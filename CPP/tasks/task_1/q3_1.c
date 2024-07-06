#include <stdio.h>

long int binaryToDecimal(long int binary);

void main() {
    long int binary;

    printf("Enter a binary number: ");
    scanf("%ld", &binary);
    long int decimal = binaryToDecimal(binary);

    printf("The decimal number is %ld\n",decimal);

}

long int binaryToDecimal(long int binary) {
    long int decimal = 0;
    int base = 1; 
    int last_digit;

    while (binary > 0) {
        last_digit = binary % 10; // Get the last digit of the binary number
        binary = binary / 10; // Remove the last digit from the binary number
        decimal += last_digit * base; // Add the contribution of the current digit
        base *= 2; // Move to the next power of 2
    }

    return decimal;
}
