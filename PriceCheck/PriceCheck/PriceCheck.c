#include <stdio.h>
#include <string.h>
#define maxLenOfProductName 20
int priceCheck(char* products, float* productPrices, char* productSold, float* soldPrice,int n,int m)
{
	int count = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (!strcmp(products + i * (uintptr_t)maxLenOfProductName, productSold + j * (uintptr_t)maxLenOfProductName)) {
				if (productPrices[i] != soldPrice[j]) {
					count++;
				}
			}
		}
	}
	return count;
}
int main()
{
	char products[][maxLenOfProductName] = { "rice", "sugar", "wheat", "cheese" };
	int n = sizeof(products) / sizeof(products[0]);
	float productPrices[] = { 16.89, 56.92, 20.89, 345.99 };
	char productSold[][20] = { "rice", "cheese" };
	int m = sizeof(productSold) / sizeof(productSold[0]);
	float soldPrice[] = { 18.99, 400.89 };
	int incorrect = priceCheck(products, productPrices, productSold, soldPrice,n,m);
	printf("The number of sale prices that were entered incorrectly are: %d\r\n", incorrect);
}

