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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <binary/binary.h>
#include <limits.h>
#include <unistd.h>

#define SIZE_MAX 15

/**
 * Display the integer into a binary.
 *
 * @param n
 *		The unsigned int.
 */
void displayBinary(unsigned int n) {
	int i;
	printf("%d in binary : ", n);
	for(i = SIZE_MAX; i >= 0; i--) {
		printf("%d", (n >> i ) & 1);
	}
	printf("\n");
}

/**
 * Put a character.
 *
 * @param n
 *		The unsigned int.
 * @return A character.
 */
int putBinary(int c)
{
	return (write(1, &c, 1));
}

/**
 * Display the integer into a byte (FR:octet).
 *
 * @param n
 *		A char.
 */
void displayByte(char n) {
	int mask;
	mask = 0x80 ; /*<<<<< 0x8;*/
	while (mask)
	{
		putBinary('0' + ((n & mask) != 0));
		mask >>= 1;
		if(mask == 0xFF00000) putBinary('\'');/*<<<<<*/
	}
}

/**
 * Display the integer into bytes (FR:octets).
 *
 * @param n
 *		An unsigned integer.
 */
void displayValue(unsigned int n) {
	char *n_addr;
	unsigned int mask;
	n_addr = (char *) &n;
	mask = 0xFF000000; /* <<<<<< 0xF00000 */
	while(mask) {
		displayByte(*n_addr++);
		mask >>= 8;   /* <<<<<< 4*/
		if (mask) putBinary('\'');
	}
	printf("\n");
}

/**
 * To get the number of Bytes to use for the integer.
 *
 * @param n
 *		An unsigned integer.
 * @return The number of Bytes we must use.
 */
int getNbOctet(unsigned int n) {
	int octet = 0;
	int isBit = 0;
	int i = 0, j;

	while(i < 3) {

		for(j = 7*(i+1); j >= i*8; j--) {
			if((n >> j ) & 1) {
				isBit++;
			}
		}

		if(isBit > 0) {
			octet++;
		}
		isBit = 0;
		i++;
	}
	return octet;
}

/**
 * Transform the integer by packets of 7 bits, the eighth is used to 
 * indicate if the writing continues on the next byte.
 *
 * @param n
 *		An unsigned integer.
 * @return The array of Bytes in 2 dimensions.
 */
 
unsigned int** transformInt(unsigned int n) {
	if(n > 0) {
		int size = getNbOctet(n);
		int i, j, l = 0;

		unsigned int** newInt = malloc(sizeof(int*));

		for (i = 0; i < 7; i++) {
			newInt[i] = malloc (sizeof(int));
		}

		if(size <= 1) {

			int k = 0;
			for(j = 7; j >= 0; j--) {
				k++;
				if((n >> j) & 1) {
					newInt[0][k-1] = 1;
				} else {
					newInt[0][k-1] = 0;
				}
			}
			newInt[0][0] = 0;

		} else {

			while(l < size) {
				int k = 0;
				for(j = 7*(l+1); j >= l*7; j--) {
					k++;
					if((n >> (j+l)) & 1) {
						newInt[l][j] = 1;
					} else {
						newInt[l][j] = 0;
					}
				}
			
				if((l+1) == size) {
					newInt[0][0] = 0;
				} else {
					newInt[0][0] = 1;
				}
			l++;
			}
		}
		return newInt;
	}
	return NULL;
}

/**
 * Transform the integer by packets of 7 bits, the eighth is used to 
 * indicate if the writing continues on the next byte.
 *
 * @param tab
 *		The array of bytes in 2 dimensions.
 * @param n
 *		An unsigned integer.
 */
void displayTransformInt(unsigned int** tab, unsigned int n) {
	int i, j;
	int size = getNbOctet(n);
	for(i = 0; i < size; i++) {
		for(j = 0; j < 8; j++) {
			printf("%d", tab[i][j]);
		}
		printf(" ");
	}
	printf("\n");
}

void freeBytes(unsigned int **tab) {
	free(tab[0]);
	free(tab);
}

