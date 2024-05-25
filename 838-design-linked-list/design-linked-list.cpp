class Node{
public:
    int val;
    Node*next;
    Node(int x){
        this->val=x;
        this->next=nullptr;
    }
};
class MyLinkedList {
    private :
    Node*head;
    int size;
public:
    MyLinkedList() {
        this->head=nullptr;
        this->size=0;
        }
    
    int get(int index) {
        if(index<0 || index>=size) return -1;
        Node*temp=head;
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node*newNode= new Node(val);
        newNode->next=head;
        head=newNode;
        size+=1;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size += 1;
    }
    
    void addAtIndex(int index, int val) {
        if(index==0) {
            addAtHead(val);
            return;
        }
        if(index==size) {
            addAtTail(val);
            return;
        }
        if(index>size) return;
        Node*temp=head;
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        Node*newNode=new Node(val);
        newNode->next=temp->next;
        temp->next=newNode;
        size+=1;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size) return;
        if(index==0) {
            head=head->next;
            size-=1;
            return;
        }
        Node*temp=head;
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        Node*del=temp->next;
        temp->next=temp->next->next;
        size-=1;
        delete del;

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