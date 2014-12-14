#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(NULL){}
};

ListNode* deleteNode(int value, ListNode *head)
{
    if(!head) return head;
    ListNode *cur = head;
    ListNode *pre = head;
    if(head && head->val == value)
        return head->next;
    cur = head -> next;
    while(cur!=NULL)
    {
        if(cur->val == value)
        {
            pre->next = cur->next;
            break;
        }
        pre = cur;
        cur = cur->next;
    }
    return head;
}

void addNode(ListNode *last, int value)
{
    ListNode *tmp = new ListNode(value);
    last -> next = tmp;
}

void printList(ListNode *head)
{
    ListNode *tmp = head;
    while(tmp)
    {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}

void deDuplicate();
ListNode* insertNode(int pos, int value,  ListNode *head) //return new head
{
    ListNode *cur = head;
    if(pos == 1)
    {
        ListNode *tmp = new ListNode(value);
        tmp->next = head;
        return tmp;
    }
    int cntPos = 0;
    while(cntPos < pos-1 && cur != NULL)
    {
        cntPos++;
        cur = cur -> next;
    }
    ListNode *tmp = new ListNode(value);
    tmp->next = cur -> next;
    cur -> next = tmp;
    return head;
}

ListNode* detectCircle(ListNode *head); // return new head

int main()
{
    int a[] = {1,1,2,3,5,8,13};
    int n = 7;
    ListNode *head = new ListNode(a[0]);
    ListNode *cur = head;
    for(int i = 1; i < n; i++)
    {
        addNode(cur,a[i]);
        cur = cur -> next;
    }
    printf("after adding nodes\n");
    printList(head);
    head = deleteNode(5,head);
    printf("after deleting one node with value 5\n");
    printList(head);
    
    return 0;
}
