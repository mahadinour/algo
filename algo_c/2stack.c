#include<stdio.h>
#define capacity 3
int stack[capacity];
int top = -1;

void push(int x){
    if(top < capacity-1){
        top = top + 1;
        stack[top] = x;
        printf("succesfully add %d \n",x);
    }
    else{
        printf("no spaces\n");
    }
}
int pop(){
    if(top>= 0){
        int val = stack[top];
        top = top - 1;
        return val;
    }
    printf("EXCEPTION from pop! empty \n");
    return -1;
}

int peek(){
    if(top >=0){
        return stack[top];
    }
    printf("EXCEPTION from peek ! empty stack \n");
    return -1 ;
}


int main(int argc, char const *argv[])
{
    printf("this is my stack\n");
    peek();
    push(10);
    push(20);
    push(30);
    printf("pop item %d \n", pop());
    push(40);//over flow is no recived
    push(50);
    printf("top of the stack %d \n",peek());
    return 0;
}
