#include "graphmst.c"

// 그래프와 MST 출력 함수
void printGraph(LinkedGraph* pGraph, const char* title){
    if(pGraph == NULL) return;
    
    printf("\n=== %s ===\n", title);
    printf("정점 개수: %d\n", pGraph->currentVertexCount);
    
    for(int i = 0; i < pGraph->maxVertexCount; i++){
        if(pGraph->pVertex[i]){
            printf("정점 %d: ", i);
            LinkedListNode* pNode = pGraph->ppAdjacentEdge[i]->headerNode.pLink;
            while(pNode != NULL){
                printf("-> %d(가중치:%d) ", pNode->data.vertexID, pNode->data.weight);
                pNode = pNode->pLink;
            }
            printf("\n");
        }
    }
}

// MST의 총 가중치 계산
int calculateMSTWeight(LinkedGraph* pMST){
    if(pMST == NULL) return 0;
    
    int totalWeight = 0;
    for(int i = 0; i < pMST->maxVertexCount; i++){
        if(pMST->pVertex[i]){
            LinkedListNode* pNode = pMST->ppAdjacentEdge[i]->headerNode.pLink;
            while(pNode != NULL){
                if(i < pNode->data.vertexID){  // 중복 계산 방지
                    totalWeight += pNode->data.weight;
                }
                pNode = pNode->pLink;
            }
        }
    }
    return totalWeight;
}

// 테스트 케이스 1: 기본 연결 그래프
void testCase1(){
    printf("\n========== 테스트 케이스 1: 기본 연결 그래프 ==========\n");
    
    LinkedGraph* pGraph = createLinkedGraph(5);
    
    // 정점 추가
    for(int i = 0; i < 5; i++){
        addVertexLG(pGraph, i);
    }
    
    // 간선 추가 (가중치 포함)
    addWeightEdgeLG(pGraph, 0, 1, 2);
    addWeightEdgeLG(pGraph, 0, 3, 6);
    addWeightEdgeLG(pGraph, 1, 2, 3);
    addWeightEdgeLG(pGraph, 1, 3, 8);
    addWeightEdgeLG(pGraph, 1, 4, 5);
    addWeightEdgeLG(pGraph, 2, 4, 7);
    addWeightEdgeLG(pGraph, 3, 4, 9);
    
    printGraph(pGraph, "원본 그래프");
    
    LinkedGraph* pMST = mstKruskal(pGraph);
    if(pMST != NULL){
        printGraph(pMST, "최소 신장 트리");
        printf("MST 총 가중치: %d\n", calculateMSTWeight(pMST));
        printf("예상 가중치: 16 (0-1:2, 1-2:3, 1-4:5, 0-3:6)\n");
        deleteLinkedGraph(pMST);
    } else {
        printf("MST 생성 실패!\n");
    }
    
    deleteLinkedGraph(pGraph);
}

// 테스트 케이스 2: 연결되지 않은 그래프
void testCase2(){
    printf("\n========== 테스트 케이스 2: 연결되지 않은 그래프 ==========\n");
    
    LinkedGraph* pGraph = createLinkedGraph(4);
    
    // 정점 추가
    for(int i = 0; i < 4; i++){
        addVertexLG(pGraph, i);
    }
    
    // 연결되지 않은 두 컴포넌트
    addWeightEdgeLG(pGraph, 0, 1, 1);
    addWeightEdgeLG(pGraph, 2, 3, 2);
    
    printGraph(pGraph, "연결되지 않은 그래프");
    
    LinkedGraph* pMST = mstKruskal(pGraph);
    if(pMST != NULL){
        printGraph(pMST, "최소 신장 트리");
        deleteLinkedGraph(pMST);
    } else {
        printf("MST 생성 실패! (예상된 결과 - 그래프가 연결되지 않음)\n");
    }
    
    deleteLinkedGraph(pGraph);
}

