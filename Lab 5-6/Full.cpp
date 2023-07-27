#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define MaxStack 40 

char infix1[80]={"A+B*(C^D*E/F)-G"};
char OpSt[MaxStack];
int SP = 0;
///--------------------------------------
char postfix1[80]={"AB+C-d/"};
float ValPostfix[80];
float ValOperandST[MaxStack];
///--------------------------------------
void push(char oper){
	if(SP == MaxStack){
		printf("ERROR STACK OVER FLOW!!!...\n");
	}else{
		SP = SP+1;
		OpSt[SP]=oper;
		ValOperandST[SP] = ValOperandL6;
	}
}

float popA(){
	float ValOperand;
	if(SP != 0){
		ValOperand = ValOperandST[SP];
		SP--;
		return(ValOperand);
	}else{
		printf("\nERROR STACK UNDER FLOW!!!...\n");
	}
}

int pop(){
	char oper;
	if(SP != 0){
		oper = OpSt[SP];
		SP--;
		return(oper);
	}else{
		printf("\nERROR STACK UNDER FLOW!!!...\n");
	}
}
int precedenceIP(char oper){
	switch(oper){
		case '+'	:return(1);
		case '-'	:return(1);
		case '*'	:return(2);
		case '/'	:return(2);
		case '^'	:return(4);
		case '('	:return(4);
	}
}
int precedenceST(char oper){
	switch(oper){
		case '+'	:return(1);
		case '-'	:return(1);
		case '*'	:return(2);
		case '/'	:return(2);
		case '^'	:return(3);
		case '('	:return(0);
	}
}
///--------------------------------------
void CalPostfixLab6(char postfix[80]){
	float pop1,pop2,Value;
	int i , len;
	char ch;
	len = strlen(postfix);
	printf("Postfix = %s\n" ,postfix);
	for(i=0 ; i<=len-1 ;i++){
		ch = postfix[i];
		if(strchr("+-*/^", ch)==0){
			printf("\nAssign Number to %c :",ch);
			scanf("%f",&ValPostfix[i]);
		}
	}
	for(i=0;i<=len-1 ; i++){
		ch = postfix[i];
		if(strchr("+-*/^", ch)==0){
			push(ValPostfix[i]);
		}else{
			pop1 = popA();
			pop2 = popA();
			switch (ch){
				case '+'	:Value = pop2 + pop1;
							 	push(Value);
							 break;
				case '-'	:Value = pop2 - pop1;
								push(Value);
							 break;
				case '*'	:Value = pop2 * pop1;
								push(Value);
							 break;
				case '/'	:Value = pop2 / pop1;
								push(Value);	
							 break;		 
				case '^'	:Value = pow (pop2 , pop1);
								push(Value);
							 break;
			}
		}
	}
	printf("\nANS = %f" ,popA());
}
///--------------------------------------
void infixTOpostfix(char infix2[80]){
	int i,j,len;
	char ch,temp;
	printf("INFIX : %s\n" ,infix2);
	len = strlen(infix2);
	printf("Infix Length = %d \n",len);
	printf("PSTFIX IS :");
	for(i=0;i<=len-1 ; i++){
		ch = infix2[i];
		if(strchr("+-*/^()",ch)==0){
			printf("%c" ,ch);
		}else{
			if(SP == 0){
				push(ch);
			}else{
				if(ch != ')'){
					if(precedenceIP(ch)>precedenceST(OpSt[SP])){
						push(ch);
					}else{
						printf("%c",pop());
						while(precedenceIP(ch)<=precedenceST(OpSt[SP]) && (SP != 0)){
							printf("%c",pop());
						}
						push(ch);
					}
				}else{
					temp = pop();
					while((temp != '(')){
						printf("%c",temp);
						temp = pop();
					}
				}
			}
		}
	}
	j = SP;
	for(i=1;i<=j;i++)
		printf("%c",pop());
}

int main (){
	printf("INFIX to POSTFIX CONVERSION PROFRAM\n");
	printf("=================================\n");
	infixTOpostfix(infix1);
	getch();
	return 0 ;
}
