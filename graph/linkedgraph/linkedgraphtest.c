#include "linkedgraph.c"

// 그래프 출력 함수 (디버깅/테스트용)
void displayLinkedGraph(LinkedGraph* pGraph) {
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
    
    printf("\n[인접 리스트]\n");
    for (int i = 0; i < pGraph->maxVertexCount; i++) {
        if (pGraph->pVertex[i] == USED) {
            printf("정점 %d의 인접 정점:", i);
            
            LinkedList* adjacentList = pGraph->ppAdjacentEdge[i];
            if (adjacentList != NULL && adjacentList->currentElementCount > 0) {
                LinkedListNode* currentNode = adjacentList->headerNode.pLink;
                
                while (currentNode != NULL) {
                    printf(" %d(가중치:%d)", 
                           currentNode->data.vertexID, 
                           currentNode->data.weight);
                    currentNode = currentNode->pLink;
                    
                    if (currentNode != NULL) {
                        printf(",");
                    }
                }
            }
            printf("\n");
        }
    }
    printf("=====================\n\n");
}

// isEmptyLG 함수 구현 (코드에 없어서 추가)
bool _isEmptyLG(LinkedGraph* pGraph) {
    if (pGraph == NULL) return false;
    return pGraph->currentVertexCount == 0;
}

// deleteLinkedGraph 함수 구현 (코드에 없어서 추가)
void _deleteLinkedGraph(LinkedGraph* pGraph) {
    if (pGraph == NULL) return;
    
    for (int i = 0; i < pGraph->maxVertexCount; i++) {
        if (pGraph->ppAdjacentEdge[i] != NULL) {
            deleteLinkedList(pGraph->ppAdjacentEdge[i]);
        }
    }
    
    if (pGraph->ppAdjacentEdge != NULL) free(pGraph->ppAdjacentEdge);
    if (pGraph->pVertex != NULL) free(pGraph->pVertex);
    free(pGraph);
}

