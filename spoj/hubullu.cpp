#include <iostream>
using namespace std;

// https://www.spoj.com/problems/HUBULLU/

#define ll long long

int main() {
	int t;
	
	scanf("%d", &t);
	ll n;
	int temp;
	while (t > 0) {
		scanf("%lld", &n);
		scanf("%d", &temp);
		
		if (temp == 0) {
			printf("Airborne wins.\n");
		} else {
			printf("Pagfloyd wins.\n");
		}
		
		t--;
	}
	
	return 0;
}