void root_to_leaf_sum(TreeNode *root,int sum,vector<int> &temp,vector<vector<int> > &sol)
{
    if(sum==0 && root->left==NULL && root->right==NULL)
        sol.push_back(temp);
    if(root->left!=NULL)
    {
        temp.push_back((root->left)->val);
        root_to_leaf_sum(root->left,sum-(root->left)->val,temp,sol);
        temp.pop_back();
    }
    if(root->right!=NULL)
    {
        temp.push_back((root->right)->val);
        root_to_leaf_sum(root->right,sum-(root->right)->val,temp,sol);
        temp.pop_back();
    }
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int> > sol;
    vector<int> temp;
    if(A==NULL)
        return sol;
    temp.push_back(A->val);
    root_to_leaf_sum(A,B-(A->val),temp,sol);
    return sol;
}
