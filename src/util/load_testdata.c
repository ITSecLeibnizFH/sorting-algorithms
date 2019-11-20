// This code has been copied from:
// https://stackoverflow.com/a/174552

#include <stdio.h>
#include <stdlib.h>

int generic_load(char *buf, const char *filename) {
    char * buffer = 0;
    long length;
    FILE * f = fopen (filename, "rb");

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

