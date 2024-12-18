char stack[10000];
int top;

void push(char symbol){
    stack[++top] = symbol;
}

char pop(){
    if(top ==-1){
        return false;
    }
    return stack[top--];
}

bool Matching(char next, char symbol){
    return((next=='(' && symbol==')')||
    (next=='{' && symbol=='}')||
    (next=='[' && symbol==']'));
}

bool isValid(char* s) {
    int i=0; top = -1;
    char symbol, next;
    while(*(s+i)!='\0'){
        symbol = *(s+i);
        switch (symbol){
            case '(':
            case '{':
            case '[': push(symbol);
            break;
            case ')':
            case '}':
            case ']':if (top == -1){
                return false;
            }
            next = pop();
            if (!Matching(next,symbol)){
                return false;
            }
            break;
        }
        i++;
    }
    return top == -1;
}
