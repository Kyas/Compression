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

#include <list/list.h>

/**
 * Display the array of characters.
 *
 * @param **s 
 *		An array of characters
 */
void displayString(char** s, int numberOfWords) {

    int i;
    
    for(i=0; i < numberOfWords; i++) {
    	printf("%s %d\n", s[i], strlen(s[i]));  
    }
    
    putchar('\n');
    
}

/**
 * Read the file and return an array of characters.
 *
 * @param *in 
 *		The file
 * @param *numberOfWords
 *		Word counter
 * @return the Array of characters
 */
char** readNoEncodedFileIntoArray(FILE* in, int* numberOfWords) {

    char c;
    int i;
    int j=0, k=0;
    
    /* Allocation of the 1st dimension */
    char** res = (char**)malloc(128*sizeof(char*));
    
    /* Allocation of the 2nd dimension */
    for (i = 0; i < 128; i++) {
        res[i] = (char*)malloc (128*sizeof(char));
    }
    
    if(res == NULL) {
    
        return NULL;
        
    }
    
    while((c=fgetc(in)) !=EOF) {
    
        if(c != '\r' && c != '\n' && c != ' ' && c != '\t' && c!= '-' && c != '\0') {
        
            res[j][k] = c;
            k++;
            
        } else if (c == '\n') {
        
        	res[j][k] = '\0'; /* To finish the current word */
            j++;
            k=0;    
            (*numberOfWords)++;
            
            res[j][k] = '\n'; /* We add the \n after in the array */
            j++;
            k=0;
            (*numberOfWords)++;
            
        } else {
        
        	res[j][k] = '\0';
            j++;
            k=0;
            (*numberOfWords)++;
            
        }
    }
    
    return res;
    
}

/**
 * Read the file and return an array of characters.
 *
 * @param *in 
 *		The file
 * @param *numberOfWords
 *		Word counter
 * @return the Array of characters
 */
Liste readNoEncodedFileIntoList(FILE* in) {

	if(in != NULL) {
	
		Liste l = NULL;
		int i;
		int numberOfWords = 0;
		char** res = (char**)malloc(128*sizeof(char*));
		
		res = readNoEncodedFileIntoArray(in, &numberOfWords);
	
		for(i=0; i < numberOfWords; i++) {
		
			addLast(&l, res[i]);
			
		}
		
		return l;
		
	}
	
	return NULL;
	
}
