#ifndef BYTEBUFFER_H_
#define BYTEBUFFER_H_

//#include <exceptions/IllegalArgumentException.h>
//#include <exceptions/IndexOutOfBoundsException.h>
//#include <exceptions/BufferOverflowException.h>
//#include <exceptions/BufferUnderflowException.h>
#include "byteorder.h"

#include <QByteArray>

/**
 * A buffer for bytes.
 * <p>
 * A byte buffer can be created in either one of the following ways:
 * <ul>
 * <li>{@link #allocate(int) Allocate} a new byte array and create a buffer
 * based on it;</li>
 * <li>{@link #allocateDirect(int) Allocate} a memory block and create a direct
 * buffer based on it;</li>
 * <li>{@link #wrap(byte[]) Wrap} an existing byte array to create a new
 * buffer.</li>
 * </ul>
 *
 */
class ByteBuffer
{
public:
	/**
	 * Creates a byte buffer based on a newly allocated byte array.
	 *
	 * @param capacity
	 *            the capacity of the new buffer
	 * @return the created byte buffer.
	 * @throws IllegalArgumentException
	 *             if {@code capacity < 0}.
	 */
	static ByteBuffer* allocate(int capacity);

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
	static ByteBuffer* wrap(QByteArray* array, bool owner = false);

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
	static ByteBuffer* wrap(QByteArray* array, int start, int len);

	/**
	 * Constructs a {@code ByteBuffer} with given capacity.
	 *
	 * @param capacity
	 *            the capacity of the buffer.
	 */
	ByteBuffer(int capacity);

	/**
	 * Returns the byte array which this buffer is based on, if there is one.
	 *
	 * @return the byte array which this buffer is based on.
	 * @exception UnsupportedOperationException
	 *                if this buffer is not based on an array.
	 */
	QByteArray* array() const;

	/**
	 * Returns this buffer's position. </p>
	 *
	 * @return  The position of this buffer
	 */
	int position();

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
	ByteBuffer* position(int newPosition);

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
	int compareTo(ByteBuffer* otherBuffer);

	/**
	 * Returns the byte at the current position and increases the position by 1.
	 *
	 * @return the byte at the current position.
	 * @exception BufferUnderflowException
	 *                if the position is equal or greater than limit.
	 */
	char get();

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
	ByteBuffer* get(QByteArray* dest);

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
	ByteBuffer* get(QByteArray* dest, int off, int len);

	/**
	 * Returns the byte at the specified index and does not change the position.
	 *
	 * @param index
	 *            the index, must not be negative and less than limit.
	 * @return the byte at the specified index.
	 * @exception IndexOutOfBoundsException
	 *                if index is invalid.
	 */
	char get(int index);

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
	char getChar();

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
	char getChar(int index);

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
	double getDouble();

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
	double getDouble(int index);

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
	float getFloat();

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
	float getFloat(int index);

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
	int getInt();

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
	int getInt(int index);

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
	long long getLong();

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
	long long getLong(int index);

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
	short getShort();

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
	short getShort(int index);

	/**
	 * Calculates this buffer's hash code from the remaining chars. The
	 * position, limit, capacity and mark don't affect the hash code.
	 *
	 * @return the hash code calculated from the remaining bytes.
	 */
	int hashCode();

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
	ByteOrder::Endianness order();

	/**
	 * Sets the byte order of this buffer.
	 *
	 * @param byteOrder
	 *            the byte order to set. If {@code null} then the order
	 *            will be {@link ByteOrder#LITTLE_ENDIAN LITTLE_ENDIAN}.
	 * @return this buffer.
	 * @see ByteOrder
	 */
	ByteBuffer* order(ByteOrder::Endianness byteOrder);

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
	ByteBuffer* put(char b);

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
	ByteBuffer* put(QByteArray* src);

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
	ByteBuffer* put(QByteArray* src, int off, int len);

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
	ByteBuffer* put(ByteBuffer* src);

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
	ByteBuffer* put(int index, char b);

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
	ByteBuffer* putChar(char value);

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
	ByteBuffer* putChar(int index, char value);

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
	ByteBuffer* putDouble(double value);

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
	ByteBuffer* putDouble(int index, double value);

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
	ByteBuffer* putFloat(float value);

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
	ByteBuffer* putFloat(int index, float value);

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
	ByteBuffer* putInt(int value);

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
	ByteBuffer* putInt(int index, int value);

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
	ByteBuffer* putLong(long long value);

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
	ByteBuffer* putLong(int index, long long value);

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
	ByteBuffer* putShort(short value);

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
	ByteBuffer* putShort(int index, short value);

	/**
	 * Returns the number of elements between the current position and the
	 * limit. </p>
	 *
	 * @return  The number of elements remaining in this buffer
	 */
	int remaining();

	/**
	 *
	 */
	int capacity();

	/**
	 *
	 */
	void setOwner( bool owner );

	/**
	 *
	 */
	~ByteBuffer();

private:

	ByteBuffer(QByteArray* src, bool owner);

	/**
	 * The byte order of this buffer, default is {@code BIG_ENDIAN}.
	 */
	ByteOrder::Endianness mOrder;
	int mLimit;
	int mPosition;
	QByteArray* mArray;
	bool mOwner;
};

#endif /* BYTEBUFFER_H_ */
