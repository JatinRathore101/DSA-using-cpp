#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
};

class Stack
{
    public:
        int size;
        Node* head=NULL;
        Stack()
        {
            head=NULL;
            size=0;
        }

        int getSize()
        {
            return size;
        }

        bool isEmpty()
        {
            if(head==NULL)
            {
                return true;
            }
            return false;
        }

        void push(int data)
        {
            size++;
            Node* element=new Node(data);
            element->next=head;
            head=element;
        }

        void pop()
        {
            if(head!=NULL)
            {
                Node* del=head;
                head=head->next;
                del->next=NULL;
                delete del;
                size--;
            }
        }

        int getTop()
        {
            if(head!=NULL)
            {
                return head->data;
            }
            return -1;
        }

        void disp()
        {
            Node* temp=head;
            while(temp!=NULL)
            {
                cout<<temp->data<<"  ";
                temp=temp->next;
            }
            cout<<endl;
        }

        ~Stack()
        {
            while(head!=NULL)
            {
                Node* del=head;
                head=head->next;
                del->next=NULL;
                delete del;
            }
        }
};

int main()
{
    Stack s;
    cout<<s.getSize()<<endl;
    s.push(11);s.push(21);s.push(17);s.push(33);s.push(29);s.push(42);
    cout<<s.getSize()<<endl;
    s.disp();
    s.pop();
    s.disp();
    cout<<s.getTop()<<endl;
    cout<<::boolalpha<<s.isEmpty()<<endl;
    s.pop();
    s.disp();
    cout<<s.getTop()<<endl;
    cout<<::boolalpha<<s.isEmpty()<<endl;
    return 0;
}

