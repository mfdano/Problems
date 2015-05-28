#include <cstdio>
int main() {
	double h,u,d,f,height,fatigue_factor;
	bool success;
	int day;
	while(scanf("%lf %lf %lf %lf",&h,&u,&d,&f) != EOF) {
		if(h == 0) break;
		success = true;
		day = 1;
		height = 0;
		fatigue_factor = (u * f) / 100;
		while(1) {
			height += u;
			if(u > 0) u -= fatigue_factor;
			if(height > h) break;
			height -= d;
			if(height < 0) { success = false; break; }
			day++;
		}
		if(success) printf("success on day %d\n",day);
		else printf("failure on day %d\n",day);
	}
	return 0;
}
