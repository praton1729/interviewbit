

def valid_char(ch):

	if('a' <= ch <= 'z' or '0' <= ch <= '9'):

		return True

	else:

		False

def isPalindrome(A):

	B = A.lower()

	n = len(B)	

	left = 0

	right = n-1

	while(left < right):

		if(valid_char(B[left]) and valid_char(B[right])):

			if(B[left]==B[right]):

				left = left + 1

				right = right - 1
				
				ret = 1
			else:

				return 0

		else:
			
			if( not valid_char(B[left]) ):

				left = left + 1

			if( not valid_char(B[right]) ):

				right = right -1

	return ret

#A = "A man, a plan, a canal: Panama"
A = "race a car"
print isPalindrome(A)

