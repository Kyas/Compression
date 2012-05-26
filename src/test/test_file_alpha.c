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
#include <alpha/file/file.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "test.h"

int main() {

	FILE *in_array = fopen("./src/exemples/texte_non_code", "r");
	FILE *in_list = fopen("./src/exemples/texte_non_code", "r");
	
	assert(in_array != NULL);
	assert(in_list != NULL);
	
	if(in_array != NULL && in_list != NULL) {
		/* 2 modes for reading the file : An array of a List */
		
		/* The array of characters */
		int numberOfWords = 0;
		char** res = (char**)malloc(4096*sizeof(char*));
		
		res = readNoEncodedFileIntoArray(in_array, &numberOfWords);
		assert(res != NULL);
		
		/* The List */
		Liste l = readNoEncodedFileIntoList(in_list);
		assert(l != NULL);
		
		free(res);
		fclose(in_array);
		fclose(in_list);
	}
	
	testSuccessful(__FILE__);

	return 0;	
}
