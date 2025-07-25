/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int sum=0;
    pair<int,int> recursion(Node* root){
        if(!root){
            return {0,0};
        }
        auto left=recursion(root->left);
        auto right=recursion(root->right);
        if(left.first>right.first){
            return {left.first+1,left.second+root->data};
        }
        else if(left.first<right.first){
            return {right.first+1,right.second+root->data};
        }
        else{
            return {left.first+1,max(left.second,right.second)+root->data};
        }
        
    }
    int sumOfLongRootToLeafPath(Node *root) {
        auto ans=recursion(root);
        return ans.second;
    }
};