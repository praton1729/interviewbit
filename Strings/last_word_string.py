
def lengthOfLastWord(A):

        def remove_trailing_spaces(s):
            
            i = 0
            while(s[i] == " "):
                i = i + 1
                
            return s[i:]
            
        def remove_preceeding_spaces(s):
            
            i = len(s)-1
            
            while(s[i]==" "):
                
                i = i -1
                
            return s[:i+1]
        
        A = remove_trailing_spaces(A)
        
        A = remove_preceeding_spaces(A)
        
        buffer_box = []
        
        for i in A:
            
            if(i == " "):
                
                buffer_box = []
                
            else:
                
                buffer_box.append(i)
                
        return len(buffer_box)

A = "   "
print lengthOfLastWord(A)
