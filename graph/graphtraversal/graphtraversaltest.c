#include "graphtraversal.c"
// 그래프 정보 출력 함수
void displayGraph(LinkedGraph* pGraph) {
    if(pGraph == NULL) return;
    
    printf("\n====== 그래프 구조 출력 ======\n");
    printf("최대 정점 수: %d, 현재 정점 수: %d\n", pGraph->maxVertexCount, pGraph->currentVertexCount);
    printf("그래프 유형: %s\n", pGraph->graphType == UNDIRECTED ? "무방향 그래프" : "방향 그래프");
    
    for(int i = 0; i < pGraph->maxVertexCount; i++) {
        if(pGraph->pVertex[i]) {
            printf("정점 [%d]의 인접 정점: ", i);
            LinkedListNode* pNode = pGraph->ppAdjacentEdge[i]->headerNode.pLink;
            while(pNode != NULL) {
                printf("%d(가중치:%d) ", pNode->data.vertexID, pNode->data.weight);
                pNode = pNode->pLink;
            }
            printf("\n");
        }
    }
    printf("==============================\n\n");
}

int graphTraversalMain() {
    // 무방향 그래프 생성 (정점 최대 6개)
    LinkedGraph* pGraph = createLinkedGraph(6);
    if(pGraph == NULL) {
        printf("그래프 생성 실패\n");
        return -1;
    }
    
    // 정점 추가
    for(int i = 0; i < 6; i++) {
        addVertexLG(pGraph, i);
    }
    
    // 간선 추가 (예제 그래프 구성)
    // 아래와 같은 그래프 구성:
    //      0 --- 1 --- 2
    //      |     |     |
    //      3 --- 4 --- 5
    
    addEdgeLG(pGraph, 0, 1);
    addEdgeLG(pGraph, 0, 3);
    addEdgeLG(pGraph, 1, 2);
    addEdgeLG(pGraph, 1, 4);
    addEdgeLG(pGraph, 2, 5);
    addEdgeLG(pGraph, 3, 4);
    addEdgeLG(pGraph, 4, 5);
    
    // 그래프 구조 출력
    displayGraph(pGraph);
    
    // DFS 테스트
    printf("\n===== DFS 탐색 결과 (시작 정점: 0) =====\n");
    traversalDFS(pGraph, 0);
    
    // BFS 테스트
    printf("\n===== BFS 탐색 결과 (시작 정점: 0) =====\n");
    traversalBFS(pGraph, 0);
    
    // 다른 시작점에서 테스트
    printf("\n===== DFS 탐색 결과 (시작 정점: 3) =====\n");
    traversalDFS(pGraph, 3);
    
    printf("\n===== BFS 탐색 결과 (시작 정점: 3) =====\n");
    traversalBFS(pGraph, 3);
    
    // 그래프 삭제
    deleteLinkedGraph(pGraph);
    
    // 방향 그래프 테스트
    printf("\n\n=== 방향 그래프 테스트 ===\n");
    LinkedGraph* pDirectedGraph = createLinkedDirectedGraph(6);
    if(pDirectedGraph == NULL) {
        printf("방향 그래프 생성 실패\n");
        return -1;
    }
    
    // 정점 추가
    for(int i = 0; i < 6; i++) {
        addVertexLG(pDirectedGraph, i);
    }
    
    // 간선 추가 (방향 그래프 구성)
    addEdgeLG(pDirectedGraph, 0, 1);
    addEdgeLG(pDirectedGraph, 1, 2);
    addEdgeLG(pDirectedGraph, 2, 0);  // 사이클 생성
    addEdgeLG(pDirectedGraph, 2, 3);
    addEdgeLG(pDirectedGraph, 3, 4);
    addEdgeLG(pDirectedGraph, 3, 5);
    addEdgeLG(pDirectedGraph, 5, 2);  // 사이클 생성
    
    // 방향 그래프 구조 출력
    displayGraph(pDirectedGraph);
    
    // 방향 그래프 DFS 테스트
    printf("\n===== 방향 그래프 DFS 탐색 결과 (시작 정점: 0) =====\n");
    traversalDFS(pDirectedGraph, 0);
    
    // 방향 그래프 BFS 테스트
    printf("\n===== 방향 그래프 BFS 탐색 결과 (시작 정점: 0) =====\n");
    traversalBFS(pDirectedGraph, 0);
    
    // 그래프 삭제
    deleteLinkedGraph(pDirectedGraph);
    
    return 0;
}