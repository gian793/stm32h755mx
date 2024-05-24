#include <stdint.h>
#include <stddef.h>
#include "stm32h7xx_hal_uart.h"

static char printOutMockBuf[ UART_MOCK_BUF_SIZE ] = {0};
uint32_t mockBufIndex = 0;

/**
  * @brief Return the mock print out buffer
  */


char* halUartMock_GetBuf( void )
{
    return printOutMockBuf;
}

/**
  * @brief Fake for HAL_UART_Transmit
  */

// HAL_StatusTypeDef 
HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    uint8_t* pDst = (uint8_t*)&printOutMockBuf[ mockBufIndex ];

    while( Size-- > 0 )
    {
        *pDst = *pData;

        ++pDst;
        ++pData;
        ++mockBufIndex;
    }

    return HAL_OK;
}
