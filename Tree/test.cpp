/*************************************************************************** 
*   @file:      main.cpp 
*   @author:    ugly_chen 
*   @date:      2015.1.3 
*   @remark:    this code is for binary tree with array 
*   @note 
说明：使用数组的方法建立一颗二叉树
例如有一个数组 int p[7] = { 0, 1, 2, 3, 4, 5, 6 };那么如何把这个数组建立成一颗二叉树呢？请看下面的代码。
****************************************************************************/  
  
#include<iostream>  
  
using namespace std;  
  
  
struct binary_tree_node  
{  
	int data;  
	binary_tree_node* left_child;  
	binary_tree_node* right_child;  
};  
  
void create_tree(binary_tree_node* &tree, int a[], int len, int index)  
{  
	if (index >= len)  
		return;  
	tree = new binary_tree_node;  
	tree->data = a[index];  
	tree->left_child = NULL;  
	tree->right_child = NULL;  
	create_tree(tree->left_child, a, len, 2 * index + 1);  
	create_tree(tree->right_child, a, len, 2 * index + 2);  
}  
  
void Print(binary_tree_node* p)  
{  
	if (NULL == p)  
		return;  
	cout << p->data;  
	Print(p->left_child);  
	Print(p->right_child);  
}  
  
int main()  
{  
	int p[7] = { 0, 1, 2, 3, 4, 5, 6 };  
	binary_tree_node*tree;  
	create_tree(tree, p, 7, 0);  
	Print(tree);  
	return 0;  
}  