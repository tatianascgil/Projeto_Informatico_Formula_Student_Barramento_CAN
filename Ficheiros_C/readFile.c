#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>

#define DATASET_DURATION	60 // duration in seconds
#define DATASET_FILENAME	"tati.bin" // name of the generated file
#define CSV_FILENAME		"tati.csv"

#define MODULE_RATE		20 // rate in Hz

#define N_MODULES		2
#define N_MESSAGES		2

int main() {
    FILE *csv_fp;
    FILE *bin_fp;
    char buffer[1024];

    csv_fp = fopen(CSV_FILENAME, "r");
    if (csv_fp == NULL) {
        printf("Error: unable to open file.\n");
        return 1;
    }

    bin_fp = fopen(DATASET_FILENAME, "rb");
    if (bin_fp == NULL) {
        printf("Error: unable to open file.\n");
        return 2;
    }

    while (fgets(buffer, 1024, csv_fp)) {
        printf("%s", buffer);
    }
    while (fgets(buffer, 1024, bin_fp)) {
        printf("%s", buffer);
    }

    fclose(csv_fp);
    fclose(bin_fp);
    return 0;
}




