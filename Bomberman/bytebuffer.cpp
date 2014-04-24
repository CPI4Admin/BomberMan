#include "bytebuffer.h"
//#include "bmerrormanager.h"

ByteBuffer::ByteBuffer(QByteArray* src, bool owner) :
		mArray(src), mOrder(ByteOrder::BIG_ENDIAN), mLimit(src->size()), mPosition(0), mOwner(owner)
{
}

ByteBuffer::~ByteBuffer()
{
	if (mOwner == true)
		delete mArray;
}

/**
 * Creates a byte buffer based on a newly allocated byte array.
 *
 * @param capacity
 *            the capacity of the new buffer
 * @return the created byte buffer.
 * @throws IllegalArgumentException
 *             if {@code capacity < 0}.
 */
ByteBuffer* ByteBuffer::allocate(int capacity)
{
	if (capacity < 0)
	{
//		throw IllegalArgumentException();
	}
	return ByteBuffer::wrap(new QByteArray(capacity, 0), true);
}

/**
 * Creates a new byte buffer by wrapping the given byte array.
 * <p>
 * Calling this method has the same effect as
 * {@code wrap(array, 0, array.length)}.
 *
 * @param array
 *            the byte array which the new buffer will be based on
 * @return the created byte buffer.
 */
ByteBuffer* ByteBuffer::wrap(QByteArray* array, bool owner)
{
	return new ByteBuffer(array, owner);
}

/**
 * Creates a new byte buffer by wrapping the given byte array.
 * <p>
 * The new buffer's position will be {@code start}, limit will be
 * {@code start + len}, capacity will be the length of the array.
 *
 * @param array
 *            the byte array which the new buffer will be based on.
 * @param start
 *            the start index, must not be negative and not greater than
 *            {@code array.length}.
 * @param len
 *            the length, must not be negative and not greater than
 *            {@code array.length - start}.
 * @return the created byte buffer.
 * @exception IndexOutOfBoundsException
 *                if either {@code start} or {@code len} is invalid.
 */

ByteBuffer* ByteBuffer::wrap(QByteArray* array, int start, int len)
{
//	int length = array->size();
//	if ((start < 0) || (len < 0) || (start + len > length))
//		throw IndexOutOfBoundsException();

	ByteBuffer* buf = new ByteBuffer(array, false);
	buf->mPosition = start;
	buf->mLimit = start + len;

	return buf;
}

/**
 * Constructs a {@code ByteBuffer} with given capacity.
 *
 * @param capacity
 *            the capacity of the buffer.
 */
ByteBuffer::ByteBuffer(int capacity) :
		mArray(0), mOrder(ByteOrder::BIG_ENDIAN), mLimit(capacity), mPosition(0), mOwner(false)
{
}

/**
 * Returns the byte array which this buffer is based on, if there is one.
 *
 * @return the byte array which this buffer is based on.
 * @exception UnsupportedOperationException
 *                if this buffer is not based on an array.
 */
QByteArray* ByteBuffer::array() const
{
	return mArray;
}

/**
 * Returns this buffer's position. </p>
 *
 * @return  The position of this buffer
 */
int ByteBuffer::position()
{
	return mPosition;
}

/**
 *
 */
int ByteBuffer::capacity()
{
	return mLimit;
}

/**
 * Sets this buffer's position.  If the mark is defined and larger than the
 * new position then it is discarded. </p>
 *
 * @param  newPosition
 *         The new position value; must be non-negative
 *         and no larger than the current limit
 *
 * @return  This buffer
 *
 * @throws  IllegalArgumentException
 *          If the preconditions on <tt>newPosition</tt> do not hold
 */
ByteBuffer* ByteBuffer::position(int newPosition)
{
//	if ((newPosition > mLimit) || (newPosition < 0))
//		throw IllegalArgumentException();
	mPosition = newPosition;
	return this;
}

/**
 * Compares the remaining bytes of this buffer to another byte buffer's
 * remaining bytes.
 *
 * @param otherBuffer
 *            another byte buffer.
 * @return a negative value if this is less than {@code other}; 0 if this
 *         equals to {@code other}; a positive value if this is greater
 *         than {@code other}.
 * @exception ClassCastException
 *                if {@code other} is not a byte buffer.
 */
