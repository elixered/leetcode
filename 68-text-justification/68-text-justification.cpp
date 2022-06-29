class Solution {
private:
    /*
    starts from words[index], try pack max number of words into a line
    return packed words in "lineWords"
    be aware "index" is passed as reference hence it will be changed for the entire solution
    */
    void packWords(const vector<string>& words, int maxWidth, int& index, vector<string>& lineWords) {
        while (index < words.size()) {
            int wordSize = words[index].size();
            if (wordSize > maxWidth) { // cant fit any more word
                break;
            }
            maxWidth -= words[index].size();
            --maxWidth; // count one space between words
            lineWords.push_back(words[index]);
            ++index; // point index to next available word
        }
    }
    
    /*
    justify words to left side for last line and for the line with only one word
    return justified result in "line"
    */
    void leftJustify(const vector<string>& words, int maxWidth, string& line) {
        for (int i = 0; i < words.size(); ++i) {
            line += words[i];
            if (i != words.size() - 1) { // append one space for each word, except last word
                line += " ";
            }
        }
        
        // append spaces to fill up the line
        int extraSpaces = maxWidth - line.size();
        line.append(extraSpaces, ' ');
    }
    
    /*
    fully justify one line
    return justified result in "line"
    */
    void fullJustify(const vector<string>& words, int maxWidth, string& line) {
        if (words.size() == 1) { // for lines with only one word we should do left justify
            leftJustify(words, maxWidth, line);
            return;
        }
        
        int totalCharLen = 0;
        for (const auto& word : words) {
            totalCharLen += word.size();
        }
        
        int totalSpaces = maxWidth - totalCharLen;
        int spaceSize = totalSpaces / (words.size() - 1);
        int extraSpaces = totalSpaces % (words.size() - 1);
        for (int i = 0; i < words.size(); ++i) {
            line += words[i];
            if (i != words.size() - 1) { // append spaces for each word except last one
                line.append(spaceSize, ' ');
                if (extraSpaces > 0) {
                    line += " ";
                    --extraSpaces;
                }
            }
        }
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> output;
        string line = "";
        vector<string> lineWords; // words to fit into each line
        int index = 0;
        while (index < words.size()) { // loop through all words
            packWords(words, maxWidth, index, lineWords);
            if (index < words.size()) {
                fullJustify(lineWords, maxWidth, line);
            }
            else {
                leftJustify(lineWords, maxWidth, line);
            }
            output.push_back(line);
            
            // clear cache and start processing a new line
            line.clear();
            lineWords.clear();
        }
        return output;
    }
};