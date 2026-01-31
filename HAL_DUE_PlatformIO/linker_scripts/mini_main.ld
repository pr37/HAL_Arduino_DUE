MEMORY
{
    FLASH (rx) : ORIGIN = 0x00088000, LENGTH = 480K
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