int ByteBuffer::compareTo(ByteBuffer* otherBuffer)
{
	int compareRemaining = (remaining() < otherBuffer->remaining()) ? remaining() : otherBuffer->remaining();
	int thisPos = mPosition;
	int otherPos = otherBuffer->mPosition;
	char thisByte, otherByte;
	while (compareRemaining > 0)
	{
		thisByte = get(thisPos);
		otherByte = otherBuffer->get(otherPos);
		if (thisByte != otherByte)
		{
			return thisByte < otherByte ? -1 : 1;
		}
		thisPos++;
		otherPos++;
		compareRemaining--;
	}
	return remaining() - otherBuffer->remaining();
}

/**
 * Returns the byte at the current position and increases the position by 1.
 *
 * @return the byte at the current position.
 * @exception BufferUnderflowException
 *                if the position is equal or greater than limit.
 */
char ByteBuffer::get()
{
	return (mArray->data()[mPosition++]);
}

/**
 * Reads bytes from the current position into the specified byte array and
 * increases the position by the number of bytes read.
 * <p>
 * Calling this method has the same effect as
 * {@code get(dest, 0, dest.length)}.
 *
 * @param dest
 *            the destination byte array.
 * @return this buffer.
 * @exception BufferUnderflowException
 *                if {@code dest.length} is greater than {@code remaining()}.
 */
ByteBuffer* ByteBuffer::get(QByteArray* dest)
{
	try
	{
		return get(dest, 0, dest->length());
    }
    catch (...)
    {
        return 0;
    }

/*    catch (const IndexOutOfBoundsException& e)
	{
        BmErrorManager::pushMessage(e.what(), BmErrorManager::DEBUG_MESSAGE);
        BmErrorManager::pushMessage(QString("ByteBuffer::get: IndexOutOfBoundsException"),
                BmErrorManager::DEBUG_MESSAGE);
		throw e;
    }
    catch (const BufferUnderflowException& e)
	{
        BmErrorManager::pushMessage(e.what(), BmErrorManager::DEBUG_MESSAGE);
        BmErrorManager::pushMessage(QString("ByteBuffer::get: BufferUnderflowException"),
                BmErrorManager::DEBUG_MESSAGE);
		throw e;
    }*/
}

/**
 * Reads bytes from the current position into the specified byte array,
 * starting at the specified offset, and increases the position by the
 * number of bytes read.
 *
 * @param dest
 *            the target byte array.
 * @param off
 *            the offset of the byte array, must not be negative and
 *            not greater than {@code dest.length}.
 * @param len
 *            the number of bytes to read, must not be negative and not
 *            greater than {@code dest.length - off}
 * @return this buffer.
 * @exception IndexOutOfBoundsException
 *                if either {@code off} or {@code len} is invalid.
 * @exception BufferUnderflowException
 *                if {@code len} is greater than {@code remaining()}.
 */
ByteBuffer* ByteBuffer::get(QByteArray* dest, int off, int len)
{
//	int length = dest->length();
//	if ((off < 0) || (len < 0) || (off + len > length))
//		throw IndexOutOfBoundsException();

//	if (len > remaining())
//		throw BufferUnderflowException();

	dest->insert(off, mArray->data() + mPosition, len);
	mPosition += len;
	return this;
}

/**
 * Returns the byte at the specified index and does not change the position.
 *
 * @param index
 *            the index, must not be negative and less than limit.
 * @return the byte at the specified index.
 * @exception IndexOutOfBoundsException
 *                if index is invalid.
 */
char ByteBuffer::get(int index)
{
	char* s = mArray->data();
	return s[index];
}

/**
 * Returns the char at the current position and increases the position by 2.
 * <p>
 * The 2 bytes starting at the current position are composed into a char
 * according to the current byte order and returned.
 *
 * @return the char at the current position.
 * @exception BufferUnderflowException
 *                if the position is greater than {@code limit - 2}.
 */
char ByteBuffer::getChar()
{
	return getChar(mPosition++);
}

/**
 * Returns the char at the specified index.
 * <p>
 * The 2 bytes starting from the specified index are composed into a char
 * according to the current byte order and returned. The position is not
 * changed.
 *
 * @param index
 *            the index, must not be negative and equal or less than
 *            {@code limit - 2}.
 * @return the char at the specified index.
 * @exception IndexOutOfBoundsException
 *                if {@code index} is invalid.
 */
char ByteBuffer::getChar(int index)
{
	return get(index);
}

/**
 * Returns the double at the current position and increases the position by
 * 8.
 * <p>
 * The 8 bytes starting from the current position are composed into a double
 * according to the current byte order and returned.
 *
 * @return the double at the current position.
 * @exception BufferUnderflowException
 *                if the position is greater than {@code limit - 8}.
 */
