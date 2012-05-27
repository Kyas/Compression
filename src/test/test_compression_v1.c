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
	FILE *in_compression = fopen("./src/exemples/version1/texte_non_code_v1_ascii", "r");
	FILE *out_compression = fopen("./src/exemples/version1/texte_non_code_v1_ascii_code", "w");
	
	FILE *in_compression_advanced = fopen("./src/exemples/version1/declaration_v1_ascii", "r");
	FILE *out_compression_advanced = fopen("./src/exemples/version1/declaration_v1_ascii_code", "w");
	
	assert(compression(in_compression, out_compression) == 1);
	assert(compression(in_compression_advanced, out_compression_advanced) == 1);
	
	printf("To see the file result with compression, go in src/test/version1/texte_non_code_v1_ascii_code !\n\n");
	printf("Text too long ! See the file \"declaration\" in src/exemples/ !\n\(Don't stop the program, the compression takes a bit longer)\n");
	
	fclose(in_compression);
	fclose(out_compression);
	
	fclose(in_compression_advanced);
	fclose(out_compression_advanced);
	
	/* The Decompression Part */
	FILE *in_decompression = fopen("./src/exemples/version1/texte_non_code_v1_ascii_code", "r");
	FILE *out_decompression = fopen("./src/exemples/version1/texte_non_code_v1_ascii_origin", "w");
	
	FILE *in_decompression_advanced = fopen("./src/exemples/version1/declaration_v1_ascii_code", "r");
	FILE *out_decompression_advanced = fopen("./src/exemples/version1/declaration_v1_ascii_origin", "w");
	
	assert(decompression(in_decompression, out_decompression) == 1);
	assert(decompression(in_decompression_advanced, out_decompression_advanced) == 1);
	
	printf("To see the file result with decompression, go in src/test/version1/texte_non_code_v1_ascii_origin !\n\n");
	printf("Text too long ! See the file \"declaration_origin\" in src/exemples/ !\n(Don't stop the program, the decompression takes a bit longer)\n");
	
	fclose(in_decompression);
	fclose(out_decompression);
	
	fclose(in_decompression_advanced);
	fclose(out_decompression_advanced);
	
	testSuccessful(__FILE__);

	return 0;
}
