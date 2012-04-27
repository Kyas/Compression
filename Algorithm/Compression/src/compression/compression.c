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
#include <file/file.h>

int compression(FILE *in, FILE *out) {
	if(in != NULL) {
		Liste tmp = NULL;
		Liste l = readNoEncodedFileIntoList(in); /* Result : deux -> et -> deux -> quatre -> quatre -> et -> quatre -> huit */
		int n = 0;		
		
		while(l != NULL) {
		
			n = codingWordList(&tmp, l->word);
			
			if(n == 0) {
			
				fprintf(out, "%d ", n);
				fprintf(out, "%d ", strlen(l->word));
				fprintf(out, "%s ", l->word);
				
			} else if(n > 0) {
				
				fprintf(out, "%d ", n);
				
			} else {
			
				return 0;
			}
			
			l = l->next;
		}
		return 1;
	}
	return 0;
}
