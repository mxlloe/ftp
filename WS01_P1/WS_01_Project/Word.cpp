#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Word.h"
#include "Utils.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

namespace sdds
{
    char ToLower(char ch) {
        if (ch >= 'A' && ch <= 'Z') ch += ('a' - 'A');
        return ch;
    }

    int StrCmp(const char* s1, const char* s2) {
        int i;
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }

    void StrCpy(char* des, const char* src) {
        int i;
        for (i = 0; src[i]; i++) des[i] = src[i];
        des[i] = 0;
    }

    int StrLen(const char* str) {
        int len;
        for (len = 0; str[len]; len++);
        return len;
    }

    bool isAlpha(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

    void trim(char word[]) {
        int i;
        while (word[0] && !isAlpha(word[0])) {
            StrCpy(word, word + 1);
        }
        i = StrLen(word);
        while (i && !isAlpha(word[i - 1])) {
            word[i-- - 1] = 0;
        }
    }

    void toLowerCaseAndCopy(char des[], const char source[]) {
        int i = 0, j = 0;
        for (; source[i] != 0; i++) {
            des[j++] = ToLower(source[i]);
        }
        des[j] = 0;
    }

    int searchWords(const Word words[], int num, const char word[]) {
        int i;
        int foundIndex = -1;  // will be set to found index; if not found sould be less than 0
        for (i = 0; foundIndex == -1 && i < num; i++) { // while not found and i is less than number of words
            if (StrCmp(words[i].letters, word) == 0) { // if word is already read and found in the list of previous words
                foundIndex = i;   // set the index to be returned.
            }
        }
        return foundIndex;
    }

    void addWord(Word words[], int* index, const char newWord[]) {
        StrCpy(words[*index].letters, newWord);
        words[*index].count++;
        (*index)++;
    }

    void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord) {
        cout << "Total number of words used: " << totNoWrds << endl;
        cout << "Total number of words overall: " << totalOverAll << endl;
        cout << "Longest word used had " << longestWord << " characters." << endl;
    }
    void print(const Word* w, bool gotoNextLine, int len) { // uses iomanip header file
        cout << setw(len) << left << w->letters;
        cout << setw(3) << right << w->count;
        if (gotoNextLine) cout << endl;
    }
    int findMaxLen(const Word words[], int noOfWords) {
        int longest = 0;
        int i;
        for (i = 0; i < noOfWords; i++) {
            if (longest < StrLen(words[i].letters))
                longest = StrLen(words[i].letters);
        }
        return longest;
    }
    void listWords(const Word words[], int noOfWords, const char* theTitle) {
        int i;
        int maxLen = findMaxLen(words, noOfWords);
        title(theTitle, maxLen);
        for (i = 0; i < noOfWords; i++) {
            print(&words[i], true, maxLen);
        }
        endList();
    }
    void swap(Word* p1, Word* p2) {
        Word w;
        w = *p1;
        *p1 = *p2;
        *p2 = w;
    }
    void sort(Word words[], int cnt, int sortType) {
        int i, j;
        for (i = 0; i < cnt - 1; i++) {
            for (j = 0; j < cnt - i - 1; j++) {
                if (sortType == SORT_BY_OCCURANCE) {
                    if (words[j].count < words[j + 1].count) {
                        swap(&words[j], &words[j + 1]);
                    }
                }
                else if (sortType == SORT_ALPHABETICALLY) {
                    if (StrCmp(words[j].letters, words[j + 1].letters) > 0) {
                        swap(&words[j], &words[j + 1]);
                    }
                }
                else {

                }
            }
        }
    }
    int totalCount(const Word* words, int num) {
        int total = 0;
        do {
            total += words[--num].count;
        } while (num);
        return total;
    }
    void wordStats() {
        Word words[MAX_NO_OF_WORDS] = { {"",0} };
        char word[MAX_WORD_LEN];
        char lowerCaseWord[MAX_WORD_LEN];
        int NoOfWords = 0;
        int maxLen = 0;
        int foundIndex = 0;
        int wordCount = 0;
        while (cin >> word) {
            trim(word);
            toLowerCaseAndCopy(lowerCaseWord, word);
            if (lowerCaseWord[0] != 0) {
                wordCount++;
                if (maxLen < StrLen(lowerCaseWord)) {
                    maxLen = StrLen(lowerCaseWord);
                }
                if (NoOfWords == 0) {
                    addWord(words, &NoOfWords, lowerCaseWord);
                }
                else {
                    foundIndex = searchWords(words, NoOfWords, lowerCaseWord);
                    if (foundIndex < 0) { // word not found in list; so word is new and never read before
                        foundIndex = NoOfWords;
                        addWord(words, &NoOfWords, lowerCaseWord);
                    }
                    else {
                        words[foundIndex].count++;
                    }
                }
            }
        }
        cout << "---------------------------------------------------" << endl <<
            "Read " << wordCount << " words!" << endl <<
            "---------------------------------------------------" << endl;
        sort(words, NoOfWords, 1);
        listWords(words, NoOfWords, "List of words Sorted by occurance");
        sort(words, NoOfWords, 0);
        listWords(words, NoOfWords, "List of words Sorted alphabetically");
        totalWordsStat(NoOfWords, totalCount(words, NoOfWords), maxLen);
    }


}