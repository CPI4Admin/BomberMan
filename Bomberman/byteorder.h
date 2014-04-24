#ifndef BYTEORDER_H_
#define BYTEORDER_H_

class ByteOrder
{
public:
	enum Endianness
	{
		BIG_ENDIAN, LITTLE_ENDIAN
	};

	static Endianness endianness();
};
#endif
