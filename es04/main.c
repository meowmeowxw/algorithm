#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#define PRINT_OUTPUT 1

int main (int argc, char* argv[])
{
   char *line[LINE_LENGTH];
   uint8_t *key;
   uint8_t *buf;
   const char *separator = ",";
   uint32_t digest;
   int n;
   clock_t start, end;

   printf("\nReading file.. %s\n\n",argv[1]);

   FILE* fin = fopen(argv[1] ,"r");
   if(fin == NULL) goto end;
   // <= >= == --> <-- ==> != 
   n = 0;
   while ( fgets((char*)line, LINE_LENGTH, fin)!= NULL ) n++;

   rewind(fin);

   //	Try hash functions 
   while (fgets((char*)line,LINE_LENGTH,fin)!= NULL )
   {
      // Read the key (part before separator (,)
      buf = (uint8_t*) strtok((char*)line, separator);

      // read value (part after separator(,)
      key = (uint8_t*) strtok(NULL, separator);

      // compute key hash
      digest = hash_modulus(key,71327);
      if(PRINT_OUTPUT) printf("hash_modulus('%.*s')\t->\tDigest: %lu\t",KEY_LENGTH,key,(long unsigned int)digest);

      digest = hash_murmur3_32(key,KEY_LENGTH,123);
      if(PRINT_OUTPUT) printf("hash_murmur('%.*s')\t->\tDigest: %lu\n",KEY_LENGTH,key,(long unsigned int)digest);
   }

   fclose(fin);
   printf("\n");

   end:printf("<ENTER> to exit...");
   getchar();
   return 0;
}
