#include <stdio.h>
#include <stdlib.h>

void error  (char []);
void succsess  (char []);

void (*message)(char []);


int main()
{
    message = &error;
    message("Out of Bounds");
      
    message = succsess;
    message("every this is good");
    
return 1; 
}

void error(char text[]){
  printf("Fehler: %s\n", text);
}

void succsess(char text[]){
  printf("Okay: %s\n", text);
}