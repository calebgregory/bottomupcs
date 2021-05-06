/* https://www.bottomupcs.com/chapter01.xhtml#d0e2111 */
#include <stdio.h>

#define LOWER_MASK 0x0F
#define UPPER_MASK 0xF0

#define UPPER_PART 0x0A
#define LOWER_PART 0x05
#define COMPOSITE_VALUE 0xA5
/* Two 4-bit values stored in one 8-bit variable
 * 10100101 OxA5
 * 1010     0xA0
 *     0101 0x05
 */

int read(char value)
{
    printf("...Read...\n");
    /*
     * 10100101 OxA5
     * &&&&&&&&
     * 00001111 0x0F
     * 00000101 0x05
     */
    char lower = value & LOWER_MASK;
    /*
     * 10100101 OxA5
     * &&&&&&&&
     * 11110000 0xF0
     * 10100000 0xA0 -> 4 times
     */
    char upper = (value & UPPER_MASK) >> 4;

    printf("Value: %#04x\nLower: %#04x\nUpper: %#04x\n", value, lower, upper);

    return 0;
}

char write(char upper, char lower) {
    printf("...Write...\n");

    char value = 0;
    value |= (upper << 4);
    value |= lower;

    printf("Upper: %#04x\nLower: %#04x\nValue: %#04x\n", upper, lower, value);

    return value;
}

int main(int argc, char* argv[])
{
    char in = write(UPPER_PART, LOWER_PART);
    read(in);

    printf("...Testing against...\n");
    read(COMPOSITE_VALUE);
}

