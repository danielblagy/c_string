#include "mystr.h"


static void free_memory(string* str)
{
	free(str->memory);
	str->length = 0;
	str->memory = 0;
}

static void allocate_memory(string* str, unsigned int length)
{
	if (str->memory)
		free_memory(str);
	
	str->memory = calloc(length + 1, sizeof(char));
	str->length = length;
	assert(str->memory);
}

static unsigned int count_length(const char* value)
{
	int l;
	for (l = 0; value[l] != '\0'; l++);
	return l;
}

static void put(string* str, const char* value, unsigned int value_length)
{
	allocate_memory(str, value_length);
	for (int i = 0; i < value_length; i++)
		str->memory[i] = value[i];
	str->memory[value_length] = '\0';
}

static string concat(string* str, const char* value, unsigned int value_length)
{
	string concat_result = {};
	allocate_memory(&concat_result, str->length + value_length);
	for (int i = 0; i < str->length; i++)
		concat_result.memory[i] = str->memory[i];
	for (int i = 0; i < value_length; i++)
		concat_result.memory[i + str->length] = value[i];
	concat_result.memory[str->length + value_length] = '\0';
	return concat_result;
}

static void append(string* str, const char* value, unsigned int value_length)
{
	string temp = concat(str, value, value_length);
	
	char* old_data = str->memory;
	str->memory = temp.memory;
	str->length = temp.length;
	free(old_data);
}

void mystr_put_raw(string* str, const char* value)
{
	put(str, value, count_length(value));
}

void mystr_put_str(string* dest, string* src)
{
	put(dest, src->memory, src->length);
}

string mystr_concat_raw(string* str, const char* value)
{
	return concat(str, value, count_length(value));
}

string mystr_concat_str(string* str1, string* str2)
{
	return concat(str1, str2->memory, str2->length);
}

void mystr_append_raw(string* str, const char* value)
{
	append(str, value, count_length(value));
}

void mystr_append_str(string* str1, string* str2)
{
	append(str1, str2->memory, str2->length);
}

char mystr_at_str(string* str, unsigned int index)
{
	return str->memory[index];
}

void mystr_put_at_str(string* str, unsigned int index, char c)
{
	str->memory[index] = c;
}

string mystr_sub(string* str, unsigned int index, unsigned int length)
{
	string sub_result = {};
	if (index + length > str->length)
		return sub_result;
	allocate_memory(&sub_result, length);
	for (int i = 0; i < length; i++)
		sub_result.memory[i] = str->memory[i + index];
	sub_result.memory[length] = '\0';
	return sub_result;
}

int mystr_equals(string* str1, string* str2)
{
	if (str1->length == str2->length)
	{
		for (int i = 0; i < str1->length; i++)
			if (str1->memory[i] != str2->memory[i])
				return 0;
		return 1;
	}
	else
		return 0;
}

void mystr_destroy(string* str)
{
	free_memory(str);
}