// 테스트 케이스 3: 단일 정점
void testCase3(){
    printf("\n========== 테스트 케이스 3: 단일 정점 ==========\n");
    
    LinkedGraph* pGraph = createLinkedGraph(1);
    addVertexLG(pGraph, 0);
    
    printGraph(pGraph, "단일 정점 그래프");
    
    LinkedGraph* pMST = mstKruskal(pGraph);
    if(pMST != NULL){
        printGraph(pMST, "최소 신장 트리");
        printf("MST 총 가중치: %d\n", calculateMSTWeight(pMST));
        deleteLinkedGraph(pMST);
    } else {
        printf("MST 생성 실패!\n");
    }
    
    deleteLinkedGraph(pGraph);
}

// 테스트 케이스 4: 복잡한 그래프
void testCase4(){
    printf("\n========== 테스트 케이스 4: 복잡한 그래프 ==========\n");
    
    LinkedGraph* pGraph = createLinkedGraph(6);
    
    // 정점 추가
    for(int i = 0; i < 6; i++){
        addVertexLG(pGraph, i);
    }
    
    // 복잡한 간선 구조
    addWeightEdgeLG(pGraph, 0, 1, 4);
    addWeightEdgeLG(pGraph, 0, 2, 4);
    addWeightEdgeLG(pGraph, 1, 2, 2);
    addWeightEdgeLG(pGraph, 1, 0, 4);
    addWeightEdgeLG(pGraph, 2, 0, 4);
    addWeightEdgeLG(pGraph, 2, 1, 2);
    addWeightEdgeLG(pGraph, 2, 3, 3);
    addWeightEdgeLG(pGraph, 2, 5, 2);
    addWeightEdgeLG(pGraph, 2, 4, 4);
    addWeightEdgeLG(pGraph, 3, 2, 3);
    addWeightEdgeLG(pGraph, 3, 4, 3);
    addWeightEdgeLG(pGraph, 4, 2, 4);
    addWeightEdgeLG(pGraph, 4, 3, 3);
    addWeightEdgeLG(pGraph, 5, 2, 2);
    addWeightEdgeLG(pGraph, 5, 4, 3);
    
    printGraph(pGraph, "복잡한 그래프");
    
    LinkedGraph* pMST = mstKruskal(pGraph);
    if(pMST != NULL){
        printGraph(pMST, "최소 신장 트리");
        printf("MST 총 가중치: %d\n", calculateMSTWeight(pMST));
        deleteLinkedGraph(pMST);
    } else {
        printf("MST 생성 실패!\n");
    }
    
    deleteLinkedGraph(pGraph);
}

// Union-Find 테스트
void testUnionFind(){
    printf("\n========== Union-Find 테스트 ==========\n");
    
    UnionFind* pUF = createUnionFind(5);
    
    printf("초기 상태 - 각 원소의 루트:\n");
    for(int i = 0; i < 5; i++){
        printf("find(%d) = %d\n", i, findUF(pUF, i));
    }
    
    printf("\nUnion 연산 수행:\n");
    printf("union(0, 1): %s\n", unionUF(pUF, 0, 1) ? "성공" : "실패");
    printf("union(2, 3): %s\n", unionUF(pUF, 2, 3) ? "성공" : "실패");
    printf("union(0, 2): %s\n", unionUF(pUF, 0, 2) ? "성공" : "실패");
    
    printf("\nUnion 후 각 원소의 루트:\n");
    for(int i = 0; i < 5; i++){
        printf("find(%d) = %d\n", i, findUF(pUF, i));
    }
    
    printf("\n사이클 검사:\n");
    printf("checkCycle(0, 1): %s\n", checkCycle(pUF, 0, 1) ? "사이클 있음" : "사이클 없음");
    printf("checkCycle(0, 4): %s\n", checkCycle(pUF, 0, 4) ? "사이클 있음" : "사이클 없음");
    
    deleteUnionFind(pUF);
}

int graphMSTMain(){
    printf("크루스칼 알고리즘 테스트 시작\n");
    
    testUnionFind();
    testCase1();
    testCase2();
    testCase3();
    testCase4();
    
    printf("\n모든 테스트 완료!\n");
    return 0;
}