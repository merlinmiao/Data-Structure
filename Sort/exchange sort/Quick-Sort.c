//快速排序：由冒泡排序改进
//
//基本思想：
//
//1．先从数列中取出一个数作为基准数。
//
//2．分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。
//
//3．再对左右区间重复第二步，直到各区间只有一个数。
//
//挖坑填坑法，先给基数挖坑，从右往左，找比基数小的数，填到基数的位置；然后从左往右找比基数大的数，填到刚才右边留出来的位置，递归调用此法，直到左右哨兵相遇，然后在此位置填入基数，至此，基数左边全是小于基数的数，右边全是大于基数的数
//
//算法分析：
//当基数为最大或者最小值时，属于最坏情况，时间复杂度为 O(n^2)
//当基数为居中时，属于最好情况，时间复杂度为j O(nlog2n)
//空间复杂度为：O(log2n)
//不稳定
//
//算法实现：

#include <stdio.h>

int main() {
	// your code goes here
	void QuickSort(int *p,int left,int right);
	int a[]={98,76,109,34,67,190,80,12,14,89,1};
	int len = sizeof(a)/sizeof(int);
	int *p=a;
	QuickSort(p,0,len-1);
	for(int i=0;i<len;i++){
		printf("%d\n",a[i]);
	}
	printf("\n");
	return 0;
}


void QuickSort(int *p,int left,int right){
	int i = left;
	int j = right;
	if (left<right) {
		int temp=*(p+i);
		while (i!=j) {
			while (j>i&&temp<=*(p+j)) {
				j--; 
			}
			*(p+i)=*(p+j);
			while (i<j&&temp>=*(p+i)) {
				i++;
			}
			*(p+j)=*(p+i);
		}
		*(p+i)=temp;
		QuickSort(p,left,i-1); //对左区间递归
		QuickSort(p,i+1,right); //对右区间递归
	}
}