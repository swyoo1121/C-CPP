#include <stdio.h>
#include <stdlib.h>
#include<string.h>


typedef struct process {
	char pid[10];
	int arrTime;
	int exeTime;
	int priority;

	int waitingTime; //대기 시간
	int turnaroundTime; //반환 시간
	int responseTime; //응답 시간
	int firstRun; //처음으로 응답했다면 0, 아니라면 1
	int firstArrTime; //처음으로 도착한 시간
} Process;


typedef struct {
	Process* pQueue;
	int cur;  //pop 횟수 기록
	int cnt;  //실제 queue에 저장된 프로세스 수
} priorityQueue;


///전역변수
priorityQueue scheduling;  //실제 도착한 프로세스 순서로 저장
int size, timeQ;  //프로세스 갯수, time quantum 전역변수로 선언
int runningTime; //진행시간 변수 
double avgWaitingTime = 0, avgTurnaroundTime = 0, avgResponsetime = 0; //전체 평균 대기시간, 반환시간, 응답시간 변수


////////////////////////////////////////////////

void push(Process node, int flag);  //queue에 노드 추가
Process pop_priority();  //root 노드 삭제
Process pop_exetime();
Process pop_arrtime();
void readFile(priorityQueue* p);  //파일을 읽어와 구조체 배열 생성
void sortReadyQueue(Process* pQueue); 
void sortByArrtime(Process* pQueue);  //도착 시간을 기준으로 오름차순 정렬
void sortByPriority(Process* pQueue);  //우선순위를 기준으로 오름차순 정렬
void sortByExetime(Process* pQueue);  //실행 시간을 기준으로 오름차순 청렬
void swap(Process* a, Process* b);  //구조체 배열에서 두 노드를 swap
void printQueue(Process node, int arrTime, int processRunningTime);  //queue 출력
void reset(priorityQueue *p);

void FCFS(priorityQueue* p);
void SJF(priorityQueue* p);
void SRTF(priorityQueue* p);
void RR(priorityQueue *p);
void nonPriRR(priorityQueue *p);
void nonpreemptivePriority(priorityQueue* p);
void preemptivePriority(priorityQueue* p);

//////////////////////////////////////////////////////////////////


void push(Process node, int flag) {
	scheduling.pQueue[scheduling.cnt] = node;
	if (flag == 1) sortByPriority(scheduling.pQueue);
	else if (flag == 2) sortByExetime(scheduling.pQueue);
	else if (flag == 3) sortByArrtime(scheduling.pQueue);
	scheduling.cnt++;
}

Process pop_priority() {
	int now = 0;
	int left = now * 2 + 1;
	int right = now * 2 + 2;
	int target = now;
	Process tempNode;

	tempNode = scheduling.pQueue[0];

	scheduling.cur++;
	scheduling.cnt--;
	if (scheduling.cnt != 0) scheduling.pQueue[0] = scheduling.pQueue[scheduling.cnt];

	while (left < scheduling.cnt) {
		if (scheduling.pQueue[target].priority > scheduling.pQueue[left].priority ||
			(scheduling.pQueue[target].priority == scheduling.pQueue[left].priority && scheduling.pQueue[target].arrTime > scheduling.pQueue[left].arrTime)) target = left;
		if (scheduling.pQueue[target].priority > scheduling.pQueue[right].priority && right < scheduling.cnt ||
			(scheduling.pQueue[target].priority == scheduling.pQueue[right].priority && scheduling.pQueue[target].arrTime > scheduling.pQueue[right].arrTime)) target = right;

		if (target == now) break;
		else {
			swap(&scheduling.pQueue[target], &scheduling.pQueue[now]);
			now = target;
			left = now * 2 + 1;
			right = now * 2 + 2;
		}
	}

	return tempNode;
}

