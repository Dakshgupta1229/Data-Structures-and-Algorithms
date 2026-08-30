
class Node{
public:
    string val;
    Node* next;
    Node* prev;
    Node(string val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class BrowserHistory {
public:
    Node* curr = NULL;
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* t = new Node(url);
        curr->next = t;
        t->prev = curr;
        curr = t;
    }
    
    string back(int steps) {
        while(curr->prev!=NULL && steps>0){
            curr = curr->prev;
            steps--;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while(curr->next!=NULL && steps>0){
            curr = curr->next;
            steps--;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */