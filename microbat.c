#include <stdlib.h>
#include <stdio.h>

int main() {
	int i, drain, remain, h, m;
	FILE *fp[6];
	int bat[6];

	fp[0] = fopen ("/sys/class/power_supply/BAT0/capacity", "r");
	fp[1] = fopen ("/sys/class/power_supply/BAT1/capacity", "r");
	fp[2] = fopen ("/sys/class/power_supply/BAT0/power_now", "r");
	fp[3] = fopen ("/sys/class/power_supply/BAT1/power_now", "r");
	fp[4] = fopen ("/sys/class/power_supply/BAT0/energy_now", "r");
	fp[5] = fopen ("/sys/class/power_supply/BAT1/energy_now", "r");

	for(i = 0; i < 6; i++) {
		fscanf (fp[i], "%d", &bat[i]);  
		fclose(fp[i]);
	}

	drain = bat[2] + bat[3];
	if (drain == 0) {
		printf ("🔌 %d%%  %d%%\n", bat[0], bat[1]);
	} else {
		remain = (bat[4] + bat[5]) * 60 / drain;
		h = remain / 60;
		m = remain % 60;
		printf("🔋 %d%%  %d%%\t(%dh %dmin)\n", bat[0], bat[1], h, m);
	}
	return 0;
}
