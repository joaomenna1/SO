#ifndef FUNCTIONS_H
#define FUNCTIONS_H

float time_diff(struct timeval *start, struct timeval *end);
void access_pages(int num_pages, int num_iterations);

#endif