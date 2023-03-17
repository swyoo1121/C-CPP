void SJF(priorityQueue *p) {

	runningTime = 0;

	while (scheduling.cur < size ) {
		while (p->cur != size && runningTime >= p->pQueue[p->cur].arrTime) {
			push(p->pQueue[p->cur]);
			p->cur++;
		}

		runningTime += pop();
	}

	printf("total running time = %d\n", runningTime);
	printf("average waiting time = %.3f\n", avgWaitingTime / size);
	printf("average turnaround time = %.3f\n", avgTurnaroundTime / size);
	printf("average response time = %.3f\n", avgResponsetime / size);

	return;
}