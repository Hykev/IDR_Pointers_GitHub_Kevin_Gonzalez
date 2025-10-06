#include <stdint.h>

#define PERIPHERAL_BASE_ADDRESS   0x40000000U
#define AHB_BASE_ADDRESS          (PERIPHERAL_BASE_ADDRESS + 0x00020000U)

#define RCC_BASE_ADDRESS          (AHB_BASE_ADDRESS + 0x00001000U)
#define RCC_IOPENR_ADDRESS        (RCC_BASE_ADDRESS + 0x0000002CU)

#define IOPORT_BASE_ADDRESS       (PERIPHERAL_BASE_ADDRESS + 0x10000000U)

#define GPIOA_BASE_ADDRESS        (IOPORT_BASE_ADDRESS + 0x00000000U)
#define GPIOA_MODER_REG           (GPIOA_BASE_ADDRESS + 0x00000000U)
#define GPIOA_ODR_REG             (GPIOA_BASE_ADDRESS + 0x00000014U)

#define GPIOC_BASE_ADDRESS        (IOPORT_BASE_ADDRESS + 0x00000800U)
#define GPIOC_MODER_REG           (GPIOC_BASE_ADDRESS + 0x00000000U)
#define GPIOC_IDR_REG             (GPIOC_BASE_ADDRESS + 0x00000010U)

// boton PC13, Led PA5
int main(void)
{
    uint32_t *rcc_iopenr = RCC_IOPENR_ADDRESS;
    uint32_t *gpioa_moder = GPIOA_MODER_REG;
    uint32_t *gpioa_odr   = GPIOA_ODR_REG;

    uint32_t *gpioc_moder = GPIOC_MODER_REG;
    uint32_t *gpioc_idr   = GPIOC_IDR_REG;


    *rcc_iopenr |= 1 << 0;
    *rcc_iopenr |= 1 << 2;

    *gpioa_moder &= ~(1 << (11));

    *gpioc_moder &= ~(1 << (26));
    *gpioc_moder &= ~(1 << (27));

    while(1)
    {
        if ((*gpioc_idr & 0x2000)) // 0b0010 0000 0000 0000
        {
            *gpioa_odr &= ~(1 << 5); // apaga
        } else {
            *gpioa_odr |= 1 << 5; // enciende
        }
    }

}
