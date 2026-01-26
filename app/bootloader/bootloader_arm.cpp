#include <stdint.h>

#define APP_START_ADDR 0x8000

typedef void (*app_entry_fp)(void);

//extern "C" to tell the linker to not mangle the function name
extern "C" void Reset_Handler() {
    uint32_t *vector_table = (uint32_t*)APP_START_ADDR;
    uint32_t stack_pointer = vector_table[0];
    uint32_t reset_handler = vector_table[1];

    //msr - move to special register
    //msp - stack pointer
    //%0 - place holder, will be replaced by our stack pointer
    //asm volatile("assembly code" : output ops : input ops : clobbered registers)
    //"r"(stack_pointer) - use any general-purpose register r0-r12 to hold our stack pointer
    __asm volatile("msr msp, %0" : : "r"(stack_pointer) : );

    //now jump to app reset handler in the vector table
    app_entry_fp app = (app_entry_fp)reset_handler;
    app();

    while(1); //never return
}