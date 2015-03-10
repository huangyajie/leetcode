#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int climbStairs(int n) {

    int nTwo = n/2;
    int i = 0;
    int j = 0;
    long double mul1 = 1.0;
    long double mul2 = 1.0;
    int sum = 0;

    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    for(i=1;i<=nTwo;i++)
    {

        for(j=1;j<=i;j++)
        {
            mul1 *=(n-2*i+j);
            mul2 *=j;
        }
        
        sum += (mul1/mul2);
        mul1 = 1.0;
        mul2 = 1.0;
    }
    return sum+1;
}



int main()
{
    printf("%d\n",climbStairs(38));
    return 0;
}
