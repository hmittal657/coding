#include <iostream>
using namespace std;

// https://www.spoj.com/problems/OFFSIDE/

int main() {
	
	int a, d;

	while (true) {

		scanf("%d", &a);
		scanf("%d", &d);

		if (a == 0 && d == 0) break;

		int att1;
		scanf("%d", &att1);

		for (int i = 1; i < a; i++) {
			int t;
			scanf("%d", &t);
			if (t < att1) {
				att1 = t;
			}
		}

		int def1, def2;

		scanf("%d", &def1);
		scanf("%d", &def2);

		if (def2 < def1) {
			int temp = def2;
			def2 = def1;
			def1 = temp;
		}

		for (int i = 2; i < d; i++) {
			int t;
			scanf("%d", &t);
			if (t > def2) continue;
			if (t <= def1) {
				def2 = def1;
				def1 = t;
			} else if (t <= def2) {
				def2 = t;
			}
		}

		if (att1 < def2) {
			printf("Y\n");
		} else {
			printf("N\n");
		}

	}

	return 0;
}