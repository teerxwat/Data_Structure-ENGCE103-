#include <stdio.h>
#include <conio.h>

int main (){
	char ProductMame[50];
	int price , unit ;
	float vat , sum , total;
	
	printf("Enter product name : ");
	scanf("%s",&ProductMame);
	printf("Enter product price : ");
	scanf("%d",&price);
	printf("Enter quantity of product : ");
	scanf("%d",&unit);
	
	sum = price * unit;
	vat = ( sum * 7 )/100;
	total = vat + sum ;
	
	printf("\n\n\t\t\tABC Mart\n\n");
	printf("Product name\t\t\tPrice\t\tqty\t\tSum\n");
	printf("-----------------------------------------------------------------------\n");
	printf("%s\t\t\t\t%d\t\t%d\t\t%.2f\n\n",ProductMame ,price , unit , sum);
	printf("-------------------------------------------------------------------------\n\n");
	printf("\t\t\t\tVAT\t\t:\t\t%.2f\n" ,vat);
	printf("\t\t\t\tNet price\t:\t\t%.2f" ,total);
	
	return 0;
}
