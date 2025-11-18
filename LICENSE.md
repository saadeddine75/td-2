#include <stdio.h>
#include <stdlib.h>


char *LoadString(int N) {
    char *str = (char*)malloc(N * sizeof(char));
    scanf("%s", str);
    return str;
}

int StringLength(char *str) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void LoadArray(char *p,char arr[]) {
    int i = 0;
    while (p[i] != '\0') {
        arr[i] = p[i];
        i++;
    }
    arr[i] = '\0';
}

void ReverseArray(char arr[], char rev[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        rev[i] = arr[n - 1 - i];
    }
    rev[n] = '\0';
}

void DisplayArray(char arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%c", arr[i]);
}

int SumStringASCII(char *p) {
    int sum = 0, i = 0;
    while (p[i] != '\0') {
        sum += p[i];
        i++;
    }
    return sum;
}

void ReverseString(char *start, char *end) {
    if (start >= end)
        return;
    char temp = *start;
    *start = *end;
    *end = temp;
    ReverseString(start + 1, end - 1);
}

int main() {
    char *str;
    int n;

    printf("Please enter the maximum size of the string:\n");
    scanf("%d", &n);
    getchar();

    str = LoadString(n);
    int len = StringLength(str);
    char arr[len + 1], rev[len + 1];

    LoadArray(str, arr);
    printf("\n Original array: ");
    DisplayArray(arr, len);

    ReverseArray(arr, rev, len);
    printf("\n Reversed array: ");
    DisplayArray(rev, len);

    int sum = SumStringASCII(str);
    printf("\n Sum of ASCII values (recursive):%d ",sum);
    ReverseString(str, str + len - 1);
    printf("\nString reversed recursively: %s\n", str);

    free(str);
    return 0;
}
