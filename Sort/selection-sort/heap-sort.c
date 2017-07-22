//堆排序 C 语言
#include <stdio.h>

int main() {
	// your code goes here
	//堆排序
	void MinHeapSort(int *p, int n);
	void MaxHeapSort(int *p, int n);
	int a[]={98,76,109,34,67,190,80,12,14,89,1};
	int len = sizeof(a)/sizeof(int);
	int *p=a;
	MinHeapSort(p,len);
	MaxHeapSort(p,len);
	printf("\n");
	return 0;
}


//堆化操作：从上至下，将小数据上浮，大数据下沉，构建小根堆

void MinHeap(int *p, int i,int n){
	int j, temp; 
	temp = *(p+i); 
	j = 2 * i + 1;
	while(j<n){
		// 表明右孩子节点数据更小
		if(j+1<n && *(p+j+1)<*(p+j)){
			j++;
		}
		//左右孩子都比父节点大，则跳出循环
		if(*(p+j)>=temp){
			 break;
		}
		*(p+i)=*(p+j); //把较小的子结点往上移动,替换它的父结点
		i=j; //父节点下沉，继续往下
		j=2*i+1;
	}
	*(p+i)=temp;
}

void MinHeapSort(int *p, int n){
	//	1、堆化数组，建立最小堆，堆中根结点数据是堆中最小的数据。
	for(int i=n/2-1;i>=0;i--){
		//初始化堆
		MinHeap(p,i,n);
	}
//	2、取出堆顶数据，然后将末尾数据移至堆顶，然后再执行堆化操作。
//	3、重复上述步骤直至堆中只有一个数据时就直接取出这个数据。
	for(int i=n-1;i>=0;i--){
		//交换首末元素位置
		int tmp;
		tmp = *p;
		*p=*(p+i);
		*(p+i)=tmp;
		MinHeap(p,0,i);
//		每次做完，将头部数据放在尾部，然后数据由 n 个元素变成 n-1一个元素进行堆排序
	}
	printf("\n构造小根堆，小数据放在尾，大数据放在前！\n");
	for(int i=0;i<n;i++){
		printf("%d\n",*p++);
	}
}


//堆化操作：从上至下，将大数据上浮，小数据下沉，构建大根堆

void MaxHeap(int *p, int i,int n){
	int j, temp; 
	temp = *(p+i); 
	j = 2 * i + 1;
	while(j<n){
		// 表明右孩子节点数据更小
		if(j+1<n && *(p+j+1)>*(p+j)){
			j++;
		}
		//左右孩子都比父节点小，则跳出循环
		if(*(p+j)<=temp){
			 break;
		}
		*(p+i)=*(p+j); //把较大的子结点往上移动,替换它的父结点
		i=j; //父节点下沉，继续往下
		j=2*i+1;
	}
	*(p+i)=temp;
}

void MaxHeapSort(int *p, int n){
	//	1、堆化数组，建立最小堆，堆中根结点数据是堆中最小的数据。
	for(int i=n/2-1;i>=0;i--){
		//初始化堆
		MaxHeap(p,i,n);
	}
//	2、取出堆顶数据，然后将末尾数据移至堆顶，然后再执行堆化操作。
//	3、重复上述步骤直至堆中只有一个数据时就直接取出这个数据。
	for(int i=n-1;i>=0;i--){
		//交换首末元素位置
		int tmp;
		tmp = *p;
		*p=*(p+i);
		*(p+i)=tmp;
		MaxHeap(p,0,i);
//		每次做完，将头部数据放在尾部，然后数据由 n 个元素变成 n-1一个元素进行堆排序
	}
	printf("\n构造大根堆，大数据放在尾，小数据放在前！\n");
	for(int i=0;i<n;i++){
		printf("%d\n",*p++);
	}
}
