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
#include <v2/file/file.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "test.h"

int main() {

	FILE *in = fopen("./src/exemples/version2/texte_non_code_v2_ascii", "r");
	
	assert(in != NULL);

	if(in != NULL) {
		
		/* The List */
		Liste la = NULL;
		Liste lp = NULL;
		
		assert(readAlphabPunctIntoList(in, &la, &lp) == 1);
		
		printf("During the reading ! These are not real Lists, just to get every word before the algorithm.\n\n");
		printf("Alphabetical word List:\n");
		printList(la);
		printf("\n");
		
		printf("Non-alphabetical word List:\n");
		printList(lp);
		
		fclose(in);
	}
	
	testSuccessful(__FILE__);

	return 0;	
}
