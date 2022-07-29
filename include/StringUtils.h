#pragma once

class StringUtils {
public:
	static unsigned short hexstr2bytes(const char* str, unsigned char* buf);
	static unsigned short split(const char* str, char sep, char** buf);
	static unsigned short find(const char* str, const char sym);
	static unsigned short len(const char* str);
	static void			  cpy(char* dest, const char* src, const unsigned short len);
	static void			  remove(char** str_arr, const unsigned short len);
};