#include <cstdio>
#include <cstring>
#define MAXN 100

int Edge[MAXN][MAXN]; // 邻接矩阵
// 题目描述
// 输入文件中包含多个测试数据，每个测试数据描述了一个无权有向图。每个测试数据的第一行为两个正整数 n 和 m， 1 ≤ n ≤ 100， 1 ≤ m ≤ 500，分别表示该有向图的顶点数目和边数，顶点的序号从 1 开始计起。接下来有 m 行，每行为两个正整数，用空格隔开，分别表示一条边的起点和终点。每条边出现一次且仅一次，图中不存在自身环和重边。输入文件最后一行为 0 0，表示输入数据结束。
// 输出描述：
// 对输入文件中的每个有向图，输出两行：第 1 行为 n 个正整数，表示每个顶点的出度；第 2行也为 n 个正整数，表示每个顶点的入度。每两个正整数之间用一个空格隔开，每行的最后一个正整数之后没有空格。
int main(int argc, char const *argv[]) {
    int i,j; // 循环变量
    int n,m; // 顶点和边数
    int u,v; // 边的起点和终点
    int od,ind; // 顶点的出度和入度
    while (1) {
        scanf("%d%d",&n,&m);
        if(n == 0 && m == 0) break;
        memset(Edge,0,sizeof(Edge)); // 初始化
        for ( i = 0; i < m; i++) {
            scanf("%d%d",&u,&v);
            Edge[u-1][v-1]=1; // 构建
        }
        for( i = 0; i < n;i++){
            od = 0; // 出度
            for(j = 0; j < n; j++){
                od += Edge[i][j];
            }
            if(i == 0) printf("%d ",od );
            else printf("%d ",od );
        }
        printf("\n");
        for( i = 0; i < n;i++){
            ind = 0; // 入度
            for(j = 0; j < n; j++){
                ind += Edge[j][i];
            }
            if(i == 0) printf("%d ",ind );
            else printf("%d ",ind );
        }
        printf("\n");
        // 打印邻接矩阵
        // for(i = 0;i<n;i++){
        //     for(j = 0;j < n ;j++){
        //         printf("%d ", Edge[i][j]);
        //     }
        //     printf("\n");
        // }
    }
    return 0;
}
