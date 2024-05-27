class Node{
    public:
    string url;
    Node*prev;
    Node*next;
    Node(string ur){
        this->url=ur;
        prev=next=nullptr;
    }
};
class BrowserHistory {
private :
    Node*head;
    Node*cur;
public:
    BrowserHistory(string homepage) {
        head= new Node(homepage);
        cur=head;
    }
    
    void visit(string url) {
        Node*newNode=new Node(url);
        cur->next=newNode;
        newNode->prev=cur;
        cur=newNode;
    }
    
    string back(int steps) {
        while(steps && cur->prev){
            cur=cur->prev;
            steps-=1;
        }
        return cur->url;
    }
    
    string forward(int steps) {
        while(steps && cur->next){
            cur=cur->next;
            steps-=1;
        }
        return cur->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */