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

	FILE *in = fopen("./src/exemples/texte_non_code_punct", "r");
	
	assert(in != NULL);

	if(in != NULL) {
		
		/* The List */
		Liste la = NULL;
		Liste lp = NULL;
		
		assert(readAlphabPunctIntoList(in, &la, &lp) == 1);
		
		fclose(in);
	}
	
	testSuccessful(__FILE__);

	return 0;	
}
