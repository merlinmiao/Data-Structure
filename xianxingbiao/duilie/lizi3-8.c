//采用一个不带头结点，只有一个尾指针 rear 的循环单链表存储队列

#include <stdio.h>
#include <stdlib.h>


typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode * next;
} LinkRear;

int visit=0;

int main() {
	LinkRear * InitRearueue(LinkRear *Rear);
	void DispLinkRear (LinkRear *Rear);
	LinkRear * Push(LinkRear *Rear,ElemType e);
	LinkRear * Pop(LinkRear *Rear);
	LinkRear *rear,*p;
	p=InitRearueue(rear);
	DispLinkRear(p);
	p=Push(p,1);
	DispLinkRear(p);
	p=Push(p,2);
	DispLinkRear(p);
	p=Pop(p);
	DispLinkRear(p);
	return 0;
}

//初始化队列，让队尾指针指向自己，并不存储数据
LinkRear * InitRearueue(LinkRear *Rear){
	Rear=NULL;
	return Rear;
}

//打印队列

void DispLinkRear (LinkRear *Rear){
	LinkRear *p;
	int cnt=0;
	printf("\n第%d次访问队列",++visit);
	if(Rear==NULL){
		printf("\n队中无结点!");
	}else if (Rear->next==Rear) {
		printf("\n队中只有一个节点，值为:%d",Rear->data);
	}else {
		p=Rear->next;
		while (p!=Rear) {
			printf("\n链队的第%d个元素值是:%d",++cnt,p->data);
			p=p->next;	
			if (p==Rear) {
				printf("\n链队最后一个元素值是:%d",p->data);
			}
		}
	} 
}

//入队

LinkRear * Push(LinkRear *Rear,ElemType e){
	LinkRear *p;
	p=(LinkRear *)malloc(sizeof(LinkRear));
	p->data=e;
	//将 p插入 Rear之后
	if (Rear==NULL) {
		p->next=p;
		Rear=p;
	}else {
		p->next=Rear->next;
		Rear->next=p;
		//将rear 指针移到 p
		Rear=p;
	}
	return Rear;
}

//出队
LinkRear * Pop(LinkRear *Rear){
	LinkRear *p;
	if(Rear==NULL){
		printf("队为空!");
	}else if(Rear->next==Rear){
		//队中只有一个节点
		printf("\n出队的元素值是:%d\n",Rear->data);
		free(Rear);
		Rear=NULL;
	}else{
		p=Rear->next;
		printf("\n出队的元素值是:%d\n",p->data);
		Rear->next=p->next;
		free(p);
	} 
	return Rear;
}