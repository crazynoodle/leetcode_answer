//WORD SERACH
/*
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 *
 * For example,
 * Given board =
 * 
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 * 
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 *
 
 struct node{
  int x;
  int y;
  node(int a,int b):x(a),y(b){}
  node(){}
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
         int n = board.size();
         int m = board[0].size();
         vector<vector<bool>> flag;
         vector<bool> inflag(m,0);
         int tem = n;
         while(tem--){
            flag.push_back(inflag);
         }

        //以word第一个字符，在board寻找匹配的位置；
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(board[i][j] == word[0])
                    if(helper(board,flag,0,word,node(i,j)))
                        return true;
                
        return false;
    }
    
    bool helper(vector<vector<char>>& board,vector<vector<bool>>& flag,int index,string& word,node pos)
    {
        if(pos.x < 0 || pos.y < 0 || pos.x > flag.size()-1 || pos.y > flag[0].size()-1)
            return false;
        bool exit = false;
        node next(0,0);
        if(word[index] == board[pos.x][pos.y] && !flag[pos.x][pos.y]){
            if(index == word.size()-1)
                return true;
            flag[pos.x][pos.y] = true;
            //往下探测
            next.x = pos.x-1;
            next.y = pos.y;
            if(!exit && helper(board,flag,index+1,word,next))
                exit = true;
            //向右探测
            next.x = pos.x;
            next.y = pos.y+1;
            if(!exit && helper(board,flag,index+1,word,next))
                exit = true;
            //向上探测
            next.x = pos.x+1;
            next.y = pos.y;
            if(!exit && helper(board,flag,index+1,word,next))
                exit = true;
            //向左探测
            next.x = pos.x;
            next.y = pos.y-1;
            if(!exit && helper(board,flag,index+1,word,next))
                exit = true;
                
            if(!exit)
                flag[pos.x][pos.y] = false;
            
            return exit;
        }else return exit;
    }
};
