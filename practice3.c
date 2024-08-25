#include<newlink.h>

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};
 
struct Node* create_new(){
    return ((struct Node *)malloc(sizeof(struct Node)));
}

struct Node* copyRandomList(struct Node* head) {
    struct Node *new_head=NULL;
    struct Node *temp=NULL;
    while (head!=NULL){
        struct Node *new=create_new()
        new->val=head->val
        new->next=head->next
        new->random=head->random
        if (new_head==NULL){
            new_head=new
        }else{
            temp=new_head
            while (temp->next!=NULL)
                temp=temp->next
            temp->next=new
        }
        head=head->next
    }
	return new_head
}