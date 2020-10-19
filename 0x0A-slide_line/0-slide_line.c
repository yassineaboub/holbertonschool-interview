#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

/**
 * slide_line - Function that slides and merges an array of integers.
 * @line: array of integers
 * @size: size of elements
 * @direction: direction
 * Return: 1 in success, otherwise 0
 */

int slide_line(int *line, size_t size, int direction)
{

size_t d = 0, p = 0, t = 1, o = size;
int g = -1;
if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
{
return (0);
}
if (direction == SLIDE_RIGHT)
{
d = size - 1;
p = size - 1;
t = -1;
o = -1;
}
while (d != o)
{
if (*(line + d) != 0)
{
if (g == *(line + d))
{
*(line + d) += g;
g = -1;
}
else
{g = *(line + d);
if ((direction == SLIDE_LEFT && d != 0)
||
((direction == SLIDE_RIGHT && d != (size - 1))))
if (*(line + p) != 0)
p += t;
}

*(line + p) = *(line + d);
if (p != d)
*(line + d) = 0;
}
d += t;
}
return (1);
}
