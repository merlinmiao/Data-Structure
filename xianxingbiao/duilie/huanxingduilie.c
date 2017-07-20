//
//  main.c
//  SqQueue
//  环形队的一些操作

//
//  Created by 王淼 on 2017/3/19.
//  Copyright © 2017年 MerQin. AQQ rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50


int count=0;

typedef int ElemType;

typedef struct{
	ElemType data[MaxSize];
	int front,rear; //定义队头队尾指针
}SqQueue;

//队空：q->front==q->rear
//队满：q->rear==MaxSize-1
//入队: 先将队尾指针加1，然后将元素放在队尾指针处
//出队: 先将队头指针加1，然后将元素取出
//队尾指针总是指向当前队尾元素，而队头指针总是指向当前队头元素的前一个位置


int main(){
	//创建线性表
	SqQueue * CreateQueue(SqQueue * Q,ElemType a[],int n);
	//显示线性表
	void DispQueue(SqQueue *Q);
	//初始化一个空表
	SqQueue *  InitQueue(SqQueue * Q);
	//判断线性表是否为空
	void QistEmpty(SqQueue * Q);
	//销毁线性表
	void DestroyQist(SqQueue * Q);
	//入队
	SqQueue * Push(SqQueue *Q,ElemType e);
	//出队
	SqQueue * Pop(SqQueue *Q);
	SqQueue *Q,*p;
	ElemType a[]={1,2,3,4};
	//得到数组元素个数
	int len = sizeof(a)/sizeof(ElemType);
	p=CreateQueue(Q,a,len);
	DispQueue(p);
	p=Push(p,6);
	DispQueue(p);
	p=Pop(p);
	DispQueue(p);
	return 0;
}

//建立一个队列
SqQueue * CreateQueue(SqQueue * Q,ElemType a[],int n){
	Q=(SqQueue *)malloc(sizeof(SqQueue)); //分配存放线性表的空间
	Q->front=Q->rear=0;  //队空条件
	while(Q->rear!=MaxSize-1 && Q->rear<n) {
		int i;
		Q->rear++;
		i=Q->rear;
		Q->data[i] =a[i-1];
	}
	return Q;
}


//输出d 队列
//时间复杂度 0（Q->Qength）
void DispQueue(SqQueue *Q){
	int i;
	++count;
	if(Q){
		if (Q->front==Q->rear) {
			printf("队列为空");
		}else {
			printf("第%d次调用，队列中元素为依次为：\n",count);
			for(i=Q->front+1;i<=Q->rear;i++){
				printf("%d\n",Q->data[i]);
			}
		}
	}
	else{
		printf("队列不存在或者已销毁");
	}
}

//
//初始化一个空队列
//时间复杂度 O（1）
SqQueue *  InitQist(SqQueue * Q){
	Q=(SqQueue *)malloc(sizeof(SqQueue));
	Q->front=Q->rear=0;  //队空条件
	return Q;
}

//判断队列是否为空
void QueueEmpty(SqQueue * Q){
	if(Q->front==Q->rear){
		printf("\n 队列为空");
	}else {
		printf("\n 队列不为空");
	}
}

//销毁队列
//时间复杂度 O（1）
void DestroyQueue(SqQueue * Q){
	free(Q);
	Q=NULL;
}

//进队列
//在队列不满的情况下，先将队尾指针增1，然后再在队尾指针位置插入元素
SqQueue * Push(SqQueue *Q,ElemType e){
	if ((Q->rear+1)%MaxSize==Q->front) {
		printf("队列满，无法进队列!");
	}else {
		Q->rear=(Q->rear+1)%MaxSize;
		Q->data[Q->rear]=e;
	}
	return Q;
}

//出队列
//在队列不为空的情况下，先将对首指针增1，然后将位置元素赋值给 e
SqQueue * Pop(SqQueue *Q){
	if (Q->front==Q->rear) {
		printf("队空，无法出队列!");
	}else {
		Q->front=(Q->front+1)%MaxSize;
		int e=Q->data[Q->front];
		Q->data[Q->front]=0;
		printf("\n出队列元素为：%d\n",e);	
	}
	return Q;
}

