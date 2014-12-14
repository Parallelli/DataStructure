#include "stack.h"
#include <time.h>

int main()
{
    myStack stack;
    int n = 10;
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        int rnd = rand()%50;
        stack.push(rnd);
    }
  /*  
    stack.print();

    stack.pop();

    stack.print();

    int topvalue = stack.top();
    printf("top value = %d\n", topvalue);
*/    
    while(!stack.empty())
    {
        stack.print();
        stack.pop();
    }
    
    return 0;
}
