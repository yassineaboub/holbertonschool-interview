#include <stdlib.h>
#include <stdio.h>

/**
 * grid_is_perfect - check if a grid is perfect
 * @grid: sandpile
 * Return: 1 if grid is perfect, otherwise 0
 */

int grid_is_perfect(int grid[3][3])
{
int i = 0;
int j = 0;
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (grid[i][j] > 3)
return (0);
}
}
return (1);
}
/**
 * grid_addition - add two grids
 * @grid1: 1st matrix
 * @grid2: 2nd matrix
 */

void addition_in_grid(int grid1[3][3], int grid2[3][3])
{
int i, j;
                                                                                                        for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
grid1[i][j] = grid1[i][j] + grid2[i][j];
}
}
}

/**
 * grid_print - print grid
 * @grid: sandpile
 */

void grid_print(int grid[3][3])
{
int i = 0;
int j = 0;
printf("=\n");
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (j)
printf(" ");
printf("%d", grid[i][j]);
}
printf("\n");
}
}

/**
 * grid_change - modify grid value
 * @grid1: sandpile
 */

void change_grid(int grid1[3][3])
{
int i = 0;
int j = 0;
int gridx[3][3];
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
gridx[i][j] = 0;
}
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (grid1[i][j] > 3)
{
grid1[i][j] = grid1[i][j] - 4;
if ((i - 1) >= 0 && (i - 1) < 3)
gridx[i - 1][j] += 1;
if ((j - 1) >= 0 && (j - 1) < 3)
gridx[i][j - 1] += 1;
if ((i + 1) >= 0 && (i + 1) < 3)
gridx[i + 1][j] += 1;
if ((j + 1) >= 0 && (j + 1) < 3)
gridx[i][j + 1] += 1;
}
}
}
addition_in_grid(grid1, gridx);
}

/**
 * sandpiles_sum - sum of two sandpiles
 * @grid1: 1st matrix
 * @grid2: 2nd matrix
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
addition_in_grid(grid1, grid2);
while (!grid_is_perfect(grid1))
{
grid_print(grid1);
change_grid(grid1);
}
}
