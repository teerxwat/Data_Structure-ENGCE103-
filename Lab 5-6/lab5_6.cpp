/*
program covert infix to postfix by assigned in variable 
*/

#include <stdio.h> //use printf()
#include <conio.h> //use getch()
#include <string.h> //user string function
#include <math.h>   // use power
#include<ctype.h> // for fn check ch is num
#define MaxStackOpt 40 //Set Max Operator STrack 
#define MaxStackOpr 40 // Set Max Operand Stack


/// Variable for infix to postfix
char infix1[ 80 ] = { "A*a+B(C^D*E/F)-G" } ;//Assign INFIX
char infix2[ 80 ] = { "2+A(A^D*E/3)-G" } ;//Assign INFIX

char OpSt[ MaxStackOpt ] ; //Operator stack size 

char ResultPostfix [ 80 ] ; // to past value from inflix to postfix function

int SP = 0 ; //Initail SP = 0
/// Variable for infix to postfix

/// Variable result of postfix
float ValPostfix[ 80 ] ;  // Keep value of Postfix here
float ValPostfixModify[ 80 ] ;  // Keep value of Postfix here

float ValOperandST[ MaxStackOpr ] ; // Operand stack size
/// Variable result of postfix


void pushOpt ( char oper ) //PUSH FUNCTION 
{
	if ( SP == MaxStackOpt ) // Check Stack Full ?
	{
		printf ( "(OPT)ERROR STACK OVER FLOW!!!.....\n" ) ;
	}
	else
	{
		SP = SP + 1 ; //Increase SP 
		OpSt[ SP ] = oper ; //Put data into Stack 
	}
}

int popOpt () //POP Function
{
	char oper ;
	if ( SP != 0 )//Check Stack Not Empty ?
	{
		oper = OpSt[ SP ] ; //Get data from Stack 
		SP-- ; //Decrease SP
		return( oper ) ; //Return data 
	}
	else 
	printf ( "\n(OPT)ERROR STACK UNDER FLOW!!!......\n" ) ;
}

void pushOpr ( float ValOperand ) // PUSH Function 
	{
		if( SP == MaxStackOpr ) // Check Stack FULL?
		{
			printf( "(OPR)ERROR STACK OVER FLOW!!!...\n" ) ;
		}
		else
		{
			SP = SP  + 1 ; // Increase SP
			ValOperandST[ SP ] = ValOperand ; // Put data into Stack
		}
	}// END VOID PUSH
	
float popOpr () //POP Function
	{
		float ValOperand ;
		if( SP !=0 ) //Check Stack NOT EMPTY?
		{
			ValOperand = ValOperandST[SP] ; // Get data From Stack
			SP-- ; // Decrease SP
			return( ValOperand ) ; // Return data
		}
		else
			printf( "\n(OPR)ERROR STACK UNDER FLOW!!!...\n" ) ;
	}// END FLOAT POP
	

int precedenceIP ( char oper )// Function for check precedence of input operator
{
	switch ( oper )
	{
		case '+'	:	return ( 1 ) ;
		case '-'	:	return ( 1 ) ;
		case '*'	:	return ( 2 ) ;
		case '/'	:	return ( 2 ) ;
		case '^'	:	return ( 4 ) ;
		case '('	:	return ( 4 ) ;
	}
}

int precedenceST ( char oper ) // Function for check precedence of stack operator
{
	switch ( oper ) 
	{
		case '+'	:	return ( 1 ) ;
		case '-'	:	return ( 1 ) ;
		case '*'	:	return ( 2 ) ;
		case '/'	:	return ( 2 ) ;
		case '^'	:	return ( 3 ) ;
		case '('	:	return ( 0 ) ;
	}
}

infixTOpostfix_display ( char infix2 [ 80 ] ) 
{
	int i ,j ,len ;
	char ch ,temp ;
	printf ( "INFIX :%s\n " ,infix2 ) ; //Show infix
	len = strlen ( infix2 ) ; //Find lenfth of infix
	printf ( "Infix Length = %d \n" ,len ) ;//Display length of infix 
	printf ( "POSTFIX IS : " ) ;
	for ( i = 0 ; i <= len - 1 ; i++ ) {
		ch = infix2[ i ] ;//Transfer character in to ch variable
	if ( strchr ( "+-*^/()", ch ) == 0 ) //Check Is OPERAND ?
	{
		printf ( "%c" ,ch ) ; //Out to Postfix
	}
	else //If OPERATOR do below  
	{
		if ( SP == 0 ) //Strack empty ?
		{
			pushOpt( ch ) ; //Push any way if Stack empty
		}
		else
			if( ch != ')' ) //If not ')' do below
			{
				if ( precedenceIP ( ch ) > precedenceST ( OpSt[ SP ] ) ) //If precedence inpyut > precedence in stack
					pushOpt ( ch ) ; //Push input operator to Stack 
				else 
				{
					printf ( "%c" ,popOpt() ) ; // Out to Postfix
					while ( precedenceIP( ch ) <= precedenceST ( OpSt[ SP ] && ( SP != 0 ) ) )//Do Untill precedence input > precedence in stack
					{
					printf ( "%c",popOpt() ) ; //Out to Postfix
					}
					pushOpt ( ch ) ; // Push operator input to Stack 				

				} //END ELSE
			}//END IF
		else 
		{
			temp = popOpt() ; //Pop operator from Stack
			while ( ( temp != '(' ) ) //Do if not found 
			{
				printf ( "%c" ,temp ) ; //Out to Postfix
				temp = popOpt() ; // Pop again and loop
			}// END WHILE
		}// END ELSE
	}// END ELSE
}//END FOR
	j = SP ; //Let j for count left Stack
	for ( i = 1 ; i <= j ; i++ ) //POP all if Input is Null
	{
		printf ( "%c",popOpt() ) ; //Out to Postfix 
//		ResultPostfix[ i ] = popOpt() ;
	}
}
infixTOpostfix ( char infix [ 80 ] ) 
{
	int i ,j ,len ;
	char ch[80] ,temp ; // convert (char)infix[i] to (char*)ch[80] for use strcat function  (**** strcat fonction request char pointer ) when is operand
	char tempPop[80] ; // convert (char)result of pop to (char*)tempPop[80] for use strcat function  (**** strcat fonction request char pointer ) when call pop function
	len = strlen ( infix ) ; //Find lenfth of infix
	printf ( "INFIX :	%s\n" ,infix ) ; //Show infix
	len = strlen ( infix ) ; //Find lenfth of infix
	printf ( "Infix Length = %d \n" ,len ) ;//Display length of infix 
	printf ( "POSTFIX IS : " ) ;
	for ( i = 0 ; i <= len - 1 ; i++ ) {
		ch[0] = infix[ i ] ;//Transfer character in to ch variable
		if ( strchr ( "+-*^/()", ch[0] ) == 0 ) //Check Is OPERAND ?
		{
			strcat ( ResultPostfix , ch ) ;
		}
		else //If OPERATOR do below  
		{
			if ( SP == 0 ) //Strack empty ?
			{
				pushOpt( ch[0] ) ; //Push any way if Stack empty
			}// End if
			else if( ch[0] != ')' ) //If not ')' do below
				{
					if ( precedenceIP ( ch[0] ) > precedenceST ( OpSt[ SP ] ) ) //If precedence inpyut > precedence in stack
						pushOpt ( ch[0] ) ; //Push input operator to Stack 
					else 
					{
						tempPop[0] = popOpt() ; // convert char from pop fonction to char*
						strcat ( ResultPostfix , tempPop ) ;
						while ( precedenceIP( ch[0] ) <= precedenceST ( OpSt[ SP ] ) && ( SP != 0 ) )//Do Untill precedence input > precedence in stack
						{
						tempPop[0] = popOpt() ; // convert char from pop fonction to char*
						strcat ( ResultPostfix , tempPop ) ;
						}
						pushOpt ( ch[0] ) ; // Push operator input to Stack 				
	
					} //END ELSE
				}//END IF
			else 
			{
				temp = popOpt() ; //Pop operator from Stack
				while ( ( temp != '(' ) ) //Do if not found 
				{
					tempPop[0] = temp ; // convert char from pop fonction to char*
					strcat ( ResultPostfix , tempPop ) ;
					temp = popOpt() ; // Pop again and loop
				}// END WHILE
			}// END ELSE
		}// END ELSE
	}//END FOR
	j = SP ; //Let j for count left Stack
	for ( i = 1 ; i <= j ; i++ ) //POP all if Input is Null
	{
//		printf ( "%c",popOpt() ) ; //Out to Postfix 
	tempPop[0] = popOpt() ;
	strcat ( ResultPostfix , tempPop ) ;

	}
}


