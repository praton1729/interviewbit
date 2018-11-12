void fib_terms_till(vector<int>& fib_array, int K)
{
		int i = 3;
		int next_term;
		fib_array.push_back(0);
		fib_array.push_back(1);
		fib_array.push_back(1);

		while(1)
		{
				next_term = fib_array[i-1] + fib_array[i-2];
				if(next_term>K) return;
				fib_array.push_back(next_term);
				i++;
		}
}

int Solution::fibsum(int A) {
		vector<int> fib_array;
		fib_terms_till(fib_array,A);
		int count=0;
		int j = fib_array.size()-1;

		while(A>0)
		{
				count+=(A/fib_array[j]);
				A = A%fib_array[j];
				j--;
		}
		return count;
}

