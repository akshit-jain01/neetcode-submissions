class Solution {
public:
    int ladderLength(string startWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if(!dict.count(endWord))
        {
            return 0;
        }
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        dict.erase(startWord);

        while(!q.empty())
        {
            auto [word, level] = q.front();
            q.pop();

            if(word==endWord)
            {
                return level;
            }

            for(int i = 0; i<word.size();i++)
            {
                char orig = word[i];

                for(char c = 'a'; c<='z'; c++)
                {
                    if(c==orig)
                    {
                        continue;
                    }

                    word[i] = c;
                    if(dict.count(word))
                    {
                        q.push({word, level+1});
                        dict.erase(word);
                    }
                }
                word[i] = orig;
            }
        }
        return 0;
    }
};
