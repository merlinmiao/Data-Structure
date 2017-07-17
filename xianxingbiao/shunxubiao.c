//
//  main.c
//  SqList
//  顺序表的一些操作
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
	int length;
}SqList;

int main(){
	//创建线性表
	SqList * CreateList(SqList * L,ElemType a[],int n);
	//显示线性表
	void DispList(SqList *L);
	//初始化一个空表
	SqList *  InitList(SqList * L);
	//判断线性表是否为空
	void ListEmpty(SqList * L);
	//销毁线性表
	void DestroyList(SqList * L);
	//查找给定值的元素的序号
	int LocateElem(SqList *L,ElemType e);
	//插入数据元素
	void ListInsert(SqList *L,int i,ElemType e);
	//删除数据元素
	void ListDelete(SqList *L,int i);
	SqList *L,*p;
	int m;
	ElemType a[]={0,1,2,3,4,5};
	//得到数组元素个数
	int len=sizeof(a) / sizeof(ElemType);
//	p=InitList(L);
	
	p=CreateList(L,a,len);
	DispList(p);
	DestroyList(p);
//	ListEmpty(p);
//	m=LocateElem(p,3);
//	printf("\n查找元素的位置为：%d",m);
//	ListInsert(p,3,8);
//	ListDelete(p,3);
	return 0;
}

//建立顺序表
SqList * CreateList(SqList * L,ElemType a[],int n){
	int i;
	L=(SqList *)malloc(sizeof(SqList)); //分配存放线性表的空间
	for(i=0;i<n;i++){
		L->data[i] =a[i];
	}
	L->length = n;
	return (L);
}


//输出线性表
//时间复杂度 0（L->length）
void DispList(SqList *L){
	int i;
	++count;
	if(L){
		if (L->length==0) {
			printf("线性表为空");
		}else {
			printf("第%d次调用，表中元素为：\n",count);
			for(i=0;i<L->length;i++){
				printf("%d\n",L->data[i]);
			}
		}
	}
	else{
		printf("线性表不存在或者已销毁");
	}
}


//初始化一个空表
//时间复杂度 O（1）
SqList *  InitList(SqList * L){
	L=(SqList *)malloc(sizeof(SqList));
	L->length = 0;
	return L;
}

//判断线性表是否为空表
void ListEmpty(SqList * L){
	if(L->length==0){
		printf("\n 线性表为空");
	}else {
		printf("\n 线性表不为空");
	}
}

//销毁线性表
//时间复杂度 O（1）
void DestroyList(SqList * L){
	free(L);
	L=NULL;
	DispList(L);
}



//查找给定值的元素的序号
//时间复杂度为  0（L->length）
int LocateElem(SqList *L,ElemType e){
	int i=0;
	while(i<L->length&&L->data[i]!=e)
		i++;
	if(i>=L->length)
		return 0;
	else
		return i+1;//返回他是第几个元素
}

//插入数据元素
//时间复杂度 O（n）P34
void ListInsert(SqList *L,int i,ElemType e){
	int j;
	Status m;
	if(i<1||i>L->length+1)
		m=FALSE;
	else{
		i--;
		for(j=L->length;j>i;j--){
			L->data[j]=L->data[j-1];
		}
		L->data[i]=e;
		L->length++;
		m=TRUE;
	}
	if(m==TRUE){
		printf("\n元素插入成功\n");
	}
	else{
		printf("\n元素插入失败\n");
	}
	DispList(L);
}

//删除数据元素
//时间复杂度 O（n）P34
void ListDelete(SqList *L,int i){
	int j;
	Status m;
	if(i<1||i>L->length+1)
		m=FALSE;
	else{
		i--;
		for(j=i;j<L->length-1;j++){
			L->data[j]=L->data[j+1];
		}
		L->length--;
		m=TRUE;
	}
	if(m==TRUE){
		printf("\n元素删除成功\n");
	}
	else{
		printf("\n元素删除失败\n");
	}
	DispList(L);
}