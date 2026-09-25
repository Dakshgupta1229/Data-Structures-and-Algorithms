/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    
    TreeNode* root = NULL;
    FindElements(TreeNode* root) {
        this->root = root;
        root->val = 0;
        traverse(root);
    }

    void traverse(TreeNode* root){
        if(root==NULL) return;
        if(root->left!=NULL) root->left->val = 2 * root->val + 1;
        if(root->right!=NULL) root->right->val = 2 * root->val + 2;
        traverse(root->left);
        traverse(root->right);
    }

    void check(TreeNode* root,int target,bool &flag){
        if(root==NULL) return;
        if(root->val==target){
            flag = true;
            return;
        }
        if(flag==true) return;
        check(root->left,target,flag);
        check(root->right,target,flag);
    }
    
    bool find(int target) {
        bool flag = false;
        check(root,target,flag);
        return flag;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */