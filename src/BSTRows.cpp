/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order here is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>
 
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

int height(struct node *root){
	if (root == NULL)
		return 0;

	int left_height = height(root->left);
	int right_height = height(root->right);

	return ((left_height>right_height) ? left_height : right_height) + 1;
}

void elements_in_Level(struct node* root, int level, int *arr, int *index)
{
	if (root == NULL)
		return;
	if (level == 1)
	{
		arr[*index] = root->data;
		*index = *index + 1;
	}
	else if (level > 1)
	{
		
		elements_in_Level(root->right, level - 1, arr, index);
		elements_in_Level(root->left, level - 1, arr, index);
	}
}

int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;

	int *arr = (int *)malloc(sizeof(int) * 1000);
	int h = height(root),index=0;
	int i;
	for (i = 1; i <= h; i++)
		elements_in_Level(root, i, &arr[0],&index);

	return arr;
}

