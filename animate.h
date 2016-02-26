#ifndef ANIMATE_H
#define ANIMATE_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MS(x) (1000 * (x))

static const char sprite[] = {'|', '/', '-', '\\'};
static const char choice[] = {'f', 'b'};

void progress_bar(const int len);
void throwing_stick(const int len, const char dir, const int loop);

#endif