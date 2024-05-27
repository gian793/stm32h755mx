#include "CppUTest/TestHarness.h"

#include <iostream>
#include <cstring>

/*---------------------------------------------------------------------------*/

#define CORE_CM7

/*---------------------------------------------------------------------------*/

extern "C"
{
	/*
	 * Add your c-only include files here
	 */
	//#include "stm32_lock.h"
	//#include "stm32h7xx_hal_uart.h"
}

#include <stdio.h>
#include <stdlib.h>

#include "mockPrintOut.h"
#include "mxLog.h"

/*---------------------------------------------------------------------------*/
		
TEST_GROUP( fLog )
{
    void setup()
    {	
		MemoryLeakWarningPlugin::saveAndDisableNewDeleteOverloads();
    }

    void teardown()
    {
		MemoryLeakWarningPlugin::restoreNewDeleteOverloads();
    }
};


TEST( fLog, fPositionGet )
{
	/*--------- Data ----------*/

	const char str1[] = "this is the 1st string";
    const char str2[] = "%this is the 2nd string";
	const char str3[] = "t%his is the 3rd string";
	const char str4[] = "  % this is the 4th string";
	const char str5[] = "this is the 5th string%";
	const char str6[] = "this is the 5th stri % ";
	const char str7[] = "Wrong %p format";

	
	/*------- Sequence --------*/
	
	CHECK_EQUAL( -1, fPositionGet(str1) );
	CHECK_EQUAL( 0, fPositionGet(str2) );
	CHECK_EQUAL( 1, fPositionGet(str3) );
	CHECK_EQUAL( 2, fPositionGet(str4) );
	CHECK_EQUAL( strlen(str5)-1, fPositionGet(str5) );
	CHECK_EQUAL( strlen(str6)-2, fPositionGet(str6) );
	CHECK_EQUAL( 6, fPositionGet(str7) );
}

TEST( fLog, fFormatGet )
{
	/*--------- Data ----------*/

	const char str1[] = "1st string";
	const char str2[] = "2nd %u string";
	const char str3[] = "%X 3rd string";
	const char str4[] = "4th string%s";
	const char str5[] = "5th string%p";		/* Invalid format. */
	const char str6[] = "6th %T string";	/* Invalid format. */
	
	/*------- Sequence --------*/

	CHECK_EQUAL( '0', fFormatGet(str1) );
	CHECK_EQUAL( 'u', fFormatGet(str2) );
	CHECK_EQUAL( 'X', fFormatGet(str3) );
	CHECK_EQUAL( 's', fFormatGet(str4) );
	CHECK_EQUAL( '0', fFormatGet(str5) );
	CHECK_EQUAL( '0', fFormatGet(str6) );
}


TEST( fLog, init_no_format )
{
	/*--------- Data ----------*/
	fLog log{"Hello world"};
	
	/*------- Sequence --------*/

	CHECK_EQUAL( 0, strcmp( log.fData.pStr, "Hello world") );
	CHECK_EQUAL( -1, log.fData.pos );
	CHECK_EQUAL( '0', log.fData.format );
}

TEST( fLog, init_wrong_format )
{
	/*--------- Data ----------*/
	fLog log{"Wrong %p format"};
	
	/*------- Sequence --------*/

	CHECK_EQUAL( 6, log.fData.pos ); 
	CHECK_EQUAL( '0', log.fData.format );
	CHECK_EQUAL( 0, strcmp(log.fData.pStr, "Wrong %p format") );
}

TEST( fLog, init_noformat )
{
	/*--------- Data ----------*/
	//constexpr char str[]{"1st string"};
	fLog log{"1st string"};
	
	/*------- Sequence --------*/

	//CHECK_EQUAL( -1, log.fData.pos ); 
	CHECK_EQUAL( '0', log.fData.format );
	//CHECK_EQUAL( 0, strcmp(log.fData.pStr, str) );
}

/*---------------------------------------------------------------------------*/

TEST_GROUP( mxLog )
{
	static constexpr size_t buf_SIZE = 64;

	UART_HandleTypeDef huart1;

	char logBuf[ buf_SIZE ] = {0};

	mxLog M7LOG{ logBuf, buf_SIZE, huart1 };

    mockPrintOut mockUart{ halUartMock_GetBuf() , UART_MOCK_BUF_SIZE };

    void setup()
    {
		M7LOG.reset();

        mockUart.reset();

        MemoryLeakWarningPlugin::saveAndDisableNewDeleteOverloads();
    }

    void teardown()
    {
        MemoryLeakWarningPlugin::restoreNewDeleteOverloads();
    }
};

TEST( mxLog, init )
{
    CHECK_TRUE( M7LOG.isEmpty() );
	CHECK_FALSE( M7LOG.isFull() );
	CHECK_EQUAL( buf_SIZE, M7LOG.capacity() );
	CHECK_EQUAL( 0, M7LOG.size() );
}

TEST( mxLog, simpleMsg1 )
{
    /*--------- Data ----------*/

	M7LOG.Info( "Simple string1" );

    /*------- Sequence --------*/

    CHECK_FALSE( M7LOG.isEmpty() );
}

TEST( mxLog, simpleStr2 )
{
    /*--------- Data ----------*/

    static constexpr char testStr1[]{"This is a test string"};

	M7LOG.Info( testStr1 );

    M7LOG.taskManager();

    /*------- Sequence --------*/

    CHECK_TRUE( mockUart.check( testStr1 ) );
}

/*---------------------------------------------------------------------------*/
