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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
   
        vector<int> Postorder;

        if (root == NULL)
            return Postorder;

        stack<TreeNode *> st;
        TreeNode *curr = root;
        TreeNode *temp = NULL;

        while (curr != NULL || !st.empty()){

            if (curr != NULL) {
                st.push(curr);             
                curr = curr->left;
            }
            else{
                temp = st.top()->right;

                if (temp == NULL){
                    temp = st.top();
                    st.pop();
                    Postorder.push_back(temp->val);

                    while (!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        Postorder.push_back(temp->val);
                    }
                }
                else{
                    curr = temp;   
                }
            }
        }

        return Postorder;   
    }
};