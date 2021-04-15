#include <stdint.h>
#include "list.h"
#include "atags.h"
#ifndef MEM_H
#define MEM_H

/*  Wrangling Memory  */
/*Memory divided up into pages. Number of pages = total mem/page size*/
#define PAGE_SIZE 4096
#define KERNEL_HEAP_SIZE (1024*1024)

typedef struct {
    //essentially some booleans to declare wether page is allocated and if page is kernel
    uint8_t allocated          : 1;
    uint8_t kernel_page        : 1;
    uint8_t kernel_heap_page   : 1;	// This page is a part of the kernel
    uint32_t reserved          : 29;
} page_flags_t;

typedef struct page {
    uint32_t vaddr_mapped;
    page_flags_t flags;
    DEFINE_LINK(page);
} page_t;

typedef struct heap_segment{
    struct heap_segment * next;
    struct heap_segment * prev;
    uint32_t is_allocated;
    uint32_t segment_size;  // Includes this header
} heap_segment_t;


void mem_init();
void * alloc_page(void);
void free_page(void * ptr);
void * kmalloc(uint32_t bytes);
void kfree(void *ptr);

#endif