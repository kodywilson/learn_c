#include <cs50.h>
#include <stdio.h>

void blocker(int n)
{
    // Create part of pyramid layer with n blocks
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}

void spacer(int n)
{
    // Add spaces before blocks
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void stacker(int n)
{
    // Stack the layers together
    int height = n;
    int layer = 1;
    while (height > 0)
    {
        spacer(height - 1);
        height--;
        blocker(layer);
        spacer(2);
        blocker(layer);
        layer++;
        printf("\n");
    }
}

int main(void)
{
    // Get pyramid height from 1 to 8 layers
    printf("Please enter a number from 1 to 8 for pyramid height.\n");
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    // Build the pyramid layer by layer
    stacker(height);
}

