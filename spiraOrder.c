#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *spiralOrder(int **matrix, int numRows, int numColumns) {
    int i = 0;
    int j = 0;
    int c = 0;
    int min = 0;
    int index = 0;
    if(matrix == NULL || numRows == 0 || numColumns == 0)
        return NULL;
    int *retArray = (int*)malloc(sizeof(int)*numRows*numColumns);
    if(retArray == NULL)
        return NULL;
    memset(retArray,0,sizeof(int)*numRows*numColumns);
    if(numRows > numColumns)
    {   
        min = numColumns/2;
        if(numColumns%2 != 0)
        {
            min +=1;
        }
    }
    else
    {
        min = numRows/2;
        if(numRows%2 != 0)
        {
            min +=1;
        }
    }
    for(c=0;c<min;c++)
    {
        for(j=c;j<numColumns-c;j++) //每一行
        {
            retArray[index] = matrix[c][j];
            index++;
        }
        if(numRows == 1)
            return retArray;
        index--;
        for(i=c;i<numRows-c;i++) //最后一列
        {
            retArray[index] = matrix[i][numColumns-1-c];
            index++;
        }
        if(numColumns == 1)
            return retArray;
        index--;
        for(j=numColumns-1-c;j>c;j--)  //最后一行
        {
            retArray[index] = matrix[numRows-1-c][j];
            index++;
        }
//      index--;
        for(i=numRows-1-c;i>c;i--) //最前一列
        {
            retArray[index] = matrix[i][0+c];
            index++;
        }

    }
    return retArray;
}

int main()
{
    int i = 0;
    int j = 0;

    //1.二维数据的分配方法
//  int (*a)[2];
//  a = (int(*)[2])malloc(sizeof(int[2])*1);
//  a[0][0] = 3;
//  a[0][1] = 2;
//  printf("%d\n",a[0][1]);
     
                //[[2,5,8],[4,0,-1]] 

    //2.二维数据的分配方法
//  int** a = (int**)malloc(sizeof(int*)*10);
//  for(i = 0;i < 10;i++)
//  {
//      a[i] = (int*)malloc(sizeof(int)*10);//分配每个指针 指向的数组大小
//  }
//  for(i=0;i<10;i++)
//  {
//      for(j=0;j<10;j++)
//      {
//          a[i][j] = (j+1)+i*10;
//      }
//  }

//  int** a = (int**)malloc(sizeof(int*)*3);
//  for(i = 0;i < 3;i++)
//  {
//      a[i] = (int*)malloc(sizeof(int)*2);//分配每个指针 指向的数组大小
//  }
//  a[0][0] = 2;
//  a[0][1] = 5;
//  a[1][0] = 8;
//  a[1][1] = 4;
//  a[2][0] = 0;
//  a[2][1] = -1;
    int** a = (int**)malloc(sizeof(int*));
    for(i = 0;i < 1;i++)
    {
        a[i] = (int*)malloc(sizeof(int)*10);//分配每个指针 指向的数组大小
    }
    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[0][3] = 4;
    a[0][4] = 5;
    a[0][5] = 6;
    a[0][6] = 7;
    a[0][7] = 8;
    a[0][8] = 9;
    a[0][9] = 10;
//  for(i=0;i<10;i++)
//  {
//      for(j=0;j<10;j++)
//      {
//          a[i][j] = (j+1)+i*10;
//      }
//  }

//  for(i=0;i<10;i++)
//  {
//      for(j=0;j<10;j++)
//      {
//          printf("%d  ",a[i][j]);
//      }
//  }
//  printf("\n");
    int* r = spiralOrder(a,1,10);

    for(i=0;i<20;i++)
    {
        printf("%d  ",r[i]);
    }
   printf("\n");
    return 0;
}
