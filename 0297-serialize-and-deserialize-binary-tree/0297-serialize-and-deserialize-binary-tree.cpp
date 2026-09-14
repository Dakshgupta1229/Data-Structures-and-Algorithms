/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        if(root==NULL) return "#,";
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL) str += "#,";
            else str += to_string(temp->val) +",";
            if(temp!=NULL){
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0]=='#') return NULL;
        stringstream ss(data);
        string value;
        getline(ss,value,',');
        TreeNode* root = new TreeNode(stoi(value));
        queue<TreeNode*> q;
        q.push(root);
        int i=2;
        int j=4;
        while(q.size()>0 && i<data.size()){
            TreeNode* temp = q.front();
            q.pop();
            getline(ss,value,',');
            if(value!="#") temp->left = new TreeNode(stoi(value));
            else temp->left = NULL;
            getline(ss,value,',');
            if(value!="#") temp->right = new TreeNode(stoi(value));
            else temp->right = NULL;
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
            i+=4;
            j+=4;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));