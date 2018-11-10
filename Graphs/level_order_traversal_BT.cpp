
/*=========================================

* File Name		:	level_order_traversal_BT.cpp

* Purpose		:

* Creation Date	:	11-11-2018

* Last Modified	:	Sunday 11 November 2018 02:59:48 AM IST

* Created By	: 	Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#include<vector>

//Definition for binary tree

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef struct TreeNode TreeNode;
 
void levelOrder_util(TreeNode* A, int level, vector<int>& temp)
{
    if(A==NULL) return;
    
    if(level==1) temp.push_back(A->val);
    
    if(level>1)
    {
        levelOrder_util(A->left,level-1,temp);
        levelOrder_util(A->right,level-1,temp);
    }
}

int height(TreeNode* A)
{
    if(A==NULL) return 0;
    
    int left_height = height(A->left);
    int right_height = height(A->right);
    
    if(left_height>right_height) return left_height+1;
    else return right_height+1;
}

vector<vector<int> > Solution::levelOrder(TreeNode* A) {

    vector<vector<int> > result;
    vector<int> temp;
    
    int h = height(A);
    int i;
    
    for(i=0;i<=h;i++)
    {
        temp = {};
        levelOrder_util(A,i,temp); 
        result.push_back(temp);
    }
    result.erase(result.begin());
    return result;
}

int main(int argc, char* argv)
{

	return 0;
}
