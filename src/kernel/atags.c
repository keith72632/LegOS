#include "../../includes/kernel/atags.h"

uint32_t get_mem_size(uint32_t mem_size)
{
    return 1024 * 1024 * mem_size;
}

/* FOR HARDWARE
uint32_t get_mem_size(atag_t * tag) {
   while (tag->tag != NONE) {
       if (tag->tag == MEM) {
           return tag->mem.size;
       }
       tag = ((uint32_t *)tag) + tag->tag_size;
   }
   return 0;

}
*/