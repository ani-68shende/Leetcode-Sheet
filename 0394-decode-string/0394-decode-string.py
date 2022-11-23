class Solution:
    
    #->> curN
    #->> curS
    def decodeString(self, s: str) -> str:
        st = []
        curN = 0
        curS = ""
        for c in s:
            if c == '[':
                st.append(curS)
                st.append(curN)
                curN = 0
                curS = ""
            elif c == ']':
                num = st.pop()
                prevS = st.pop()
                curS = prevS + num*curS;
            elif c>='0' and c<='9':
                curN = curN*10 + int(c)
            else:
                curS += c;
        return curS;