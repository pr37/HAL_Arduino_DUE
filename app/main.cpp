#include <stdint.h>

#define LED_PIN 27
#define PIOA_BASE 0x400E0E00U

#define PIO_PER_OFFSET 0x00U
#define PIO_OER_OFFSET 0x10U
#define PIO_SODR_OFFSET 0x30U
#define PIO_CODR_OFFSET 0x34U

#define PIO_PER (*(volatile uint32_t *)(PIOA_BASE + PIO_PER_OFFSET))
#define PIO_OER (*(volatile uint32_t *)(PIOA_BASE + PIO_OER_OFFSET))
#define PIO_SODR (*(volatile uint32_t *)(PIOA_BASE + PIO_SODR_OFFSET))
#define PIO_CODR (*(volatile uint32_t *)(PIOA_BASE + PIO_CODR_OFFSET))

void delay(volatile uint32_t t) {
    while(t--) {__asm volatile("nop");}
}

extern "C" void main() {
    PIO_PER |= (1 << LED_PIN);
    PIO_OER |= (1 << LED_PIN);

    while (1) {
        PIO_SODR = (1 << LED_PIN);
        delay(1000000);
        PIO_CODR = (1 << LED_PIN);
        delay(1000000);
    }
}
