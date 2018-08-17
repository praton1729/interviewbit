
class Solution:

    # @param A : string

    # @return an integer

    def isNumber(self, A):

        def isdigit(x):

            if('0' <= x <= '9'):

                return 1

            else:

                return 0

        b = A.strip()
        
        if(len(b)==0):

            return 0
            
        if(len(b)==1 and not isdigit(b[0])):

            return 0
            
        if (b[0]!='+' and b[0]!='-' and not isdigit(b[0]) and b[0]!='.'):

            return 0

        # // To check if a '.' or 'e' is found in given

        # // string. We use this flag to make sure that

        # // either of them appear only once.

        flagDotOrE = 0

        # for (int i=1; i<str.length(); i++)

        for i in range(1,len(b)):

            # // If any of the char does not belong to

            # // {digit, +, -, ., e}

            if (not isdigit(b[i]) and b[i] != 'e' and b[i]!='.' and b[i] != '+' and b[i]!='-'):

                return 0

            if (b[i] == '.'):

                # // checks if the char 'e' has already

                # // occurred before '.' If yes, return 0.

                if (flagDotOrE == 1):

                    return 0

                # // If '.' is the last character.

                if (i+1 >= len(b)):

                    return 0

                # // if '.' is not followed by a digit.

                if (not isdigit(b[i+1]) and b[i+1] != '+' and b[i+1] != '-'):

                    return 0

            elif(b[i] == 'e'):

                # // set flagDotOrE = 1 when e is encountered.

                flagDotOrE = 1

                # // if there is no digit before 'e'.

                if (not isdigit(b[i-1])):

                    return 0

                # // If 'e' is the last Character

                if (i+1>=len(b)):

                    return 0

                # // if e is not followed either by

                # // '+', '-' or a digit

                if (not isdigit(b[i+1]) and b[i+1] != '+' and b[i+1] != '-'):

                    return 0

        # /* If the string skips all above cases, then

        #   it is numeric*/

        return 1

a = Solution()

A = " 0.1"

print a.isNumber(A)