double ByteBuffer::getDouble()
{
	long long l = getLong();
	return *(double*) &l;
}

/**
 * Returns the double at the specified index.
 * <p>
 * The 8 bytes starting at the specified index are composed into a double
 * according to the current byte order and returned. The position is not
 * changed.
 *
 * @param index
 *            the index, must not be negative and equal or less than
 *            {@code limit - 8}.
 * @return the double at the specified index.
 * @exception IndexOutOfBoundsException
 *                if {@code index} is invalid.
 */
double ByteBuffer::getDouble(int index)
{
	long long l = getLong(index);
	return *(double*) &l;
}

/**
 * Returns the float at the current position and increases the position by
 * 4.
 * <p>
 * The 4 bytes starting at the current position are composed into a float
 * according to the current byte order and returned.
 *
 * @return the float at the current position.
 * @exception BufferUnderflowException
 *                if the position is greater than {@code limit - 4}.
 */
float ByteBuffer::getFloat()
{
	int i = getInt();
	return *(float*) &i;
}

/**
 * Returns the float at the specified index.
 * <p>
 * The 4 bytes starting at the specified index are composed into a float
 * according to the current byte order and returned. The position is not
 * changed.
 *
 * @param index
 *            the index, must not be negative and equal or less than
 *            {@code limit - 4}.
 * @return the float at the specified index.
 * @exception IndexOutOfBoundsException
 *                if {@code index} is invalid.
 */
float ByteBuffer::getFloat(int index)
{
	int i = getInt(index);
	return *(float*) &i;
}

/**
 * Returns the int at the current position and increases the position by 4.
 * <p>
 * The 4 bytes starting at the current position are composed into a int
 * according to the current byte order and returned.
 *
 * @return the int at the current position.
 * @exception BufferUnderflowException
 *                if the position is greater than {@code limit - 4}.
 */
int ByteBuffer::getInt()
{
	int pos = mPosition;
	mPosition += 4;
	return getInt(pos);
}

/**
 * Returns the int at the specified index.
 * <p>
 * The 4 bytes starting at the specified index are composed into a int
 * according to the current byte order and returned. The position is not
 * changed.
 *
 * @param index
 *            the index, must not be negative and equal or less than
 *            {@code limit - 4}.
 * @return the int at the specified index.
 * @exception IndexOutOfBoundsException
 *                if {@code index} is invalid.
 */
int ByteBuffer::getInt(int index)
{
	int data = *(int*) (mArray->data() + index);
	if (mOrder == ByteOrder::endianness())
		return data;
	else
		return ((((data) & 0xff000000) >> 24) | (((data) & 0x00ff0000) >> 8) | (((data) & 0x0000ff00) << 8)
				| (((data) & 0x000000ff) << 24));
}

/**
 * Returns the long at the current position and increases the position by 8.
 * <p>
 * The 8 bytes starting at the current position are composed into a long
 * according to the current byte order and returned.
 *
 * @return the long at the current position.
 * @exception BufferUnderflowException
 *                if the position is greater than {@code limit - 8}.
 */
long long ByteBuffer::getLong()
{
	int pos = mPosition;
	mPosition += 8;
	return getLong(pos);
}

/**
 * Returns the long at the specified index.
 * <p>
 * The 8 bytes starting at the specified index are composed into a long
 * according to the current byte order and returned. The position is not
 * changed.
 *
 * @param index
 *            the index, must not be negative and equal or less than
 *            {@code limit - 8}.
 * @return the long at the specified index.
 * @exception IndexOutOfBoundsException
 *                if {@code index} is invalid.
 */
long long ByteBuffer::getLong(int index)
{
	long long data = *(long long*) (mArray->data() + index);
	if (mOrder == ByteOrder::endianness())
		return data;
	else
		return ((((data) & 0xff00000000000000ull) >> 56) | (((data) & 0x00ff000000000000ull) >> 40)
				| (((data) & 0x0000ff0000000000ull) >> 24) | (((data) & 0x000000ff00000000ull) >> 8)
				| (((data) & 0x00000000ff000000ull) << 8) | (((data) & 0x0000000000ff0000ull) << 24)
				| (((data) & 0x000000000000ff00ull) << 40) | (((data) & 0x00000000000000ffull) << 56));
}

