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
 
#include <list/list.h>
#include <coding/coding.h>
#include <decoding/decoding.h>
#include <v1/file/file.h>
#include <v1/compression/compression.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "test.h"

int main() {

	/* The Compression Part */
	FILE *in_compression = fopen("./src/exemples/declaration", "r");
	FILE *out_compression = fopen("./src/exemples/declaration_code", "w");
	
	assert(compression(in_compression, out_compression) == 1);
	
	fclose(in_compression);
	fclose(out_compression);
	
	/* The Decompression Part */
	FILE *in_decompression = fopen("./src/exemples/declaration_code", "r");
	FILE *out_decompression = fopen("./src/exemples/declaration_origin", "w");
	
	assert(decompression(in_decompression, out_decompression) == 1);
	
	fclose(in_decompression);
	fclose(out_decompression);

	testSuccessful(__FILE__);

	return 0;
}
