//  main.c
//  链队的各项操作
//
//  Created by 王淼 on 2017/3/14.
//  Copyright © 2017年 Merlin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(LinkQueue)



//C语言中并没有bool类型变量。这是C++中新增的系统类型。
//使用枚举类型定义如下
typedef enum
{
	false,
	true
}bool;
//false 0;true 1;
int n;
int visit=0;

typedef int ElemType;

typedef  struct LNode{
	ElemType data;
	struct LNode * next;
} QNode ;

typedef  struct {
	QNode * front;
	QNode * rear;
} LinkQueue ;

int main() {
	// insert code here...
	//尾插法建表
	LinkQueue * CreateListR(LinkQueue *head,ElemType a[],int n);
	void DispList(LinkQueue *head);
//	bool ListEmpty(LinkQueue *L);
//	void ListLenth(LinkQueue *L);
	LinkQueue * Push(LinkQueue *Q,ElemType e);
	LinkQueue * Pop(LinkQueue *Q);
	LinkQueue * head,*p;
	ElemType a[]={1,2,3,4,5};
	int len=sizeof(a) / sizeof(ElemType);
	p=CreateListR(head, a, len);
	DispList(p);
	p=Push(p,6);
	DispList(p);
	p=Pop(p);
	DispList(p);
	return 0;
}


//所建表数据次序和原数组相同;算法时间复杂度为 O(n)
LinkQueue * CreateListR(LinkQueue *Q,ElemType a[],int n){
	int i;
	Q=(LinkQueue *)malloc(LEN);
	Q->front=Q->rear=NULL;
	QNode *p;
	for (i=0; i<n; i++) {
		p=(QNode *)malloc(sizeof(QNode)); //创建一个数据结点
		p->data=a[i];
		if (Q->rear==NULL) {
			Q->front=Q->rear=p;
		}else {
			Q->rear->next=p;
			Q->rear=p;
		}
		
	}
	return Q;
}

//输出链表
void DispList(LinkQueue *Q){
	QNode *p=Q->front;
	printf("\n链队第%d 次访问！",++visit);
	int count=1;
	while (Q->rear!=p) {
		printf("\n链队第%d个结点的值为：%d",count,p->data);
		p=p->next; //p 移向下一个结点
		count++;
		if (Q->rear==p) {
			printf("\n链队最后一个结点的值为：%d",p->data);
		}
	}
}

//初始化队
void InitQueue(LinkQueue *Q){
	Q=(LinkQueue*)malloc(LEN);
	Q->front=Q->rear=NULL;
}

//销毁队
//从头结点一个一个开始销毁
void DestroyList(LinkQueue *Q){
	QNode *p,*r;
	p=Q->front;
	if (p!=NULL) {
		r=p->next;
		while (r!=NULL) {
			free(p); //只能一个节点一个节点顺序释放
			p=r;
			r=p->next;
		}
	}
	free(p);
	free(Q);
}

//判断链队是否为空
bool QueueEmpty(LinkQueue *Q){
	 if(Q->rear==NULL)
		 return true;
	 else
		 return false;
}


//进队
//在单链表尾插入结点 P，并让队尾指针指向
LinkQueue * Push(LinkQueue *Q,ElemType e){
	QNode *p;
	p=(QNode *)malloc(sizeof(QNode));
	p->data=e;
	p->next=NULL;
	if (Q->rear==NULL) {
		Q->front=Q->rear=p;
	}else {
		Q->rear->next=p;
		Q->rear=p;
	}
	return Q;
}

//出队
//在队不为空的情况下，取出头结点后的结点值，并删除
LinkQueue * Pop(LinkQueue *Q){
	QNode *p;
	if(Q->rear==NULL){
		printf("队为空，无法出队");
	}else{
		int e;
		p=Q->front;
		e=p->data;
		printf("\n出队的元素为:%d\n",e);
		if(Q->front==Q->rear){
			Q->front=Q->rear=NULL;
		}else{
			Q->front=Q->front->next;
		}
		free(p);
	}
	return Q;
}