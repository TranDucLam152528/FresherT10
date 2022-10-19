#include <stdio.h>
#include <string.h>
#include <stdint.h>


uint8_t PORTA = 0b11011001;

const char *byte_to_binary(int x)  //
{
    static char b[9];
    b[0] = '\0';
    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }
    return b;
}

void BlinkLED(uint8_t PIN, uint8_t status){
 PORTA = (PORTA & ((0b11111110+status)<<(PIN-1)))|((0b00000000+status)<<(PIN-1));
}

int main(int argc, char const *argv[])
{
    BlinkLED(5,0);
    printf("%s\n", byte_to_binary(PORTA));
    return 0;
}