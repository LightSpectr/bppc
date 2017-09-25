#include "funkce01.h" 

void tisk(unsigned long long *aPocet, int *aIndex ) { 
  unsigned long long znaky = 0; 
  for (int i = 0; i < 256; i++) { 
    znaky = znaky + aPocet[i]; 
  } 
  printf("%llu\n", znaky); 
  for (int i = 0; i < 256; i++) { 
    printf("%3d;%2x;%3llu;%.4lf\n", aIndex[i], aIndex[i], aPocet[aIndex[i]], 100.*aPocet[aIndex[i]] / znaky); 

  } 
} 
void setrid(unsigned long long *aPocet, int *aIndex) { 

  int tmp; 
  int size = 256; 
  for (int i = 0; i < size-1; ++i) // i - номер прохода 
  { 
    for ( int j = 0; j < size-1; ++j) // внутренний цикл прохода 
    { 
      if (aPocet[aIndex[j+1]] > aPocet[aIndex[j]]) 
      { 
        tmp = aIndex[j + 1]; 
        aIndex[j + 1] = aIndex[j]; 
        aIndex[j] = tmp; 
      } 
    } 
  } 

} 
int statistika(FILE *aFsrc) 
{ 
  unsigned long long pocet[256] = { 0, }; 

  int c; 
  unsigned int i = 0; 
  int index[256]; 
  for (int d = 0; d < 256; d++) { 
    index[d] = d; 
  } 


  do { 
    c = fgetc(aFsrc); 
    pocet[c]++; 
    i++; 
    //} while (c != EOF); 
   } while (!feof(aFsrc)); 
  if (i-1 == 0) { 
    return 1; 
  } 
  tisk(pocet, index); 
  setrid(pocet, index); 
  tisk(pocet, index); 
  return 0; 
}
