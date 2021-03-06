/*
Once Monk was watching a fight between an array and a tree, of being better. Tree got frustrated and converted that array into a Binary Search Tree by inserting the elements as nodes in BST, processing elements in the given order in the array. Now Monk wants to know the height of the created Binary Search Tree.

Help Monk for the same.

Note:

1) In Binary Search Tree, the left sub-tree contains only nodes with values less than or equal to the parent node; the right sub-tree contains only nodes with values greater than the parent node.

2) Binary Search Tree with one node, has height equal to 
1
1.

Input Format :

The first line will consist of 
1
1 integer 
N
N, denoting the number of elements in the array.
In next line, there will be 
N
N space separated integers, 
A
[
i
]
A[i] , where 
1
≤
i
≤
N
1≤i≤N, denoting the elements of array.

Output Format

Print the height of the created Binary Search Tree.
Source: Hackerearth
*/


#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create(int data)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

void insert(struct Node*root,int data)
{
    
    if(data>root->data)
    {
        if(root->right==NULL)
        root->right=create(data);
        else
        insert(root->right,data);
    }
    else
    {
        if(root->left==NULL)
        root->left=create(data);
        else
        insert(root->left,data);
    }
}

int height(struct Node* root,int count)
{
    if(root!=NULL)
    {
        count++;
        int h1=height(root->left,count);
        int h2=height(root->right,count);
        if(h2>h1)
        return h2;
        return h1;
    }
        return count;
}


int main()
{
    int n,data;
    cin>>n;
    cin>>data;
    struct Node * root=create(data);
    
    for(int i=0;i<n-1;i++)
    {
        cin>>data;
        insert(root,data);
    }
    cout<<height(root,0);
    
    
    return 0;
}
