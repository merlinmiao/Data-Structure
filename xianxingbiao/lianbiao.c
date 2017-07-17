//  main.c
//  链表的各项操作
//
//  Created by 王淼 on 2017/3/14.
//  Copyright © 2017年 Merlin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(LinkList)



//C语言中并没有bool类型变量。这是C++中新增的系统类型。
//使用枚举类型定义如下
typedef enum
{
	false,
	true
}bool;
//false 0;true 1;

typedef int ElemType;

ElemType visit=0;

typedef  struct LNode{
	ElemType data;
	struct LNode * next;
} LinkList ;
int n;

int main() {
	// insert code here...
	//头插法建表
	LinkList * CreateListF(LinkList *head,ElemType a[],int n);
	//尾插法建表
	LinkList * CreateListR(LinkList *head,ElemType a[],int n);
	void DispList(LinkList *head);
	bool ListEmpty(LinkList *L);
	void ListLenth(LinkList *L);
	ElemType GetData(LinkList*L,int i);
	int LocateElem(LinkList*L,ElemType data);
	void ListInsert(LinkList*L,int i,ElemType e);
	void ListDelete(LinkList*L,int i);
	LinkList * head,*p;
//	head=(LinkList *)malloc(LEN);
	ElemType a[]={1,2,3,4,5};
	int len=sizeof(a) / sizeof(ElemType);
	p=CreateListR(head, a, len);
	DispList(p);
//	ListLenth(p);
//	printf("\n 找到的元素的值是：%d",GetData(p,3));
	//printf("\n 所找元素的位置是：%d",LocateElem(p,1));
	ListInsert(p,1,9);
	ListDelete(p,1);
	printf("\n");
	return 0;
}

//头插法建表:所建表数据和原数组次序相反；算法时间复杂度为 O(n)
LinkList * CreateListF(LinkList *head,ElemType a[],int n){
	LinkList * s;
	int i;
	head=(LinkList *)malloc(LEN);
	head->next=NULL;   //创建头结点，将其 next 域置为 NULL
	for (i=0; i<n; i++) {
		s=(LinkList *)malloc(LEN); //创建一个数据结点
		s->data=a[i];
		s->next=head->next;
		head->next=s;
	}
	return head;
}

//尾插法建表：所建表数据次序和原数组相同;算法时间复杂度为 O(n)
LinkList * CreateListR(LinkList *head,ElemType a[],int n){
	LinkList * s,*r;
	int i;
	head=(LinkList *)malloc(LEN);
	r=head;//r始终指向尾结点，开始指向头结点
	for (i=0; i<n; i++) {
		s=(LinkList *)malloc(LEN); //创建一个数据结点
		s->data=a[i];
		r->next=s;
		r=s;
	}
	r->next=NULL; //将尾结点 next 域置为 NULL
	return head;
}

//输出链表
void DispList(LinkList *head){
	LinkList * p=head->next;
	printf("\n链表第%d 次访问！",++visit);
	int count=1;
	while (p!=NULL) {
		printf("\n链表除 head 外第%d个结点的值为：%d",count,p->data);
		p=p->next; //p 移向下一个结点
		count++;
	}
}

//初始化单链表
void InitList(LinkList *L){
	L=(LinkList*)malloc(LEN);
	L->next=NULL;
}

//销毁线性表
//从头结点一个一个开始销毁
void DestroyList(LinkList *L){
	LinkList *head,*p;
	head=L;
	p=head->next;
	while (p!=NULL) {
		free(head); //只能一个节点一个节点顺序释放
		head=p;
		p=head->next;
	}
	free(head);
}

//判断链表是否为空
bool ListEmpty(LinkList *L){
	 if(L->next==NULL)
		 return true;
	 else
		 return false;
}

//求线性表的长度:即表中元素的个数
void ListLenth(LinkList *L){
	int n=0;
	LinkList *p=L;//p 指向头结点
	while (p->next!=NULL) {
		n++;
		p=p->next;
	}
	printf("\n单链表的长度为%d",n);
}

//取线性表中某个位置元素的值
ElemType GetData(LinkList*L,int i){
	int edata=0,j=0;
	LinkList *p=L;
	while (j<i&&p!=NULL) {
		p=p->next;
		j++;
	}
	if(p!=NULL)
		edata = p->data;
	return edata;
}

//按元素值查找元素所在的位置
int LocateElem(LinkList*L,ElemType data){
	LinkList *p;
	int i=1;
	p=L->next;
	while (p!=NULL&&p->data!=data) {
		p=p->next;
		i++;
	}
	if(p!=NULL&&p->data==data)
		return i;
	else
		return 0;
}

//插入数据元素
void ListInsert(LinkList*L,int i,ElemType e){
	int j=1;
	LinkList *p=L,*s;
	while (j<i&&p!=NULL) {
		p=p->next;
		j++;
	}
	if(p!=NULL){
		s=(LinkList*)malloc(LEN);
		s->data=e;
		s->next=p->next;
		p->next=s;
	}
	DispList(L);
}

//删除数据元素
void ListDelete(LinkList*L,int i){
	int j=0;
	LinkList *p=L,*s;
	if(i<1){
		printf("\n 头结点不能删除");
	}
	else{
		while (j<i-1&&p!=NULL) {
			p=p->next;
			j++;
		}
		if(p!=NULL){
			s=p->next;
			if(s==NULL)
				printf("\n 此节点不存在！");
			else{
				p->next=s->next;
				free(s);
			}
		}
	}
	DispList(L);
}




