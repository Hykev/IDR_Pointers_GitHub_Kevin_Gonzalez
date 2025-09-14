#include <stdint.h>

/* PERIPHERAL & BUS BASE ADDRESS */
#define PERIPHERAL_BASE_ADDRESS   0x40000000U
#define AHB_BASE_ADDRESS          (PERIPHERAL_BASE_ADDRESS + 0x00020000U)

/* RCC BASE ADDRESS */
#define RCC_BASE_ADDRESS          (AHB_BASE_ADDRESS + 0x00001000U)
#define RCC_IOPENR_ADDRESS        (RCC_BASE_ADDRESS + 0x0000002CU)

/* IOPORT BASE ADDRESS */
#define IOPORT_BASE_ADDRESS       (PERIPHERAL_BASE_ADDRESS + 0x10000000U)

/* GPIOA BASE & SPECIFIC ADDRESS */
#define GPIOA_BASE_ADDRESS        (IOPORT_BASE_ADDRESS + 0x00000000U)
#define GPIOA_MODER_REG           (GPIOA_BASE_ADDRESS + 0x00000000U)
#define GPIOA_ODR_REG             (GPIOA_BASE_ADDRESS + 0x00000014U)

/* GPIOC BASE & SPECIFIC ADDRESS */
#define GPIOC_BASE_ADDRESS        (IOPORT_BASE_ADDRESS + 0x00000800U)
#define GPIOC_MODER_REG           (GPIOC_BASE_ADDRESS + 0x00000000U)
#define GPIOC_IDR_REG             (GPIOC_BASE_ADDRESS + 0x00000010U)
#define GPIOC_ODR_REG             (GPIOC_BASE_ADDRESS + 0x00000014U)


int main(void)
{
    uint32_t *rcc_iopenr = RCC_IOPENR_ADDRESS;   // Pointer variable to RCC, IOPENR register
    uint32_t *gpioa_moder = GPIOA_MODER_REG;     // Pointer variable to GPIOA, MODER register
    uint32_t *gpioa_odr   = GPIOA_ODR_REG;       // Pointer variable to GPIOA, ODR register

    uint32_t *gpioc_moder = GPIOC_MODER_REG;     // Pointer variable to GPIOA, MODER register
    uint32_t *gpioc_idr   = GPIOC_IDR_REG;       // Pointer variable to GPIOA, ODR register

    // Enable clock for GPIOA
    *rcc_iopenr |= 1 << 0;
    // Enable clock for GPIOC
    *rcc_iopenr |= 1 << 2;

    // GPIOA5 as output
    *gpioa_moder &= ~(1 << (11));

    // GPIOC13 as input
    *gpioc_moder &= ~(1 << (26));
    *gpioc_moder &= ~(1 << (27));

    while(1)
    {
        if ((*gpioc_idr & 0x2000))
        {
            *gpioa_odr &= ~(1 << 5);   // Clear pin A5
        } else {
            *gpioa_odr |= 1 << 5;      // Set pin A5
        }              
    }

}