int linkedGraphMain() {
    LinkedGraph* undirectedGraph = NULL;
    LinkedGraph* directedGraph = NULL;
    int maxVertexCount = 6;
    bool result = false;
    
    // 1. 무방향 그래프 생성
    printf("1. 무방향 그래프 생성 (최대 정점 수: %d)\n", maxVertexCount);
    undirectedGraph = createLinkedGraph(maxVertexCount);
    if (undirectedGraph == NULL) {
        printf("무방향 그래프 생성 실패\n");
        return -1;
    }
    printf("무방향 그래프 생성 성공\n");
    
    // 2. 방향 그래프 생성
    printf("\n2. 방향 그래프 생성 (최대 정점 수: %d)\n", maxVertexCount);
    directedGraph = createLinkedDirectedGraph(maxVertexCount);
    if (directedGraph == NULL) {
        printf("방향 그래프 생성 실패\n");
        deleteLinkedGraph(undirectedGraph);
        return -1;
    }
    printf("방향 그래프 생성 성공\n");
    
    // 3. 무방향 그래프에 정점 추가
    printf("\n3. 무방향 그래프에 정점 추가 (0~5)\n");
    for (int i = 0; i < maxVertexCount; i++) {
        result = addVertexLG(undirectedGraph, i);
        if (result) {
            printf("정점 %d 추가 성공\n", i);
        } else {
            printf("정점 %d 추가 실패\n", i);
        }
    }
    
    // 4. 무방향 그래프에 간선 추가
    printf("\n4. 무방향 그래프에 간선 추가\n");
    result = addEdgeLG(undirectedGraph, 0, 1);
    printf("간선 추가 (0,1): %s\n", result ? "성공" : "실패");
    
    result = addEdgeLG(undirectedGraph, 0, 2);
    printf("간선 추가 (0,2): %s\n", result ? "성공" : "실패");
    
    result = addEdgeLG(undirectedGraph, 1, 2);
    printf("간선 추가 (1,2): %s\n", result ? "성공" : "실패");
    
    result = addEdgeLG(undirectedGraph, 2, 3);
    printf("간선 추가 (2,3): %s\n", result ? "성공" : "실패");
    
    result = addWeightEdgeLG(undirectedGraph, 3, 4, 10);
    printf("가중치 간선 추가 (3,4,10): %s\n", result ? "성공" : "실패");
    
    result = addWeightEdgeLG(undirectedGraph, 3, 5, 5);
    printf("가중치 간선 추가 (3,5,5): %s\n", result ? "성공" : "실패");
    
    // 5. 무방향 그래프 상태 출력
    printf("\n5. 무방향 그래프 상태 출력\n");
    displayLinkedGraph(undirectedGraph);
    
    // 6. 방향 그래프에 정점 추가
    printf("\n6. 방향 그래프에 정점 추가 (0~5)\n");
    for (int i = 0; i < maxVertexCount; i++) {
        result = addVertexLG(directedGraph, i);
        if (result) {
            printf("정점 %d 추가 성공\n", i);
        } else {
            printf("정점 %d 추가 실패\n", i);
        }
    }
    
    // 7. 방향 그래프에 간선 추가
    printf("\n7. 방향 그래프에 간선 추가\n");
    result = addEdgeLG(directedGraph, 0, 1);
    printf("간선 추가 (0,1): %s\n", result ? "성공" : "실패");
    
    result = addEdgeLG(directedGraph, 1, 2);
    printf("간선 추가 (1,2): %s\n", result ? "성공" : "실패");
    
    result = addEdgeLG(directedGraph, 2, 0);  // 사이클 형성
    printf("간선 추가 (2,0): %s\n", result ? "성공" : "실패");
    
    result = addEdgeLG(directedGraph, 2, 3);
    printf("간선 추가 (2,3): %s\n", result ? "성공" : "실패");
    
    result = addWeightEdgeLG(directedGraph, 3, 4, 8);
    printf("가중치 간선 추가 (3,4,8): %s\n", result ? "성공" : "실패");
    
    result = addWeightEdgeLG(directedGraph, 4, 5, 7);
    printf("가중치 간선 추가 (4,5,7): %s\n", result ? "성공" : "실패");
    
    // 8. 방향 그래프 상태 출력
    printf("\n8. 방향 그래프 상태 출력\n");
    displayLinkedGraph(directedGraph);
    
    // 9. 간선 제거 테스트 (무방향 그래프)
    printf("\n9. 무방향 그래프에서 간선 (0,2) 제거\n");
    result = removeEdgeLG(undirectedGraph, 0, 2);
    printf("간선 제거 (0,2): %s\n", result ? "성공" : "실패");
    displayLinkedGraph(undirectedGraph);
    
    // 10. 간선 제거 테스트 (방향 그래프)
    printf("\n10. 방향 그래프에서 간선 (2,3) 제거\n");
    result = removeEdgeLG(directedGraph, 2, 3);
    printf("간선 제거 (2,3): %s\n", result ? "성공" : "실패");
    displayLinkedGraph(directedGraph);
    
    // 11. 정점 제거 테스트 (무방향 그래프)
    printf("\n11. 무방향 그래프에서 정점 3 제거\n");
    result = removeVertexLG(undirectedGraph, 3);
    printf("정점 제거 (3): %s\n", result ? "성공" : "실패");
    displayLinkedGraph(undirectedGraph);
    
    // 12. 정점 제거 테스트 (방향 그래프)
    printf("\n12. 방향 그래프에서 정점 2 제거\n");
    result = removeVertexLG(directedGraph, 2);
    printf("정점 제거 (2): %s\n", result ? "성공" : "실패");
    displayLinkedGraph(directedGraph);
    
    // 13. 잘못된 정점/간선 관련 오류 테스트
    printf("\n13. 오류 테스트\n");
    
    // 13-1. 이미 존재하는 정점 추가
    result = addVertexLG(undirectedGraph, 0);
    printf("이미 존재하는 정점 추가 (0): %s\n", result ? "성공" : "실패(정상)");
    
    // 13-2. 범위 밖의 정점 ID 사용
    result = addVertexLG(undirectedGraph, maxVertexCount);
    printf("범위 밖의 정점 추가 (%d): %s\n", maxVertexCount, result ? "성공" : "실패(정상)");
    
    // 13-3. 존재하지 않는 정점 간의 간선 추가
    result = addEdgeLG(undirectedGraph, -1, 0);
    printf("잘못된 간선 추가 (-1,0): %s\n", result ? "성공" : "실패(정상)");
    
    // 13-4. 삭제된 정점에 연결된 간선 추가
    result = addEdgeLG(undirectedGraph, 1, 3);  // 정점 3은 이미 삭제됨
    printf("삭제된 정점에 간선 추가 (1,3): %s\n", result ? "성공" : "실패(정상)");
    
    // 14. 그래프가 비어있는지 확인
    printf("\n14. 그래프 비어있는지 확인\n");
    printf("무방향 그래프: %s\n", isEmptyLG(undirectedGraph) ? "비어있음" : "비어있지 않음");
    
    // 15. 모든 정점 제거 테스트
    printf("\n15. 무방향 그래프의 모든 정점 제거\n");
    for (int i = 0; i < maxVertexCount; i++) {
        if (undirectedGraph->pVertex[i] == USED) {
            removeVertexLG(undirectedGraph, i);
            printf("정점 %d 제거\n", i);
        }
    }
    displayLinkedGraph(undirectedGraph);
    printf("무방향 그래프: %s\n", isEmptyLG(undirectedGraph) ? "비어있음" : "비어있지 않음");
    
    // 16. 메모리 해제
    printf("\n16. 그래프 메모리 해제\n");
    deleteLinkedGraph(undirectedGraph);
    deleteLinkedGraph(directedGraph);
    printf("그래프 메모리 해제 완료\n");
    
    return 0;
}