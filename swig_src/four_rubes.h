#ifndef FOUR_RUBES_H
#define FOUR_RUBES_H

using namespace std;

/*
 * Abbreviate:
 *     rpn: reverse polish notation
 *     ion: in order notation
 */
#define MAXN 100

#include <string>
#include <cstring>

/* 
 * C++ style exception wrapper for python
 */
class InputError {};

bool is_lower_priority(char op_a, char op_b);
string ion_to_rpn(string ion);
int do_operation(int a, int b, char op);
int calculate(string ion);

#endif
