/*
 * 请实现两个函数，分别用来序列化和反序列化二叉树。
 * 这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
 */

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        string ans = "[";
        string sep;
        serialize(root, ans, sep);
        ans += "]";
        return ans;
    }

    TreeNode* deserialize(string data) {
        int n = data.length();
        if (n == 0 || data[0] != '[' || data[n - 1] != ']')
            return nullptr;
        int i = 1;
        stack<TreeNode *> s;
        TreeNode *ans;
        bool left = true;
        while (i < n - 1) {
            string num;
            while (i < n - 1 && data[i] != ',') {
                num += data[i];
                i++;
            }
            i++;
            TreeNode *node = num == "null" ?  nullptr : new TreeNode(stoi(num));
            if (s.empty()) {
                s.push(node);
                ans = node;
            } else {
                if (node) {
                    TreeNode *top = s.top();
                    if (left)
                        top->left = node;
                    else {
                        top->right = node;
                        left = true;
                    }
                    s.push(node);
                } else {
                    if (left) {
                        left = false;
                    } else {
                        s.pop();
                        while (!s.empty() && s.top()->right)
                            s.pop();
                    }
                }
            }
        }

        return ans;
    }

private:
    void serialize(TreeNode *root, string& str, string sep) {
        if (root == nullptr) {
            str += sep + "null";
        } else {
            str += sep + to_string(root->val);
            sep = ",";
            serialize(root->left, str, sep);
            serialize(root->right, str, sep);
        }
    }
};

void print(TreeNode *root, string sep)
{
    if (root) {
        cout << sep << root->val;
        print(root->left, ",");
        print(root->right, ",");
    } else {
        cout << sep << "null";;
    }
}

int main()
{
    TreeNode nodes[5] = { 1, 2, 3, 4, 5 };
    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];
    nodes[2].left = &nodes[3];
    nodes[2].right = &nodes[4];

    cout << Codec().serialize(&nodes[0]) << endl;
    // [1,2,null,null,3,4,null,null,5,null,null]

    TreeNode *root = Codec().deserialize("[1,2,null,null,3,4,null,null,5,null,null]");
    cout << "[";
    print(root, "");
    cout << "]" << endl;

    // ---------------------------------------

    TreeNode nodes2[5] = { 1, 2, 3, 4, 5 };
    nodes2[0].left = &nodes2[1];
    nodes2[0].right = &nodes2[2];
    nodes2[1].left = &nodes2[3];
    nodes2[1].right = &nodes2[4];

    cout << Codec().serialize(&nodes2[0]) << endl;
    // [1,2,4,null,null,5,null,null,3,null,null]

    TreeNode *root2 = Codec().deserialize("[1,2,4,null,null,5,null,null,3,null,null]");
    cout << "[";
    print(root2, "");
    cout << "]" << endl;
}
