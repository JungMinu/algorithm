#include <iostream>
using namespace std;
 
typedef struct Node {
    int data; // 데이터 필드
    struct Node* nextNode; // 다음 노드를 가리키는 주소값
} Node;
 
class LinkedQueue {
private:
    int size; // 큐의 크기
    Node* front; // 전단의 주소값
    Node* rear; // 후단의 주소값
public:
    LinkedQueue()
    {
        size = 0; // 크기를 0으로 초기화 한다
        front = NULL; // 전단의 주소값을 NULL로 초기화 한다
        rear = NULL; // 후단의 주소값을 NULL로 초기화 한다
    }
    ~LinkedQueue()
    {
        while(!isEmpty()) // 큐가 비어있지 않을때까지
        {
            Node* deq = dequeue(); // 전단에 존재하는 노드를 제거한다
            delete deq; // 메모리 공간에서 deq를 해제한다
        }
    }
    void enqueue(int data)
    {
        Node* newNode = new Node(); // 새로 노드를 추가한다
        newNode->data = data; // 새로 추가된 노드의 데이터에 매개변수로 받은 데이터의 값을 대입한다
        newNode->nextNode = NULL; // 다음 노드를 NULL로 초기화 한다
 
        if (front == NULL) // 전단의 주소값이 NULL 이라면, 즉 처음 추가하는 것이라면
        {
            front = newNode; rear = newNode; // 전단의 주소값과 후단의 주소값은 새로 추가된 노드의 주소값
        } else {
            rear->nextNode = newNode; // 후단의 다음 노드를 새로 추가된 노드로 지정한다
            rear = newNode; // 새로 추가된 노드를 후단으로 지정한다
        }
 
        size++; // 크기를 1 증가시킨다
    }
    Node* dequeue()
    {
        Node* temp = front; // 전단의 주소값을 temp에 대입한다
 
        if (front->nextNode == NULL)  // 전단의 다음 노드가 NULL 인것은 노드가 하나뿐이다
        {
            rear = NULL; front = NULL; // 전단과 후단의 주소값을 NULL로 초기화한다
        } else // 전단의 다음 노드가 존재한다면, 즉 노드가 두개 이상이라면
            front = front->nextNode; // 전단의 다음 노드를 전단으로 지정한다
 
        size--; // 크기를 1 감소시킨다
        return temp; // 큐에서 제거된 전단의 주소값을 반환한다
    }
    // 큐가 비어있는지 확인을 한다
    bool isEmpty() { return front == NULL; } // 전단의 주소값이 NULL이라면, 즉 큐가 비어있다면 true 아닐 경우 false
    int getSize() { return size; } // 큐의 크기를 가져온다
};
 
int main()
{
    LinkedQueue lq;
    int size;
 
    // 데이터의 삽입과 제거
    lq.enqueue(50);
    lq.enqueue(60);
    lq.dequeue();
    lq.enqueue(80);
    lq.enqueue(90);
    lq.dequeue();
    lq.enqueue(89);
 
    // 큐의 크기를 가져온다
    size = lq.getSize();
    for(int i = 0; i < size; i++)
        cout << "빠져나간 데이터: " << lq.dequeue()->data << endl;
 
    return 0;
}
