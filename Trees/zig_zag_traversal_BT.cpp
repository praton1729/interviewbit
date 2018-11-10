#include<stdio.h>
#include<stdlib.h>
#include<vector>

// Definition for binary tree

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int height(TreeNode* A)
{
    if(A==NULL) return 0;
    
    int left_height = height(A->left);
    int right_height = height(A->right);
    
    if(left_height > right_height) return (left_height+1);
    else return (right_height+1);
}

void Solution::zigzagLevelOrder_util(TreeNode* A, int level, int flag, vector<int>& temp)
{
    if(A==NULL) return;
    
    if(level==1) temp.push_back(A->val);
    else if (level>1)
    {
        if(flag)
        {
            zigzagLevelOrder_util(A->right,level-1,flag,temp);
            zigzagLevelOrder_util(A->left,level-1,flag,temp);
        }
        else
        {           
            zigzagLevelOrder_util(A->left,level-1,flag,temp);
            zigzagLevelOrder_util(A->right,level-1,flag,temp);
        }
    }
}

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    
    int h = height(A);
    int i,transversal_flag=1;//transversal_flag=0 for left->right and 1 for right->left.

    vector<vector<int> > result;
    vector<int> temp;
    
    for(i=0;i<=h;i++)
    {
        temp = {};
        zigzagLevelOrder_util(A,i,transversal_flag,temp);
        result.push_back(temp);
        transversal_flag = !transversal_flag;
    }
    result.erase(result.begin());
    return result;
}

