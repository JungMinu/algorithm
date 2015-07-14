#include <stdio.h>
#include <stdlib.h>

typedef struct coord	{	//데이터 구조체 DATA
	int x, y;
} DATA;

typedef struct queue	{	//데이터와 다음을 가리키는 큐로 구성된 구조체 Queue
	DATA data;
	struct queue *next;
} Queue;

Queue *head, *tail;	//head와 tail로 구성

void push(DATA val)	//push함수 - 데이터를 tail에 push 하는 역할
{
	tail->data = val;	//tail에 데이터를 넣음
	tail->next = (Queue *)malloc(sizeof(Queue));	//다음 공간 할당
	tail = tail->next;	//이제부터 꼬리는 다음 꼬리가 됨
	tail->next = 0;		//초기화
}

DATA pop()	//pop함수 - header에 있는 데이터를 pop 함
{
	Queue *p = head;	//head라는 포인터 지정
	DATA result = head->data;	//result는 head의 데이터
	head = head->next;	//헤드 재지정함(다음데이터로)
	free(p);	//포인터 할당 해제

	return result;	//result반환함
}

int isEmpty()
{
	return !head;
}

void init()
{
	head = (Queue *)malloc(sizeof(Queue));
	head->next = 0;
	tail = head;
}

const int D[2][4] = {
	{ 0, 0, 1, -1 },
	{ 1, -1, 0, 0 }
};

int main(void)
{
	int map[101][101];
	int N, M;

	init();
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &map[i][j]);	//데이터를 입력 받음
			//map[i][j] -= '0';
		}
	}

	DATA t;		//데이터 구조체 선언 후, 필드에 데이터 삽입
	t.x = 1;
	t.y = 1;
	push(t);

	for (int s = 1, k = 1;; s++)	//s 증가시킴
	{
		int p = k;	//p에 1 대입
		k = 0;	//k에 0 대입

		while (p--)	//p를 감소시키면서 진행
		{
			DATA pick = pop();		//pop
			if (pick.x == N && pick.y == M)	//if it is end,
			{
				printf("%d", s);	//print s / s is counting variable
				return 0;	//end
			}

			for (int i = 0; i<4; i++)	//4번 진행, 4방향으로 진행하나봄
			{
				int new_x = pick.x + D[0][i];		//0번째 행의 i
				int new_y = pick.y + D[1][i];		//1번째 행의 i

				if (new_x < 1 || new_y < 1 || new_x > N || new_y > M || !map[new_x][new_y])
					continue;	//만약, 너무 크거나, 작거나, 1이 아니거나 하면 다음걸로 넣는다.

				map[new_x][new_y] = 0;	//0으로 바꾼다.
				t.x = new_x;	//새로운 값을 넣는다. 
				t.y = new_y;	// ""
				push(t);	//push 호출
				k++;	//k를 더한다.
			}

		}	//while
	}	//for


}	//main

/*
4 6
101111
101010
101011
111011
*/
