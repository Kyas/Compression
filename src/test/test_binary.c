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
 
#include <binary/binary.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "test.h"

int main() {

	unsigned int** newInt = malloc(sizeof(int*));
	unsigned int** newInt2 = malloc(sizeof(int*));
	assert(newInt != NULL && newInt2 != NULL);
	
	displayBinary(5);
	displayBinary(707);
	
	printf("\n");
	printf("How many bytes do we need for %d ? %d\n", 5, getNbOctet(5));
	printf("How many bytes do we need for %d ? %d\n", 707, getNbOctet(707));
	
	
	newInt = transformInt(5);
	newInt2 = transformInt(707);
	
	printf("Transformation for the integer 5 : %d\n", 5);
	displayTransformInt(newInt, 5);
	printf("Transformation for the integer 7 : %d\n\n", 707);
	displayTransformInt(newInt2, 707);
	
	printf("\n");
	testSuccessful(__FILE__);
	
	return 0;
}
