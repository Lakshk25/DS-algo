
class Solution{
public:
    void solve(Node *root, int l, int h , int& count){
        if(root == NULL)
            return;
        
        // if in range(l <= root <= h) count++
        if(root -> data >= l && root -> data <= h)
            count++;
        
        solve(root -> left , l , h , count);
        solve(root -> right , l , h , count);
    }
    int getCount(Node *root, int l, int h)
    {
        int count = 0;
        solve(root , l , h , count);
        return count;
    }
};