#include <iostream>
using namespace std;

struct List
{
    int num;
    List *next;
};

List *head;

void reverse(int begin, int end, List *&head)
{
    if (begin == end) return;
    end -= begin;
    List* pre = new List;
    pre->next = head;
    for (int i = 0; i<begin; i++)
    {
      pre = pre->next;
    }
    List* pstart = pre->next;
    List* f = pstart;
    while (end--)
    {
      List *p = pstart->next;
      pstart->next = p->next;
      p->next = pre->next;
      pre->next = p;
    }
    if (begin == 0)
      head = pre->next;
    else
      f = pre->next;
}

List *Create()
{
    List *p = NULL;
    List *q = NULL;
    head = NULL;
    for ( int i = 0; i < 10; i++ ) {
        p = new List;
        p->num = i * 2;
        if ( head == NULL ) {
            head = p;
        }
        else {
            q->next = p;
        }
        q = p;
    }

    if ( head != NULL ) {
        q->next = NULL;
    }

    return head;
}

void displayList(List *head)
{
    while ( head != NULL ) {
        cout << head->num;
        head = head->next;
        if ( head != NULL ) {
            cout << "->";
        }
    }
    cout << endl;
}

int main() {
    Create();
    int begin, end;
    cin >> begin >> end;
    reverse(begin, end, head);
    displayList(head);
    return 0;
}
