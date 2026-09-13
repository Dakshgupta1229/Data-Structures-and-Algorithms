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
    void traverse(TreeNode* root){
        if(root==NULL) return;
        int parent = root->val;
        if(root->left!=NULL) root->left->val = 2 * parent + 1;
        if(root->right!=NULL) root->right->val = 2 * parent + 2;
        traverse(root->left);
        traverse(root->right);
    }

    TreeNode* root;
    FindElements(TreeNode* root) {
        root->val = 0;
        this->root = root;
        traverse(root);
    }
    bool check(TreeNode* root,int target){
        if(root==NULL) return false;
        if(root->val==target) return true;
        bool left_tree = check(root->left,target);
        if(left_tree==true) return left_tree;
        return check(root->right,target);
    }
    
    bool find(int target) {
        bool result = check(root,target);
        return result;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */