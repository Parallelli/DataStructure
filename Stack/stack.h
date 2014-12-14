#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <assert.h>

using namespace std;

class myStack
{
    protected:
        vector<int>stk;
        int sz;
    public:
        myStack()
        {
            sz = 0;
        }
        void push(int val);
        void pop();
        int top();
        void print();
        bool empty();
};
