#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_WORDS 1000
#define MAX_LENGTH 100
typedef struct {
    char word[MAX_LENGTH];
    int count;
} WordCount;
int findWordIndex(WordCount words[], int numWords, const char *word) {
    for (int i = 0; i < numWords; ++i)
        if (strcmp(words[i].word, word) == 0) 
            return i;
    return -1;
}
void main() {
    char paragraph[10000];
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;
    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);
    char *token = strtok(paragraph, " \n\t");
    while (token) {
        for (char *p = token; *p; ++p) 
            *p = tolower(*p);
        int index = findWordIndex(wordCounts, numWords, token);
        if (index == -1) {
            strncpy(wordCounts[numWords].word, token, MAX_LENGTH - 1);
            wordCounts[numWords].word[MAX_LENGTH - 1] = '\0';
            wordCounts[numWords].count = 1;
            ++numWords;
        } else
            ++wordCounts[index].count;
        token = strtok(NULL, " \n\t");
    }
    printf("Word frequencies:\n");
    for (int i = 0; i < numWords; ++i)
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
}
