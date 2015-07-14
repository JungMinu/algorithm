#include <iostream>
#include <string>
  
using namespace std;
  
class Node
{
public:
    string data; // 데이터 필드
    Node* NextLink; // 다음 노드를 가리키는 포인터
    Node* PrevLink; // 이전 노드를 가리키는 포인터
};
  
class CDLL
{
public:
    Node* Head; // 리스트의 머리 부분, 처음 부분
  
    CDLL()
    {
        Head = NULL; // 헤드(Head)의 초기화
    }
  
    void appendNode(string data)
    {
        Node* newNode = new Node(); // 새로운 노드를 생성한다.
  
        newNode->data = data; // 이 노드의 데이터에 집어넣으려는 데이터로 초기화 시킨다.
        newNode->NextLink = NULL; // 다음 노드를 이어주는 링크를 NULL로 초기화 시킨다.
        newNode->PrevLink = NULL; // 이전 노드를 이어주는 링크를 NULL로 초기화 시킨다.
  
        if (Head != NULL) { // 노드를 처음 추가하는 것이 아니라면
            Node* Tail = Head->PrevLink; // Tail이 헤드의 이전 노드를 가리키게 한다
 
            Tail->NextLink->PrevLink = newNode; // 꼬리 노드의 다음 노드, 즉 헤드 노드의 이전 노드는 새로운 노드
            Tail->NextLink = newNode; // 꼬리 노드의 다음을 가리키는 노드를 새로 추가되는 노드로 지정
            newNode->NextLink = Head; // 새로 추가되는 노드의 다음 노드는 헤드를 가리키도록 지정
            newNode->PrevLink = Tail; // 새로 추가되는 노드의 이전 노드는 현재 꼬리 노드로 지정
        }
        else { // 노드를 처음 추가하는 것이라면
            Head = newNode; // 새로 추가되는 노드를 헤드로 지정한다
            Head->NextLink = Head; // 헤드의 다음 노드를 헤드로 지정한다. 자신이 첫 노드이자 마지막 노드.
            Head->PrevLink = Head; // 헤드의 이전 노드를 헤드로 지정한다. 자신이 첫 노드이자 마지막 노드.
        }
    }
  
    void deleteNode(string data)
    {
        Node* pNode = Head; // 임시 포인터에 헤드의 주소 값으로 초기화 한다
  
        if (pNode == NULL) return; // 한번도 추가하지 않았다면 그냥 빠져나온다
        else { // 노드가 하나만 존재하는 것이 아니라면
            do {
                // data와 pNode->data와 비교하여 일치하면 반복문을 빠져 나온다
                if (data.compare(pNode->data) == 0) break;
                pNode = pNode->NextLink; // 임시 노드에 다음 노드의 주소값을 대입한다.
            } while (pNode != Head); // 임시 포인터의 주소 값이 헤드의 주소 값이 될때까지 반복
 
            if (pNode == Head) { // 삭제하려는 노드가 헤드 노드이면
                Head->PrevLink->NextLink = pNode->NextLink; // 꼬리 노드가 가리키는 다음 노드를 삭제하려는 노드의 다음 노드로 지정
                Head->NextLink->PrevLink = pNode->PrevLink; // 헤드 노드 다음에 위치하는 노드의 이전 노드를 삭제하려는 노드의 이전 노드로 지정
 
                Head = pNode->NextLink; // 삭제하려는 노드의 다음 노드를 헤드 노드로 지정
 
                pNode->PrevLink = NULL; // pNode의 PrevLink를 NULL로 지정
                pNode->NextLink = NULL; // pNode의 NextLink를 NULL로 지정
            }
            else {
                Node* Temp = pNode; // 임시 노드를 만들고 임시 노드에 삭제하려는 노드 지정
 
                pNode->PrevLink->NextLink = Temp->NextLink; // 삭제하려는 노드의 이전 노드의 다음 노드를 삭제하려는 노드의 다음 노드로 지정
                pNode->NextLink->PrevLink = Temp->PrevLink; // 삭제하려는 노드의 다음 노드의 이전 노드를 삭제하려는 노드의 이전 노드로 지정
 
                pNode->PrevLink = NULL; // pNode의 PrevLink를 NULL로 지정
                pNode->NextLink = NULL; // pNode의 NextLink를 NULL로 지정
            }
        }
    }
  
    void printNode() {
        Node* tempPoint = Head; // 임시 포인터를 생성하고 이 포인터에 헤드의 주소 값을 대입
         
        // 노드가 하나도 존재하지 않으면 함수를 빠져나옴
        if (tempPoint->NextLink == NULL) { cout << "리스트가 비어 있습니다." << endl; return; }
        // 노드가 하나만 존재할 경우
        if (tempPoint->NextLink == Head) { cout << tempPoint->data << "[" << tempPoint << "-" << tempPoint->NextLink << "]" << endl; }
        // 노드가 하나가 아닌 하나 이상 존재할 경우
        else {
            while (tempPoint->NextLink != Head) // 임시 노드의 다음 노드가 헤드 노드가 될때까지 반복
            {
                cout << tempPoint->data << "[" << tempPoint << "-" << tempPoint->NextLink << "] <->"; // 임시 노드의 주소 값과 다음 노드의 주소 값 그리고 데이터를 출력
                tempPoint = tempPoint->NextLink; // 임시 노드의 다음 노드를 가리키게 함
            }
  
            cout << tempPoint->data << "[" << tempPoint << "-" << tempPoint->NextLink << "] " << endl; // 꼬리 노드의 주소 값과 다음 노드의 주소 값 그리고 데이터를 출력
        }
    }
};
  
int main()
{
    CDLL List;
  
    List.appendNode("빨강");
    List.appendNode("주황");
    List.appendNode("노랑");
    List.printNode();
  
    List.deleteNode("노랑");
    List.deleteNode("주황");
    List.printNode();
    List.deleteNode("빨강");
    List.printNode();
  
    return 0;
}
