#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

int main(int argc, char **argv) {
    assert(argc > 1);
    size_t bytes = atoi(argv[1]) * (1000 * 1000);
    uint8_t *data = (uint8_t *) malloc(bytes);
    while (true) {
        for (size_t i = 0; i < bytes; i++) {
            data[i] = 0xF1;
        }
    }
    return 0;
}
