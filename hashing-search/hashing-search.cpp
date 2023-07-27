#include <stdio.h>		//use printf
#include <stdlib.h>		//use random
#include <conio.h>		//use getch
#include <time.h>		//use time 
#include <windows.h>	//use Sound

#define MaxData 100 	//define Max Data 
#define Lo 1 			//define Lo = 1 

int Data[ MaxData ] ; 
int N , M , key , Addr , Times ;
bool result ; 

struct Node{		//declare structure if node
	int info ;
	struct Node *link ;
}; //end struct

struct Node *Start[ MaxData ] , *H1 , *p ; //declare pointer node 

Node *Allocate(){
	struct Node *temp ; 
	temp = ( Node* ) malloc( sizeof( Node ) ) ; //allocate node by size declare
	return ( temp ) ;
} //end allocate 

bool Duplicate ( int i , int Data1 ){
	int j ;
	for( j = 0 ; j <= i ; j++ ){
		if( Data1 == Data[ j ] ) {
			return ( true ) ;
		}//end if 
	}//end for 
	return ( false ) ;
} //end duplicate 

void PrepareRawKey ( int N ){
	int i , temp ; 
	srand( time( NULL ) ) ; //for difference random number in rand()
	for( i = 0 ; i < N ; i++ ){
		temp = ( rand() % 989 ) + 10 ; //random difference number 10 .... 999
		while( Duplicate( i - 1 , temp ) ){ //loop if still duplicate
			temp = ( rand() % 989 ) + 10 ; //random again
		} //end while
		Data[ i ] = temp ;
	}//end for
}// end preparerawkey

void DispKey( int N ){
	int i ;
	for( i = 0 ; i < N ; i++ ){
		printf( "%2d " , Data[ i ] ) ; //show data[]
	}//end for
	printf( "\n" ) ;
}// end dispkey

void CreateHead ( int Head ){
	int i ; 
	struct Node *p ;
	for( i = 1 ; i <= Head ; i++ ){ //count by number of head
		p = Allocate() ;
		p -> info = NULL ;
		p -> link = NULL ; //let next = null
		Start[ i ] = p ; //let start of each node = address of  first node
	}//endfor
}//end createhead

void CreateHashTable ( int N ) {
	int i ;
	struct Node *H1 , *p ;
	for( i = 0 ; i < N ; i++ ){
		Addr = Data[ i ] % M + Lo ; //calculate address of key ( addr = k mod M + lo )
		H1 = Start[ Addr ] ;
		if( H1 -> info == NULL ){ //if head node
			H1 -> info = Data[ i ] ; 
		} //end if
		else {
			while( H1 -> link != NULL ){
				H1 = H1 -> link ; 
			} //end while
			p = Allocate() ; //add new node
			p -> info = Data[ i ] ; 
			p -> link = NULL ;
			H1 -> link = p ;
		} //end else
	}//end for
}//end createhashtable

void DispHashTable(){
	int i ;
	struct Node *H1 ; 
	for ( i = 1 ; i <= M ; i++ ){
		H1 = Start[ i ] ; 
		printf( "\nAddress %2d : " , i ) ;
		while( H1 != NULL ){
			printf( "%3d " , H1 -> info ) ;
			H1 = H1 -> link ; // skip next node
		}//end while
	}// end for
	printf( "\n" ) ;
} //end disphashtable

bool SearchHash( int key ){
	struct Node *H1 ; 
	Addr = key % M + Lo ; //calculate address of key ( addr = k mod m + lo )
	H1 = Start[ Addr ] ;
	Times = 0 ;
	while( H1 != NULL ){
		Times++ ; //add counter times 
		if( H1 -> info == key ){
			return( true ) ; //found
		}//end if
		else{
			H1 = H1 -> link ; 
		}//end else
	}//end while
	return( false ) ; //not found
}//end searchhash

int main() {
	printf( "HASHING SEARCH(DYNAMIC CHAINING \n" ) ;
	printf( "=======================================\n" ) ;
	N = 10 ;
	M = N * 0.50 ; //let M = 50% of N 
	PrepareRawKey( N ) ;
	printf( "Raw key :\n" ) ;
	DispKey( N ) ;
	printf( "-----------------------------------\n" ) ;
	CreateHead( M ) ; //create head node
	CreateHashTable( N ) ;
	while( key != -999 ){
		DispHashTable();
		printf( "-------------------------------------\n" ) ;
		printf("\nEnter Key for Search(-999 for EXIT)=") ;
		scanf( "%d" , &key ) ; //read key from keyboard
		if( key != -999 ){
			result = SearchHash( key ) ; 
			printf( "Key Address :%d\n" , Addr ) ;
			printf( "Searching Time :%d\n" , Times ) ;
			printf( "Result" ) ;
			if( result ){
				printf( "FOUND\n" ) ; //if found
			} //end if 
			else{
				Beep( 600 , 600 ) ;
				printf( "NOT FOUND!!!\n" ) ; //if not found	
			} //end else
			printf( "------------------------------Searching Finished\n" ) ;
		}//end if
	} //end while
	return( 0 ) ;
}//end main
