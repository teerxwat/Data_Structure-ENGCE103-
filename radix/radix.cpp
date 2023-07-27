/* program ascending radix sort can....
1.random raw data into 1 dimention array
2.sorting and display detail of each step result
3.display final result
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define MaxData 100 
#define MaxRow 10
#define MaxCol 20 

int Data[ MaxData ] ;
int Radix[ MaxRow ][ MaxCol ] ; //radix is temporary tank the size is [0..MaxRaw , 0..MaxCol ] 
int N , N1 ;

void ClearStackPT(){ //clear every block = 0 and use Radix[0] for SP
	int i ; 
	for ( i = 0 ; i <= MaxRow ; i++ ){
		Radix[ i ][ 0 ] = NULL ; //this position keep the SP
	}//end for
}//end fn.

void PrepareRawData( int N2 ){
	int i ;
	srand( time( NULL ) ) ; //for difference random number in rand()
	for( i = 0 ; i < N2 ; i++ ) {
		Data[ i ] = ( rand() % 899 ) + 100 ;//random difference number 100 ... 999
	}//end for
}//end fn.

void DispData( int N2 ){ //show data in array
	int i ; 
	for( i = N2 - 1 ; i >= 1 ; i-- ){
		printf( "%3d " , Data[ i ] ) ;
	}//end for
	printf( "\n" ) ;
}//end fn.

void Push( int Rad , int Dat ){ //put data into Parallel Stack by keep SP at (Rat , 0)
	int SP ;
	SP = Radix[ Rad ][ 0 ] + 1 ; //skip SP
	Radix[ Rad ][ 0 ] = SP ; //keep new SP
	Radix[ Rad ][ SP ] = Dat ; //push data into that Radix
	//printf( "SP = %d | Radix [ Rad = %d ][ 0 ] = %d | Radix[ Rad = %d ][ SP = %d ] = %d \n" , SP , Rad , Radix[ Rad ][ 0 ] , Rad , SP ,  Radix[ Rad ][ SP ]) ;
}//end fn.

void ReadStack( int NN){ //read data form each stack and transfer to data[]
	int i , j , k , SP ;
	k = NN ;//start of data[] at subcript 0
	for( i = 0 ; i <= MaxRow ; i++ ){
		SP = Radix[ i ][ 0 ] ; //max count value of each radix keep at column 0 
		for( j = 1 ; j <= SP ; j++ ){
				Data[ k ] = Radix[ i ][ j ] ; // transfer data from every stack to data[]
			k-- ;
		}//end for
	}//end for
}//end fn.

void RadixSort( int N2 ){ 
	int Digit , i , RadixNo ;
	char Txt[ 2 ] ;
	for( Digit = 2 ; Digit >= 0 ; Digit-- ){ //count down
		printf( "[Digit :%d]==>\n", 3-Digit ) ;
		for( i = N2-1 ; i >= 0 ; i-- ){ //data[] counter
			itoa( Data[ i ] ,Txt , 10 ) ; //convert integer to text itao( input , output , base ) 
			//printf("itoa is %s\n" , itoa( Data[ i ] ,Txt , 10 ) ) ;
			RadixNo = Txt[Digit] - 48 ; //convert text that digit to number 
			//printf("RadixNo is %d\n" ,RadixNo ) ; 
			Push( RadixNo , Data[ i ] ) ; //push data to stack at that radix 
		}//end for
		ReadStack( N2 ) ;
		DispData( N2 ) ;
		ClearStackPT() ;
	}//end for
}//end fn.

int main(){
	printf( "ASCENDING RADIX SORT\n" ) ;
	printf( "======================================================\n" ) ;
	N = 16 ;
	N1 = N ; //keep N to N1 because N is 0 when finished
	PrepareRawData( N ) ;
	printf( "Raw Data......\n" ) ;
	DispData( N ) ;
	RadixSort( N ) ;
	printf( "===============================================Finished \n" ) ;
	printf( "Sorted Data : \n" ) ;
	DispData(N1) ; //sorted data
	getch() ;
	return( 0 ) ; 
}//end main
