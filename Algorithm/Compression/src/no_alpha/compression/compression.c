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
#include <coding/coding.h>
#include <decoding/decoding.h>

#include <no_alpha/file/file.h>

int newCompression (FILE *in, FILE *out) {
	if(in != NULL) {
		Liste tmp = NULL;
		Liste la = NULL;
		Liste lp = NULL;
		
		int na = 0;
		int np = 0;
		
		printf("%d\n", readAlphabIntoList(in, &la));
		printf("%d\n", readPunctIntoList(in, &lp));
		printList(lp);
		
		/* TODO Différencier maintenant les deux alpha */
		
		while(la != NULL && lp != NULL) {
		
			na = codingWordList(&tmp, la->word);
			np = codingWordList(&tmp, lp->word);
			
			if(na == 0) {
			
				fprintf(out, "%d ", na);
				fprintf(out, "%d ", strlen(la->word));
				
				/* To make sure that the end of the line doesn't contain SPACES ! */
/*				if(strcmp(la->next->word, "\n") != 0) {*/
/*					fprintf(out, "%s ", la->word);*/
/*				} else {*/
/*					fprintf(out, "%s", la->word);*/
/*				}*/
				
			} else if(na > 0) {
				
				if(strcmp(la->next->word, "\n") != 0) {
					fprintf(out, "%d ", na);
				} else {
					fprintf(out, "%d", na);
				}
				
			} else if(na == -2) {
				fprintf(out, "\n");
			} else {
			
				return 0;
			}
			
			
			la = la->next;
			lp = lp->next;
		}
		return 1;
	}
	return 0;
}

int newDecompression(FILE *in, FILE *out) {
	if(in != NULL) {
	
		Liste tmp = NULL;
		Liste la = NULL;
		
		int n = 0;	
		
		readAlphabIntoList(in, &la);
		
		while(la != NULL) {
			
			if(strcmp(la->word, "0") == 0) { /* If the current word is the digit 0 */
			
				n = decodingWordList(&tmp, la->next->next->word, 0);
				
				/* To make sure that the end of the line doesn't contain SPACES ! */
				if(strcmp(la->next->next->next->word, "\n") != 0) {
					fprintf(out, "%s ", la->next->next->word);
				} else {
					fprintf(out, "%s", la->next->next->word);
				}
					
				la = la->next->next;
				
			} else if(strcmp(la->word, "\n") == 0) { /* If the current word is '\n' */
			
				n = decodingWordList(&tmp, NULL, -2);
				
				fprintf(out, "\n");
				
			} else if(strcmp(la->word, "") == 0) { /* If the current word is the space */
			
				n = decodingWordList(&tmp, NULL, -1);
				
			} else if(atoi(la->word) > 0) {
			
				n = decodingWordList(&tmp, NULL, atoi(la->word));
				
				if(strcmp(la->next->word, "\n") != 0) {
					fprintf(out, "%s ", tmp->word);
				} else {
					fprintf(out, "%s", tmp->word);
				}
				
			} else {
				return -1;
			}
			la = la->next;
		}
		
		return 1;
	}
	
	return 0;

}
