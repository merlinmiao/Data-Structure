//
//  main.c
//  插入排序：直接插入排序

// 最好在正序，时间复杂度为 O（n）,最坏为反序，时间复杂度为O(n^2)
//  平均时间复杂度 O（n^2）
//  空间复杂度为 O（1）
//  稳定
//  Created by 王淼 on 2017/3/22.
//  Copyright © 2017年 Merlin. All rights reserved.
//

#include <stdio.h>

int main() {
	// your code goes here
	//直接插入排序
	void sort(int *p,int n);
	int a[]={98,76,109,34,67,190,80,12,14,89,1};
	int len = sizeof(a)/sizeof(int);
	int *p=a;
	sort(p,len);
	for(int i=0;i<len;i++){
		printf("%d\n",a[i]);
	}
	printf("\n");
	return 0;
}

void sort(int *p,int n){
	for(int i=1;i<n;i++){
		//从1开始
		int temp = *(p+i);
		int j=i-1;
		//先找到比 temp 小的元素，然后元素后移
		while(j>=0&&temp<*(p+j)){
			*(p+j+1)=*(p+j);
			j--;
		}
		*(p+j+1)=temp;
	}
}
