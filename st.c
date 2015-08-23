#include <iostream>
#include <string>
using namespace std;
 
typedef struct node
{
    string data; // 데이터 필드
    struct node* nextNode; // 위의 노드를 가리키는 포인터 (스택이기 때문에)
} Node;
 

class Stack {
private:
    int count; // = 스택에 존재하는 노드 수
    Node* top; // = 가장 위에 있는 노드
    Node* list; // = 가장 아래에 있는 노드
public:
    Stack()
    {
        count = 0; // count를 0으로 초기화
        top = NULL; // top을 NULL로 초기화
        list = NULL; // list를 NULL로 초기화
    }
    void push(string data)
    {
        Node* newNode = new Node; // 새로운 노드를 만든다
        newNode->data = data; // 새로 추가된 노드의 데이터에 인자로 받은 data를 대입한다
        newNode->nextNode = NULL; // nextNode는 NULL로  초기화 한다
 
        // 만약 리스트가 NULL이라면 = 스택에 데이터가 아무것도 존재하지 않는다면
        if (list == NULL) list = newNode; // 새로 추가된 노드를 가장 아래에 있는 노드로 지정한다
        else { // 스택에 데이터가 하나 이상 존재할 경우
            Node* tmpNode = list; // 임시 노드를 만들고, 가장 아래에 있는 노드를 대입한다
             
            while (tmpNode->nextNode != NULL) // 임시 노드의 다음을 가리키는 노드가 NULL일때까지 반복 = top을 구함
                tmpNode = tmpNode->nextNode; // tmpNode는 다음 노드를 가리키게 한다
 
            tmpNode->nextNode = newNode; // 가장 위에있는 노드의 다음 노드를 새로 추가된 노드로 지정한다
        }
 
        top = newNode; count++; // 새로 추가된 노드를 가장 위에있는 노드로 지정하고 count를 1 증가시킨다
    }
    Node* pop()
    {
        Node* topNode = top; // 가장 위에있는 노드의 주소를 다른 포인터에 복사한다
        // 만약 list가 비어있다면 = 노드가 하나도 존재하지 않는다 = 스택이 비어있다
        if (list == NULL) cout << "스택이 비어있습니다." << endl;
        // 최하위 노드와 최상위 노드가 같다면 = 노드가 하나만 존재한다면
        // list와 top를 아무것도 가리키게 하지 않고 count를 1 감소시킨다
        else if (list == top) { list = NULL; top = NULL; count--; }
        // 노드가 두개 이상 존재한다면
        else {
            Node* currentNode = list; // 최하위 노드의 주소를 다른 포인터에 복사한다
 
            // currentNode 포인터가 NULL를 가리키고 있지 않으며 다음 노드가 최상위 노드일때까지 루프를 돈다
            // 즉, currentNode는 최상위 노드에서 하나 아래에 있는 노드를 최종적으로 가리키게 된다
            while (currentNode != NULL && currentNode->nextNode != top)
                // currentNode의 다음 노드 주소값을 currentNode에 대입한다
                currentNode = currentNode->nextNode;
 
            // currentNode를 최상위 노드로 지정한다
            top = currentNode;
            currentNode->nextNode = NULL; // currentNode가 가리키는 다음 노드를 NULL로 변경한다
            count--; // count를 1 감소시킨다
        }
 
        return topNode; // 제거된 이전의 top 노드의 주소값을 반환한다
    }
    int getSize() { return count; } // 현재 스택 내에 있는 노드의 수를 반환한다
    bool isEmpty() { return (list == NULL); } // 스택이 비어있으면 true, 비어있지 않다면 false
    Node* getTop() { return top; } // 가장 위에있는 노드의 주소값을 반환한다
};
 
int main()
{
    Stack stack; // 스택 클래스를 기반으로 한 객체
    int getSize; // stack의 노드 수를 담을 변수
 
    // 스택에 순서대로 삽입(push)한다
    stack.push("Internet Explorer");
    stack.push("Google Chrome");
    stack.push("Opera");
    stack.push("Netscape");
    stack.push("Mozilla Firefox");
    stack.push("Safari");
 
    // stack의 노드 수를 getSize 변수에 담는다
    getSize = stack.getSize();
    // stack의 노드 수만큼 루프를 돈다
    for(int i=0; i<getSize; i++)
    {
        if (stack.isEmpty()) break; // 만약 스택이 비어있을 경우 빠져나온다
        // pop 연산을 수행하며 스택의 제거되는 데이터를 출력한다.
        cout << "제거되는 데이터: " << stack.pop()->data << ", ";
 
        // 스택이 비어있지 않을 경우에
        if (!stack.isEmpty()) cout << "현재 최상위 데이터: " << stack.getTop()->data << endl;
        // 스택이 비어있을 경우에
        else cout << "최상위 데이터가 존재하지 않습니다." << endl;
    }
     
    return 0;
}
