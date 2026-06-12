class TrieNode {
    public:
        TrieNode * children[26];
        bool isLeaf;

        TrieNode(){
            for(int i=0; i<26; i++)
            {
                children[i]= nullptr;
            }
            isLeaf = false;
        }
    
};

class WordDictionary {
public:

    TrieNode *root;
    
    WordDictionary() {
        root = new TrieNode(); 
    }

    bool searchHelper(const string& word, int idx, TrieNode* node){
        //backtracking

        //base case
        if( idx == word.length())
        {
            return node->isLeaf;
        }

        char c = word[idx];

        // try all children
        if(c=='.')  
        {
            for(int i =0; i< 26; i++)
            {
                //constraint
                if(node->children[i]!= nullptr)
                {
                    //make choices
                    TrieNode *child = node->children[i];   

                    //explore recurse
                    if(searchHelper(word, idx+1, child))
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        else{
            // follow one child

            if(node->children[c- 'a']== nullptr)
            {
                return false;
            }

            return searchHelper(word, idx+1, node->children[c-'a']);   //child out os scope

        }
    }

    
    void addWord(string word) {
        //same as insert func

        TrieNode *curr = root;
        for(char c: word)
        {
            if(curr->children[c- 'a'] == nullptr )
            {
                //create a new node
                TrieNode *newNode = new TrieNode();

                //keep the reference
                curr->children[c -'a'] = newNode;
            }
            //move the curr pointer
            curr = curr->children[c -'a'];
        }
        //mark end
        curr->isLeaf = true;
        
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);

    }
};
