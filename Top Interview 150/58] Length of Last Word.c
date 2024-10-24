//This has a runtime of 0ms and Time complexity of O(N) and Space complexity of O(1).
//I found it little difficult to solve it in C
int lengthOfLastWord(char* s) {
    int length = 0;
    int i = strlen(s) - 1 ;
    while (i>=0 && isspace(s[i])){
        i--;
    }

    while (i>=0 && !isspace(s[i])){
        i--;
        length++;
    }

    return length;
}
