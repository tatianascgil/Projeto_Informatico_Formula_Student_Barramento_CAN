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

/*
 * Carlos Tojal e Guilherme Candido
 * FSIPLeiria | Formula Student Team
 */

#define DATASET_DURATION	60 // duration in seconds
#define DATASET_FILENAME	"teste.bin" // name of the generated file
#define CSV_FILENAME		"teste.csv"

#define MODULE_RATE		20 // rate in Hz

#define N_MODULES		2
#define N_MESSAGES		2

// each message on the file follows this structure
struct can_frame_t
{
    uint16_t id;
    uint8_t data[8];
};

// generate the 16-bit ID for a module message pair
uint16_t get_id_for_module_message(uint8_t module, uint8_t message)
{
    // 7 most significant bits for module id, following 4 for message id
    return module << 4 | message;
}

// write a 16-bit value in 2 bytes of an array
void put_data_in_two_bytes(uint16_t data, uint8_t *buffer)
{
    buffer[0] = data & 0xFF;
    buffer[1] = (data & 0xFF00) >> 8;
}

int main()
{

    char module_name[100];
    strcpy(module_name, "xpto");
    // current timestamp since start in milliseconds
    unsigned long cur_t_millis = 0;

    // pointer to struct array
    struct can_frame_t *data = NULL;
    size_t n_frames = 0; // number of elements in array

    // csv file pointer
    FILE *csv_fp;

    if((csv_fp = fopen(CSV_FILENAME, "w")) == NULL)
    {
        fprintf(stderr, "Error opening CSV file: %s\n", strerror(errno));
        return -1;
    }

    // seed random
    srand(time(NULL));

    // write the CSV headers
    fprintf(csv_fp, "Timestamp;Nome Modulo;ID; ");
    for(int i = 0; i < 4; i++)
    {
        fprintf(csv_fp, "Byte %d e %d;", i, i+1);
    }
    printf("\n");

    // fill the structure
    while(cur_t_millis <= DATASET_DURATION * 1000)
    {

        // iterate modules and messages
        for(uint8_t mod = 1; mod <= N_MODULES; mod++)
        {
            for(uint8_t mes = 1; mes <= N_MESSAGES; mes++)
            {
                if((data = realloc(data, ++n_frames * sizeof(struct can_frame_t))) == NULL)
                {
                    fprintf(stderr, "Error allocating frame: %s\n", strerror(errno));
                    return -1;
                }

                // get id for the module and message
                uint16_t id = get_id_for_module_message(mod, mes);

                data[n_frames-1].id = id;

                // temporary 16-bit value
                uint16_t value;
                switch(id)
                {
                // dynamics module data
                case 0x11:
                    strcpy(module_name, "Dynamics module data");


                    // bytes 0 and 1 - rear right wheel speed
                    value = rand() / RAND_MAX * 30001;
                    put_data_in_two_bytes(value, data[n_frames-1].data);

                    // bytes 2 and 3 - rear right suspension travel
                    value = rand() % 501;
                    put_data_in_two_bytes(value, data[n_frames-1].data+2);

                    // bytes 4 and 5 - real left wheel speed
                    value = rand() / RAND_MAX * 30001;
                    put_data_in_two_bytes(value, data[n_frames-1].data+4);

                    // bytes 6 and 7 - rear left suspension travel
                    value = rand() % 501;
                    put_data_in_two_bytes(value, data[n_frames-1].data+6);

                    break;

                // dynamics module sensor errors
                case 0x12:
                    strcpy(module_name, "Dynamics module sensor errors");
                    // all sensor errors are the same
                    for(uint8_t i = 0; i < 4; i++)
                    {
                        int err = rand() % 2;
                        put_data_in_two_bytes(err, data[n_frames-1].data+(i*2));
                    }
                    break;

                // thermal sensor module
                // 2 messages
                case 0x21:
                    strcpy(module_name, "Thermal sensor module");
                    for(uint8_t i = 0; i < 4; i++)
                    {
                        int value = rand() % 1000;
                        put_data_in_two_bytes(value, data[n_frames-1].data+(i*2));
                    }
                    break;
                case 0x22:
                    strcpy(module_name, "Thermal sensor module");
                    // range between 0 and 1000
                    for(uint8_t i = 0; i < 4; i++)
                    {
                        int value = rand() % 1000;
                        put_data_in_two_bytes(value, data[n_frames-1].data+(i*2));
                    }
                    break;
                default:
                    printf("Codigo invalido");
                }

                // write the time, frame id and 8 bytes
                /*printf("\n%.3f 0x%x", (float) cur_t_millis / 1000, data[n_frames-1].id);
                if(fprintf(csv_fp, "\n%.3f;0x%x", (float) cur_t_millis / 1000, data[n_frames-1].id) < 0) {
                	fprintf(stderr, "Error writing CSV header: %s\n", strerror(errno));
                	return -2;
                }
                for(uint8_t i = 0; i < 8; i++) {
                	printf(";%d", data[n_frames-1].data[i]);
                	if(fprintf(csv_fp, ";%d", data[n_frames-1].data[i]) < 0) {
                		fprintf(stderr, "Error writing CSV record data: %s\n", strerror(errno));
                		return -3;
                	}
                }
                */

                // write the time, frame id and 8 bytes

                printf("\n%.3f %s : 0x%x", (float) cur_t_millis / 1000, module_name, data[n_frames-1].id);


                if(fprintf(csv_fp, "\n%.3f; %s; 0x%x", (float) cur_t_millis / 1000, module_name, data[n_frames-1].id) < 0)
                {
                    fprintf(stderr, "Error writing CSV header: %s\n", strerror(errno));
                    return -2;
                }
                for(uint8_t i = 0; i < 8; i += 2)
                {
                    printf(";%02d%02d", data[n_frames-1].data[i], data[n_frames-1].data[i+1]);
                    if(fprintf(csv_fp, ";%02d%02d", data[n_frames-1].data[i], data[n_frames-1].data[i+1]) < 0)
                    {
                        fprintf(stderr, "Error writing CSV record data: %s\n", strerror(errno));
                        return -3;
                    }
                }
            }
        }

        cur_t_millis += (double) 1 / MODULE_RATE * 1000;
    }

    // close the CSV file descriptor
    if(fclose(csv_fp) == EOF)
    {
        fprintf(stderr, "Error closing the CSV file: %s\n", strerror(errno));
        return -5;
    }

    // output file descriptor
    int fd;

    // open file
    if((fd = open(DATASET_FILENAME, O_CREAT | O_WRONLY | O_TRUNC)) < 0)
    {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return -2;
    }

    // save the data
    if(write(fd, data, n_frames * sizeof(struct can_frame_t)) < 0)
    {
        fprintf(stderr, "Error writing data: %s\n", strerror(errno));
        return -3;
    }

    // close the file
    if(close(fd) < 0)
    {
        fprintf(stderr, "Error closing file: %s\n", strerror(errno));
        return -4;
    }

    // free the buffer
    free(data);

    return 0;
}

