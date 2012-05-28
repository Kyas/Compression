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
#include <decoding/decoding.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "test.h"

int main() {
	
	Liste l = NULL;
	
	/* Exemple : 
		
		To decode the coding text below :
		
			0 deux 0 et 1 0 quatre 
			3 3 2 0 huit 
		
			4 3 2 0 seize 
			0 répétez 0 dit 0 le 0 maitre 
		
		We try to recreate the List
		Use the function printList(l), you well get the result :
			 huit -> et -> quatre -> deux -> seize -> répétez -> dit -> le -> maître
	*/
	
	assert(decodingWordList(&l, "deux", 0) == 1);
	assert(decodingWordList(&l, "et", 0) == 1);
	assert(decodingWordList(&l, NULL, 1) == 1);
	assert(decodingWordList(&l, "quatre", 0) == 1);
	assert(decodingWordList(&l, NULL, 3) == 1);
	assert(decodingWordList(&l, NULL, 3) == 1);
	assert(decodingWordList(&l, NULL, 2) == 1);
	assert(decodingWordList(&l, "huit", 0) == 1);
	
	assert(decodingWordList(&l, NULL, 4) == 1);
	assert(decodingWordList(&l, NULL, 3) == 1);
	assert(decodingWordList(&l, NULL, 2) == 1);
	assert(decodingWordList(&l, "seize", 0) == 1);
	assert(decodingWordList(&l, "répétez", 0) == 1);
	assert(decodingWordList(&l, "dit", 0) == 1);
	assert(decodingWordList(&l, "le", 0) == 1);
	assert(decodingWordList(&l, "maître", 0) == 1);
	
	printf("See the source code to understand (src/test/test_decoding.c) !\n\n");
	printList(l);
	printf("\n");
	
	testSuccessful(__FILE__);
	
    return 0;
}
