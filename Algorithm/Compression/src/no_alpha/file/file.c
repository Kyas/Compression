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

void displayString(char** s, int numberOfWords) {

    int i;
    
    for(i=0; i < numberOfWords; i++) {

    		printf("%s ", s[i]); 

    }
    
    putchar('\n');
    
}

char** readAlphabIntoArray(FILE* in, int* numberOfWords) {

    char c;
    int i;
    int j=0, k=0;
    
    /* Allocation of the 1st dimension */
    char** res = (char**)malloc(4096*sizeof(char*));
    
    /* Allocation of the 2nd dimension */
    for (i = 0; i < 4096; i++) {
        res[i] = (char*)malloc (128*sizeof(char));
    }
    
    if(res == NULL) {
    
        return NULL;
        
    }
    
    while((c=fgetc(in)) !=EOF) {
    
        if(isalnum(c) && isalpha(c)) {
        
            res[j][k] = c;
            k++;
            
        } else {
        
        	res[j][k] = '\0';
            j++;
            k=0;
            (*numberOfWords)++;
            
        }
    }
    
    return res;
    
}

char** readPunctIntoArray(FILE* in, int* numberOfWords) {

    char c;
    int i;
    int j=0, k=0;
    
    /* Allocation of the 1st dimension */
    char** res = (char**)malloc(4096*sizeof(char*));
    
    /* Allocation of the 2nd dimension */
    for (i = 0; i < 4096; i++) {
        res[i] = (char*)malloc (4096*sizeof(char));
    }
    
    if(res == NULL) {
    
        return NULL;
        
    }
    
    while((c=fgetc(in)) !=EOF) {
    
        if(!isalnum(c) && !isalpha(c)) {
        
            res[j][k] = c;
            k++;
            
        } else {
        
        	res[j][k] = '\0';
            j++;
            k=0;
            (*numberOfWords)++;
            
        }
    }
    
    return res;
    
}

int readAlphabIntoList(FILE* in, Liste *la) {

	if(in != NULL) {
	
		int i;
		int numberOfWords = 0;
		char** alphabetical = (char**)malloc(4096*sizeof(char*));
		
		alphabetical = readAlphabIntoArray(in, &numberOfWords);
		
		for(i=0; i < numberOfWords; i++) {
		
			addLast(la, alphabetical[i]);
		}
		
		return 1;
		
	}
	
	return 0;
	
}

int readPunctIntoList(FILE* in, Liste *lp) {

	if(in != NULL) {
	
		int i;
		int numberOfWords = 0;
		char** ponctuation = (char**)malloc(4096*sizeof(char*));
		
		ponctuation = readPunctIntoArray(in, &numberOfWords);
		
		for(i=0; i < numberOfWords; i++) {
		
			addLast(lp, ponctuation[i]);
		}
		
		return 1;
		
	}
	
	return 0;
	
}
