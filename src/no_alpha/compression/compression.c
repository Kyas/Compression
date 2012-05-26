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
#include <coding/coding.h>
#include <decoding/decoding.h>

#include <no_alpha/file/file.h>
#include <no_alpha/compression/compression.h>

int newCompression (FILE *in, FILE *out) {
	if(in != NULL) {
		Liste tmp_la = NULL;
		Liste tmp_lp = NULL;
		Liste la = NULL;
		Liste lp = NULL;

		int na = 0;
		int np = 0;

		readAlphabPunctIntoList(in, &la, &lp);
		
		while(la != NULL || lp != NULL) {

			na = codingWordList(&tmp_la, la->word);
			
			if(la != NULL) {
				if(na == 0) {

					fprintf(out, "%d", na);
					fprintf(out, "%d ", strlen(la->word));
					fprintf(out, "%s ", la->word);
				
				} else {

					fprintf(out, "%d ", na);
				
				} 
			
				la = la->next;
			}
			
			if(lp != NULL) {
				np = codingWordPunctList(&tmp_lp, lp->word);
			
				if(np == 0) {

					fprintf(out, "%d", np);
					fprintf(out, "%d ", strlen(lp->word));
					fprintf(out, "%s ", lp->word);
				
				} else {

					fprintf(out, "%d ", np);
				
				}
			
				lp = lp->next;
			}

		}
		
		return 1;
	}
	return 0;
}

int newDecompression(FILE *in, FILE *out) {
	if(in != NULL) {

		Liste l1 = NULL;
		Liste l2 = NULL;

		int index = 0;

		char c;
		int i = 0, j = 0;

		c=fgetc(in);
		while(c != EOF) {

			if(c == '0') { /* New word */
				c=fgetc(in);
				char* size = (char*) malloc (sizeof(char));

				while(isdigit(c)) {
					size[i] = c;
					c = fgetc(in);
					i++;
				}
				size[i] = '\0';
				i=0;

				c=fgetc(in);
				char* word = (char*) malloc (sizeof(char));

				while(j < atoi(size)) {
					word[j] = c;
					j++;
					c = fgetc(in);
				}
				word[j] = '\0';
				j = 0;

				fprintf(out, "%s", word);
				if(index%2 == 0) {
					decodingWordList(&l1, word, 0);
					index++;
				} else {
					decodingWordList(&l2, word, 0);
					index++;
				}
				

			} else {
				
				if(index%2 == 0) {
					decodingWordList(&l1, NULL, c - '0');
					fprintf(out, "%s", l1->word);
				
					index++;
				} else {
					decodingWordList(&l2, NULL, c - '0');
					fprintf(out, "%s", l2->word);
				
					index++;
				}
				c = fgetc(in);
				
			}
			c = fgetc(in);

		}
		return 1;
	}
	return 0;

}