Process pop_exetime() {
	int now = 0;
	int left = now * 2 + 1;
	int right = now * 2 + 2;
	int target = now;
	Process tempNode;

	tempNode = scheduling.pQueue[0];


	scheduling.cur++;
	scheduling.cnt--;

	if (scheduling.cnt != 0) scheduling.pQueue[0] = scheduling.pQueue[scheduling.cnt];

	while (left < scheduling.cnt) {
		if (scheduling.pQueue[target].exeTime > scheduling.pQueue[left].exeTime || (scheduling.pQueue[target].exeTime == scheduling.pQueue[left].exeTime && scheduling.pQueue[target].arrTime > scheduling.pQueue[left].arrTime))
			target = left;
		if (scheduling.pQueue[target].exeTime > scheduling.pQueue[right].exeTime && right > target || (scheduling.pQueue[target].exeTime == scheduling.pQueue[right].exeTime && scheduling.pQueue[target].arrTime > scheduling.pQueue[right].arrTime))
			target = right;

		if (target == now) break;
		else {
			swap(&scheduling.pQueue[target], &scheduling.pQueue[now]);
			now = target;
			left = now * 2 + 1;
			right = now * 2 + 2;
		}
	}

	return tempNode;;
}

Process pop_arrtime() {
	int now = 0;
	int left = now * 2 + 1;
	int right = now * 2 + 2;
	int target = now;
	Process tempNode;

	tempNode = scheduling.pQueue[0];

	scheduling.cur++;
	scheduling.cnt--;

	if (scheduling.cnt != 0) scheduling.pQueue[0] = scheduling.pQueue[scheduling.cnt];

	while (left < scheduling.cnt) {
		if (scheduling.pQueue[target].arrTime > scheduling.pQueue[left].arrTime)
			target = left;
		if (scheduling.pQueue[target].arrTime > scheduling.pQueue[right].arrTime && right > target)
			target = right;

		if (target == now) break;
		else {
			swap(&scheduling.pQueue[target], &scheduling.pQueue[now]);
			now = target;
			left = now * 2 + 1;
			right = now * 2 + 2;
		}
	}

	return tempNode;
}

void readFile(priorityQueue* p) {
	//scheduling queue와 ready queue 동적 할당
	//ready queue에 텍스트 파일 정보 저장
	int i = 0;
	FILE* fp = fopen("ready queue.txt", "r");

	if (fp == NULL) {
		printf("Error\n");
		return;
	}

	fscanf(fp, "%d", &size);
	p->pQueue = (Process*)malloc(sizeof(Process) * size);
	scheduling.pQueue = (Process*)malloc(sizeof(Process) * size);

	for (i = 0; i < size; i++) {
		fscanf(fp, "%s %d %d %d", &p->pQueue[i].pid, &p->pQueue[i].arrTime, &p->pQueue[i].exeTime, &p->pQueue[i].priority);
	}
	fscanf(fp, "%d", &timeQ);

	for (i = 0; i < size; i++) {
		p->pQueue[i].responseTime = 0;
		p->pQueue[i].turnaroundTime = 0;
		p->pQueue[i].waitingTime = 0;
		p->pQueue[i].firstRun = 0;
		p->pQueue[i].firstArrTime = p->pQueue[i].arrTime;
	}

	fclose(fp);

}

void swap(Process* a, Process* b) {
	//두 프로세스 노드 교환
	Process temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void sortReadyQueue(Process* pQueue) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (pQueue[i].arrTime > pQueue[j].arrTime) {
				swap(&pQueue[i], &pQueue[j]);
			}
		}
	}
}

