/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 27, 2014
    Problem:    Text Justification 
    Source:     https://oj.leetcode.com/problems/text-justification/
    Note:

    Given an array of words and a length L, 
    format the text such that each line has exactly L characters and is fully (left and right) justified.

    You should pack your words in a greedy approach; 
    that is, pack as many words as you can in each line. 
    Pad extra spaces ' ' when necessary so that each line has exactly L characters.

    Extra spaces between words should be distributed as evenly as possible. 
    If the number of spaces on a line do not divide evenly between words, 
    the empty slots on the left will be assigned more spaces than the slots on the right.

    For the last line of text, 
    it should be left justified and no extra space is inserted between words.

    For example,

        words: ["This", "is", "an", "example", "of", "text", "justification."]
        L: 16.

    Return the formatted lines as:
    
        [
            "This    is    an",
            "example  of text",
            "justification.  "
        ]

    Note: Each word is guaranteed not to exceed L in length.

    Solution:   1.  Cut the plaintext into substring
                2.  If length of each substring less than L, 
                        add extra ' ' followed ' ' until length reach L.
 */ 


class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        int total = words.size();
        string line = "";
        int k=0;
        string blank = " ";

        while(k < total){
            if(line.size()+words[k].size() <= L)
                line += words[k];

            bool last_line;
            k+1<total ? last_line=false : last_line=true; 

            if(!last_line && line.size()+1+words[k+1].size()<=L){
                line += ' ';
                k++;
            }
            else{
                while(line.size() < L){
                    int origin_len = line.size();
                    for(int i=0; i<line.size() && line.size()<L && !last_line; i++){
                        if(line[i]==' '){
                            line.insert(i, blank);
                            while(line[i+1]==' ')
                                i++;
                        }
                    }

                    if(origin_len == line.size())
                        while(line.size()<L)
                            line += ' ';
                }
            }

            if(line.size()==L){
                result.push_back(line);
                line = "";
                k++;
            }
        }
        return result;
    
    }
};

int main(){
    std::vector<string> v;
    v.push_back("Here");
    v.push_back("is");
    v.push_back("an");
    v.push_back("example");
    v.push_back("of");
    v.push_back("text");
    v.push_back("justification.");
    Solution s;
    s.fullJustify(v, 14);
    return 0;
}
