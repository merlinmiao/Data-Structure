//  main.c
//  链栈的各项操作
//
//  Created by 王淼 on 2017/3/14.
//  Copyright © 2017年 Merlin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(LinkStack)



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
} LinkStack ;


int main() {
	// insert code here...
	//头插法建表
	LinkStack * CreateListF(LinkStack *head,ElemType a[],int n);
	//尾插法建表
	LinkStack * CreateListR(LinkStack *head,ElemType a[],int n);
	void DispList(LinkStack *head);
	bool ListEmpty(LinkStack *L);
	void ListLenth(LinkStack *L);
	LinkStack * Push(LinkStack *L,ElemType e);
	LinkStack * Pop(LinkStack *L);
	LinkStack * head,*p;
//	head=(LinkStack *)malloc(LEN);
	ElemType a[]={1,2,3,4,5};
	int len=sizeof(a) / sizeof(ElemType);
	p=CreateListF(head, a, len);
	DispList(p);
	p=Push(p,6);
	DispList(p);
	p=Pop(p);
	DispList(p);
	return 0;
}

//头插法建表:所建表数据和原数组次序相反；算法时间复杂度为 O(n)
LinkStack * CreateListF(LinkStack *head,ElemType a[],int n){
	LinkStack * s;
	int i;
	head=(LinkStack *)malloc(LEN);
	head->next=NULL;   //创建头结点，将其 next 域置为 NULL
	for (i=0; i<n; i++) {
		s=(LinkStack *)malloc(LEN); //创建一个数据结点
		s->data=a[i];
		s->next=head->next;
		head->next=s;
	}
	return head;
}

//尾插法建表：所建表数据次序和原数组相同;算法时间复杂度为 O(n)
LinkStack * CreateListR(LinkStack *head,ElemType a[],int n){
	LinkStack * s,*r;
	int i;
	head=(LinkStack *)malloc(LEN);
	r=head;//r始终指向尾结点，开始指向头结点
	for (i=0; i<n; i++) {
		s=(LinkStack *)malloc(LEN); //创建一个数据结点
		s->data=a[i];
		r->next=s;
		r=s;
	}
	r->next=NULL; //将尾结点 next 域置为 NULL
	return head;
}

//输出链表
void DispList(LinkStack *head){
	LinkStack * p=head->next;
	printf("\n链栈第%d 次访问！",++visit);
	int count=1;
	while (p!=NULL) {
		printf("\n链栈除 head 外第%d个结点的值为：%d",count,p->data);
		p=p->next; //p 移向下一个结点
		count++;
	}
}

//初始化栈
void InitList(LinkStack *L){
	L=(LinkStack*)malloc(LEN);
	L->next=NULL;
}

//销毁栈
//从头结点一个一个开始销毁
void DestroyList(LinkStack *L){
	LinkStack *head,*p;
	head=L;
	p=head->next;
	while (p!=NULL) {
		free(head); //只能一个节点一个节点顺序释放
		head=p;
		p=head->next;
	}
	free(head);
}

//判断链栈是否为空
bool ListEmpty(LinkStack *L){
	 if(L->next==NULL)
		 return true;
	 else
		 return false;
}

//求链栈的长度:即表中元素的个数
void ListLenth(LinkStack *L){
	int n=0;
	LinkStack *p=L;//p 指向头结点
	while (p->next!=NULL) {
		n++;
		p=p->next;
	}
	printf("\n链栈的长度为%d",n);
}

//进栈
//将新数据插入到头结点后面
LinkStack * Push(LinkStack *L,ElemType e){
	LinkStack *p;
	p=(LinkStack *)malloc(LEN);
	p->data=e;
	p->next=L->next;
	L->next=p;
	return L;
}

//出栈
//在栈不为空的情况下，取出头结点后的结点值，并删除
LinkStack * Pop(LinkStack *L){
	LinkStack *p;
	if(L->next==NULL){
		printf("栈为空，无法出栈");
	}else{
		int e;
		p=L->next;
		e=p->data;
		L->next=p->next;
		free(p);
		printf("\n出栈的元素为:%d\n",e);
	}
	return L;
}