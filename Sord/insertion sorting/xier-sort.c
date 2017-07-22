//
//  main.c
//  插入排序：希尔排序
//  时间复杂度 O（n^2）
//  空间复杂度 O (1)
//  不稳定：相同元素相对位置会发生改变
//  Created by 王淼 on 2017/3/30.
//  Copyright © 2017年 Merlin. All rights reserved.
//

#include <stdio.h>

int main() {
	// your code goes here
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
	//gap 为距离
	int gap=n/2;
	while (gap>0) {
		for(int i=gap;i<n;i++){
			//从1开始
			int temp = *(p+i);
			int j=i-gap;
			while(j>=0&&temp<*(p+j)){
				*(p+j+gap)=*(p+j);
				j=j-gap;
			}
			*(p+j+gap)=temp;
		}
		gap=gap/2;
	}
}
