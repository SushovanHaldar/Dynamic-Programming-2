/* Extended version of power function that can work
 for float x and negative y*/
#include<stdio.h>
//http://www.geeksforgeeks.org/write-a-c-program-to-calculate-powxn/

float power(float x, int y)
{
    float temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);      
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
} 
 
/* Program to test function power */
int main()
{
	// notice that (-1%2) = 1
    float x = 2;
    int y = -2;
    printf("%f", power(x, y));
    getchar();
    return 0;
}