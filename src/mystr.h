#ifndef MYSTR_H
#define MYSTR_H

#include <stdlib.h>
#include <assert.h>


typedef struct
{
	char* memory;
	unsigned int length;
} string;

void mystr_put_raw(string*, const char*);
void mystr_put_str(string*, string*);

string mystr_concat_raw(string*, const char*);
string mystr_concat_str(string*, string*);

void mystr_append_raw(string*, const char*);
void mystr_append_str(string*, string*);

char mystr_at_str(string*, unsigned int);
void mystr_put_at_str(string*, unsigned int, char);

string mystr_sub(string*, unsigned int, unsigned int);

int mystr_equals(string*, string*);

void mystr_destroy(string*);

#endif