class Node{
    public:
    int value;
    Node*next;
    Node(int v){
        this->value=v;
        this->next=nullptr;
    }

};
class MyLinkedList {
private:
    Node*head;
    int size;    
public:
    MyLinkedList() {
        head=nullptr;
        size=0;
    }
    
    int get(int index) {
       if (index < 0 || index >= size) return -1;
        Node*temp=head;
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        return temp->value;
    }
    
    void addAtHead(int val) {
        Node*newNode= new Node(val);
        newNode->next=head;
        head=newNode;
        size+=1;
    }
    
    void addAtTail(int val) {
        if(head==nullptr) {
            addAtHead(val);
            return;
        }
        Node*temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=new Node(val);
        size+=1;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size) return;
        Node*newNode=new Node(val);
        Node*temp=head;
        if(index==0) {
            addAtHead(val);
            return;
        }
        for(int i=1;i<index;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        size+=1;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return ;
        if(index==0) {
            head=head->next;
            size-=1;
            return;
        }
        Node*temp=head;
        for(int i=1;i<index;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        size-=1;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */