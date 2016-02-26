#include "main.h"

int main(int argc, char **argv)
{
	printf("[ terminal animation ]\n");

	/* get parameters */
	const int choice = (argc == 2) ? atoi(argv[1]) : 2;
	const int len = (argc == 3) ? atoi(argv[0]) : 50;

	/* start animation */
	animate(choice, len);

	return EXIT_SUCCESS;
}

/* start progress bar animation if choice 1 
   or start throwing stick animation if choice 2 */
void animate(const int type, const int len)
{
	if (type == 1) {
		progress_bar(len);
	} else if (type == 2) {
		/* loop to run throwing stick animation forwards and backwards */
		int i=0;
		for (;;) {
			throwing_stick(len, (i % 2) ? 'b' : 'f', 1);
			i = (i+1) % 2;
		}
	} else {
		fprintf(stderr, "choice must be 1 (progress bar) or 2 (throwing stick)\n");
		exit(EXIT_FAILURE);
	}
}
