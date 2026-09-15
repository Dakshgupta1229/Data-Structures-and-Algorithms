class Node{
public:
    string val;
    Node* next;
    Node* prev = NULL;
    Node(string val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class BrowserHistory {
public:
    Node* head;
    Node* tail;
    int size;
    BrowserHistory(string homepage) {
        Node* t = new Node(homepage);
        head = t;
        tail = t;
        size = 0;

    }
    
    void visit(string url) {
        Node* t = new Node(url);
        tail->next = t;
        t->prev = tail;
        tail = t;
        size++;
    }
    
    string back(int steps) {
        Node* temp = tail;
        while(steps>0 && temp->prev!=NULL){
            temp = temp->prev;
            steps--;
        }
        tail = temp;
        return temp->val;
    }
    
    string forward(int steps) {
        Node* temp = tail;
        while(steps>0 && temp->next!=NULL){
            temp = temp->next;
            steps--;
        }
        tail = temp;
        return tail->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */