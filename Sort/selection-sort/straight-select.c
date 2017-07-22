
//直接选择排序：直接选择排序和直接插入排序类似，都将数据分为有序区和无序区。
//所不同的是直接插入排序是将无序区的第一个元素直接插入到有序区以形成一个更大的有序区，
//而直接选择排序是从无序区选一个最小的元素直接放到有序区的最后。
////
//算法分析：
//
//平均时间复杂度为 O（n^2）
//空间复杂度为 O（1）
//不稳定

//说明：直接选择排序和冒泡排序类似，每趟产生的有序区一定是全局有序区。

//算法实现：
#include <stdio.h>

int main() {
	// your code goes here
	void SelectSort(int *p,int n);
	int a[]={98,76,109,34,67,190,80,12,14,89,1};
	int len = sizeof(a)/sizeof(int);
	int *p=a;
	SelectSort(p,len);
	for(int i=0;i<len;i++){
		printf("%d\n",a[i]);
	}
	printf("\n");
	return 0;
}

void SelectSort(int *p,int n){
	for(int i=0;i<n-1;i++){
		int k=i;
		for (int j=i+1;j<n;j++) {
			if (*(p+j)<*(p+k)) {
				k=j;
			}
		}
		if (k!=i) {
			int temp=*(p+i);
			*(p+i)=*(p+k);
			*(p+k)=temp;
		}
	}
}