MEMORY
{
    FLASH (rx) : ORIGIN = 0x00080000, LENGTH = 32K
    RAM (rwx) :  ORIGIN = 0x20000000, LENGTH = 96K
}

SECTIONS
{
    .isr_vector:
    {
        KEEP(*(.isr_vector))
    } > FLASH

    .text : 
    {
        *(.text*)
    } > FLASH

    .data : 
    {
        *(.data*)
    } > RAM AT > FLASH

    .bss : 
    {
        *(.bss*)
    } > RAM
}