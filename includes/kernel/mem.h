#include <stdint.h>
#include "list.h"
#include "atags.h"
#ifndef MEM_H
#define MEM_H

/*  Wrangling Memory  */
/*Memory divided up into pages. Number of pages = total mem/page size*/

typedef struct {
    //essentially some booleans to declare wether page is allocated and if page is kernel
    uint8_t allocated    : 1;
    uint8_t kernel_page  : 1;
    uint32_t reserved    : 30;
} page_flags_t;

typedef struct page {
    uint32_t vaddr_mapped;
    page_flags_t flags;
    DEFINE_LINK(page);
} page_t;

void mem_init();
void * alloc_page(void);
void free_page(void * ptr);

#endif