class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss, st;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] =='#')
        {
            if(ss.empty())
            {
                continue;
            }
            else
            {
                ss.pop();
            }
        }
        else
        {
            ss.push(s[i]);
        }
    }

    for(int i = 0; i < t.length(); i++)
    {
        if(t[i] =='#')
        {
            if(st.empty())
            {
                continue;
            }
            else
            {
                st.pop();
            }
        }
        else
        {
            st.push(t[i]);
        }
    }

    if(st.size() != ss.size())
    {
        return false;
    }

    while(!ss.empty())
    {
        if(st.top() != ss.top())
        {
            return false;
        }

        st.pop();
        ss.pop();
    }

    return true;
    }
};