#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int count =2;


void print(int sideLength, int arr[][sideLength], int count){
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if(arr[x][y] == count){
                printf("\033[1;31m%d\033[0m  ", arr[x][y]);
            }
            else
            printf("%d  ", arr[x][y]);
        }
        printf("\n");
        
    }
    printf("\n");

}



void tile(int sideLength, int arr[sideLength][sideLength], int blackX, int blackY, int startX, int StartY){
    int halfSide;
    halfSide = (sideLength/2) -1;
    if(sideLength == 2) // base case
    {
        printf("\nInside loop\n");
        for (int i = startX; i <=startX+1; i++)
        {
            for (int j = StartY; j <=StartY+1; j++)
            {
                if (i!=blackX || j!=blackY)
                {
                    print(sideLength, arr, count);
                    arr[i][j] = count;
                }
                
            }
            
        }
                printf("\nOutside loop\n");

                        printf("\nBase call print: %d\n",sideLength);
                        printf("\nBlack XY: %d,%d\n",blackX,blackY);

        print(sideLength, arr, count);
        count ++;
        return;
        
    }
    else
    {
        if (blackX<halfSide) // top half
        {
            if (blackY<halfSide) // 1st Quad
            {
                arr[halfSide][halfSide+1] = count;
                arr[halfSide+1][halfSide+1] = count;
                arr[halfSide+1][halfSide] = count;
                printf("\n1st quad print: \n");
                print(sideLength, arr, count);
                count++;
                tile(sideLength/2, arr, blackX, blackY, 0, 0); //recursion on 1st quadrant
                tile(sideLength/2, arr, halfSide, halfSide+1, 0, halfSide+1); //recursion on 2nd quadrant
                tile(sideLength/2, arr, halfSide+1, halfSide, halfSide+1, 0); //recursion on 3rd quadrant
                tile(sideLength/2, arr, halfSide+1, halfSide+1, halfSide+1, halfSide+1); //recursion on 4th quadrant
                
            }
            else //2nd quad
            {
                arr[halfSide][halfSide] = count;
                arr[halfSide+1][halfSide+1] = count;
                arr[halfSide+1][halfSide] = count;
                print(sideLength, arr, count);
                count++;
                tile(sideLength/2, arr, halfSide, halfSide, 0, 0); //recursion on 1st quadrant
                tile(sideLength/2, arr, blackX, blackY, 0, halfSide+1); //recursion on 2nd quadrant
                tile(sideLength/2, arr, halfSide+1, halfSide, halfSide+1, 0); //recursion on 3rd quadrant
                tile(sideLength/2, arr, halfSide+1, halfSide+1, halfSide+1, halfSide+1); //recursion on 4th quadrant

            }
            
        }
        else //bottom half
        {
            if (blackY<halfSide) // 3rd quad
            {
                arr[halfSide][halfSide] = count;
                arr[halfSide][halfSide+1] = count;
                arr[halfSide+1][halfSide+1] = count;
                print(sideLength, arr, count);
                count++;
                tile(sideLength/2, arr, halfSide, halfSide, 0, 0); //recursion on 1st quadrant
                tile(sideLength/2, arr, halfSide, halfSide+1, 0, halfSide+1); //recursion on 2nd quadrant
                tile(sideLength/2, arr, blackX, blackY, halfSide+1, 0); //recursion on 3rd quadrant
                tile(sideLength/2, arr, halfSide+1, halfSide+1, halfSide+1, halfSide+1); //recursion on 4th quadrant
            }
            else // 4th quad
            {
                arr[halfSide][halfSide] = count;
                arr[halfSide][halfSide+1] = count;
                arr[halfSide+1][halfSide] = count;
                print(sideLength, arr, count);
                count++;
                tile(sideLength/2, arr, halfSide, halfSide, 0, 0); //recursion on 1st quadrant
                tile(sideLength/2, arr, halfSide, halfSide+1, 0, halfSide+1); //recursion on 2nd quadrant
                tile(sideLength/2, arr, halfSide+1, halfSide, halfSide+1, 0); //recursion on 3rd quadrant
                tile(sideLength/2, arr, blackX, blackY, halfSide+1, halfSide+1); //recursion on 4th quadrant
                
            }
            
        }
        
    }


}

int main(){
    int n,i,j;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of i: ");
    scanf("%d", &i);
    printf("Enter the value of j: ");
    scanf("%d", &j);

    int sideLength = (int)pow(2,n);
    // int N = 8;
    // printf("%d" , N/2);

    printf("Value of side is: %d\n", sideLength);


    // creating array
    // int* arr[sideLength]; 
    // for (int i = 0; i < sideLength; i++)
    // {
    //     arr[i] = (int*)malloc(sideLength * sizeof(int));
    // }
    int arr[sideLength][sideLength]; 

    // int* arr = malloc((sideLength * sideLength) * sizeof(int));
    



    // initializing array
    for (int x = 0; x < sideLength; x++)
    {
        for (int y = 0; y < sideLength; y++)
        {
            arr[x][y] = 1;
        }
        
    }

    arr[i][j] = 0;
    print(sideLength, arr, count);

    tile(sideLength, arr, i, j, 0, 0 );
    printf("\nFinal Print:\n");
    for (int x = 0; x < sideLength; x++)
    {
        for (int y = 0; y < sideLength; y++)
        {
            if(x==i && y==j){
                printf("\033[1;31m%d\033[0m  ", arr[x][y]);
            }
            else
            printf("%d  ", arr[x][y]);
        }
        printf("\n");
        
    }
    
    
    return 0;
}