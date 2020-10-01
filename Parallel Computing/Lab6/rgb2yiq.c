#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
#define IMG_SIZE 300*300
int main()
{
struct timeval TimeValue_Start;
struct timezone TimeZone_Start;
struct timeval TimeValue_Final;
struct timezone TimeZone_Final;
long time_start, time_end;
double time_overhead;
char filename[100];
printf("Enter the name of the file containing the pixel values: ");
scanf("%s", filename);
FILE* finp = fopen(filename, "r");
if (!finp)
{
printf("Error while opening input file!\n");
exit(0);
}
int R[IMG_SIZE], G[IMG_SIZE], B[IMG_SIZE];int a = 0, tmp;
while (!feof(finp) && a < IMG_SIZE)
{
fscanf(finp, "%d", &tmp);
R[a] = tmp;
fscanf(finp, "%d", &tmp);
G[a] = tmp;
fscanf(finp, "%d", &tmp);
B[a] = tmp;
printf("RGB from Input: %d %d %d\n", R[a], G[a], B[a]);
a++;
}
fclose(finp);
int Y[IMG_SIZE], I[IMG_SIZE], Q[IMG_SIZE];
gettimeofday(&TimeValue_Start, &TimeZone_Start);
for (int a = 0; a < IMG_SIZE; a++)
{
Y[a] = 0.299*R[a] + 0.587*G[a] + 0.114*B[a];
I[a] = 0.596*R[a] - 0.275*G[a] - 0.321*B[a];
Q[a] = 0.212*R[a] - 0.523*G[a] + 0.311*B[a];
}
gettimeofday(&TimeValue_Final, &TimeZone_Final);
time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
time_overhead = (time_end - time_start)/1000000.0;
double SEQ = time_overhead;
gettimeofday(&TimeValue_Start, &TimeZone_Start);
#pragma omp parallel num_threads(2)
{
#pragma omp for
for (int a = 0; a < IMG_SIZE; a++)
{
Y[a] = 0.299*R[a] + 0.587*G[a] + 0.114*B[a];
I[a] = 0.596*R[a] - 0.275*G[a] - 0.321*B[a];
Q[a] = 0.212*R[a] - 0.523*G[a] + 0.311*B[a];
}
}
gettimeofday(&TimeValue_Final, &TimeZone_Final);
time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
time_overhead = (time_end - time_start)/1000000.0;
double PAR2 = time_overhead;gettimeofday(&TimeValue_Start, &TimeZone_Start);
#pragma omp parallel num_threads(4)
{
#pragma omp for
for (int a = 0; a < IMG_SIZE; a++)
{
Y[a] = 0.299*R[a] + 0.587*G[a] + 0.114*B[a];
I[a] = 0.596*R[a] - 0.275*G[a] - 0.321*B[a];
Q[a] = 0.212*R[a] - 0.523*G[a] + 0.311*B[a];
}
}
gettimeofday(&TimeValue_Final, &TimeZone_Final);
time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
time_overhead = (time_end - time_start)/1000000.0;
double PAR4 = time_overhead;
gettimeofday(&TimeValue_Start, &TimeZone_Start);
#pragma omp parallel num_threads(8)
{
#pragma omp for
for (int a = 0; a < IMG_SIZE; a++)
{
Y[a] = 0.299*R[a] + 0.587*G[a] + 0.114*B[a];
I[a] = 0.596*R[a] - 0.275*G[a] - 0.321*B[a];
Q[a] = 0.212*R[a] - 0.523*G[a] + 0.311*B[a];
}
}
gettimeofday(&TimeValue_Final, &TimeZone_Final);
time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
time_overhead = (time_end - time_start)/1000000.0;
double PAR8 = time_overhead;
gettimeofday(&TimeValue_Start, &TimeZone_Start);
#pragma omp parallel num_threads(16)
{
#pragma omp for
for (int a = 0; a < IMG_SIZE; a++)
{
Y[a] = 0.299*R[a] + 0.587*G[a] + 0.114*B[a];
I[a] = 0.596*R[a] - 0.275*G[a] - 0.321*B[a];
Q[a] = 0.212*R[a] - 0.523*G[a] + 0.311*B[a];
}
}
gettimeofday(&TimeValue_Final, &TimeZone_Final);
time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
time_overhead = (time_end - time_start)/1000000.0;
double PAR16 = time_overhead;FILE* fout = fopen("YIQ.txt", "w");
if (!fout)
{
printf("Error while opening output file!\n");
exit(0);
}
for (int a = 0; a < IMG_SIZE; a++)
{
printf("YIQ to Output: %d %d %d\n", Y[a], I[a], Q[a]);
fprintf(fout, "%d %d %d ", Y[a], I[a], Q[a]);
}
fclose(fout);
printf("\nTIME TAKEN FOR SEQUENTIAL CONVERSION: %lf\n", SEQ);
printf("TIME TAKEN FOR PARALLEL CONVERSION (2 Threads): %lf\n",PAR2);
printf("TIME TAKEN FOR PARALLEL CONVERSION (4 Threads): %lf\n",PAR4);
printf("TIME TAKEN FOR PARALLEL CONVERSION (8 Threads): %lf\n",PAR8);
printf("TIME TAKEN FOR PARALLEL CONVERSION (16 Threads): %lf\n",PAR16);
}