class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>>m;
        for(auto i :paths)
        {
            stringstream ss(i);
            istream_iterator<std::string> begin(ss);
            istream_iterator<std::string> end;
            vector<string> tokens(begin, end);
            for(int j=1;j<tokens.size();j++)
            {
                string names=tokens[0];
                if(names[names.size()-1]!='/')
                    names.push_back('/');
                int k=0;
                string data="";
                while(k<tokens[j].size() and tokens[j][k]!='(')
                    names.push_back(tokens[j][k++]);
                k++;
                while(k<tokens[j].size() and tokens[j][k]!=')')
                    data.push_back(tokens[j][k++]);
                m[data].push_back(names);
            }
        }
        vector<vector<string>>res;
        for(auto i:m)
            if(i.second.size()>1)
                res.push_back(i.second);
        return res;
    }
};