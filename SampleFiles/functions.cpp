#include<iostream>
#include <cstring> //needed for strcpy

using namespace std;
#define MAXSTRING 100

int main(int argc, char *argv[]){
    // argv[0] = copmiled code file name
    // argv[1] = input file name
    // argv[2] = output file name


    /*STRINGS*/
    char s1[] = "abc"; //Defining Strings, can be treated as character arrays
    
    /*POINTERS*/
    char c = 'a'; 
    char *p; //define a pointer to a character object

    p = &c; // set p to point to c
    cout << *p << endl; // get value of object that p is pointing to

    /*ARRAY POINTERS*/
    char s[MAXSTRING];
    strcpy(s, "ABC");  //saves value "ABC" to variable s
    strcpy(s, "she sells sea shells by the seashore"); //needs importing cstream
    p = s + 14; // p points to 14th index of s
    for ( ; *p != '\0'; p++) { // p will iterate over all characters of the string
        if (*p == 'e') // *p dereferences pointer and accesses value that is being pointed to
        *p = 'E';

        if (*p == ' ')
        *p = '\n';
    }
    cout << s << endl;
}