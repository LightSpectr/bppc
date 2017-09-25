#include "funkce01.h" 
#include <cstdio> 
#include <iostream> 

using std::cout; 
using std::endl; 
using std::cerr; 



int main(int argc, char *argv[]) 
{ 
//for (int i = 0; i < argc; ++i) 
// { 
// cout « "Parametr#" « i « ": " « argv[i] « endl; 
// } 
if (argc != 2) 
{ 
cerr « "Spatny pocet parametru" « endl; 
return 1; 
} 

FILE *fsrc = nullptr; 
fsrc = fopen(argv[1], "rb"); 
if (fsrc == nullptr) 
{ 
cerr « "Soubor se nepodarilo otevrit" « endl; 
return 2; 
} 
if (statistika(fsrc) == 1) { 
cerr « "pustoj dokument" « endl; 
return 4; 
} 

if (fclose(fsrc)) 
{ 
cerr « "Soubor se nepodarilo zavrit" « endl; 
return 3; 
} 

return 0; 
}
