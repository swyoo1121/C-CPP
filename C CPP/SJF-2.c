#include<stdio.h>
#include<stdlib.h>

typedef struct process {
	int PID;
	int Arrival_time;
	int Service_time;
	int Priority;
	int Allocation_time;
} Process;

int Process_count = 4;
int Now_Process_count = 0;
int Nowtime = 0;
int Totaltime = 13;

Process Queue[10] = {
    {.PID = 0, .Arrival_time = 1, .Service_time = 6},
    {.PID = 1, .Arrival_time = 0, .Service_time = 3},
    {.PID = 2, .Arrival_time = 2, .Service_time = 2},
    {.PID = 3, .Arrival_time = 1, .Service_time = 1}};

Process Nowqueue[10];


void SJF() {

    int Nowprocess;
	int min_remain_time;
	int temp_remain_time;
	int index = 0;

	while (Nowtime != Totaltime) {

		for (int i = 0; i < Process_count; i++) {
			if (Queue[i].Arrival_time == Nowtime) {
				Nowqueue[Now_Process_count] = Queue[i];
				Now_Process_count += 1;
			}
		}

		min_remain_time = Nowqueue[index].Service_time - Nowqueue[index].Allocation_time;

		for (int i = 0; i < Now_Process_count; i++) {
			temp_remain_time = Nowqueue[i].Service_time - Nowqueue[i].Allocation_time;

			if (temp_remain_time < min_remain_time) {
				min_remain_time = temp_remain_time;
				Nowprocess = Nowqueue[i].PID;
				index = i;
			}
			else {
				Nowprocess = Nowqueue[index].PID;
			}
		}

		printf("%d\n", Nowprocess);
		Nowqueue[index].Allocation_time += 1;

		if (Nowqueue[index].Service_time - Nowqueue[index].Allocation_time == 0) {
			int k = index;
			for (int i = 0; i <= (Now_Process_count - (index + 1)); i++) {
				Nowqueue[k] = Nowqueue[k + 1];
				k++;
			}
			Now_Process_count -= 1;
			index = 0;
		}

		Nowtime++;
	}
	return;
}

int main(void) {
	SJF();
}

