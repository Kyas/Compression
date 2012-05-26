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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "test.h"

int main() {

	Liste l = NULL;

	assert(addLast(&l, "test1") == 1);
	assert(addFirst(&l, "test2") == 1);
	assert(addFirst(&l, "test3") == 1);
	assert(addFirst(&l, "test4") == 1);
	assert(addFirst(&l, "test5") == 1);
	assert(addFirst(&l, "test6") == 1);
	assert(addFirst(&l, "test7") == 1);
	
	assert(moveToFirst(&l, 7) == 1);
	assert(size(&l) == 7);
	assert(indexOf(l, "test5") == 4);
	assert(deleteAt(&l,2) == 1);
	assert(deleteFirst(&l) == 1);

	testSuccessful(__FILE__);
	
    return 0;
}
