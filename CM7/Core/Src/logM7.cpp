/**
 * \file            logM7.cpp
 * \brief           log task.
 * \author          g.marcolin
 */

#include <array>
#include <complex>
#include <ctime>
#include <concepts>
#include <mutex>
#include <memory>
#include <cstddef>
#include <cstring>

#include "cmsis_os.h"
#include "mxLog.h"
#include "logM7.h"

/*---------------------------------------------------------------------------*/

extern "C" [[noreturn]] void vLogM7Task( void* pArgument );

/*---------------------------------------------------------------------------*/

extern UART_HandleTypeDef huart1;

extern TIM_HandleTypeDef htim2;

/*---------------------------------------------------------------------------*/

#define printTest_PERIOD_MS                         ( 1000 )

/*---------------------------------------------------------------------------*/

extern UART_HandleTypeDef huart1;

/*---------------------------------------------------------------------------*/

constexpr size_t logBuf_SIZE = 1024;

char logBuf[ logBuf_SIZE ] = {0};

mxLog M7LOG{ logBuf, logBuf_SIZE, huart1 };

/*---------------------------------------------------------------------------*/

constexpr char testStr1[]{"This is a new test %d with a tail-1"};

constexpr char testStrStr[]{"Third test {%s} with a inner string"};

int32_t pi1Int32 = 2255;

int32_t pi2Int32 = 3389;

void logTest( void )
{
    static constexpr char testStr2[]{"Another test %d is now-2"};
    static constexpr char testStr3[]{"Test with NO parameter"};

    int32_t parInt32 = 45;
    uint32_t parUint32 = 43;
    float parFloat = 0.2347263;
    double parDouble = 23.876;

    //M7LOG.Info( testStr1, &par );
    M7LOG.Info( testStrStr, "Inner string333" );

    M7LOG.Info( "\n\r" );
    M7LOG.Info( "String5" );

    M7LOG.Info( "\n\r" );
    M7LOG.Info( "String6 with par = %d and tail", parInt32 );

    M7LOG.Info( "\n\r");
    M7LOG.Info( testStr1, pi1Int32 );

    M7LOG.Info( "\n\r");
    M7LOG.Info( testStr2, pi2Int32 );

    M7LOG.Info( "\n\r" );
    M7LOG.Info( "String7 with par = 0x%x", parUint32 );

    M7LOG.Info( "\n\r");
    M7LOG.Info( testStr3 );

    M7LOG.Info( "\n\r" );
    M7LOG.Info( "String8 with par = %f and tail", parFloat );

    M7LOG.Info( "\n\r" );
    M7LOG.Info( "String9 with double par = %g and tail", parDouble );

//    M7LOG.Info( "This is a new test %d with a tail", NULL );
}

/*---------------------------------------------------------------------------*/

static bool printTrigger = false;
uint32_t prIdx = 0;

static uint32_t prevTim2 = 0;
static uint32_t diff = 0;

void vLogM7Task( void* pArgument )
{
//    static constexpr time_t todayUnix_TIME  = 1697950558;
    static uint32_t prevTick = 0;

    logTest();

    M7LOG.Info( "\n\r", nullptr );

    while(1)
    {
        uint32_t tick = HAL_GetTick();

        if( ( tick - prevTick ) > pdMS_TO_TICKS( printTest_PERIOD_MS ) )
        {
            prevTick = tick;

            /*----------------------------------*/
//            static time_t time = todayUnix_TIME;
//
//            ++time;
//
//            struct tm* pTimeInfo = localtime (&time);
//
//            char timeBuf[64] = {0};
//
//            strftime( timeBuf, sizeof( timeBuf ), "\n\rTime -> %a %Y-%m-%d %H:%M:%S", pTimeInfo );
//
            /*----------------------------------*/
        }

        M7LOG.taskManager();

        taskENTER_CRITICAL();

        prevTim2 = htim2.Instance->CNT;

        osDelay( pdMS_TO_TICKS( 50 ) );

        diff = htim2.Instance->CNT - prevTim2;

        taskEXIT_CRITICAL();

        if( printTrigger )
        {
            printTrigger = false;

            ++prIdx;

            M7LOG.Info( "\n\r", nullptr );
            M7LOG.Info( "Print idx: %u triggered", prIdx );
        }
    }
}

/*---------------------------------------------------------------------------*/
