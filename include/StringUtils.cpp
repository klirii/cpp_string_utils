#include "StringUtils.h"

#include <iostream>
using namespace std;

unsigned short StringUtils::find(const char* str, const char sym) {
	for (unsigned short i = 0; str[i]; ++i)
		if (str[i] == sym)
			return i;
	return 0;
}

unsigned short StringUtils::len(const char* str) {
	unsigned short i = 0;
	for (; *str; ++i, str++) {}
	return i;
}

void StringUtils::cpy(char* dest, const char* src, const unsigned short len) {
	for (unsigned short i = 0; i < len; i++)
		dest[i] = src[i];
}

void StringUtils::remove(char** str_arr, const unsigned short len) {
	for (unsigned short i = 0; i < len; i++)
		delete[] str_arr[i];
	delete[] str_arr;
}

unsigned short StringUtils::split(const char* str, char sep, char** buf) {
	if (!*str)
		return 0;

	unsigned short sep_element  = 0;
	unsigned short word_counter = 0;

	bool is_last_word = false;

	while (true) {
		sep_element = find(str, sep);
		if (sep_element || is_last_word) {
			if (is_last_word)
				sep_element = len(str);

			char* word = new char[sep_element + 1];
			cpy(word, str, sep_element);
			word[sep_element] = 0;
			buf[word_counter] = word;

			++word_counter;
			if (is_last_word)
				break;
		}
		else if (!sep_element) {
			is_last_word = true;
			continue;
		}

		str += sep_element + 1;
	}

	return word_counter;
}

unsigned short StringUtils::hexstr2bytes(const char* str, unsigned char* buf) {
	unsigned short i = 0;
	char** bytes = new char* [32767];

	unsigned short bytes_len = StringUtils::split(str, ' ', bytes);
	for (; i < bytes_len; i++)
		buf[i] = strtol(bytes[i], nullptr, 16);

	remove(bytes, bytes_len);
	return i;
}