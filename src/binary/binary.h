/*****************************************************************************
 * 
 * Copyright 2012 
 * LE ROUX Thomas <thomas@november-eleven.fr>
 * LOR Jérémy <jeremyk.lor@gmail.com>
 * 
 * This file is part of the Algorithm Project : Compression.
 * 
 * Compression is free software: you can redistribute it and/or modify
 * it under the terms of the zlib license. See the COPYING file.
 * 
 *****************************************************************************/

#ifndef BINARY_H
#define BINARY_H

/**
 * Display the integer into a binary. 
 *
 * @param n 
 *		The unsigned int.
 */
void displayBinary(unsigned int n);

/**
 * To get the number of Bytes to use for the integer.
 *
 * @param n
 *		An unsigned integer.
 * @return The number of Bytes we must use.
 */
int getNbOctet(unsigned int nbr);

/**
 * Put a character.
 *
 * @param c
 *		An integer
 * @return The return of the function write.
 */
int putBinary(int c);

/**
 * Display the integer into a byte (FR:octet).
 *
 * @param n
 *		A char.
 */
void displayByte(char n);

/**
 * Display the integer into bytes (FR:octets).
 *
 * @param n
 *		An unsigned integer.
 */
void displayValue(unsigned int n);

/**
 * Transform the integer by packets of 7 bits, the eighth is used to 
 * indicate if the writing continues on the next byte.
 *
 * @param n
 *		An unsigned integer.
 * @return The array of Bytes in 2 dimensions.
 */
unsigned int** transformInt(unsigned int n);

/**
 * Transform the integer by packets of 7 bits, the eighth is used to 
 * indicate if the writing continues on the next byte.
 *
 * @param tab
 *		The array of bytes in 2 dimensions.
 * @param n
 *		An unsigned integer.
 */
void displayTransformInt(unsigned int** tab, unsigned int n);

/**
 * Free the array of bytes.
 *
 * @param tab
 *		The array of bytes in 2 dimensions.
 */
void freeBytes(unsigned int **tab);

#endif
