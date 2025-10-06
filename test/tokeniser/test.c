#include "../inc/json.h"

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    (void) argc;
    (void) argv;

    char *token_name[] = {
        "TOKEN_BLOCK_START",
        "TOKEN_BLOCK_END",
        "TOKEN_ARRAY_START",
        "TOKEN_ARRAY_END",
        "TOKEN_STRING",
        "TOKEN_NUMBER",
        "TOKEN_BOOL_TRUE",
        "TOKEN_BOOL_FALSE",
        "TOKEN_COLON",
        "TOKEN_COMMA",
        "TOKEN_NULL",
        "TOKEN_END",
        "TOKEN_UNKNOWN",
        "TOKEN_ERROR"
    };
    
    char buffer[BUFFER_SIZE];
    char *buffer_pointer = NULL;
    char output[BUFFER_SIZE];
    char *value_pointer = NULL;
    int value_length = 0;
    int token = 13;

    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        buffer_pointer = buffer;
        while ((token = get_token(&buffer_pointer, &value_pointer, &value_length)) != TOKEN_END) {
            memcpy(output, value_pointer, value_length);
            output[value_length] = '\0';
            printf("%s: %s\n", token_name[token], output);
        }
    }
    return(0);
}