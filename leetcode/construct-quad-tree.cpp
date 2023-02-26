// https://leetcode.com/problems/construct-quad-tree/

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    Node* help(int x1, int y1, int l, vector<vector<int>>& grid) {
        
        if (l <= 0) return NULL;

        Node* r = new Node();

        int sum = 0;

        for (int i = x1; i < x1+l; i++) {
            for (int j = y1; j < y1+l; j++) {   
                sum += grid[i][j];
            }
        }
        
        if (sum == 0) {
            r->val = 0;
            r->isLeaf = true;
            return r;
        } else if (sum == l*l) {
            r->val = 1;
            r->isLeaf = true;
            return r;
        } else {
            r->val = 1;
            r->isLeaf = false;
            r->topLeft = help(x1, y1, l/2, grid);
            r->topRight = help(x1, y1 + l/2, l/2, grid);
            r->bottomLeft = help(x1 + l/2, y1, l/2, grid);
            r->bottomRight = help(x1 + l/2, y1 + l/2, l/2, grid);
            return r;
        }
    }

    Node* construct(vector<vector<int>>& grid) {
        
        int n = grid.size();

        return help(0, 0, n, grid);

    }
};