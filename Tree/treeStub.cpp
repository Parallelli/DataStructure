#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<stdlib.h>
#include<list>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(){}
    TreeNode(int v) : val(v), left(NULL), right(NULL){}
};

void deleteTeeNode(int val);
TreeNode* nextTreeNode_inorder(TreeNode *target);
TreeNode* nextTreeNode_postorder(TreeNode *target);
TreeNode* searchBST(int value);

/*
   Time complexity: O(n), T(n) = 2T(n/2) + O(1)
*/
TreeNode* sortedVectorToBST(vector<int>v, int start, int end)
{
    if(start > end)
        return NULL;
    int mid = start + (end - start)/2;
    TreeNode* rt = new TreeNode(v[mid]);
    rt -> left = sortedVectorToBST(v,start,mid-1);
    rt -> right = sortedVectorToBST(v,mid+1,end);
    return rt;
}

TreeNode* sortedArrayToBST(int a[], int start, int end)
{
    if(start > end)
        return NULL;
    int mid = start + (end - start)/2;
    TreeNode *rt = new TreeNode(a[mid]);
    rt->left = sortedArrayToBST(a, start, mid-1);
    rt->right = sortedArrayToBST(a, mid + 1, end);
    return rt;
}
/*
   Time complexity: O(n)
   Naive: find target value in linked list every time, T(n) = 2T(n/2)+O(n/2)
   O(nlgn)
*/
TreeNode* sortedLinkedListToBST(list<int>::iterator it, int start, int end)
{
    if(start > end)
        return NULL;
    int mid = start + (end - start)/2;
    TreeNode *leftChild = sortedLinkedListToBST(it,start,mid-1);
    TreeNode *rt = new TreeNode(*it);
    rt->left = leftChild;
    it++;
    TreeNode *rightChild = sortedLinkedListToBST(it,mid+1,end);
    rt -> right = rightChild;

    return rt;
}
void inorder(TreeNode *rt)
{
    if(rt)
    {
        printf("%d ", rt->val);
        if(rt->left)
            inorder(rt->left);
        if(rt->right)
            inorder(rt->right);
    }
}
void inorder_iterative(TreeNode *rt)
{
    //to do
}
int main()
{
    int a[] = {1,3,4,6,7,8,10,13,14}; //from wikipedia
    int n = 9;
    vector<int>v(a,a+n);
    list<int>l;
    for(int i = 0; i < n; i++)
        l.push_back(a[i]);
    list<int>::iterator it = l.begin();

    TreeNode* rt0 = sortedVectorToBST(v,0,n-1);
    TreeNode* rt1 = sortedArrayToBST(a,0,n-1);
    TreeNode* rt2 = sortedLinkedListToBST(it,0,n-1);
    
    inorder(rt0);
    printf("\n");    
    inorder(rt1);
    printf("\n");
    inorder(rt2);
    printf("\n");

    return 0;
}
