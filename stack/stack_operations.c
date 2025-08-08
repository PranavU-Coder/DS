#include<stdio.h>
#include<stdlib.h>
#define MAX 10

// DATA STRUCTURE

typedef struct{
    int object;
} Element;

// ALL THE FUNCTIONS I WILL BE USING 

int isFull(int *top){
    if(*top == MAX-1){
        return 1;
    } else 
    return 0;
}

int isEmpty(int *top){
    if(*top == 1){
        return 1;
    } else 
    return 0;
}

void CreateStack(Element stack[10],int *top,int object){
    stack[++(*top)].object = object;
}

int Pop(Element stack[10],int *top){
    int element = stack[*top].object;
    (*top)--;
    return element;
}


// MAIN PROGRAM

int main(void){
    int top = -1;
    int i,ch;
    Element stack[MAX];
    do {
        printf("\nChoices : ");
        printf("\n 1 : Push \n 2 : Pop \n 3 : Display \n 4 : Exit \n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
             if(isFull(&top)==0){
                printf("Enter a value : ");
                scanf("%d",&i);

                CreateStack(stack,&top,i);
             } else {
                printf("stack overflow");
             } break;
            
             case 2: 
              if(isEmpty(&top)==0){
                int del = Pop(stack , &top);
                printf("element popped is : %d",del);
              } else {
                printf("empty stack");
              } break;

              case 3:
              printf("the content of the stack is : ");
              for(int j=top;j>=0;j--){
                printf("%d ",stack[j].object);
              } break;
              
              default: printf("invalid choice\n"); 
        }
    } while(ch!=4);
    return 0;
}