#include <stdio.h>
#include <stdbool.h>

#define MAX_PEOPLE 50

typedef struct {
    int id;
} People;

typedef struct {
    People data[MAX_PEOPLE];
    int head;
    int tail;
    int count;
} Queue;

void Queue_init(Queue *q) {
    for(int i = 0; i < MAX_PEOPLE; i++)
        q->data[i].id = i + 1;
    q->head = 0;
    q->tail = MAX_PEOPLE - 1;
    q->count = MAX_PEOPLE;
}

int Queue_push(Queue *q, People p) {
    // 队列满
    if (q->count == MAX_PEOPLE) return 0;
    
    q->tail = (q->tail + 1) % MAX_PEOPLE;
    q->data[q->tail] = p;
    q->count++;
    return 1;
}

int Queue_pop(Queue *q) {
    // 队列空
    if (q->count == 0) return 0;
    
    q->head = (q->head + 1) % MAX_PEOPLE;
    q->count--;
    return 1;
}

People Queue_top(Queue q) {
    return q.data[q.head]; 
} 

int main() {
    Queue q;
    int total_people=50;
    int report_interval=5;

    // TODO: 在这里添加你的代码
    Queue_init(&q);

    while(q.count != 1) {
        for(int i = 0; i < report_interval - 1; i++) {
            People tmp = Queue_top(q);
            Queue_pop(&q);
            Queue_push(&q, tmp);
        }
        printf("淘汰: %d\n", Queue_top(q).id);
        Queue_pop(&q);
    }
    
    printf("最后剩下的人是: %d\n", q.data[q.head].id);

    return 0;
}