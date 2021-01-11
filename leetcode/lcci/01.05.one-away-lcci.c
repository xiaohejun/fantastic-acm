#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

bool oneEditAway(char* first, char* second){
    int firstLen = strlen(first);
    int secondLen = strlen(second);
    int diff = firstLen - secondLen;
    int absDiff = diff < 0 ? -diff : diff;
    if (absDiff > 1) {
        return false;
    }
    switch (diff) {
        case -1: { // can insert ?
            int cnt = 1;
            for (int i = 0, j = 0; j < secondLen; ++i, ++j) {
                if ((i < firstLen ? first[i] : '#') != second[j]) {
                    if (cnt) {
                        --cnt;
                        --i;
                    } else {
                        return false;
                    }
                }
            }
            break;
        }
        case 0: { // can replace ?
            int cnt = 1;
            for (int i = 0; i < firstLen; ++i) {
                if (first[i] != second[i]) {
                    if (cnt) {
                        --cnt;
                    } else {
                        return false;
                    }
                }
            }
            break;
        }
        case 1: { // can delete ?
            int cnt = 1;
            for (int i = 0, j = 0; i < firstLen; ++i, ++j) {
                if (first[i] != (j < secondLen ? second[j] : '#')) {
                    if (cnt) {
                        --cnt;
                        --j;
                    } else {
                        return false;
                    }
                }
            }
            break;
        }
        default:
            break;
    }
    return true;
}

int main()
{
    printf("%s\n", oneEditAway("pale", "palex") ? "True" : "False");
    //printf("%s\n", oneEditAway("pales", "pal") ? "True" : "False");
    return 0;
}