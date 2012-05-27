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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "test.h"

int main() {

	Liste l = NULL;
	
	/* Exemple : 
		First, we get one by one the word in the text 
		then we return his position according to the function codingWordList 
		(see what he does exactly in List.h)
		
			0 deux 0 et 1 0 quatre 
			3 3 2 0 huit 
		
			4 3 2 0 seize 
			0 répétez 0 dit 0 le 0 maitre 
		
		At the end, we got the List, use the function printList(l), you well get the result : 
			huit -> et -> quatre -> deux -> seize -> répétez -> dit -> le -> maître
		*/
	
	assert(codingWordList(&l, "deux") == 0);
	assert(codingWordList(&l, "et") == 0);
	assert(codingWordList(&l, "deux") == 1);
	assert(codingWordList(&l, "quatre") == 0);
	assert(codingWordList(&l, "quatre") == 3);
	assert(codingWordList(&l, "et") == 3);
	assert(codingWordList(&l, "quatre") == 2);
	assert(codingWordList(&l, "huit") == 0);
	
	assert(codingWordList(&l, "huit") == 4);
	assert(codingWordList(&l, "et") == 3);
	assert(codingWordList(&l, "huit") == 2);
	assert(codingWordList(&l, "seize") == 0);
	assert(codingWordList(&l, "répétez") == 0);
	assert(codingWordList(&l, "dit") == 0);
	assert(codingWordList(&l, "le") == 0);
	assert(codingWordList(&l, "maître") == 0);
	
	printf("See the source code to understand (src/test/test_coding.c) !\n\n");
	
	testSuccessful(__FILE__);
	
    return 0;
}
