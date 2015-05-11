#include <cstdio>
int main() {
	int test,student,speed,minSpeed;
	scanf("%d",&test);
	for(int t=1;t<=test;t++) {
		scanf("%d",&student);
		for(int i=1;i<=student;i++) {
			scanf("%d",&speed);
			if(i == 1) minSpeed = speed;
			if(speed > minSpeed) minSpeed = speed;
		}
		printf("Case %d: %d\n",t,minSpeed);
	}
	return 0;
}
