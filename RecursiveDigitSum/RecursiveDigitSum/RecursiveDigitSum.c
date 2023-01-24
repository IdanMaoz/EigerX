// RecursiveDigitSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
int recursiveDigitSum(int num,int sum)
{
    if (num == 0) {
        return sum;
    }
    return recursiveDigitSum(num / 10, sum + num % 10);
}

int main()
{
    int num = 2347623;
    int sum = recursiveDigitSum(num, 0);
    printf("The sum is: %d\r\n", sum);
}

