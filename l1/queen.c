#include <stdio.h>

int main (){
	int x1 = 1, y1 = 1, x2 = 1, y2 = 1;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

	while (x1 | y1 | x2 | y2) {
		if (x1 == x2 & y1 == y2) {
			printf("%d", 0);
		} else if (x1 == x2 | y1 == y2) {
			printf("%d", 1);
		} else {
			int dx = x1 - x2;
			int dy = y1 - y2;
			dx = dx < 0 ? -dx : dx;
			dy = dy < 0 ? -dy : dy;

			if (dx == dy) {
				printf("%d", 1);
			} else {
				printf("%d", 2);
			}
		}

		printf("\n");
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	}

	return 0;
}