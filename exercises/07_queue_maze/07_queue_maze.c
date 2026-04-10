#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

int visited[MAX_ROW][MAX_COL] = {0};

// map move control
struct move {
	int dx;
	int dy;
} move_list[4] = {
	{0, -1}, {-1, 0}, {0, 1}, {1, 0}
};

int check_next_step(int x, int y) {
	if(x >= 0 && x < MAX_COL && y >= 0 && y < MAX_ROW)
		if(visited[y][x] != 1 && maze[y][x] != 1)
			return 1;
	return 0;
}

// node type
typedef struct {
	int x;
	int y;
	int path;
} node;

// queue
#define QUEUE_DEPTH 10

node queue[QUEUE_DEPTH];
int head = 0, tail = 0;

int queue_push(node nd) {
	// queue full
	if( tail + 1 == head || (head == 0 && tail == (QUEUE_DEPTH -1))) return 0;
	else {
		queue[tail] = nd;
		tail = (tail + 1) % QUEUE_DEPTH;
	}
}

int queue_pop() {
	if(head == tail) return 0;
	else {
		head = (head + 1) % QUEUE_DEPTH;
		return 1;
	}
}

node queue_head() {
	return queue[head];
}

int queue_size() {
	return (tail > head) ? (tail - head) : (tail - head + 10);
}


int main(void)
{
	// TODO: 在这里添加你的代码
	// record path
	node apath[MAX_COL * MAX_ROW];
	int index = 0;
	// initial node
	node start = {0, 0, -1};
	queue_push(start);
	visited[0][0] = 0;
	while(1) {
		node current = queue_head();
		apath[index++] = current;
		queue_pop();
		// reach end
		if(current.x == 4 && current.y == 4)
			break;
		for(int i = 0; i < 4; i++) {
			int x = current.x + move_list[i].dx;
			int y = current.y + move_list[i].dy;
			if(check_next_step(current.x + move_list[i].dx, current.y + move_list[i].dy)) {
				node append = {x, y, index - 1};
				visited[y][x] = 1;
				queue_push(append);
			}
		}
	}

	int next = index - 1;
	node output_list[100];
	int output_idx = 0;
	while(1) {
		// printf("(%d,%d) ", apath[next].y, apath[next].x);
		output_list[output_idx++] = apath[next];
		if(apath[next].path == -1) break;
		next = apath[next].path;
	}

	for(int i = 0; i < output_idx; i++) {
		printf("(%d,%d)\n", output_list[i].y, output_list[i].x);
	}
	return 0;
}