/**
 * @file case_parser.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>

#define MAX_WORDS_P_FRAME 15u
#define MAX_CHARS_P_WORD 20u

static void word_tolower(uint8_t *word)
{
    for (size_t i = 0u; i < strlen(word); ++i)
    {
        word[i] = tolower(word[i]);
    }
}

uint8_t *camel_case(uint8_t *str)
{
    uint8_t words[MAX_WORDS_P_FRAME][MAX_CHARS_P_WORD];
    uint8_t words_count = 0u;
    uint8_t *word_ptr = NULL;
    uint8_t *camelcase = NULL;
    size_t camelcase_len = 0u;
    uint8_t *parsed_word = NULL;

    parsed_word = strtok(str, " _");
    if (parsed_word != NULL)
    {
        word_tolower(parsed_word);
        strncpy(words[words_count], parsed_word, MAX_CHARS_P_WORD);
        camelcase_len += strlen(words[words_count]);
        for (words_count = 1u; words_count < MAX_WORDS_P_FRAME; words_count++)
        {
            parsed_word = strtok(NULL, " _");
            if (parsed_word == NULL)
            {
                break;
            }

            word_tolower(parsed_word);
            parsed_word[0] = toupper(parsed_word[0]);
            strncpy(words[words_count], parsed_word, MAX_CHARS_P_WORD);
            camelcase_len += strlen(words[words_count]);
        }
    }

    camelcase = malloc(camelcase_len + 1);
    word_ptr = camelcase;

    for (uint8_t i = 0u; i < words_count; i++)
    {
        strcpy(word_ptr, &words[i][0]);
        word_ptr += strlen(words[i]);
    }

    return camelcase;
}

uint8_t *pascal_case(uint8_t *str)
{
    uint8_t *pascalcase = camel_case(str);
    pascalcase[0] = toupper(pascalcase[0]);

    return pascalcase;
}

uint8_t *snake_case(uint8_t *str)
{
    uint8_t words[MAX_WORDS_P_FRAME][MAX_CHARS_P_WORD];
    uint8_t words_count = 0u;
    uint8_t *word_ptr = NULL;
    uint8_t *snakecase = NULL;
    size_t snakecase_len = 0u;
    uint8_t *parsed_word = NULL;

    parsed_word = strtok(str, " _");
    if (parsed_word != NULL)
    {
        word_tolower(parsed_word);
        strncpy(words[words_count], parsed_word, MAX_CHARS_P_WORD);
        strcat(words[words_count], "_");
        snakecase_len += strlen(words[words_count]);
        for (words_count = 1u; words_count < MAX_WORDS_P_FRAME; words_count++)
        {
            parsed_word = strtok(NULL, " _");
            if (parsed_word == NULL)
            {
                break;
            }

            word_tolower(parsed_word);
            strncpy(words[words_count], parsed_word, MAX_CHARS_P_WORD);
            strcat(words[words_count], "_");
            snakecase_len += strlen(words[words_count]);
        }
    }

    snakecase = malloc(snakecase_len);
    word_ptr = snakecase;

    for (uint8_t i = 0u; i < words_count; i++)
    {
        strcpy(word_ptr, &words[i][0]);
        word_ptr += strlen(words[i]);
    }

    *(--word_ptr) = '\0';

    return snakecase;
}
