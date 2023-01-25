#include <stdio.h>
#include <stdbool.h>
#define capacity 10
int queue[capacity];

int front = 0, rear = -1, totalitem = 0;

bool isfull(){
	if(totalitem == capacity){
		return true ;
	}
	return false;
}
bool isempty(){
	if(totalitem == 0){
		return true;
	}
	return false;
}
void enqueue (int item ){
	if(isfull()){
		printf ("the queue is full ..........\n");
        return ;
	}
	rear = (rear + 1)%capacity;
	queue[rear] = item;
	totalitem = totalitem + 1;
}

int dequeue(){
    if (isempty())
    {
        printf("sorry, the queue is empty ............\n");
        return -1;
    }
    int frontitem = queue[front];
    queue[frontitem] = - 1;
    front = (front + 1)% capacity;
    totalitem = totalitem - 1;
	return frontitem;
}
void show(){
	printf("queqe ............\n");
	for(int i= 0 ;i <capacity ; i++){
		printf("queue : %d ............\n",queue[i]);
	}
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);
    enqueue(90);
    enqueue(100);
    enqueue(110);
    show();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    show();
    return 0;
}