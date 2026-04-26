struct Node
{
    int value;
    int key;
    Node* prev;
    Node* next;
    Node(int k ,int v )
    {
        key=k;
        value=v;
        prev= nullptr;
        next=nullptr;
    }
};
class LRUCache {
    Node* head= new Node(-1,-1);
    Node* tail= new Node(-1,-1);
    int cap;
    int size;
    unordered_map<int,Node*> mp;

public:

    void remove(Node* node)
    {
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    void addfront(Node* node)
    {
        Node*temp=head->next;
        head->next=node;
        node->next=temp;
        temp->prev=node;
        node->prev=head;
    }

    void removelru()
    {
        Node* lru=tail->prev;
        lru->prev->next=tail;
        tail->prev=lru->prev;
        mp.erase(lru->key);
        size--;
        delete(lru);
    }

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        size=0;

    }
    
    int get(int key) {
        if (!mp.count(key))
        return -1;
        else{
            remove(mp[key]);
            addfront(mp[key]);
            return mp[key]->value;
        }
        
    }
    
    void put(int key, int value)
    {
        if (mp.count(key))
        {
            mp[key]->value=value;
            remove(mp[key]);
            addfront(mp[key]);
        }
        
        else
        {
            Node* newnode= new Node(key,value);
            if(size==cap)
            {
                removelru();     
            }
            mp[key]=newnode;
            addfront(newnode);
            size++;
        }
    }
};
