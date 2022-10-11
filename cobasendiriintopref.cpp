#include<iostream>
#include<conio.h>
#include<string.h>
#define MAX 20
using namespace std;

char stack [MAX];
int top = -1;
char pop();
void push(char item);

void push(char item){
    top++;
    stack[top]=item;
}

char pop(){
    char a;
    a=stack[top];
    top--;
    return a;
}

int prcd(char symbol){
    switch(symbol){
        case '+':
        case '-':
        return 2;
        case '*':
        case '/':
        return 4;
        case '^':
        case '$':
        return 6;
        case '(':
        case ')':
        case '#':
        return 1;
    }
}

int isoperator(char symbol){
    switch(symbol){
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '$':
        case '(':
        case ')':
        return 1;
        default:
        return 0;
    }
}

void convertip(char infix[], char prefix[]){
    int i,symbol,j=0;
    char test[MAX];
    infix = strrev (infix);
    stack[++top]='#';
    for(i = 0; i<strlen(infix); i++){
        symbol=infix[i];
        if(isoperator(symbol)==0){
            prefix[j]=symbol;
            j++;
        }else{
            if(symbol==')'){
                push(symbol);
            }else if(symbol=='('){
                while(stack[top]!=')'){
                    prefix[j]=pop();
                    j++;
                }
                pop();
            }else{
                if(prcd(symbol)>prcd(stack[top])){
                    push(symbol);
                }else{
                    while(prcd(symbol)<=prcd(stack[top])){
                        prefix[j]=pop();
                        j++;
                    }
                    push(symbol);
                 }
                
            }
        }
    }

    while(stack[top]!='#'){
        prefix[j]=pop();
        j++;
    }
    prefix[j]='\0';
    prefix=strrev(prefix);
    
}





int main(){
    char infix[20],prefix[20];
    cout<<"Input Infix : ";
    cin>>infix;
    convertip(infix,prefix);
    cout<<"Konversi prefixnya adalah :";
    cout<<(prefix);
    getch();
    return 0;
}