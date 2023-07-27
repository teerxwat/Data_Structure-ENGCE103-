#include <stdio.h>
int num_b, num_exp ;
int power( int base, int E ) { 
     int x, y ;
    if( E == 0 ) { 
        return 1 ;
    } 
    else {
        return ( base *    power( base , E - 1 ) );
    }
}


int main( ) { 
    printf( "Recusive (Exponent) PROGRAM\n" ) ;
    printf( "==========================================================================================\n" ) ;
    printf( "Enter Base Number : " ) ;
    scanf("%d", &num_b ) ;
    printf( "Enter Exp : " ) ;
    scanf("%d", &num_exp ) ;
    int ans = power( num_b, num_exp );
    // printf("Exp is %d ^ %d",p) ;
    printf("\nAnswer is = %d", ans) ;
    return 0 ;
}
