//
//  main.c
//  SqStack
//  顺序栈的一些操作
//
//  Created by 王淼 on 2017/3/19.
//  Copyright © 2017年 Merlin. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

int count=0;
typedef int Status;
typedef int ElemType;

typedef struct{
	ElemType data[MaxSize];
	int  top;
}SqStack;

int main(){
	//创建线性表
	SqStack * CreateList(SqStack * L,ElemType a[],int n);
	//显示线性表
	void DispList(SqStack *L);
	//初始化一个空表
	SqStack *  InitList(SqStack * L);
	//判断线性表是否为空
	void ListEmpty(SqStack * L);
	//销毁线性表
	void DestroyList(SqStack * L);
	//进栈
	SqStack * Push(SqStack *L,ElemType e);
	//出栈
	void Pop(SqStack *L);
	//取栈顶元素
	void GetTop(SqStack *L);
	SqStack *L,*p;
	ElemType a[]={0,1,2,3,4,5};
	//得到数组元素个数
	int len = sizeof(a)/sizeof(ElemType);
	p=CreateList(L,a,len);
	DispList(p);
	p=Push(p,6);
	DispList(p);
	Pop(p);
	GetTop(p);
	return 0;
}

//建立一个栈
SqStack * CreateList(SqStack * L,ElemType a[],int n){
	L=(SqStack *)malloc(sizeof(SqStack)); //分配存放线性表的空间
	L->top=-1;
	while(L->top!=MaxSize-1 && L->top<n-1) {
		int i;
		L->top++;
		i=L->top;
		L->data[i] =a[i];
	}
	return L;
}


//输出线性表
//时间复杂度 0（L->length）
void DispList(SqStack *L){
	int i;
	++count;
	if(L){
		if (L->top==-1) {
			printf("线性栈为空");
		}else {
			printf("第%d次调用，栈中元素为：\n",count);
			for(i=0;i<=L->top;i++){
				printf("%d\n",L->data[i]);
			}
		}
	}
	else{
		printf("线性栈不存在或者已销毁");
	}
}

//
//初始化一个空栈
//时间复杂度 O（1）
SqStack *  InitList(SqStack * L){
	L=(SqStack *)malloc(sizeof(SqStack));
	L->top = -1; //栈空条件
	return L;
}
//
//判断线性栈是否为空表
void ListEmpty(SqStack * L){
	if(L->top==-1){
		printf("\n 线性表为空");
	}else {
		printf("\n 线性表不为空");
	}
}
//
//销毁线性栈
//时间复杂度 O（1）
void DestroyList(SqStack * L){
	free(L);
	L=NULL;
	DispList(L);
}
//
//进栈
//在栈不满的情况下，先将栈顶指针增1，然后再将栈顶指针位置插入元素
SqStack * Push(SqStack *L,ElemType e){
	if (L->top==MaxSize-1) {
		printf("栈满，无法进栈!");
	}else {
		L->top++;
		L->data[L->top]=e;
	}
	return L;
}

//出栈
//在栈不为空的情况下，先将栈顶元素赋值给 e，然后将栈顶指针减1
void Pop(SqStack *L){
	if (L->top==-1) {
		printf("栈空，无法出栈!");
	}else {
		int e=L->data[L->top];
		L->top--;
		printf("\n出栈元素为%d\n",e);
		DispList(L);	
	}
}

//取栈顶元素
void GetTop(SqStack *L){
	if (L->top==-1) {
		printf("栈空，无栈顶元素!");
	}else{
		printf("栈顶元素为%d",L->data[L->top]);
	}
}