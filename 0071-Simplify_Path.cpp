// My solution -- state machine?
class Solution {
    public:
    string simplifyPath(string path) {
        vector<string> stack;
        string res;
        // parser
        string s;
        bool dot = false;
        bool dotdot = false;
        bool slash = false;
        path.append(1, '/');
        for(int i=0; i<path.size(); ++i){
            auto e = path[i];
            switch(e){
                case '/':
                    if(dotdot){
                        if(!s.empty()){
                            s.clear();
                        }else if(!stack.empty()){
                            stack.pop_back();
                        }
                        dotdot = false;
                    }
                    else if(dot){
                        dot = false;
                    }
                    else if(!s.empty()){
                        stack.push_back(s);
                        s.clear();
                    }
                    slash = true;
                    break;
                case '.':
                    if(slash){
                        dot = true;
                        slash = false;        
                    }else if(dot){
                        dot = false;
                        dotdot = true;
                    }else if(dotdot){
                        s += "...";
                        dotdot = false;
                    }else{
                        s += ".";
                    }
                    break;
                default:
                    slash = false;
                    if(dot){
                        s += ".";
                        dot = false;                       
                    }                       
                    else if(dotdot){
                        s += "..";
                        dotdot = false;                        
                    }                        
                    s.append(1, e);
            }
        }
        for(const auto& e: stack){
            res += "/" +  e;
        }
        return res.empty()?"/":res;
    }
};
