/*Atags is a list of info about certain aspects of hardware. Created by bootloadeer before kernel
is loaded. Bootloader places it at 0x100, and also passes that address through the register r2. 
Atags can decipher how large memory is, where the bootloader put a ramdisk, what the serial number
of the board is, and the command line passed to the kernel via cmdline.txt. Atags consist of a 4 byte
word size, a tag id, and tag specifc info. Atags list always starts with CORE and ends with NONE, 
with the identifier 0x00. Tags are concatenated together, so the next tag in the list can be found 
by adding number of bytes specified by the size.*/

#include <stdint.h>
#ifndef ATAGS_H
#define ATAGS_H
typedef enum {
    NONE    = 0x00000000,
    CORE    = 0x54410001,
    MEM     = 0x54420005,
    INITRD2 = 0x54420005,
    CMDLINE = 0x54410009
} atag_tag_t;

typedef struct {
    uint32_t size;
    uint32_t start;
} mem_t;

typedef struct {
    uint32_t start;
    uint32_t size;
} initrd2_t;

typedef struct {
    char line[1];
} cmdline_t;

typedef struct atag {
    uint32_t tag_size;
    atag_tag_t tag;
    union {
        mem_t mem;
        initrd2_t initrd2;
        cmdline_t cmdline;
    };
} atag_t;

uint32_t get_mem_size(uint32_t mem_size);

/*FOR HARDWARE
uint32_t get_mem_size(atag_t * tag);
*/

#endif