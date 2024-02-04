#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int count =2;
void finalPrint(int **arr, int side);

void print(int sideLength, int **arr, int count, int startX, int startY){
    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
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



void tile(int sideLength, int **arr, int blackX, int blackY, int startX, int StartY){
    // printf("\nINSIDE THE TILE");
    int halfSide;
    halfSide = (sideLength/2) -1;
    // printf("HalfSide, sideLength: (%d , %d)\n", halfSide,sideLength);
    // printf("Start (X,Y): (%d , %d)\n", startX,StartY);
    // printf("Black (X,Y): (%d , %d)\n", blackX,blackY);
    // printf("Count: (%d)\n", count);
    // printf("\n");
    if(sideLength == 2) // base case
    {
        
        // printf("\nInside base case\n");
        for (int i = startX; i <=startX+1; i++)
        {
            for (int j = StartY; j <=StartY+1; j++)
            {
                // printf("\n(i,j): (%d,%d)\n",i,j);
                // printf("\nBefore Update\n");
                // print(sideLength, arr, count);
                if (i!=blackX || j!=blackY)
                {
                    arr[i][j] = count;
                    // printf("\nAfter update\n");
                    // print(sideLength, arr, count);

                }
                
            }
            
        }

                        // printf("\nBase call print: %d\n",sideLength);
                        // printf("\nBlack XY: %d,%d\n",blackX,blackY);
        // finalPrint(arr, 8);
        // print(sideLength, arr, count, startX, StartY);
                // printf("\nOutside base case\n");
        count ++;
        return;
        
    }
    else
    {
        if (blackX<=(startX+ halfSide)) // top half
        {
            if (blackY<=(StartY+ halfSide)) // 1st Quad
            {
                arr[startX+halfSide][StartY+halfSide+1] = count;
                arr[startX+halfSide+1][StartY+halfSide+1] = count;
                arr[startX+halfSide+1][StartY+halfSide] = count;
                
                // print(sideLength, arr, count,0,0);
                // finalPrint(arr, 8);
                count++;
                // printf("\nAfter 1st main call: 1: %d \n",sideLength);
                tile(sideLength/2, arr, blackX, blackY,startX+ 0,StartY+ 0); //recursion on 1st quadrant

                // printf("\nAfter 2st main call: 1: %d\n",sideLength);
                tile(sideLength/2, arr, (halfSide+startX), (halfSide+1+StartY),startX+ 0,StartY+ halfSide+1); //recursion on 2nd quadrant
                
                // printf("\nAfter 3st recursive call: 1: %d \n",sideLength);
                tile(sideLength/2, arr, (halfSide+1+startX), (halfSide+StartY),startX+ halfSide+1,StartY+ 0); //recursion on 3rd quadrant
                // printf("\nAfter 4st recursive call: 1: %d \n",sideLength);
                tile(sideLength/2, arr, (halfSide+1+startX), (halfSide+1+StartY),startX+ halfSide+1,StartY+ halfSide+1); //recursion on 4th quadrant
                
            }
            else //2nd quad
            {
                arr[startX+halfSide][StartY+halfSide] = count;
                arr[startX+halfSide+1][StartY+halfSide+1] = count;
                arr[startX+halfSide+1][StartY+halfSide] = count;
                // print(sideLength, arr, count);
                count++;
                // printf("\nAfter 1st recursive call: 2 :%d\n", sideLength);
                tile(sideLength/2, arr, (startX+halfSide), (halfSide + StartY),startX+ 0,StartY+ 0); //recursion on 1st quadrant
                // printf("\nAfter 2st recursive call: 2 :%d\n", sideLength);
                tile(sideLength/2, arr, blackX, blackY,startX+ 0,StartY+ halfSide+1); //recursion on 2nd quadrant
                // printf("\nAfter 3st recursive call: 2 :%d\n", sideLength);
                tile(sideLength/2, arr, (halfSide+1+startX), (halfSide+StartY),startX+ halfSide+1,StartY+ 0); //recursion on 3rd quadrant
                // printf("\nAfter 4st recursive call: 2 :%d\n", sideLength);
                tile(sideLength/2, arr, (halfSide+1+startX), (halfSide+1+StartY),startX+ halfSide+1,StartY+ halfSide+1); //recursion on 4th quadrant

            }
            
        }
        else //bottom half
        {
            if (blackY<=(StartY+ halfSide)) // 3rd quad
            {
                arr[startX+halfSide][StartY+halfSide] = count;
                arr[startX+halfSide][StartY+halfSide+1] = count;
                arr[startX+halfSide+1][StartY+halfSide+1] = count;
                // print(sideLength, arr, count);
                count++;
                // printf("\nAfter 1st recursive call: 3 :%d\n", sideLength);
                tile(sideLength/2, arr, (startX+ halfSide), (StartY+ halfSide),startX+ 0,StartY+ 0); //recursion on 1st quadrant

                // printf("\nAfter 2st recursive call: 3 :%d\n", sideLength);
                tile(sideLength/2, arr,  (startX+ halfSide), (StartY+ halfSide+1),startX+ 0,StartY+ halfSide+1); //recursion on 2nd quadrant

                // printf("\nAfter 3st recursive call: 3 :%d\n", sideLength);
                tile(sideLength/2, arr, blackX, blackY,startX+ halfSide+1,StartY+ 0); //recursion on 3rd quadrant

                // printf("\nAfter 4st recursive call: 3 :%d\n", sideLength);
                tile(sideLength/2, arr, (startX+ halfSide+1), (StartY+ halfSide+1),startX+ halfSide+1,StartY+ halfSide+1); //recursion on 4th quadrant
            }
            else // 4th quad
            {
                arr[startX+halfSide][StartY+halfSide] = count;
                arr[startX+halfSide][StartY+halfSide+1] = count;
                arr[startX+halfSide+1][StartY+halfSide] = count;
                // print(sideLength, arr, count);
                count++;
                                // printf("\nAfter 1st recursive call: 4 :%d\n", sideLength);

                tile(sideLength/2, arr, (halfSide+startX), (halfSide+StartY), startX+ 0, StartY+ 0); //recursion on 1st quadrant
                // printf("\nAfter 2st recursive call: 4 :%d\n", sideLength);
                tile(sideLength/2, arr, (halfSide+startX), (halfSide+1+StartY),startX+ 0,StartY+ halfSide+1); //recursion on 2nd quadrant
                // printf("\nAfter 3st recursive call: 4 :%d\n", sideLength);
                tile(sideLength/2, arr, (halfSide+1+startX), (halfSide+StartY),startX+ halfSide+1,StartY+ 0); //recursion on 3rd quadrant
                // printf("\nAfter 4st recursive call: 4 :%d\n", sideLength);
                tile(sideLength/2, arr, blackX, blackY,startX+ halfSide+1,StartY+ halfSide+1); //recursion on 4th quadrant
                
            }
            
        }
        
    }


}

void finalPrint(int **arr, int side){
    int count =1; 
    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side;   j++)
        {
            if(arr[i][j]>9 && arr[i][j]<=99){
                if (arr[i][j] == 0)
            {
                printf("%d  ",arr[i][j]);
            }
            else if (arr[i][j] % 7 == 0)
            {
                printf("\033[1;31m%d  \033[1;0m", arr[i][j]);
            }
            else if (arr[i][j] % 7 == 1)
            {
                printf("\033[1;32m%d  \033[1;0m", arr[i][j]);
            }
            else if (arr[i][j] % 7 == 2)
            {
                printf("\033[1;33m%d  \033[1;0m", arr[i][j]);
            }
            else if (arr[i][j] % 7 == 3)
            {
                printf("\033[1;36m%d  \033[1;0m", arr[i][j]);
            }
            else if (arr[i][j] % 7 == 4)
            {
                printf("\033[1;35m%d  \033[1;0m", arr[i][j]);
            }
            else if (arr[i][j] % 7 == 5)
            {
                printf("\033[1;30m%d  \033[1;0m", arr[i][j]);
            }
            else if (arr[i][j] % 7 == 6)
            {
                printf("\033[1;34m%d  \033[1;0m", arr[i][j]);
            }
            

            }
            else if(arr[i][j]<=9){
                if (arr[i][j] == 0)
            {
                printf("%d   ",arr[i][j]);
            }
            else if (arr[i][j] % 7 == 0)
            {
                printf("\033[1;31m%d   \033[1;0m", arr[i][j]);
            }
            else if (arr[i][j] % 7 == 1)
            {
                printf("\033[1;32m%d   \033[1;0m", arr[i][j]);
            }
            else if (arr[i][j] % 7 == 2)
            {
                printf("\033[1;33m%d   \033[1;0m", arr[i][j]);
            }
            else if (arr[i][j] % 7 == 3)
            {
                printf("\033[1;36m%d   \033[1;0m", arr[i][j]);
            }
            else if (arr[i][j] % 7 == 4)
            {
                printf("\033[1;35m%d   \033[1;0m", arr[i][j]);
            }
            else if (arr[i][j] % 7 == 5)
            {
                printf("\033[1;30m%d   \033[1;0m", arr[i][j]);
            }
            else if (arr[i][j] % 7 == 6)
            {
                printf("\033[1;34m%d   \033[1;0m", arr[i][j]);
            }
            

            }
            else if(arr[i][j]>99){
                if (arr[i][j] == 0)
            {
                printf("%d   ",arr[i][j]);
            }
            else if (arr[i][j] % 7 == 0)
            {
                printf("\033[1;31m%d \033[1;0m", arr[i][j]);
            }
            else if (arr[i][j] % 7 == 1)
            {
                printf("\033[1;32m%d \033[1;0m", arr[i][j]);
            }
            else if (arr[i][j] % 7 == 2)
            {
                printf("\033[1;33m%d \033[1;0m", arr[i][j]);
            }
            else if (arr[i][j] % 7 == 3)
            {
                printf("\033[1;36m%d \033[1;0m", arr[i][j]);
            }
            else if (arr[i][j] % 7 == 4)
            {
                printf("\033[1;35m%d \033[1;0m", arr[i][j]);
            }
            else if (arr[i][j] % 7 == 5)
            {
                printf("\033[1;30m%d \033[1;0m", arr[i][j]);
            }
            else if (arr[i][j] % 7 == 6)
            {
                printf("\033[1;34m%d \033[1;0m", arr[i][j]);
            }
            

            }
            
            
            
        }
        printf("\n");
        
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

    // printf("Value of side is: %d\n", sideLength);


    // creating array
    int** arr=malloc(sideLength*sizeof(int*)); 
    for (int i = 0; i < sideLength; i++)
    {
        arr[i] = malloc(sideLength * sizeof(int));
    }
    // int arr[sideLength][sideLength]; 

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
    // print(sideLength, arr, count);

    tile(sideLength, arr, i, j, 0, 0 );
    // printf("\nFinal Print:\n");
    // for (int x = 0; x < sideLength; x++)
    // {
    //     for (int y = 0; y < sideLength; y++)
    //     {
    //         if(x==i && y==j){
    //             printf("\033[1;31m%d\033[0m  ", arr[x][y]);
    //         }
    //         else
    //         printf("%d  ", arr[x][y]);
    //     }
    //     printf("\n");
        
    // }

    finalPrint(arr, sideLength);

    // NOT WORKING FOR VALUES N=2 : (2,1) , (3,1)
    
    
    return 0;
}