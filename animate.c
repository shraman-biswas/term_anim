#include "animate.h"

/* displays a dynamic progress bar  */
void progress_bar(const int len)
{
	int i;
	char *disp;
	float tmp;
	disp = (char *)calloc(len + 1, sizeof(char)); /* setup display memory */
	memset(disp, ' ', len + 1);					/* clear display */
	for (i=0; i<100; ++i) {
		tmp = (float)i / 100 * len;
		disp[(int)tmp] = '=';
		disp[(int)tmp + 1] = '>';
		printf("\rprogress bar [%s] %d%% ", disp, i + 1);
		fflush(stdout);
		usleep(MS(50));
	}
	printf("\n");
	free(disp);
}

/* displays a throwing stick animation in a specified direction */
void throwing_stick(const int len, const char dir, const int loop)
{
	int i, stop, d;
	char *disp = (char *)calloc(len, sizeof(char)); /* setup display memory */
	memset(disp, ' ', len);							/* clear display */
	switch (dir) {
		case 'F':	/* throw stick forwards - left to right */
		case 'f':
			i = 0;
			stop = len - 1;
			d = 1;
			break;
		case 'B':
		case 'b':	/* throw stick backwards - right to left */
			i = len - 1;
			stop = 0;
			d = -1;
			break;
		default:	/* direction must be forwards or backwards */
			fprintf(stderr, "direction must be 'f' or 'b'\n");
			exit(EXIT_FAILURE);
	}
	for (; i!=stop; i+=d) {
		if ((0 < i) && (i < len-1))
			disp[i-d] = ' ';
		disp[i] = sprite[i % 4]; /* update sprite with every iteration */
		printf("\rthrowing stick [%s] ", disp);
		fflush(stdout);
		usleep(MS(50));
	}
	if (!loop)
		printf("\n");
	free(disp);
}