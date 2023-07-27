#include <stdio.h>
#include <conio.h>

char ch;

void DecToBin(int data2 , int byt)
	{
		int count , chk , bits ;
		bits = (byt * 8) -1 ;
		for ( count = bits ; count >= 0 ; count-- ){
			chk = data2 >> count ;
			if( chk & 1)
				printf("1");
			else
				printf("0");
			if( count %4 == 0 && count > 3 )
				printf(" ");	
		}
	printf("B\n");
	}
	
void UnsignedShortInt(){
	unsigned short int data ;
	printf("\nUNSIGNED SHORT INTEFER MODE [0 to 65,535]\n");
	printf("===========================================\n");
	printf("Enter Raw Data : ");
	scanf("%hu" , &data );
	printf("Data in Decimal = %hu D\n" ,data );
	printf("Data in Hexamal = %x H\n" ,data );
	printf("Data in Binary  = ");
	DecToBin(data , sizeof(data));
	printf("size		= %d bytes\n" , sizeof(data));
	getch();
}

void UnsignedInt(){
	unsigned int data ;
	printf("\nUNSIGNED INTEGER MODE [0 to 4,294,967,295 ]\n");
	printf("=============================================\n");
	printf("Enter Raw Data : ");
	scanf("%u",&data);
	printf("Data in Decimal = %hu D\n" ,data );
	printf("Data in Hexamal = %x H\n" ,data );
	printf("Data in Binary  = ");
	DecToBin(data,sizeof(data));
	printf("size		= %d Bytes\n" ,sizeof(data));
	getch();
}

void Boolean(){
	bool data ;
	printf("\nBOOLEAN MODE [0 to 255 ]\n");
	printf("===========================\n");
	printf("Enter Taw Data : ");
	scanf("%hu" ,&data);
	printf("Data Meaning	= ");
	if(data)
		printf("TRUE\n");
	else
		printf("FALSE\n");
	printf("Data in Decimal = %hu D\n" ,data );
	printf("Data in Hexamal = %x H\n" ,data );
	printf("Data in Binary  = ");
	DecToBin(data,sizeof(data));
	printf("size		= %d Bytes\n" ,sizeof(data));
	getch();
}	

void Character(){
	char data ;
	printf("\nCHARACTER MODE [0 to 255]\n");
	printf("===========================\n");
	printf("Enter Raw Data ; ");
	scanf("%hu",&data);
	printf("Data in Decimal = %hu D\n" ,data );
	printf("Data in Hexamal = %x H\n" ,data );
	printf("Character	= %c\n" ,data);
	printf("Data in Binary  = ");
	DecToBin(data,sizeof(data));
	printf("size		= %d Bytes\n" ,sizeof(data));
	getch();
}

void SFloat(){
	float data;
	printf("\nSingle Precision Float MODE [1.2E-38 to 3.4E+ ]\n");
	printf("=================================================\n");
	printf("Enter Raw Data : ");
	scanf("%f" ,&data);
	printf("Data in Decimal = %f D\n" ,data );
	printf("Data in Hexamal = %x H\n" ,data );
	printf("Data in Binary  = ");
	DecToBin(data,sizeof(data));
	printf("size		= %d Bytes\n" ,sizeof(data));
	getch();	  
}

void BintoDec() {
	unsigned  long data, i = 1 , temp = 0, m = 0, l = 0 , n = 0; 
	printf("\n Binary Mode [ 2 to 8 10 16 ]\n");
	printf("=============================================\n");
	printf("Enter Raw Data : ");
	scanf("%ld",&data);
	n = data ;
	while( n > 0 ) {
        m = ( n % 10 );             
        n = ( n / 10 );  
        l = m * i;
        temp = temp + l;
        i = i * 2;
	}
	printf("Data in Octal = %o O\n",temp);
	printf("Data in Decimal = %d D\n",temp);
	printf("Data in Haxamal = %x H\n",temp);
	getch();
}

int main(){
	printf("\nDATA REPRESENTATION PROGRAM...\n");
	printf("================================\n");
	while ( ch != '0' ){
		printf("\n[1]:Unsign ShorInt	[2]:Boolean 	[3]:Unsigned Int	[4]:Character\n");
		printf("[5]:Single Prec Float	[6]:BintoDec    [0]:Exit") ;
		printf("\n");
		ch = getch();
		switch(ch){
			case '1' :	UnsignedShortInt();
						break;
			case '2' :	Boolean();
						break;
			case '3' :	UnsignedInt();
						break;
			case '4' :	Character();
						break;
			case '5' :	SFloat();
						break;
			case '6' : 	BintoDec();
						break;
		}
	}
	printf("\n");
	return(0);
}
