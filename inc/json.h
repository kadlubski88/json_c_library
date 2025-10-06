//###########################################################################
//# json_c_library: A c library to parse, modify and generate json strings. #
//# https://github.com/kadlubski88/json_c_library                           #
//#                                                                         #
//# The MIT License (MIT)                                                   #
//# Copyright © 2025 Georges Kadlubski                                      #
//# URL: https://mit-license.org/                                           #
//###########################################################################

#ifndef _HEADER_JSON_H_
#define _HEADER_JSON_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define PERROR fprintf(stderr, "Error in file %s at line %d: %s\n", __FILE__, __LINE__, strerror(errno))

#define PARSING_SUCCESS 0
#define PARSING_FAILURE 1

//###################
//# Enum definition #
//###################

typedef enum{
    TOKEN_BLOCK_START,
    TOKEN_BLOCK_END,
    TOKEN_ARRAY_START,
    TOKEN_ARRAY_END,
    TOKEN_STRING,
    TOKEN_NUMBER,
    TOKEN_BOOL_TRUE,
    TOKEN_BOOL_FALSE,
    TOKEN_COLON,
    TOKEN_COMMA,
    TOKEN_NULL,
    TOKEN_END,
    TOKEN_UNKNOWN
}token_type;

typedef enum{
    STATE_KEY,
    STATE_VALUE,
}key_value_state;

//######################
//# function prototype #
//######################

token_type get_token(char **input, char **token_value, int *token_length);

#endif //_HEADER_JSON_H_