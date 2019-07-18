#include <unistd.h>

int main(void)
{
    write(1, "main works", 10);

    return 0;
}