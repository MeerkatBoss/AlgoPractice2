#include <stack>
#include <cstdio>

#include "profilers.h"
#include "array_stack.h"
#include "list_stack.h"
#include "benchmarks.h"

int main()
{
    printf("%8s|%12s|%12s|%12s\n", "No.", "std", "array", "list");
    puts("--------+------------+------------+------------");
    run_benchmarks<stack_simple, stack_complex, stack_random>
        ::on_classes<std_stack, ArrayStack, ListStack>();
}