#include <stdio.h>

#include "mystr.h"


void debug_str(string* str)
{
	printf("%d\t%s\t%d\n", str->memory, str->memory, str->length);
}

int main()
{
	string s1 = {};
	string s2 = {};
	
	mystr_put_raw(&s1, "Hello");
	mystr_put_raw(&s2, ":)");
	
	mystr_append_raw(&s1, "! ");
	mystr_append_str(&s1, &s2);
	
	debug_str(&s1);
	
	printf("%c\n", mystr_at_str(&s1, 1));
	
	mystr_put_at_str(&s2, 0, 'X');
	mystr_put_at_str(&s2, 1, 'D');
	debug_str(&s2);
	
	string subs = mystr_sub(&s1, 3, 5);
	debug_str(&subs);
	
	printf("%d\n", mystr_equals(&s1, &s2));
	string s3 = {};
	mystr_put_raw(&s3, "XD");
	printf("%d\n", mystr_equals(&s3, &s2));
	
	mystr_destroy(&s1);
	debug_str(&s1);
	
	return 0;
}