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

// stack
struct pos {
	int x;
	int y;
	int step;
};

struct pos pos_stack[MAX_COL * MAX_ROW] = {};
int stop = 0;

void stack_push(int x, int y, int step) {
	pos_stack[stop].x = x;
	pos_stack[stop].y = y;
	pos_stack[stop].step = step;
	stop++;
}

void stack_pop() {
	stop--;
}

struct pos stack_top() {
	return pos_stack[stop - 1];
}

void stack_update_step(int step) {
	pos_stack[stop - 1].step = step;
}

int main(void)
{
	// TODO: 在这里添加你的代码
	stack_push(0, 0, -1);
	visited[0][0] = 1;

	while(1) {
		struct pos curr = stack_top();
		if(curr.x == 4 && curr.y == 4)
			break;
		int i = curr.step + 1;
		for(; i < 4; i++) {
			int x = curr.x + move_list[i].dx;
			int y = curr.y + move_list[i].dy;
			if(check_next_step(x, y)) {
				stack_update_step(i);
				visited[y][x] = 1;
				stack_push(x, y, -1);
				break;
			}
		}
		if(i == 4) stack_pop();
	}

	for(int i = stop - 1; i >= 0; i--) {
		printf("(%d,%d)\n", pos_stack[i].y, pos_stack[i].x);
	}

	return 0;
}