/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            stack<TreeNode*> p_path;
            stack<TreeNode*> q_path;
            
            if(getNodePath(p_path,root,p) && getNodePath(q_path,root,q)){
                int l = p_path.size();
                // TreeNode* tem = new TreeNode(l);
                // return tem;
                int r = q_path.size();
                // TreeNode* tem = new TreeNode(l);
                // return tem;
                if(l==r){
                    // for(int i = 0;i<l;i++){
                    while(!p_path.empty()){
                        if(p_path.top() == q_path.top()){
                            return p_path.top();
                        }else{
                            p_path.pop();
                            q_path.pop();
                        } 
                    }
                }else if(l>r){
                    while(l!=r){
                        l--;
                        p_path.pop();
                    }
                    // for(int i = 0;i<r;i++){
                    while(!p_path.empty()){
                        if(p_path.top() == q_path.top()){
                            return p_path.top();
                        }else{
                            p_path.pop();
                            q_path.pop();
                        } 
                    }
                }else if(l<r){
                    while(l!=r){
                        r--;
                        q_path.pop();
                    }
                    // for(int i = 0;i<l;i++){
                    while(!q_path.empty()){
                        if(p_path.top() == q_path.top())
                            return p_path.top();
                        else{
                            p_path.pop();
                            q_path.pop();
                        } 
                    }
                }
            }
            
            return root;
    }
    
    TreeNode* HasNode(TreeNode* root,TreeNode* target){
        if(root == NULL || target == NULL)
            return NULL;
        
        if(root->val == target->val){
            return root;
        }else{
            TreeNode *res;
            if((res = HasNode(root->left,target)) != NULL)
                return res;
            else if((res = HasNode(root->right,target)) != NULL)
                return res;
            else
                return NULL;
        }
    }
    
    bool getNodePath(stack<TreeNode*>& res,TreeNode* root,TreeNode* target){
        if(root == NULL || target == NULL)
            return false;
        
        bool flag = false;    
        if(root->val == target->val){
            res.push(root);
            flag = true;
        }else{
            res.push(root);
            if(root->left){
                if(getNodePath(res,root->left,target))
                    flag = true;
                if(!flag)
                    res.pop();
            }
            if(root->right && !flag){
                if(getNodePath(res,root->right,target))
                    flag = true;
                if(!flag)
                    res.pop();
            }
        }
            return flag;
    }
};
