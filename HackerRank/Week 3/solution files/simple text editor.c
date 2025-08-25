#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000000
#define STACK_SIZE 100000


char *history[STACK_SIZE];
int top = -1;

void push(char *s) {
    history[++top] = strdup(s);
}

char* pop() {
    if (top < 0) return "";
    return history[top--];
}

int main() {
    int Q;
    scanf("%d", &Q);

    char S[MAX_LEN] = "";
    push(S);  

    for (int i = 0; i < Q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) { 
            char W[MAX_LEN];
            scanf("%s", W);
            strcat(S, W);
            push(S);
        }
        else if (type == 2) { 
            int k;
            scanf("%d", &k);
            int len = strlen(S);
            S[len - k] = '\0';
            push(S);
        }
        else if (type == 3) { 
            int k;
            scanf("%d", &k);
            printf("%c\n", S[k - 1]);
        }
        else if (type == 4) { // undo
            free(history[top--]);
            strcpy(S, history[top]); 
        }
    }
    return 0;
}
