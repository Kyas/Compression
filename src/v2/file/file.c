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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include <list/list.h>

#define SIZE_MAX 8092

void displayString(char** s, int numberOfWords) {

	int i;

	for(i=0; i < numberOfWords; i++) {

		printf("%s ", s[i]);

	}

	putchar('\n');

}

int readAlphabPunctIntoList(FILE* in, Liste *la, Liste *lp) {

	char c;
	int i=0;
	int j=0;

	c=fgetc(in);
	while(c != EOF) {
		
		if(isalnum(c)) {
			char* alphab = (char*) malloc (SIZE_MAX * sizeof(char));

			while(isalnum(c)) {
				alphab[i] = c;
				i++;
				c=fgetc(in);
			}
			alphab[i] = '\0';
			addLast(la, alphab);
			i=0;

		} else {
	
			char* punct = (char*) malloc (SIZE_MAX * sizeof(char));

			while(!isalnum(c) && c != EOF) {
				punct[j] = c;
				j++;
				c=fgetc(in);
			}
			punct[j] = '\0';
			addLast(lp, punct);
			j=0;
			if(!isalnum(c)) {
				return 1;
			}
		}
		
	}

	return 1;

}
