// This code has been copied from:
// https://stackoverflow.com/a/174552

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "../lib/jsmn.h"

int generic_load(char *buf, const char *filename) {
    char *buffer = 0;
    long length;
    FILE *f = fopen (filename, "rb");

    if (f)
    {
    	fseek (f, 0, SEEK_END);
    	length = ftell (f);
    	fseek (f, 0, SEEK_SET);
    	buffer = (char *) malloc (length + 1);
    	buffer[length] = '\0';
    	if (buffer)
    	{
    		fread (buffer, 1, length, f);
    	}
    	fclose (f);
    }
}

// int load_all_from_file() {
// 	jsmn_parser p;
// 	jsmntok_t t[128]; /* We expect no more than 128 JSON tokens */

// 	const char *filename = "../testdata/simple.json";
// 	char *s;
// 	int resnum = generic_load(s, filename);

// 	jsmn_init(&p);
// 	int r = jsmn_parse(&p, s, strlen(s), t, 128);
// }
