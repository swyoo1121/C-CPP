#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node{ // 이진 탐색 트리의 노드 구조체
    int key;
    struct node *left, *right;
};

struct node *makeNode(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> key = data;
    ptr -> left = ptr -> right = NULL;
    return ptr;
} // 매개변수로 받은 data를 저장하는 노드 구조체를 만들어 반환하는 함수
// ptr 포인터는 node 크기만큼의 메모리를 동적으로 할당 받음
// key는 data, left와 right는 NULL로 초기화한 후 반환

struct node *insert(struct node *node, int data)
{
    if (node == NULL) makeNode(data);
    else if (node->key > data) return insert(node->left, data);
    else return insert(node->right, data);
    return node;
} 


struct node *minNode(struct node *node)
{
    struct node *cur = node;
    
    /*
        여기서 디버깅하면 Segfault 떠서 막혔습니다..
        의도는 insert를 통해 노드를 추가해주면서, 받아온 포인터가 null일 경우 노드가 없다는 뜻이므로 makeNode로 노드를 생성합니다.
        null이 아닐 경우 노드의 key 값과 입력받은 data 값을 비교해서 data가 작으면 왼쪽, 크면 오른쪽의 노드로 접근해서 다시 insert를 진행합니다.
        다 insert하면 inorder함수를 통해 순회를 시작하는데, 이때 minNode를 이용해서 제일 작은 값부터 탐색하도록 만들고 싶었습니다.
        여기서부터 막혔습니다.
    */
    if (cur->left == NULL) return cur;
    else return minNode(cur->left);
}

struct node* deleteNode(struct node* node, int data) // 이진탐색트리에서 data를 삭제하는 재귀함수
{
    if (node == NULL) // node가 NULL이라면 그대로 반환
        return node;
    if (data < node -> key) // 삭제할 data가 node -> key보다 작다면 왼쪽 자식 노드를 매개변수로 deleteNode 함수를 재귀호출
        node -> left = deleteNode(node -> left, data);
    else if (data > node -> key) // 삭제할 data가 node -> key보다 크면 오른쪽 자식 노드를 매개변수로 deleteNode 함수를 재귀호출
        node -> right = deleteNode(node -> right, data);
    else { // node가 삭제할 노드이며 노드의 삭제는 세 가지 경우가 존재
        // case (1), (2)
        if (node -> left == NULL)
        {
            // 코드 작성
        }
        else if (node -> right == NULL)
        {
            // 코드 작성
        }

        // case (3)
        struct node *tmp = minNode(node -> right);
        
        // 코드 작성
    }
    return node;
}

void inorder(struct node *node) // 이진 탐색 트리를 inorder 순회하는 재귀함수
{
    cout << minNode(node)->key << endl;
}

int main() // data[] 배열에 있는 값들을 insert
{
    struct node *root = NULL;
    int data[] = {10, 8, 6, 9, 7, 15, 12, 14}; // 입력 데이터
    int del; // 삭제 노드

    for (int i = 0; i < sizeof(data); i++) {
        insert(root, data[i]);
    }

    inorder(root); // inorder 함수를 호출하여 트리 내용을 출력

    while (1) // -1이 입력될 때까지 삭제할 노드를 입력받아 deleteNode를 수행하고 inorder로 출력
    {
        cout << "\n Enter node to delete(-1 to quit): ";
        cin >> del;

        if (del == -1) break;

        // 코드 작성
    }
}