/**
 * Returns the short at the current position and increases the position by 2.
 * <p>
 * The 2 bytes starting at the current position are composed into a short
 * according to the current byte order and returned.
 *
 * @return the short at the current position.
 * @exception BufferUnderflowException
 *                if the position is greater than {@code limit - 2}.
 */
short ByteBuffer::getShort()
{
	int pos = mPosition;
	mPosition += 2;
	return getShort(pos);
}

/**
 * Returns the short at the specified index.
 * <p>
 * The 2 bytes starting at the specified index are composed into a short
 * according to the current byte order and returned. The position is not
 * changed.
 *
 * @param index
 *            the index, must not be negative and equal or less than
 *            {@code limit - 2}.
 * @return the short at the specified index.
 * @exception IndexOutOfBoundsException
 *                if {@code index} is invalid.
 */
short ByteBuffer::getShort(int index)
{
	short data = *(short*) (mArray->data() + index);
	if (mOrder == ByteOrder::endianness())
		return data;
	else
		return ((((data) >> 8) & 0xff) | (((data) & 0xff) << 8));
}

/**
 * Calculates this buffer's hash code from the remaining chars. The
 * position, limit, capacity and mark don't affect the hash code.
 *
 * @return the hash code calculated from the remaining bytes.
 */
int ByteBuffer::hashCode()
{
	int myPosition = mPosition;
	int hash = 0;
	while (myPosition < mLimit)
	{
		hash = hash + get(myPosition++);
	}
	return hash;
}

/**
 * Returns the byte order used by this buffer when converting bytes from/to
 * other primitive types.
 * <p>
 * The default byte order of byte buffer is always
 * {@link ByteOrder#BIG_ENDIAN BIG_ENDIAN}
 *
 * @return the byte order used by this buffer when converting bytes from/to
 *         other primitive types.
 */
ByteOrder::Endianness ByteBuffer::order()
{
	return mOrder;
}

/**
 * Sets the byte order of this buffer.
 *
 * @param byteOrder
 *            the byte order to set. If {@code null} then the order
 *            will be {@link ByteOrder#LITTLE_ENDIAN LITTLE_ENDIAN}.
 * @return this buffer.
 * @see ByteOrder
 */
ByteBuffer* ByteBuffer::order(ByteOrder::Endianness byteOrder)
{
	mOrder = byteOrder;
	return this;
}

/**
 * Writes the given byte to the current position and increases the position
 * by 1.
 *
 * @param b
 *            the byte to write.
 * @return this buffer.
 * @exception BufferOverflowException
 *                if position is equal or greater than limit.
 */
ByteBuffer* ByteBuffer::put(char b)
{
	mArray->insert(mPosition++, b);
	return this;
}

/**
 * Writes bytes in the given byte array to the current position and
 * increases the position by the number of bytes written.
 * <p>
 * Calling this method has the same effect as
 * {@code put(src, 0, src.length)}.
 *
 * @param src
 *            the source byte array.
 * @return this buffer.
 * @exception BufferOverflowException
 *                if {@code remaining()} is less than {@code src.length}.
 */
ByteBuffer* ByteBuffer::put(QByteArray* src)
{
	try
	{
		return put(src, 0, src->length());
    }
    catch(...)
    {
        return 0;
    }
/*
    catch (const IndexOutOfBoundsException& e)
	{
		DmErrorManager::pushMessage(e.what(), DmErrorManager::DEBUG_MESSAGE);
		DmErrorManager::pushMessage(QString("ByteBuffer::put: IndexOutOfBoundsException"),
				DmErrorManager::DEBUG_MESSAGE);
		throw e;
    }
    catch (const BufferUnderflowException& e)
	{
		DmErrorManager::pushMessage(e.what(), DmErrorManager::DEBUG_MESSAGE);
		DmErrorManager::pushMessage(QString("ByteBuffer::put: BufferUnderflowException"),
				DmErrorManager::DEBUG_MESSAGE);
		throw e;
    }*/
}

/**
 * Writes bytes in the given byte array, starting from the specified offset,
 * to the current position and increases the position by the number of bytes
 * written.
 *
 * @param src
 *            the source byte array.
 * @param off
 *            the offset of byte array, must not be negative and not greater
 *            than {@code src.length}.
 * @param len
 *            the number of bytes to write, must not be negative and not
 *            greater than {@code src.length - off}.
 * @return this buffer.
 * @exception BufferOverflowException
 *                if {@code remaining()} is less than {@code len}.
 * @exception IndexOutOfBoundsException
 *                if either {@code off} or {@code len} is invalid.
 */
