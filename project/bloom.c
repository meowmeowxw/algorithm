#include <stdlib.h>
#include "bloom.h"
void insertElem(const uint8_t* elem)
{
  int i = 1;
  while(i<=k)
  {
    filter[hashFunction(elem,i)]=1;
    ++i;
  }    
}
bool checkElem(const uint8_t* elem)
{
  int i = 1;
  while(i<=k)
  {
    if(!filter[hashFunction(elem,i)])
    {
      return false;
    }
    ++i;
  }
  return true;
}
void buildFilter(const uint8_t** dataset)
{
  filter=calloc(m,sizeof(bool));
  int i;
  for(int j=0;j<n;++j)
  {
    i=1;
    while(i<=k)
    {
      filter[hashFunction(dataset[j],i)]=1;
      ++i;
    }
  }
  puts("build filter done");
}
void selfCheck(const uint8_t** dataset, FILE* fout)
{
  int i;
  int good=0;
  for(int j=0;j<n;++j)
  {
    i=1;
    if(filter[hashFunction(dataset[j],i)])
    {
      ++good;
    }
  }
  puts("self check done");
  fprintf(fout,"True Positives (self-check): %d\n",good);
}
void nonElementsCheck(const uint8_t** dataset, FILE* fout)
{
  int i;
  int good=0;
  int bad=0;
  for(int j=0;j<non_elements;++j)
  {
    if(checkElem(dataset[j]))
    {
         ++bad;
    }else
    {
      ++good;
    }
        
  }
  fprintf(fout,"True negatives: %d\n",good);
  fprintf(fout,"False positives: %d\n",bad);
  fprintf(fout,"FPR: %f",(double)bad/non_elements);
}
