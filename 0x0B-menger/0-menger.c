#include <stdio.h>
#include <stdlib.h>

#include "menger.h"

/**
 * menger - Function that draws a 2D Menger Sponge
 * @level: level to draw
 * Return: void
*/
void menger(int level)
{
int m, p, e, c, x;
char hash;
e = pow(3, level);
for (m = 0; m < e; m++)
{
for (p = 0; p < e; p++)
{
c = m;
x = p;
hash = '#';
while (c > 0)
{
if (c % 3 == 1 && x % 3 == 1)
hash = ' ';
c /= 3;
x /= 3;
}
printf("%c", hash);
}
printf("\n");
}
}
