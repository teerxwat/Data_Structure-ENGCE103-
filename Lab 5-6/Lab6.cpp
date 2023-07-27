#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define MaxStack 40

char postfix1[80]={"AB+C-d/"};
float ValPostfix[80];
float ValOperandST[MaxStack];
int SP = 0;

void push(float ValOperand){
	if(SP == MaxStack){
		printf("ERROR STACK OVER FLOW!!!...\n");
	}else{
		SP = SP+1;
		ValOperandST[SP] = ValOperand;
	}
}

float pop(){
	float ValOperand;
	if(SP != 0){
		ValOperand = ValOperandST[SP];
		SP--;
		return(ValOperand);
	}else{
		printf("\nERROR STACK UNDER FLOW!!!...\n");
	}
}
void CalPostfix(char postfix[80]){
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
			pop1 = pop();
			pop2 = pop();
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
	printf("\nANS = %f" ,pop());
}

int main(){
	printf("POSTFIX CALULATION PROGRAM\n");
	printf("=========================\n");
	CalPostfix(postfix1);
	getch();
	return(0);
}