ByteBuffer* ByteBuffer::put(QByteArray* src, int off, int len)
{
/*	int length = src->length();
	if ((off < 0) || (len < 0) || (off + len > length))
	{
		throw IndexOutOfBoundsException();
	}

	if (len > remaining())
	{
		throw BufferOverflowException();
    }*/

	mArray->insert(mPosition, src->data() + off, len);
	mPosition += len;
	return this;
}

/**
 * Writes all the remaining bytes of the {@code src} byte buffer to this
 * buffer's current position, and increases both buffers' position by the
 * number of bytes copied.
 *
 * @param src
 *            the source byte buffer.
 * @return this buffer.
 * @exception BufferOverflowException
 *                if {@code src.remaining()} is greater than this buffer's
 *                {@code remaining()}.
 * @exception IllegalArgumentException
 *                if {@code src} is this buffer.
 */
ByteBuffer * ByteBuffer::put(ByteBuffer * src)
{
/*	if (src == this)
	{
		throw IllegalArgumentException();
	}
	if (src->remaining() > remaining())
	{
		throw BufferOverflowException();
    }*/
	QByteArray* contents = new QByteArray(src->remaining(), 0);
	src->get(contents);
	put(contents);
	delete contents;
	return this;
}

/**
 * Write a byte to the specified index of this buffer without changing the
 * position.
 *
 * @param index
 *            the index, must not be negative and less than the limit.
 * @param b
 *            the byte to write.
 * @return this buffer.
 * @exception IndexOutOfBoundsException
 *                if {@code index} is invalid.
 */
ByteBuffer* ByteBuffer::put(int index, char b)
{
	mArray->insert(index, b);
	return this;
}

/**
 * Writes the given char to the current position and increases the position
 * by 2.
 * <p>
 * The char is converted to bytes using the current byte order.
 *
 * @param value
 *            the char to write.
 * @return this buffer.
 * @exception BufferOverflowException
 *                if position is greater than {@code limit - 2}.
 */
ByteBuffer* ByteBuffer::putChar(char value)
{
	return put(value);
}

/**
 * Writes the given char to the specified index of this buffer.
 * <p>
 * The char is converted to bytes using the current byte order. The position
 * is not changed.
 *
 * @param index
 *            the index, must not be negative and equal or less than
 *            {@code limit - 2}.
 * @param value
 *            the char to write.
 * @return this buffer.
 * @exception IndexOutOfBoundsException
 *                if {@code index} is invalid.
 */
ByteBuffer* ByteBuffer::putChar(int index, char value)
{
	return put(index, value);
}

/**
 * Writes the given double to the current position and increases the position
 * by 8.
 * <p>
 * The double is converted to bytes using the current byte order.
 *
 * @param value
 *            the double to write.
 * @return this buffer.
 * @exception BufferOverflowException
 *                if position is greater than {@code limit - 8}.
 */
ByteBuffer* ByteBuffer::putDouble(double value)
{
	return putLong(*(long long*) &value);
}

/**
 * Writes the given double to the specified index of this buffer.
 * <p>
 * The double is converted to bytes using the current byte order. The
 * position is not changed.
 *
 * @param index
 *            the index, must not be negative and equal or less than
 *            {@code limit - 8}.
 * @param value
 *            the double to write.
 * @return this buffer.
 * @exception IndexOutOfBoundsException
 *                if {@code index} is invalid.
 */
ByteBuffer* ByteBuffer::putDouble(int index, double value)
{
	return putLong(index, *(long long*) &value);
}

/**
 * Writes the given float to the current position and increases the position
 * by 4.
 * <p>
 * The float is converted to bytes using the current byte order.
 *
 * @param value
 *            the float to write.
 * @return this buffer.
 * @exception BufferOverflowException
 *                if position is greater than {@code limit - 4}.
 */
ByteBuffer* ByteBuffer::putFloat(float value)
{
	return putInt(*(int*) &value);
}

/**
 * Writes the given float to the specified index of this buffer.
 * <p>
 * The float is converted to bytes using the current byte order. The
 * position is not changed.
 *
 * @param index
 *            the index, must not be negative and equal or less than
 *            {@code limit - 4}.
 * @param value
 *            the float to write.
 * @return this buffer.
 * @exception IndexOutOfBoundsException
 *                if {@code index} is invalid.
 */
