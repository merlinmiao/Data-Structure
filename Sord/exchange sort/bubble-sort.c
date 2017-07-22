//冒泡排序：
//注意两点就是，无序区逐渐减少，有序区逐渐增加，排序的过程始终在无序区
//如果让头部作为有序区，那就从尾部开始排；
//如果让尾部作为有序区，那就从头部开始排；
//
//算法分析：
//时间复杂度：
//最好的情况：O(n) 最坏的情况：O（n^2）
//平均时间复杂度：O（n^2）
//空间复杂度：O(1)
//稳定
//
//
//算法实现：
#include <stdio.h>

int main() {
	// your code goes here
	//冒泡排序
	void fun(int *p,int n);
	int a[]={98,76,109,34,67,190,80,12,14,89,1};
	int len = sizeof(a)/sizeof(int);
	int *p=a;
	fun(p,len);
	for(int i=0;i<len;i++){
		printf("%d\n",a[i]);
	}
	printf("\n");
	return 0;
}

void fun(int *p,int n){
	for(int i=0;i<n-1;i++){
//		设定头部为有序区，从尾部开始比较元素
		for (int j=n-1; j>i; j--) {
			if(*(p+j)<*(p+j-1)){
				int temp=*(p+j);
				*(p+j)=*(p+j-1);
				*(p+j-1)=temp;
			}
		}
	}
}
