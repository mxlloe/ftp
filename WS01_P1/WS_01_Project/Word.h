#pragma once
#include "Utils.h"

namespace sdds {
    const int MAX_WORD_LEN = 21;
    const int MAX_NO_OF_WORDS = 500;
    const int SORT_BY_OCCURANCE = 1;
    const int SORT_ALPHABETICALLY = 0;
    using namespace std;
    struct Word {
        char letters[MAX_WORD_LEN];
        int count;
    };

    char ToLower(char ch);
    int StrCmp(const char* s1, const char* s2);
    void StrCpy(char* des, const char* src);
    int StrLen(const char* str);
    bool isAlpha(char ch);
    void trim(char word[]);
    void toLowerCaseAndCopy(char des[], const char source[]);
    void addWord(Word words[], int* index, const char newWord[]);
    void print(const Word* w, bool gotoNextLine, int len);
    int findMaxLen(const Word words[], int noOfWords);
    void listWords(const Word words[], int noOfWords, const char* theTitle);
    void swap(Word* p1, Word* p2);
    void sort(Word words[], int cnt, int sortType);
    int totalCount(const Word* words, int num);
    void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
    void wordStats();
    void programTitle();






}
