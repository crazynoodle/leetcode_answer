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

                int r = q_path.size();

                if(l==r){
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
    
    TreeNode* lowestCommonAncestor_(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root == NULL)
                return NULL;
            
            if(!IsInclude(root,p,q))
                return NULL;
            else{
                TreeNode* left =  lowestCommonAncestor(root->left,p,q);
                TreeNode* right = lowestCommonAncestor(root->right,p,q);
                if(!left && !right)
                    return root;
                else if(!left && right)
                    return right;
                else return left;
            }
            return root;
    }
    
    TreeNode* HasNode(TreeNode* root,TreeNode* target){
        if(root == NULL || target == NULL)
            return NULL;
        
        if(root == target){
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
        if(root == target){
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
    
    /*判断结点是否同时包含A和B*/
    bool IsInclude(TreeNode* pRoot,TreeNode* nFirst,TreeNode* nSec,bool& bIsInFir,bool& bIsInSec)
    {
    	if (!pRoot)
    	{
    		return false;
    	}

    	if (pRoot == nSec){
    	       // if(pRoot == nFirst){
    	       //     if(bIsInFir)
    		      //  bIsInSec = true;
    	       // }else
    	            bIsInSec = true;
    	}    
    // 	if (pRoot == nFirst && !bIsInFir){
    	if (pRoot == nFirst){
    		    bIsInFir = true;
    	}

    
    	if (bIsInFir && bIsInSec)
    	{
    		return true;
    	}
    	else
    	{
    		if(IsInclude(pRoot->left,nFirst,nSec,bIsInFir,bIsInSec))
    		{
    			return true;
    		}
    		else
    		{
    			return IsInclude(pRoot->right,nFirst,nSec,bIsInFir,bIsInSec);
    		}
    	}
    }

    /*判断结点是否同时包含A和B*/
    bool IsInclude(TreeNode* pRoot,TreeNode* nFirst,TreeNode* nSec){
    	bool bIsInFir = false;
    	bool bIsInSec = false;
    	return IsInclude(pRoot,nFirst,nSec,bIsInFir,bIsInSec);
    }

    TreeNode* lowestCommonAncestor_old(TreeNode* root, TreeNode* p, TreeNode* q) {
        // special cases
        if(root == NULL)
            return NULL;
        if(p == root || q == root)
            return root;
        if(p == q)
            return p;
            
        vector<TreeNode*> vp;
        vector<TreeNode*> vq;
        stack<TreeNode*> stk;
        unordered_map<TreeNode*, bool> m;   //visited
        stk.push(root);
        m[root] = true;
        while(!stk.empty())
        {
            TreeNode* top = stk.top();
            if(top->left && m[top->left] == false)
            {
                stk.push(top->left);
                m[top->left] = true;
                if(top->left == p)
                {
                    vp = stkTovec(stk);
                    if(!vq.empty())
                        break;
                }
                if(top->left == q)
                {
                    vq = stkTovec(stk);
                    if(!vp.empty())
                        break;
                }
                continue;
            }
            if(top->right && m[top->right] == false)
            {
                stk.push(top->right);
                m[top->right] = true;
                if(top->right == p)
                {
                    vp = stkTovec(stk);
                    if(!vq.empty())
                        break;
                }
                if(top->right == q)
                {
                    vq = stkTovec(stk);
                    if(!vp.empty())
                        break;
                }
                continue;
            }
            stk.pop();
        }
        int i = 0;
        for(; i < vp.size() && i < vq.size(); i ++)
        {
            if(vp[i] != vq[i])
                break;
        }
        return vp[i-1];
    }
    
    vector<TreeNode*> stkTovec(stack<TreeNode*> stk)
    {
        vector<TreeNode*> v;
        while(!stk.empty())
        {
            TreeNode* top = stk.top();
            stk.pop();
            v.push_back(top);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

