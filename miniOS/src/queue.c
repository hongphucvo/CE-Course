#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t *q)
{
	return (q->size == 0);
}

void enqueue(struct queue_t *q, struct pcb_t *proc)
{
	/* TODO: put a new process to queue [q] */
	if(q->size == MAX_QUEUE_SIZE) {
		fprintf(stderr, "queue is full\n");
	}
	q->proc[q->size] = proc;
	q->size++;
}

struct pcb_t *dequeue(struct queue_t *q)
{
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if(q->size == 0) return NULL;
	struct pcb_t *process = q->proc[0];
	if (q->size > 0)
	{
		uint32_t min_remain = process->burst_time;
		int min_index = 0;

		for (int i = 1; i < q->size; i++)
		{
			//if (q->proc[i]->arrival_time<=timestamp)//deadline with timestamp
			//{
			if(q->proc[i]->burst_time<min_remain){
				min_remain=q->proc[i]->burst_time;
				min_index=i;
			}
			//}
		}
		process = q->proc[min_index];
		
		q->proc[min_index] = q->proc[q->size - 1];
		q->proc[q->size - 1] = NULL;
		q->size--;
	}
	return process;
}
