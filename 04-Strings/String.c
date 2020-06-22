#include "String.h"

int GetLength(const char string[]){
    return (string[0] == '\0') ? 0 : 1 + GetLength(++string);
}

bool IsEmpty(const char string[]){
    return string[0]  == '\0' ? true : false;
}

char* Power(const char string[], const int times){
 int stringLength = GetLength(string);
 int totalSize = times * stringLength + 1;
 char* newString = (char*)malloc(totalSize);
  if(newString == NULL)                     
    {
        printf("Error! memory not allocated.");
        exit(0);
    }
 for (int i = 0; i< times; i++){
    for (int j = 0; j < stringLength; j++)
    {
     newString[times * stringLength + j] = string[j];
    }
 }
 newString[totalSize] = '\0';
 return newString;
}

char* Concat(const char string_1[], const char string_2[]){
 int string_1Length = GetLength(string_1);
 int totalSize = string_1Length + GetLength(string_2) + 1;
 char* newString = (char*)malloc(totalSize);
 for (int i=0; i < string_1Length; i++){
  newString[i] = string_1[i];
 }
 for (int i=0; i < GetLength(string_2); i++){
  newString[string_1Length + i] = string_2[i];
 }
 newString[totalSize] = '\0';
 return newString;
}