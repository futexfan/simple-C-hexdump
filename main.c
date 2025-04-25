#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(int argc, char *argv[])
{
  if (argv[1] == NULL){return 1;}

  FILE *file = fopen(argv[1], "r");

  fseek(file, 0, SEEK_END);
  int32_t fileSize = ftell(file);
  if (fileSize <= 0 || fileSize > 3200000 ) { fclose(file); return 1; }

  fseek(file, 0, SEEK_SET);
  uint8_t *fileCont = malloc(fileSize + 1);
  if (!fileCont) { fclose(file); return 1; }
  
  fread(fileCont, 1, fileSize, file);
  fileCont[fileSize] = '\0';

  for (int32_t i = 0; i < fileSize; i++)
  {
    printf("%d : %02x\n",i,(int8_t)fileCont[i]);
  }

  free(fileCont);
  fileCont = NULL;
  fclose(file);

  return 0;
}
