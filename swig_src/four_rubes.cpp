#include "four_rubes.h"

/* 
 * Impletation
 */
InputError input_error;

bool is_lower_priority(char op_a, char op_b) {
    /*
     * return priority between two operators
     */
    if (op_a == '+' || op_b == '-') {
        if (op_b == '*' || op_b == '\\') {
            return true;
        }
    }
    return false;
}

string ion_to_rpn(string ion) {
    /*
     * Return reverse polish notation from in order notation,
     * If input is error, return 'error'.
     */
    string rpn = "";

    char stack[MAXN] = {'\0'};
    int top = 0;
    
    for (int i = 0; i < ion.length(); i++) {
        char cur = ion[i];
        if (cur >= '0' && cur <= '9') {
            rpn.push_back(cur);
        } else if (cur == '(') {
            stack[top++] = cur;
        } else if (cur == ')') {
            bool is_match = false;
            while (top > 0) {
                int temp = stack[--top];
                if (temp == '(') {
                    is_match = true;
                    break;
                } else {
                    rpn.push_back(temp);                    
                }
            }
            if (!is_match) {
                throw input_error;
            }
        } else {
            if (top > 0) {
                if (is_lower_priority(cur, stack[top - 1])) {
                    while (top > 0) {
                        int temp = stack[--top];
                        if (temp == '(') {
                            break;
                        } else {
                            rpn.push_back(temp);                   
                        }
                    }
                }
            }
            stack[top++] = cur;
        }
    }

    while (top > 0) {
        // mis match check
        if (stack[top - 1] == '(') {
            throw input_error;
        }
        rpn.push_back(stack[--top]);
    }
    
    return rpn;
}

int do_operation(int a, int b, char op) {
    /*
     * Return result of noraml arthematic operation
     */
    int result = 0;
    switch (op) {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    }

    return result;
}

int calculate(string ion) {
    /*
     * Calculate in order string to get result
     */
    string rpn = ion_to_rpn(ion);

    int stack[MAXN] = {0};
    int top = 0;
    for (int i = 0; i < rpn.length(); i++) {
        int cur = rpn[i];
        if (cur >= '0' && cur <= '9') {
            stack[top++] = cur - '0';            
        } else {
            int a = stack[--top];
            stack[top - 1] = do_operation(stack[top - 1], a, cur);
        }
    }
    return stack[top - 1];
}
