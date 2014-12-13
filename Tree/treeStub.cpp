#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<stdlib.h>
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
void constructBST();

int main()
{
    int a[] = {1,3,4,6,7,8,10,13} //from wikipedia
    int n = 8;
    vector<int>v(a,a+n);
    //...

    return 0;
}
