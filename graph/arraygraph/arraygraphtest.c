#include "arraygraph.c"

// 그래프 내용을 출력하는 함수
void displayArrayGraph(ArrayGraph* pGraph) {
    if (pGraph == NULL) {
        printf("그래프가 존재하지 않습니다.\n");
        return;
    }
    
    printf("\n===== 그래프 정보 =====\n");
    printf("그래프 유형: %s\n", pGraph->graphType == UNDIRECTED ? "무방향" : "방향");
    printf("최대 정점 수: %d\n", pGraph->maxVertexCount);
    printf("현재 정점 수: %d\n", pGraph->currentVertexCount);
    
    printf("\n[정점 상태]\n");
    for (int i = 0; i < pGraph->maxVertexCount; i++) {
        if (pGraph->pVertex[i] == USED) {
            printf("정점 %d: 사용 중\n", i);
        }
    }
    
    printf("\n[인접 행렬]\n");
    printf("    ");
    for (int i = 0; i < pGraph->maxVertexCount; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < pGraph->maxVertexCount; i++) {
        if (pGraph->pVertex[i] == USED) {
            printf("%2d: ", i);
            for (int j = 0; j < pGraph->maxVertexCount; j++) {
                printf("%2d ", pGraph->ppAdjacentEdge[i][j]);
            }
            printf("\n");
        }
    }
    printf("=====================\n\n");
}

int arrayGraphMain() {
    ArrayGraph* undirectedGraph = NULL;
    ArrayGraph* directedGraph = NULL;
    int maxVertexCount = 6;
    
    // 1. 무방향 그래프 생성
    printf("1. 무방향 그래프 생성\n");
    undirectedGraph = createArrayGraph(maxVertexCount);
    if (undirectedGraph == NULL) {
        printf("무방향 그래프 생성 실패\n");
        return -1;
    }
    printf("무방향 그래프 생성 성공\n");
    
    // 2. 방향 그래프 생성
    printf("2. 방향 그래프 생성\n");
    directedGraph = createArrayDirectedGraph(maxVertexCount);
    if (directedGraph == NULL) {
        printf("방향 그래프 생성 실패\n");
        deleteArrayGraph(undirectedGraph);
        return -1;
    }
    printf("방향 그래프 생성 성공\n");
    
    // 3. 무방향 그래프에 정점 추가
    printf("3. 무방향 그래프에 정점 추가 (0~5)\n");
    for (int i = 0; i < maxVertexCount; i++) {
        if (addVertexAG(undirectedGraph, i)) {
            printf("정점 %d 추가 성공\n", i);
        } else {
            printf("정점 %d 추가 실패\n", i);
        }
    }
    
    // 4. 무방향 그래프에 간선 추가
    printf("\n4. 무방향 그래프에 간선 추가\n");
    addEdgeAG(undirectedGraph, 0, 1);
    addEdgeAG(undirectedGraph, 0, 2);
    addEdgeAG(undirectedGraph, 1, 2);
    addEdgeAG(undirectedGraph, 2, 3);
    addWeightEdgeAG(undirectedGraph, 3, 4, 10);
    addWeightEdgeAG(undirectedGraph, 3, 5, 5);
    
    // 5. 무방향 그래프 상태 출력
    displayArrayGraph(undirectedGraph);
    
    // 6. 방향 그래프에 정점 추가
    printf("6. 방향 그래프에 정점 추가 (0~5)\n");
    for (int i = 0; i < maxVertexCount; i++) {
        addVertexAG(directedGraph, i);
    }
    
    // 7. 방향 그래프에 간선 추가
    printf("\n7. 방향 그래프에 간선 추가\n");
    addEdgeAG(directedGraph, 0, 1);
    addEdgeAG(directedGraph, 1, 2);
    addEdgeAG(directedGraph, 2, 0);  // 사이클 형성
    addEdgeAG(directedGraph, 2, 3);
    addWeightEdgeAG(directedGraph, 3, 4, 8);
    addWeightEdgeAG(directedGraph, 4, 5, 7);
    
    // 8. 방향 그래프 상태 출력
    displayArrayGraph(directedGraph);
    
    // 9. 무방향 그래프에서 정점과 간선 제거 테스트
    printf("9. 무방향 그래프에서 정점 3 제거\n");
    if (removeVertexAG(undirectedGraph, 3)) {
        printf("정점 3 제거 성공\n");
    } else {
        printf("정점 3 제거 실패\n");
    }
    displayArrayGraph(undirectedGraph);
    
    // 10. 방향 그래프에서 간선 제거 테스트
    printf("10. 방향 그래프에서 간선 (2,3) 제거\n");
    if (removeEdgeAG(directedGraph, 2, 3)) {
        printf("간선 (2,3) 제거 성공\n");
    } else {
        printf("간선 (2,3) 제거 실패\n");
    }
    displayArrayGraph(directedGraph);
    
    // 11. 중복 정점 추가 테스트
    printf("11. 이미 있는 정점 0 중복 추가 테스트\n");
    if (addVertexAG(undirectedGraph, 0)) {
        printf("정점 0 추가 성공\n");
    } else {
        printf("정점 0 추가 실패 (이미 존재)\n");
    }
    
    // 12. 잘못된 정점 ID 테스트
    printf("12. 잘못된 정점 ID (-1) 테스트\n");
    if (addVertexAG(undirectedGraph, -1)) {
        printf("정점 -1 추가 성공\n");
    } else {
        printf("정점 -1 추가 실패 (유효하지 않은 ID)\n");
    }
    
    // 13. 모든 정점 제거 테스트
    printf("\n13. 무방향 그래프에서 모든 정점 제거\n");
    for (int i = 0; i < maxVertexCount; i++) {
        if (removeVertexAG(undirectedGraph, i)) {
            printf("정점 %d 제거 성공\n", i);
        }
    }
    displayArrayGraph(undirectedGraph);
    
    // 14. 그래프 비어있는지 확인
    printf("14. 무방향 그래프 비어있는지 확인: %s\n", 
           isArrayGraphEmpty(undirectedGraph) ? "비어있음" : "비어있지 않음");
    
    // 15. 메모리 해제
    printf("\n15. 그래프 메모리 해제\n");
    deleteArrayGraph(undirectedGraph);
    deleteArrayGraph(directedGraph);
    printf("그래프 메모리 해제 완료\n");
    
    return 0;
}