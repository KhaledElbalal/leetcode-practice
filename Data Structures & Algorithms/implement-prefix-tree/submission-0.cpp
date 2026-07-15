class PrefixTree {
public:
    struct Node {
    char data;                  
    Node* children[26]; 
    bool termination = false;       
    Node(char val) {
            data = val;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    Node() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
    };

    vector<Node*> arr;
    PrefixTree() {
        arr = vector<Node*> (26);
    }
    
    void insert(string word) {
        int i = 1;
        if(!arr[word[0]-'a']) arr[word[0] - 'a'] = new Node(word[0]);
        Node* currentNode = arr[word[0] - 'a'];
        while(i != word.size()) {
            if(!currentNode->children[word[i] - 'a']) currentNode->children[word[i] - 'a'] = new Node(word[i]);
            currentNode = currentNode->children[word[i] - 'a'];
            i++;
        }
        currentNode->termination = true;
    }
    
    bool search(string word) {
        Node* currentNode = arr[word[0] - 'a'];
        int i = 1;
        while(i != word.size() && currentNode) {
            currentNode = currentNode->children[word[i] - 'a'];
            i++;
        }
        return currentNode && currentNode->termination;
    }
    
    bool startsWith(string prefix) {
        Node* currentNode = arr[prefix[0] - 'a'];
        int i = 1;
        while(i != prefix.size() && currentNode) {
            currentNode = currentNode->children[prefix[i] - 'a'];
            i++;
        }
        return currentNode;
    }
};
