/*program ASCENDING SELECTION SORT can .....
1.random raw data into 1 dimention arrya 
2.sorting and display detail of each result 
3.display final result
*/

#include<stdio.h> 
#include<conio.h>	//use getch
#include<stdlib.h>	//use random
#include<time.h>	//use time
#define MaxData 100	//Define Max Data

int Data[ MaxData ] ;
int N ;

void PrepareRawData( int N ){
	int i ; 
	srand( time( NULL ) ) ; //for difference random number in rand()
	for( i = 1 ; i <= N ; i++ ){
		Data[ i ] = 1 + rand() % 99 ; // random difference number 1...99
	}//end for
}//end fn. 

void DispData( int N , int out ){
	int i ; 
	printf( "	" ) ;
	for( i = 1 ; i <= N ; i++ ){
		if( out >= i ){
			printf( "[%2d] " , Data[ i ] ) ; //show []if it's output
		}//end if
		else{
			printf( " %2d  " , Data[ i ] ) ; //show normal form it is not output
		}//end else
	}//end for
	printf( "\n" ) ;
}//end fn.


void swap(int a , int b ){
	int temp ;
	temp = Data[ a ] ;
	Data[ a ] = Data [ b ] ;
	Data[ b ] = temp ; 
}//end fn.


int Minimum( int j ){ //find minimum data in data[] between j...N
	int i , temp ,Location ;
	Location = j ; // set first location
	temp = Data[ j ] ; //set begin value 
	for( i = j + 1 ; i <= N ; i++ ){
		if( temp > Data[ i ]){
			temp = Data[ i ] ; //change new minimum data 
			Location = i ; //keep new location
		}//end if 
	} //end for
	return( Location ) ; //return address of minimum data 
}//end fn.

void SeletionSort( int N ){
	int i , j ,Location ;
	printf( "-------------------------------------------------------------------------------------------\n" ) ;
	printf( "i	LOC	" ) ;
	for( i = 1 ; i <= N ; i++ ){
		printf( "(%2d) " , i ) ;
	}//end for
	printf( "\n	" ) ;
	DispData( N , i ) ; //show every step sorting
	printf( "-------------------------------------------------------------------------------------------\n" ) ;
	
	for( i = 1 ; i <= N ; i++ ){
		Location = Minimum( i ) ; //find minumum location between i..N
		swap( i , Location ) ;
		printf( "(%2d) (%2d) " , i , Location ); //show location of array
		DispData( N , i ) ; //show every step sorting
	}//end for
}//end fn.

int main(){
	printf( "ASCENDING SELECTION SORT\n" ) ;
	printf( "===================================================================================================\n" ) ;
	N = 12 ; 
	PrepareRawData( N );
	printf( "Raw Data...." ) ;
	DispData( N , 0 ) ;
	printf( "Processing Data....\n" ) ;
	SeletionSort( N ) ;
	printf( "-------------------------------------------------------------------------------------------\n" ) ;
	printf( "Sorted Data :" ) ;
	DispData( N , N ) ; //sorted data
	getch();
	return( 0 ) ;
}
