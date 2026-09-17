class OrderedStream {
public:
    map<int,string> m;
    int n;
    int ptr = 1;
    OrderedStream(int n) {
        this->n = n;
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> v;
        m[idKey] = value;
        for(int i=ptr;i<=n;i++){
            if(m.find(i)!=m.end()) v.push_back(m[i]);
            else{
                ptr = i;
                break;
            }
        }
        return v;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */