// 静态数组：表示顶点i的颜色
int color[2010]={0};
vector<int> graph[2010];

class Solution {
private:
    bool dfs(int u,int c)
    {
        color[u]=c;// 顶点u进行染色

        for(int j:graph[u])// 对u的邻节点进行染色
        {
            if(!color[j])// 邻节点j没有进行染色，则染相反的色
            {
                // j 号点的邻节点存在奇数环，则返回false
                if(!dfs(j,3-c))return false;
            }   
            // 若j号点已经染色，而且色和u相同，则匹配失败
            else if(color[j]==c)return false;
        }
        // 所有点都染色过了，返回true
        return true;
    }
public:
    // 题解：建图，然后转换为二分图匹配
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        // 全局变量在lc中要初始化一次
        memset(color,0,sizeof color);
        for(int i=1;i<=N;++i)graph[i]=vector<int> ();
    
        // 由于同组的相互不喜欢，那么他们连在一起时，把他们分成不同组就好了
        // 建立无向图的邻接表
        for(auto& d:dislikes)
        {
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }

        // 剩下的代码完全雷同 785. 判断二分图了
        for(int i=1;i<=N;++i)
        {
            // 若i 号点没有进行染色，则进行染色
            if(!color[i])
            {
                // i 号点染色失败，则返回false
                if(!dfs(i,1))return false;
            }
        }
        return true;
    }
};