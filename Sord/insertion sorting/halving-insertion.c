//
//  main.c
//  插入排序：折半插入排序
//  平均时间复杂度 O（n^2）
//  空间复杂度 O (1)
//  稳定
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
	for(int i=1;i<n;i++){
		//从1开始
		int temp = *(p+i);
		int low=0;
		int high=i-1;
		//计算 0 ~ i-1 的中间点，用 i 索引处的元素与中间值进行比较，如果 i 索引处的元素大，说明要插入的这个元素应该在中间值和刚加入i索引之间，反之，就是在刚开始的位置 到中间值的位置，这样很简单的完成了折半；
		while(low<=high){
			int mid = (low+high)/2;
			if(temp>*(p+mid)){
				low=mid+1;
			}
			else{
				high=mid-1;
			}
		}
		//折半查找直到 low - high=1 ，然后将元素从 low 到 i 之间后移，将 *（p+i) 插入到 *(p+low)
		for ( int j=i; j > low; j--) {
			*(p+j) = *(p+j-1);
		}
		*(p+low)=temp;
	}
}