ByteBuffer* ByteBuffer::putFloat(int index, float value)
{
	return putInt(index, *(int*) &value);
}

/**
 * Writes the given int to the current position and increases the position by
 * 4.
 * <p>
 * The int is converted to bytes using the current byte order.
 *
 * @param value
 *            the int to write.
 * @return this buffer.
 * @exception BufferOverflowException
 *                if position is greater than {@code limit - 4}.
 */
ByteBuffer* ByteBuffer::putInt(int value)
{
	int pos = mPosition;
	mPosition += 4;
	return putInt(pos, value);
}

/**
 * Writes the given int to the specified index of this buffer.
 * <p>
 * The int is converted to bytes using the current byte order. The position
 * is not changed.
 *
 * @param index
 *            the index, must not be negative and equal or less than
 *            {@code limit - 4}.
 * @param value
 *            the int to write.
 * @return this buffer.
 * @exception IndexOutOfBoundsException
 *                if {@code index} is invalid.
 */
ByteBuffer* ByteBuffer::putInt(int index, int value)
{
	if (mOrder != ByteOrder::endianness())
	{
		value = ((((value) & 0xff000000) >> 24) | (((value) & 0x00ff0000) >> 8) | (((value) & 0x0000ff00) << 8)
				| (((value) & 0x000000ff) << 24));
	}
	(*(int*) (mArray->data() + index)) = value;
	return this;
}

/**
 * Writes the given long to the current position and increases the position
 * by 8.
 * <p>
 * The long is converted to bytes using the current byte order.
 *
 * @param value
 *            the long to write.
 * @return this buffer.
 * @exception BufferOverflowException
 *                if position is greater than {@code limit - 8}.
 */
ByteBuffer* ByteBuffer::putLong(long long value)
{
	int pos = mPosition;
	mPosition += 8;
	return putLong(pos, value);
}

/**
 * Writes the given long to the specified index of this buffer.
 * <p>
 * The long is converted to bytes using the current byte order. The position
 * is not changed.
 *
 * @param index
 *            the index, must not be negative and equal or less than
 *            {@code limit - 8}.
 * @param value
 *            the long to write.
 * @return this buffer.
 * @exception IndexOutOfBoundsException
 *                if {@code index} is invalid.
 */
ByteBuffer* ByteBuffer::putLong(int index, long long value)
{
	if (mOrder != ByteOrder::endianness())
	{
		value = ((((value) & 0xff00000000000000ull) >> 56) | (((value) & 0x00ff000000000000ull) >> 40)
				| (((value) & 0x0000ff0000000000ull) >> 24) | (((value) & 0x000000ff00000000ull) >> 8)
				| (((value) & 0x00000000ff000000ull) << 8) | (((value) & 0x0000000000ff0000ull) << 24)
				| (((value) & 0x000000000000ff00ull) << 40) | (((value) & 0x00000000000000ffull) << 56));
	}
	(*(long long*) (mArray->data() + index)) = value;
	return this;
}

/**
 * Writes the given short to the current position and increases the position
 * by 2.
 * <p>
 * The short is converted to bytes using the current byte order.
 *
 * @param value
 *            the short to write.
 * @return this buffer.
 * @exception BufferOverflowException
 *                if position is greater than {@code limit - 2}.
 */
ByteBuffer* ByteBuffer::putShort(short value)
{
	int pos = mPosition;
	mPosition += 2;
	return putShort(pos, value);
}

/**
 * Writes the given short to the specified index of this buffer.
 * <p>
 * The short is converted to bytes using the current byte order. The
 * position is not changed.
 *
 * @param index
 *            the index, must not be negative and equal or less than
 *            {@code limit - 2}.
 * @param value
 *            the short to write.
 * @return this buffer.
 * @exception IndexOutOfBoundsException
 *                if {@code index} is invalid.
 */
ByteBuffer* ByteBuffer::putShort(int index, short value)
{
	if (mOrder != ByteOrder::endianness())
	{
		value = ((((value) >> 8) & 0xff) | (((value) & 0xff) << 8));
	}
	(*(long long*) (mArray->data() + index)) = value;
	return this;
}

/**
 * Returns the number of elements between the current position and the
 * limit. </p>
 *
 * @return  The number of elements remaining in this buffer
 */
int ByteBuffer::remaining()
{
	return mLimit - mPosition;
}

/**
 *
 */
void ByteBuffer::setOwner( bool owner )
{
	mOwner = owner;
}

