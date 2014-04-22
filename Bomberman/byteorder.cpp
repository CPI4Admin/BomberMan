#include "byteorder.h"

ByteOrder::Endianness ByteOrder::endianness()
{
	union
	{
		int i;
		char b[sizeof(int)];
	} u;
	u.i = 0x01020304;
	return (u.b[0] == 0x01) ? BIG_ENDIAN : LITTLE_ENDIAN;
}
