class TrieNode
{
    public:
        TrieNode *children[26];
        bool isLeaf;

        TrieNode(){
            for(int i=0; i<26; i++)
            {
                children[i]= nullptr;
            }
            isLeaf = false;
        }      
};


class PrefixTree {
public:
    TrieNode *root;

    PrefixTree() {
        root = new TrieNode();
        
    }
    
    void insert(string word) {
        TrieNode *curr = root;

        for(char c: word)
        {
            if(curr->children[c- 'a'] == nullptr)   //create new node
            {
                curr->children[c - 'a'] = new TrieNode();
            }

            //move curr pointer to new
            curr = curr->children[c- 'a'];
        }
        //mark end
        curr->isLeaf = true;
        
    }
    
    bool search(string word) {
        TrieNode *curr = root;

        for(char c: word)
        {
            if(curr->children[c - 'a'] ==nullptr)
            {
                return false;
            }
            curr = curr->children[c -'a'];
        }
        return curr->isLeaf;
        
    }
    
    bool startsWith(string prefix) {
        //prefix search
        TrieNode *curr = root;

        for(char c: prefix)
        {
            if(curr->children[c-'a'] == nullptr)
            {
                return false;
            }
            curr = curr->children[c- 'a'];
        }

        return true;

    }
};
