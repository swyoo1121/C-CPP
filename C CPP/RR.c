#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct process {
	char pid[10];
	int arrTime;
	int exeTime;
	int remainTime;	// 선점, RR에 의해 실행 중 중단 됐을 경우 남아있는 exeTime을 저장하기 위한 변수
	int priority;
} Process;

typedef struct {
	Process *pQueue;
	int cur;  //pop 횟수 기록
	int cnt;  //실제 queue에 저장된 프로세스 수
} priorityQueue;

priorityQueue scheduling;  //실제 도착한 프로세스 순서로 저장
int size, timeQ; //프로세스 총 수, time quantum 전역변수로 선언
int runningTime; //진행시간 변수 
int tempWaitingTime, tempTurnaroundTime, tempResponseTime; //프로세스별 대기시간, 반환시간, 응답시간 변수
double avgWaitingTime = 0, avgTurnaroundTime = 0, avgResponsetime = 0; //전체 평균 대기시간, 반환시간, 응답시간 변수

void push(Process node);  //queue에 노드 추가
int pop_RR();  //root 노드 삭제
void readFile(priorityQueue *p);  //파일을 읽어와 구조체 배열 생성
void sortByArrtime(Process *pQueue);  //도착 시간을 기준으로 오름차순 정렬
void swap(Process *a, Process *b);  //구조체 배열에서 두 노드를 swap
void printQueue(Process node);  //queue 출력

int check(Process node); // remainTime을 조사하여 다시 스케줄링 큐에 push할지 결정
void RR(priorityQueue *p); // Round Robin

//////////////////////////////////////////////////////////////////

void push(Process node) {
	//scheduling queue에 도착한 프로세스를 push
	scheduling.pQueue[scheduling.cnt] = node;
	scheduling.cnt++;
}


int pop_RR() {
	//scheduling queue의 최상위 노드를 pop
	//TQ만큼 executionTime 차감
	//check함수 실행
	int now = 0;
	int left = now * 2 + 1;
	int right = now * 2 + 2;
	int target = now;
	
	if (check(scheduling.pQueue[0]) == 1) {
		push(scheduling.pQueue[size - 1])
	}
	else {
		scheduling.cur++;
		scheduling.cnt--;
		printQueue(scheduling.pQueue[0]);
	}

	return timeQ;
}


void readFile(priorityQueue *p) {
	//scheduling queue와 ready queue 동적 할당
	//ready queue에 텍스트 파일 정보 저장
	int i = 0;
	FILE *fp = fopen("ready queue.txt", "r");

	if (fp == NULL) {
		printf("Error\n");
		return;
	}

	fscanf(fp, "%d", &size);
	p->pQueue = (Process*)malloc(sizeof(Process) * size);
	scheduling.pQueue = (Process*)malloc(sizeof(Process) * size);

	for (i = 0; i < size; i++) {
		fscanf(fp, "%s %d %d %d", &p->pQueue[i].pid, &p->pQueue[i].arrTime, &p->pQueue[i].exeTime, &p->pQueue[i].priority);
		&p->pQueue[i].remainTime = &p->pQueue[i].exeTime;
	}
	fscanf(fp, "%d", &timeQ);

	fclose(fp);

}


void swap(Process *a, Process *b) {
	//두 프로세스 노드 교환
	Process temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


void sortByArrtime(Process *pQueue) {
	//처음 텍스트 파일에서 ready queue 목록을 읽어온 후 도착 시간에 따라 오름차순 정렬
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (pQueue[i].arrTime > pQueue[j].arrTime) {
				swap(&pQueue[i], &pQueue[j]);
			}
		}
	}
}


void printQueue(Process node) {
	printf("%s Waiting Time : %d \tTurnaround Time : %d \tResponse Time : %d\n", node.pid, runningTime - node.arrTime, runningTime  - node.arrTime + node.exeTime, runningTime - node.arrTime + 1);
	avgWaitingTime += runningTime - node.arrTime;
	avgTurnaroundTime += runningTime - node.arrTime + node.exeTime;
	avgResponsetime += runningTime - node.arrTime + 1;
}


int check(Process node) {
    if (node.exeTime != 0) return 1;
	else return 0;
}


void RR(priorityQueue *p) {

	runningTime = 0;

	while (scheduling.cur < size ) {
		while (p->cur != size && runningTime >= p->pQueue[p->cur].arrTime) {
			push(p->pQueue[p->cur]);
			p->cur++;
		}

		runningTime += pop_RR();
	}

	printf("total running time = %d\n", runningTime);
	printf("average waiting time = %.38f\n", avgWaitingTime / size);
	printf("average turnaround time = %.3f\n", avgTurnaroundTime / size);
	printf("average response time = %.3f\n", avgResponsetime / size);

	return;
}

int main() {
	priorityQueue readyQueue;
	readyQueue.cur = 0;
	scheduling.cur = 0;
	scheduling.cnt = 0;

	readFile(&readyQueue);
	sortByArrtime(readyQueue.pQueue); // readyQueue는 시간순 오름차순

	RR(&readyQueue);

	return 0;
}