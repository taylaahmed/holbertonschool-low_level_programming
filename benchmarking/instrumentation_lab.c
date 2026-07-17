#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
    *state = (*state * 1103515245u) + 12345u;
    return *state;
}

static void build_dataset(void)
{
    unsigned int state;
    int i;

    state = SEED_VALUE;

    for (i = 0; i < DATASET_SIZE; i++)
        dataset[i] = (int)(next_value(&state) % 100000);
}

static void process_dataset(void)
{
    int i;
    int v;

    for (i = 0; i < DATASET_SIZE; i++)
    {
        v = dataset[i];
        v = (v * 3) + (v / 7) - (v % 11);
        if (v < 0)
            v = -v;
        dataset[i] = v;
    }
}

static unsigned long reduce_checksum(void)
{
    unsigned long sum;
    int i;

    sum = 0;
    for (i = 0; i < DATASET_SIZE; i++)
        sum = (sum * 131ul) + (unsigned long)dataset[i];

    return sum;
}

int main(void)
{
    unsigned long checksum;

    /* Students must add clock-based timing and print required lines. */
    clock_t start_total;
    clock_t end_total;
    clock_t start;
    clock_t end;
    double total;
    double data;
    double process;
    double reduce;

    start_total = clock();

    start = clock();
    build_dataset();
    end = clock();
    data = (double)(end - start) / (double)CLOCKS_PER_SEC;

    start = clock();
    process_dataset();
    end = clock();
    process = (double)(end - start) / (double)CLOCKS_PER_SEC;

    start = clock();
    checksum = reduce_checksum();
    end = clock();
    reduce = (double)(end - start) / (double)CLOCKS_PER_SEC;

    end_total = clock();
    total = (double)(end_total - start_total) / (double)CLOCKS_PER_SEC;
    

    if (checksum == 0ul)
        printf("impossible\n");

    /* Required output (exact format, no extra lines):
     * TOTAL seconds: <float>
     * BUILD_DATA seconds: <float>
     * PROCESS seconds: <float>
     * REDUCE seconds: <float>
     */

     printf("TOTAL seconds: %f\n", total);
     printf("BUILD_DATA seconds: %f\n", data);
     printf("PROCESS seconds: %f\n", process);
     printf("REDUCE seconds: %f\n", reduce);

    return 0;
}
