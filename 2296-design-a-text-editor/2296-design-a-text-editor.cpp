class TextEditor {
public:
    stack<char> before,after;
    TextEditor() {
        
    }
    
    void addText(string text) {
        for(int i=0; i<text.size(); i++)
            before.push(text[i]);
    }
    
    int deleteText(int k) {
        int x = 0;
        while(!before.empty() && k>0)
        {
            k--;
            before.pop();
            x++;
        }
        return x;
    }
    
    string cursorLeft(int k) {
        while(!before.empty() && k>0)
        {
            k--;
            after.push(before.top());
            before.pop();
        }
        string ans = "";
        while(!before.empty() && ans.size()<10)
        {
            ans.push_back(before.top());
            before.pop();
        }
        reverse(ans.begin(),ans.end());
        for(auto it:ans)
            before.push(it);
        return ans;
    }
    
    string cursorRight(int k) {
        while(!after.empty() && k>0)
        {
            k--;
            before.push(after.top());
            after.pop();
        }
        string ans = "";
        while(!before.empty() && ans.size()<10)
        {
            ans.push_back(before.top());
            before.pop();
        }
        reverse(ans.begin(),ans.end());
        for(auto it:ans)
            before.push(it);
        return ans;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */