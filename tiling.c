#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to tile the given region recursively
void tileRegion(int **tile, int x, int y, int size, int missingX, int missingY) {
    if (size == 2) {
        int tileNumber = 1;
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                if (i == missingX && j == missingY) {
                    tile[i][j] = 0;
                } else {
                    tile[i][j] = tileNumber;
                }
                tileNumber++;
            }
        }
    } else {
        int newSize = size / 2;
        tileRegion(tile, x, y, newSize, missingX, missingY);
        tileRegion(tile, x, y + newSize, newSize, x + newSize - 1, y + newSize);
        tileRegion(tile, x + newSize, y, newSize, x + newSize, y + newSize - 1);
        tileRegion(tile, x + newSize, y + newSize, newSize, x + newSize, y + newSize);
    }
}

// Function to print the tiled region
void printTiledRegion(int **tile, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%3d ", tile[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int size = pow(2, n);
    int **tile = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        tile[i] = (int *)malloc(size * sizeof(int));
    }

    int missingX, missingY;
    printf("Enter the coordinates of the missing block (x y): ");
    scanf("%d %d", &missingX, &missingY);

    tileRegion(tile, 0, 0, size, missingX, missingY);
    printTiledRegion(tile, size);

    // Free memory
    for (int i = 0; i < size; i++) {
        free(tile[i]);
    }
    free(tile);

    return 0;
}
