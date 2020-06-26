/*
    求连通图数量，可以用深度优先搜索和广度优先搜索遍历，能遍历完一个就算是一个连通图
*/
class Solution {
public:
    vector<vector<char>> graph;
    int heng,zong;
    void dep(int x,int y){
        if(x>=heng || y>=zong || x<0 || y<0)
            return;
        if( graph[x][y] == '0' )
            return;
        graph[x][y] = '0' ;//标记为已经遍历过
        dep(x,y-1);//往水平向左方向探查
        dep(x,y+1);//往水平向右方向探查
        dep(x+1,y);//往竖直向下方向探查
        dep(x-1,y);//往竖直向上方向探查
    }
    int numIslands(vector<vector<char>>& grid) {
        graph = grid;
        heng = graph.size();
        if(heng != 0)
            zong = graph[0].size();
        int num = 0;
        for(int i = 0; i<heng;i++) {
            for(int j=0;j<zong;j++) {
                if( graph[i][j] == '0' )
                    continue;
                dep(i,j);
                num++;
            }
        }
        return num;
    }
};