void CalPostfix( char postfix[ 80 ] )
	{
		float pop1 ,pop2 ,value ;
		int i ,len ;
		char ch ;
		len = strlen( postfix ) ;
		printf( "Postfix = %s\n", postfix ) ;
		for( i = 0 ; i <= len - 1 ; i++ ) // Assign data to OPERAND
		{
			ch = postfix[ i ] ; // Split Character for assign data
			if( strchr( "+-*/^", ch ) == 0 ) // Check Is OPERAND?
			{
				printf( "\nAssign Number to %c : ",ch ) ;
				scanf( "%f" ,&ValPostfix[ i ] ) ; // Read data from KBD and direct to Value of OPERAND in Array
			}
		}
		for( i = 0 ; i <= len - 1 ; i++ ) // Calculate Value of POSTFIX
		{
			ch = postfix[ i ] ; //Split Character for prepare to STACK
			if( strchr( "+-*/^", ch ) == 0 )  //Check Is OPERAND?
			{
				pushOpr( ValPostfix[ i ] ) ; // push value of OPERAND to Stack
			} 
			else {
				pop1 = popOpr() ; // pop 1st
				pop2 = popOpr() ; // pop 2nd
				switch( ch )
				{
					case '+' : value = pop2 + pop1 ; // Calculate
					pushOpr( value ) ;                  // Push value to Stack
					break ;
					case '-' : value = pop2 - pop1 ; 
					pushOpr( value ) ; 
					break ;
					case '*' : value = pop2 * pop1 ; 
					pushOpr( value ) ; 
					break ;
					case '/' : value = pop2 / pop1 ; 
					pushOpr( value ) ; 
					break ;
					case '^' : value = pow(pop2,pop1) ; 
					pushOpr( value ) ; 
					break ;
				} 
			} // END IF
		} // ENF IF
		printf( "\nANS = %f",popOpr() ) ; // Last value is ANSWER
	} // END Fn.
	
void CalPostfixModify( char postfix[ 80 ] )
	{
		float pop1 ,pop2 ,value ,tempVal ;
		int i ,len ;
		char ch ;
		len = strlen( postfix ) ;
		printf( "Postfix = %s\n", postfix ) ;
		for( i = 0 ; i <= len - 1 ; i++ ) // Assign data to OPERAND
		{
			ch = postfix[ i ] ; // Split Character for assign data
			if( strchr( "+-*/^", ch ) == 0 ) // Check Is OPERAND?
			{	
				if ( isdigit( ch ) ) // check ch is number then convert to float
				{
					ValPostfixModify [ i ] = ch - '0' ;
				}
				else if ( ch != '@' ) // check when ch is duplicate 
				{
					printf( "\nAssign Number to %c : ",ch ) ;
					scanf( "%f" ,&ValPostfixModify[ i ] ) ; // Read data from KBD and direct to Value of OPERAND in Array
					tempVal = ValPostfixModify[ i ] ;
				}// END IF
				
				for ( int j = i + 1 ; j <= len - 1 ; j++ ) {
					if ( postfix[ i ] == postfix[ j ] ) {
						ValPostfixModify[ j ] = tempVal ;
						postfix[ j ] = '@' ;	
					}
				}
				
			}// END IF
		}
		for( i = 0 ; i <= len - 1 ; i++ ) // Calculate Value of POSTFIX
		{
			ch = postfix[ i ] ; //Split Character for prepare to STACK
			if( strchr( "+-*/^", ch ) == 0 )  //Check Is OPERAND?
			{
				pushOpr( ValPostfixModify[ i ] ) ; // push value of OPERAND to Stack
			} 
			else {
				pop1 = popOpr() ; // pop 1st
				pop2 = popOpr() ; // pop 2nd
				switch( ch )
				{
					case '+' : value = pop2 + pop1 ; // Calculate
					pushOpr( value ) ;                  // Push value to Stack
					break ;
					case '-' : value = pop2 - pop1 ; 
					pushOpr( value ) ; 
					break ;
					case '*' : value = pop2 * pop1 ; 
					pushOpr( value ) ; 
					break ;
					case '/' : value = pop2 / pop1 ; 
					pushOpr( value ) ; 
					break ;
					case '^' : value = pow(pop2,pop1) ; 
					pushOpr( value ) ; 
					break ;
				} 
			} // END IF
		} // ENF IF
		printf( "\nANS = %f",popOpr() ) ; // Last value is ANSWER
	} // END Fn.
	
int main ()
{
	printf ( "INFIX to POSTFIX CONVERSION PROGRAM\n" ) ;
	printf ( "===================================\n" ) ;

	infixTOpostfix ( infix2 ) ;
	
	printf ( " %s\n\n" , ResultPostfix ) ;
	printf( "\nPOSTFIX CALCULATION PROGRAM\n" ) ;
	printf( "===========================\n" ) ;
	CalPostfixModify( ResultPostfix ) ;
	getch() ;
	return ( 0 ) ;
}// END MAIN
