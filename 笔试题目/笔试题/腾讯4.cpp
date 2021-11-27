#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param root TreeNode类 指向量子树的根
     * @param b int整型vector<vector<>> 表示每次交换的两个子树
     * @return TreeNode类
     */
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<int, TreeNode*> umap;
    bool isValid(TreeNode* node1, TreeNode* node2) {
        if (node1 == node2)
            return false;

        TreeNode* p = parent[node1];
        while (p) {
            if (p == node2) {
                return false;
            }
            p = parent[p];
        }

        p = parent[node2];
        while (p) {
            if (p == node1) {
                return false;
            }
            p = parent[p];
        }

        return true;
    }
    TreeNode* solve(TreeNode* root, vector<vector<int> >& b) {
        // write code here
        if (root == NULL)
            return NULL;
        queue<TreeNode*> q;
        q.push(root);
        umap.insert({ root->val,root });
        parent[root] = NULL;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            if (curr->left) {
                umap.insert({ curr->left->val,curr->left });
                q.push(curr->left);
                //cout << curr->left << " ";
                parent[curr->left] = curr;
            }
            if (curr->right) {
                umap.insert({ curr->right->val,curr->right });
                q.push(curr->right);
                //cout << curr->right << endl;
                parent[curr->right] = curr;
            }
            q.pop();
        }
        for (vector<int>& vec : b) {
            int x = vec[0], y = vec[1];
            TreeNode* node1 = umap[x], * node2 = umap[y];
            if (isValid(node1, node2)) {
                TreeNode* p1 = parent[node1], * p2 = parent[node2];
                //交换
                if (p1->left==node1) {
                    if (p2->left == node2) {
                        p2->left = node1;
                    }
                    else {
                        p2->right = node1;
                    }
                    p1->left = node2;
                }
                else {
                    if (p2->left == node2) {
                        p2->left = node1;
                    }
                    else {
                        p2->right = node1;
                    }
                    p1->right = node2;
                }
                //记录
                parent[node1] = p2;
                parent[node2] = p1;
            }

        }
        return root;
    }
};
/**
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution_ {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param root TreeNode类 指向量子树的根
     * @param b int整型vector<vector<>> 表示每次交换的两个子树
     * @return TreeNode类
     */
    TreeNode* solve(TreeNode* root, vector<vector<int> >& b) {
        // write code here
        //找到两个节点对应的祖先,带1的直接跳过，否则必有祖先
        for (const auto& item : b) {
            if (item[0] == 1 || item[1] == 1) continue;
            TreeNode* lf, *rf;
            //左f右t
            bool ld, rd;
            TreeNode* l, * r;
            lf = findNode(root, item[0], ld);
            rf = findNode(root, item[1], rd);

            if (ld) l = lf->right;
            else l = lf->left;
            if (rd) r = rf->right;
            else r = rf->left;

            if (judgeF(l, r)) continue;

            if (ld) lf->right = r;
            else lf->left = r;
            if (rd) rf->right = l;
            else rf->left = l;
        }
        return root;
    }

    bool judgeF(TreeNode* l, TreeNode* r) {
        bool ret = false;
        ret |= dfs(l, r);
        ret |= dfs(r, l);
        return ret;
    }

    bool dfs(TreeNode* base, TreeNode* target) {
        if (target == nullptr || base == nullptr) return false;
        if (base == target) return true;
        return dfs(base->left, target) || dfs(base->right, target);
    }

    TreeNode* findNode(TreeNode* root, int val, bool& d) {
        if (root == nullptr) return nullptr;
        if (root->left == nullptr && root->right == nullptr) return nullptr;
        if (root->left != nullptr && root->left->val == val) {d = false; return root;}
        if (root->right != nullptr && root->right->val == val) {d = true; return root;}
        TreeNode* temp = nullptr;
        if (root->left != nullptr) temp = findNode(root->left, val, d);
        if (temp != nullptr) return temp;
        if (root->right != nullptr) temp = findNode(root->right, val, d);
        if (temp != nullptr) return temp;
        return temp;
    }
};
