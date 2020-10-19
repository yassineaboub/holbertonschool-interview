#include "sandpiles.h"

/**
 * grid_print - func that prints the grid
 * @grid: print the grid
 */
void grid_print(int grid[3][3])
{
int x = 0, i = 0;
printf("=\n");
for (x = 0; x < 3; x++)
{
for (x = 0; x < 3; x++)
{
printf("%d", grid[x][i]);
if (x < 2)
putchar(' ');
}
putchar('\n');
}
}
/**
 * toppling - sandpile thar turn around topple
 * @grid: sandpile
 * @topl: another grid
 * return: void
 */
void toppling(int grid[3][3], int topl[3][3])
{
int x = 0, i = 0;
for (x = 0; x < 3; x++)
{
for (i = 0; i < 3; i++)
{
if (topl[x][i] == 1)
{
grid[x][i] = grid[x][i] - 4;
if (x > 0)
grid[x - 1][i] = grid[x - 1][i] + 1;
if (x < 2)
grid[x + 1][i] = grid[x + 1][i] + 1;
if (i > 0)
grid[x][i - 1] = grid[x][i - 1] + 1;
if (i < 2)
grid[x][i + 1] = grid[x][i + 1] + 1;
}
}
}
}
/**
 * sandpiles_sum -  function that computes sum of two sandpiles
 * @grid1: 1st matrix
 * @grid2: 2nd matrix
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
int x = 0, i = 0, g = 0;
int topl[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
for (x = 0; x < 3; x++)
for (i = 0; i < 3; i++)
grid1[x][i] = grid1[x][i] + grid2[x][i];
while (1)
{
g = 0;
for (x = 0; x < 3; x++)
{
for (i = 0; i < 3; i++)
{
if (grid1[x][i] > 3)
{
topl[x][i] = 1;
g = 1;
}
else
{
topl[x][i] = 0;
}
}
}
if (g == 0)
return;
grid_print(grid1);
toppling(grid1, topl);
}
}
