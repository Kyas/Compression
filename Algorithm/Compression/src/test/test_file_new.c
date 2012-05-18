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
#include <no_alpha/file/file.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "test.h"

int main() {

	FILE *in_array = fopen("./src/exemples/texte_non_code_punct", "r");
	FILE *in_list = fopen("./src/exemples/texte_non_code_punct", "r");
	
	assert(in_array != NULL);
	assert(in_list != NULL);
	
	if(in_array != NULL) {
		/* 2 modes for reading the file : An array of a List */
		
		/* The array of characters */
		int numberOfWords = 0;
		char** res = (char**)malloc(4096*sizeof(char*));
		
		res = readPunctIntoArray(in_array, &numberOfWords);
		assert(res != NULL);
		
		/* The List */
		Liste la = NULL;
		
		assert(readAlphabIntoList(in_list, &la) == 1);
		
		fclose(in_array);
		fclose(in_list);
	}
	
	testSuccessful(__FILE__);

	return 0;	
}
