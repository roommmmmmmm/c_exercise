#include <cstdio>
#include <cstring>
#define MAXN 100
// 邻接表

struct ArcNode{ // 边结点
    int adjvex; // 有向边的另一个邻接点
    ArcNode *nextarc; // 指向下一个边节点
};

struct VNode{ // 顶点
    int data; // 顶点信息
    ArcNode *head1; // 出边表表头指针
    ArcNode *head2; // 入边表表头指针
};

struct LGraph{ // 邻接表存储结构
    VNode vertexs[MAXN]; // 顶点数组
    int vexnum,arcnum; // 顶点数和边数
};

LGraph lg; // 图的邻接表存储
// 采用邻接表存储表示，构造有向图
void CreateLG() {
    int i = 0;
    ArcNode *pi;
    int v1,v2; // 有向边的两个顶点
    for (i = 0;i < lg.vexnum;i++)
        lg.vertexs[i].head1 = lg.vertexs[i].head2 = NULL;
    for(i = 0; i < lg.arcnum;i++){
        scanf("%d%d",&v1,&v2);
        v1--;v2--;
        pi = new ArcNode; // 假定有足够的空间
        pi->adjvex = v2;
        pi->nextarc = lg.vertexs[v1].head1; // 插入链表
        lg.vertexs[v1].head1 = pi;
        pi = new ArcNode;
        pi->adjvex = v1;
        pi->nextarc = lg.vertexs[v2].head2;
        lg.vertexs[v2].head2 = pi;
    }
}
// 释放图的邻接表各顶点的边链表中的所有边界点所占的存储空间
void DeleteLG(){
    int i;
    ArcNode *pi;
    for(i = 0;i<lg.vexnum;i++){
        pi = lg.vertexs[i].head1;
        // 释放第i个节点出边表各边结点所占的存储空间
        while (pi != NULL) {
            lg.vertexs[i].head1 = pi->nextarc;
            delete pi;
            pi = lg.vertexs[i].head1;
        }
        pi = lg.vertexs[i].head2;
        // 释放第i个节点入边表各边结点所占的存储空间
        while (pi != NULL) {
            lg.vertexs[i].head2 = pi->nextarc;
            delete pi;
            pi = lg.vertexs[i].head2;
        }
    }
}
int main(int argc, char const *argv[]) {
    int i;
    int ind,od; // 入度和出度
    ArcNode *pi; // 遍历边链表的节点指针
    while (1) {
        lg.vexnum = lg.arcnum = 0;
        scanf("%d%d", &lg.vexnum,&lg.arcnum );
        if (lg.vexnum == 0) break;
        CreateLG();
        for ( i = 0; i < lg.vexnum; i++) {
            od = 0;
            pi = lg.vertexs[i].head1;
            while (pi != NULL) {
                od++;
                pi->nextarc;
            }
            if (i == 0 ) printf("%d ", od);
            else printf("%d ",od );
        }
        printf("\n");
        for ( i = 0; i < lg.vexnum; i++) {
            ind = 0;
            pi = lg.vertexs[i].head2;
            while (pi != NULL) {
                ind++;
                pi = pi->nextarc;
            }
            if ( i == 0) printf("%d",ind);
            else printf("%d",ind );
        }
        printf("\n");
        DeleteLG();
    }
    return 0;
}
