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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();

            for(int i = 0;i<size;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp)
                {
                    ans+= to_string(temp->val) + ',';
                    q.push(temp->left);   // yes push even if nullptr
                    q.push(temp->right);   // yes push even if nullptr
                }
                else    // if encounter a nullptr, just push a canary in the ans
                {
                    ans+="#,";
                }
            }
            
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    
    TreeNode* deserialize(string data) {
        if(!data.size())
        {
            return nullptr;
        }

        vector<string> tokens;
        string temp = "";
        for(char c: data)
        {
            if(c==',')
            {
                tokens.push_back(temp);
                temp = "";
            }
            else
            {
                temp += c;
            }
        }
        if(tokens[0]=="#")
        return nullptr;
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(tokens[0]));

        q.push(root);
        int i = 1;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(tokens[i]!="#")
            {
                curr->left = new TreeNode(stoi(tokens[i]));
                q.push(curr->left);
            }
            i++;
            if(tokens[i]!="#")
            {
                curr->right = new TreeNode(stoi(tokens[i]));
                q.push(curr->right);
            }
            i++;
        }

        return root;
    }
};