void sortByArrtime(Process* pQueue) {
	int now = scheduling.cnt;
	int parent = (now - 1) / 2;

	while (now > 0 && pQueue[now].arrTime < pQueue[parent].arrTime) {
		swap(&pQueue[now], &pQueue[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
}

void sortByPriority(Process* pQueue) {
	//scheduling queue에 push를 한 경우 배열의 가장 끝에 새로운 프로세스 저장
	//부모 노드와 우선순위를 비교하여 자리 찾기
	int now = scheduling.cnt;
	int parent = (now - 1) / 2;

	while (now > 0 && (pQueue[now].priority < pQueue[parent].priority ||
		(pQueue[now].priority == pQueue[parent].priority && pQueue[now].arrTime < pQueue[parent].arrTime))) {
		swap(&pQueue[now], &pQueue[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
}

void sortByExetime(Process* pQueue) {
	int now = scheduling.cnt;
	int parent = (now - 1) / 2;

	while (now > 0 && (pQueue[now].exeTime < pQueue[parent].exeTime ||
		(pQueue[now].exeTime == pQueue[parent].exeTime && pQueue[now].arrTime < pQueue[parent].arrTime))) {
		swap(&pQueue[now], &pQueue[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
}

void printQueue(Process node, int arrTime, int processRunningTime) {
	node.waitingTime = runningTime - arrTime - processRunningTime;

	avgWaitingTime += node.waitingTime;
	avgTurnaroundTime += node.turnaroundTime;
	avgResponsetime += node.responseTime;
	printf("%s Waiting Time : %d \tTurnaround Time: %d \tResponse Time : %d\n", node.pid, node.waitingTime, node.turnaroundTime, node.responseTime);
}

void reset(priorityQueue *p) {
	p->cur = 0;
	scheduling.cur = 0;
	scheduling.cnt = 0;
	avgWaitingTime = 0; 
	avgTurnaroundTime = 0;
	avgResponsetime = 0;
	runningTime = 0;

	for (int i = 0; i < size; i++) {
		p->pQueue[i].responseTime = 0;
		p->pQueue[i].turnaroundTime = 0;
		p->pQueue[i].waitingTime = 0;
		p->pQueue[i].firstRun = 0;
		p->pQueue[i].firstArrTime = p->pQueue[i].arrTime;
	}
}
////////////////////////

void FCFS(priorityQueue* p) {

	for(int i=0; i<size; i++) {
		p->pQueue[i].responseTime = runningTime - p->pQueue[i].arrTime;
		p->pQueue[i].turnaroundTime = runningTime + p->pQueue[i].exeTime - p->pQueue[i].arrTime;
		printQueue(p->pQueue[i], p->pQueue[i].arrTime, 0);

		runningTime += p->pQueue[i].exeTime;
	}

	printf("total running time = %d\n", runningTime);
	printf("average waiting time = %.3f\n", avgWaitingTime / size);
	printf("average turnaround time = %.3f\n", avgTurnaroundTime / size);
	printf("average response time = %.3f\n", avgResponsetime / size);
}

void SJF(priorityQueue* p) {

	Process poppedNode;

	while (scheduling.cur < size) {
		while (p->cur != size && runningTime >= p->pQueue[p->cur].arrTime) {
			push(p->pQueue[p->cur], 2);
			p->cur++;
		}

		//runningTime += pop_exetime();
		poppedNode = pop_exetime();
		poppedNode.turnaroundTime = runningTime + poppedNode.exeTime - poppedNode.arrTime;
		poppedNode.responseTime = runningTime - poppedNode.arrTime;
		printQueue(poppedNode, poppedNode.arrTime, 0);
		runningTime += poppedNode.exeTime;
	}

	printf("total running time = %d\n", runningTime);
	printf("average waiting time = %.3f\n", avgWaitingTime / size);
	printf("average turnaround time = %.3f\n", avgTurnaroundTime / size);
	printf("average response time = %.3f\n", avgResponsetime / size);

	return;
}

void SRTF(priorityQueue* p) {
	
	int processRunningTime = 0; 
	int arrTime = 0; 
	Process poppedNode; 

	while (scheduling.cur <= size || scheduling.cnt != 0) {
		while (p->cur != size && runningTime >= p->pQueue[p->cur].arrTime) {
			push(p->pQueue[p->cur], 2);
			p->cur++; 
		}

		poppedNode = pop_exetime();
		if (!poppedNode.firstRun) {
			poppedNode.firstRun = 1;
			poppedNode.responseTime = runningTime - poppedNode.firstArrTime;
		}

		while (poppedNode.exeTime > processRunningTime) {
			arrTime = poppedNode.arrTime;

			if (poppedNode.exeTime > scheduling.pQueue[0].exeTime) {
				poppedNode.arrTime = runningTime;
				poppedNode.exeTime -= processRunningTime;
				push(poppedNode, 2);
				break;
			}
			processRunningTime++;
			runningTime++;

			while (p->cur != size && runningTime >= p->pQueue[p->cur].arrTime) {
				push(p->pQueue[p->cur], 2);
				p->cur++;
			}
		}

		if (processRunningTime == poppedNode.exeTime) poppedNode.turnaroundTime = runningTime - poppedNode.firstArrTime;
		printQueue(poppedNode, arrTime, processRunningTime);

		processRunningTime = 0;
	}


	printf("total running time = %d\n", runningTime);
	printf("average waiting time = %.3f\n", avgWaitingTime / size);
	printf("average turnaround time = %.3f\n", avgTurnaroundTime / size);
	printf("average response time = %.3f\n", avgResponsetime / size);

}

void nonPriRR(priorityQueue* p) {

	int processRunningTime = 0;
	int arrTime = 0; 
	Process poppedNode;

	while (scheduling.cur <= size || scheduling.cnt != 0) {
		while (p->cur != size && runningTime >= p->pQueue[p->cur].arrTime) {  
			push(p->pQueue[p->cur], 3);
			p->cur++; 
		}

		poppedNode = pop_priority(); 
		arrTime = poppedNode.arrTime;

		if (!poppedNode.firstRun) { 
			poppedNode.firstRun = 1;
			poppedNode.responseTime = runningTime - poppedNode.firstArrTime;
		}

		while (timeQ > processRunningTime) {
			processRunningTime++;
			runningTime++;

			while (p->cur != size && runningTime >= p->pQueue[p->cur].arrTime) {
				push(p->pQueue[p->cur], 1);
				p->cur++;
			}
			if (processRunningTime == poppedNode.exeTime) {
				poppedNode.turnaroundTime = runningTime - poppedNode.firstArrTime;
				break;
			}
	
		}
		if(processRunningTime != poppedNode.exeTime) {
			poppedNode.exeTime -= timeQ;
			poppedNode.arrTime = runningTime;
			push(poppedNode, 1);
		}
	
		printQueue(poppedNode, arrTime, processRunningTime);
		
		processRunningTime = 0;
	}


	printf("total running time = %d\n", runningTime);
	printf("average waiting time = %.3f\n", avgWaitingTime / size);
	printf("average turnaround time = %.3f\n", avgTurnaroundTime / size);
	printf("average response time = %.3f\n", avgResponsetime / size);
}

void RR(priorityQueue *p) {

	int processRunningTime = 0;
	int arrTime = 0; 
	Process poppedNode;

	while (scheduling.cur <= size || scheduling.cnt != 0) {
		while (p->cur != size && runningTime >= p->pQueue[p->cur].arrTime) {  
			push(p->pQueue[p->cur], 3);
			p->cur++; 
		}

		poppedNode = pop_arrtime(); 
		arrTime = poppedNode.arrTime;

		if (!poppedNode.firstRun) { 
			poppedNode.firstRun = 1;
			poppedNode.responseTime = runningTime - poppedNode.firstArrTime;
		}

		while (timeQ > processRunningTime) {
			processRunningTime++;
			runningTime++;

			while (p->cur != size && runningTime >= p->pQueue[p->cur].arrTime) {
				push(p->pQueue[p->cur], 3);
				p->cur++;
			}
			if (processRunningTime == poppedNode.exeTime) {
				poppedNode.turnaroundTime = runningTime - poppedNode.firstArrTime;
				break;
			}
	
		}
		if(processRunningTime != poppedNode.exeTime) {
			poppedNode.exeTime -= timeQ;
			poppedNode.arrTime = runningTime;
			push(poppedNode, 3);
		}
	
		printQueue(poppedNode, arrTime, processRunningTime);
		
		processRunningTime = 0;
	}


	printf("total running time = %d\n", runningTime);
	printf("average waiting time = %.3f\n", avgWaitingTime / size);
	printf("average turnaround time = %.3f\n", avgTurnaroundTime / size);
	printf("average response time = %.3f\n", avgResponsetime / size);
}

void nonpreemptivePriority(priorityQueue* p) {

	Process poppedNode;

	while (scheduling.cur < size) {
		while (p->cur != size && runningTime >= p->pQueue[p->cur].arrTime) {
			push(p->pQueue[p->cur], 1);
			p->cur++;
		}
		poppedNode = pop_priority();
		poppedNode.turnaroundTime = runningTime + poppedNode.exeTime - poppedNode.arrTime;
		poppedNode.responseTime = runningTime - poppedNode.arrTime;
		printQueue(poppedNode, poppedNode.arrTime, 0);
		runningTime += poppedNode.exeTime;

	}

	printf("total running time = %d\n", runningTime);
	printf("average waiting time = %.3f\n", avgWaitingTime / size);
	printf("average turnaround time = %.3f\n", avgTurnaroundTime / size);
	printf("average response time = %.3f\n", avgResponsetime / size);

}

void preemptivePriority(priorityQueue* p) {

	int processRunningTime = 0;
	int arrTime = 0; 
	Process poppedNode;

	while (scheduling.cur <= size || scheduling.cnt != 0) {
		while (p->cur != size && runningTime >= p->pQueue[p->cur].arrTime) {  
			push(p->pQueue[p->cur], 1);
			p->cur++; 
		}

		poppedNode = pop_priority(); 

		if (!poppedNode.firstRun) { 
			poppedNode.firstRun = 1;
			poppedNode.responseTime = runningTime - poppedNode.firstArrTime;
		}

		while (poppedNode.exeTime > processRunningTime) {
			arrTime = poppedNode.arrTime;

			if (poppedNode.priority > scheduling.pQueue[0].priority) {
				poppedNode.arrTime = runningTime;
				poppedNode.exeTime -= processRunningTime;
				push(poppedNode, 1);
				break;
			}
			processRunningTime++;
			runningTime++;

			while (p->cur != size && runningTime >= p->pQueue[p->cur].arrTime) {
				push(p->pQueue[p->cur], 1);
				p->cur++;
			}
		}

		if (processRunningTime == poppedNode.exeTime) poppedNode.turnaroundTime = runningTime - poppedNode.firstArrTime;
		printQueue(poppedNode, arrTime, processRunningTime);
		
		processRunningTime = 0;
	}


	printf("total running time = %d\n", runningTime);
	printf("average waiting time = %.3f\n", avgWaitingTime / size);
	printf("average turnaround time = %.3f\n", avgTurnaroundTime / size);
	printf("average response time = %.3f\n", avgResponsetime / size);

}



int main() {
	priorityQueue readyQueue;
	readyQueue.cur = 0;
	scheduling.cur = 0;
	scheduling.cnt = 0;

	readFile(&readyQueue);
	sortReadyQueue(readyQueue.pQueue);

	printf("FCFS\n");
	FCFS(&readyQueue);
	reset(&readyQueue);
	
	printf("\nSJF\n");
	SJF(&readyQueue);
	reset(&readyQueue);

	printf("\nSRTF\n");
	SRTF(&readyQueue);
	reset(&readyQueue);

	printf("\nRR\n");
	RR(&readyQueue);
	reset(&readyQueue);

	printf("\nnonPriRR\n");
	nonPriRR(&readyQueue);
	reset(&readyQueue);

	printf("\nNonpreemptive\n");
	nonpreemptivePriority(&readyQueue);
	reset(&readyQueue);

	printf("\nPreemptive\n");
	preemptivePriority(&readyQueue);

	return 0;
}