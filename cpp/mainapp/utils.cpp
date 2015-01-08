#include "utils.h"

void Utils::setBit(uint32_t& value,BYTE offset,bool isset)
{
	CHECKVALID( offset < BIT_MAX );
	uint32_t mask = 0x1 << offset;
	IF( isset )
		value |= mask;
	ELSE
		value &= ~mask;
	ENDIF
}

void Utils::setBit(uint32_t& value,BYTE offsetstart,BYTE offsetfinish,uint32_t countervalue)
{
	CHECKVALID( offsetfinish <= BIT_MAX && offsetfinish > offsetstart );
	uint32_t dstmask = (0xffffffff >> offsetstart << offsetstart ) << (BIT_MAX-offsetfinish) >> (BIT_MAX-offsetfinish);
	countervalue = ( countervalue << offsetstart ) & dstmask;
	value = value & (~dstmask) | countervalue;
}

bool Utils::getBit(uint32_t value,BYTE offset)
{
	CHECKVALIDRETURN( offset < BIT_MAX, false );
	uint32_t mask = 0x1 << offset;
	return value & mask ? true:false;
}

uint32_t Utils::getBit(uint32_t value,BYTE offsetstart,BYTE offsetfinish)
{
	CHECKVALIDRETURN( offsetfinish <= BIT_MAX && offsetfinish > offsetstart , 0 );
	uint32_t dstmask = (0xffffffff >> offsetstart << offsetstart ) << (BIT_MAX-offsetfinish) >> (BIT_MAX-offsetfinish);
	return (dstmask & value) >> offsetstart;
}