link::-->https://leetcode.com/problems/word-search/description/

Word-Search

code::-->
class Solution {
public:
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool search(vector<vector<char>>&board,string word,int index,int i,int j,int row ,int col,vector<vector<bool>>&visited){
if(i<0||i>=row||j<0||j>=col||visited[i][j]==true||word[index]!=board[i][j]){
    return false;
}
if(index==word.length()-1)return true;
if(index>=word.length())return false;
visited[i][j]=true;
for(int k=0;k<4;k++){
 int p=i+dx[k],q=j+dy[k];
 if(search(board,word,index+1,p,q,row,col,visited)){
     return true;
 }
}
visited[i][j]=false;
return false;

}
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){
                    if(search(board,word,0,i,j,row,col,visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};