/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node* GetNewNode(int data) {

	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

struct node* Insert(struct node *root, int data) {
	if (root == NULL) 
		root = GetNewNode(data);
	
	else if (data <= root->data)
		root->left = Insert(root->left, data);
	
	else 
		root->right = Insert(root->right, data);
	
	return root;
}

struct node *my_new_func(struct node *root, int *arr, int start, int end)
{
	int mid;
	if (start == end)
	{
		//printf("\narr[%d] = %d", start, arr[start]);
		root = Insert(root, arr[start]);
	}
	if (start < end)
	{
		mid = (start + end) / 2;
		//printf("\narr[%d] = %d", mid, arr[mid]);
		
		root = Insert(root, arr[mid]);
		root = my_new_func(root, arr, start, mid - 1);
		root = my_new_func(root, arr, mid + 1, end);
	}
	return root;

}

struct node * convert_array_to_bst(int *arr, int len){
	if (arr == NULL || len <= 0)
		return NULL;
	struct node *root = NULL;
	return my_new_func(root, arr, 0, len - 1);
	
}

