/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    vector<TreeNode*> v;
    void find_first_num(ListNode* head, TreeNode* root)
    {
        if(root->val == head->val)
            v.push_back(root);

        if(root->left)
            find_first_num(head, root->left);

        if(root->right)
            find_first_num(head, root->right);
    }

    bool is_path(ListNode* head, TreeNode* root)
    {
        if(!head)
            return true;
        if(!root || head->val != root->val)
            return false;

        return is_path(head->next, root->left) || is_path(head->next, root->right); 
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        find_first_num(head, root);
        bool res = false;
        for(int i = 0; i < v.size(); i++)
        {
            res = is_path(head, v[i]);
            if(res)
                break;
        }
        return res;
    }
};