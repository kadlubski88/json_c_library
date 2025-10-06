//###########################################################################
//# json_c_library: A c library to parse, modify and generate json strings. #
//# https://github.com/kadlubski88/json_c_library                           #
//#                                                                         #
//# The MIT License (MIT)                                                   #
//# Copyright © 2025 Georges Kadlubski                                      #
//# URL: https://mit-license.org/                                           #
//###########################################################################

#include "../inc/json.h"

token_type get_token(char **input, char **token_value, int *token_length) {
    // reset value length;
    *token_length = 0;
    // skip white spaces and new line
    while (**input && (**input == 0x20 || **input == '\n')) {
        (*input)++;
    }
    // tokenise
    switch (**input) {
    case '{':
        (*input)++;
        return TOKEN_BLOCK_START;
    case '}':
        (*input)++;
        return TOKEN_BLOCK_END;
    case '[':
        (*input)++;
        return TOKEN_ARRAY_START;
    case ']':
        (*input)++;
        return TOKEN_ARRAY_END;
    case ':':
        (*input)++;
        return TOKEN_COLON;
    case ',':
        (*input)++;
        return TOKEN_COMMA;
    case '"':
        (*input)++;
        *token_value = *input;
        while (**input && **input != '"') {
            (*token_length)++;
            (*input)++;
        }
        if (**input == '"') {
            (*input)++;
        }
        // Maximal string length?
        return TOKEN_STRING;
    case 't':
        if (strncmp(*input, "true", 4) == 0) {
            (*input) += 4;
            return TOKEN_BOOL_TRUE;
        }
    case 'f':
        if (strncmp(*input, "false", 5) == 0) {
            (*input) += 5;
            return TOKEN_BOOL_FALSE;
        }
    case 'n':
        if (strncmp(*input, "null", 4) == 0) {
            (*input) += 4;
            return TOKEN_NULL;
        } else {
            // not bool
            (*input)++;
            return TOKEN_UNKNOWN;
        }
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        *token_value = *input;
        (*token_length)++;
        (*input)++;
        while ((**input <= '9' && **input >= '0') || **input == '.') {
            (*token_length)++;
            (*input)++;
        }
        return TOKEN_NUMBER;
    case '\0':
        return TOKEN_END;
    default:
        (*input)++;
        return TOKEN_UNKNOWN;
    }
}