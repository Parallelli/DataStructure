#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;

struct LinkedList
{
    int val;
    LinkedList *next;
    LinkedList(){}
    LinkedList(int v):val(v), next(NULL){}
};

void deleteNode(int val);
void deDuplicate();
LinkedList* detectCircle(LinkedList *head); // return new head

