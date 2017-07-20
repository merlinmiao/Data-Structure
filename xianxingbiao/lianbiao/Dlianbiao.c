//  main.c
//  链表的各项操作
//
//  Created by 王淼 on 2017/3/14.
//  Copyright © 2017年 Merlin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(DLinkList)



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

typedef  struct DNode{
	ElemType data;
	struct DNode * prior;
	struct DNode * next;
} DLinkList ;
int n;

int main() {
	// insert code here...
	//头插法建表
	DLinkList * CreateListF(DLinkList *head,ElemType a[],int n);
	//尾插法建表
	DLinkList * CreateListR(DLinkList *head,ElemType a[],int n);
	void DispList(DLinkList *head);
	bool ListEmpty(DLinkList *L);
	void ListLenth(DLinkList *L);
	ElemType GetData(DLinkList*L,int i);
	int LocateElem(DLinkList*L,ElemType data);
	void ListInsert(DLinkList*L,int i,ElemType e);
	void ListDelete(DLinkList*L,int i);
	DLinkList * head,*p;
//	head=(DLinkList *)malloc(LEN);
	ElemType a[]={1,2,3,4,5};
	int len=sizeof(a) / sizeof(ElemType);
	p=CreateListF(head, a, len);
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
DLinkList * CreateListF(DLinkList *head,ElemType a[],int n){
	DLinkList * s;
	int i;
	head=(DLinkList *)malloc(LEN);
	head->prior=head->next=NULL;   //创建头结点，将其前后指针域置为 NULL
	for (i=0; i<n; i++) {
		s=(DLinkList *)malloc(LEN); //创建一个数据结点
		s->data=a[i];
		s->next=head->next;
		//插入第二个结点及以上时，要考虑前后
		if (head->next!=NULL) {
			head->next->prior=s;
		}
		head->next=s;
		s->prior=head;
		
	}
	return head;
}

//尾插法建表：所建表数据次序和原数组相同;算法时间复杂度为 O(n)
DLinkList * CreateListR(DLinkList *head,ElemType a[],int n){
	DLinkList * s,*r;
	int i;
	head=(DLinkList *)malloc(LEN);
	r=head;//r始终指向尾结点，开始指向头结点
	for (i=0; i<n; i++) {
		s=(DLinkList *)malloc(LEN); //创建一个数据结点
		s->data=a[i];
		r->next=s;
		s->prior=r;
		r=s;
	}
	r->next=NULL; //将尾结点 next 域置为 NULL
	return head;
}

//输出链表
void DispList(DLinkList *head){
	DLinkList * p=head->next;
	printf("\n链表第%d 次访问！",++visit);
	int count=1;
	while (p!=NULL) {
		printf("\n链表除 head 外第%d个结点的值为：%d",count,p->data);
		p=p->next; //p 移向下一个结点
		count++;
	}
}

//初始化单链表
void InitList(DLinkList *L){
	L=(DLinkList*)malloc(LEN);
	L->prior=L->next=NULL;
}

//销毁线性表
//从头结点一个一个开始销毁
void DestroyList(DLinkList *L){
	DLinkList *head,*p;
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
bool ListEmpty(DLinkList *L){
	 if(L->next==NULL)
		 return true;
	 else
		 return false;
}

//求线性表的长度:即表中元素的个数
void ListLenth(DLinkList *L){
	int n=0;
	DLinkList *p=L;//p 指向头结点
	while (p->next!=NULL) {
		n++;
		p=p->next;
	}
	printf("\n单链表的长度为%d",n);
}

//取线性表中某个位置元素的值
ElemType GetData(DLinkList*L,int i){
	int edata=0,j=0;
	DLinkList *p=L;
	while (j<i&&p!=NULL) {
		p=p->next;
		j++;
	}
	if(p!=NULL)
		edata = p->data;
	return edata;
}

//按元素值查找元素所在的位置
int LocateElem(DLinkList*L,ElemType data){
	DLinkList *p;
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
void ListInsert(DLinkList*L,int i,ElemType e){
	int j=1;
	DLinkList *p=L,*s;
	while (j<i&&p!=NULL) {
		p=p->next;
		j++;
	}
	if(p!=NULL){
		s=(DLinkList*)malloc(LEN);
		s->data=e;
		s->next=p->next;
		if(p->next!=NULL)
			p->next->prior=s;
		s->prior=p;
		p->next=s;
	}
	DispList(L);
}

//删除数据元素
void ListDelete(DLinkList*L,int i){
	int j=0;
	DLinkList *p=L,*s;
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
				if (s->next!=NULL) {
					s->next->prior=p;
				}
				free(s);
			}
		}
	}
	DispList(L);
}




