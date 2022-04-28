#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};

/*
Children Sum Property:
It is a property in which the sum 
of values of the left child and right child should be 
equal to the value of their node if both children are present. 
Else if only one child is present then the value of the child 
should be equal to its node value.

for a tree to satisy children sum property: all nodes
must follow this property, if one nodes fails. Then, the 
whole tree fails at it.
*/

//Time: O(N)
//Space: O(logN)
bool childrenSum(Node* root)
{
	if(root==NULL)
	{
		return true;
	}

	if(root->left==NULL and root->right==NULL)
	{
		return true;
	}

	int sum=0;

	if(root->left)
	{
		sum+=root->left->data;
	}

	if(root->right)
	{
		sum+=root->right->data;
	}

	return (root->data==sum and childrenSum(root->left) and childrenSum(root->right));
}

int main()
{
	Node* root=new Node(10);

	root->left=new Node(20);
	root->right=new Node(30);

	root->left->left=new Node(40);
	root->left->right=new Node(50);

	root->right->left=new Node(60);
	root->right->right=new Node(70);

	cout<<childrenSum(root)<<endl;
	
	return 0;
}