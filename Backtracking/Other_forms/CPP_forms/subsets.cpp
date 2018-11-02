#include<bits/stdc++.h>
using namespace std;

void subsets_util(vector<int> &A, vector<vector<int> > &result, vector<int> &subset,int index){

		for(int i = index;i<A.size();i++){
				subset.push_back(A[i]);
				result.push_back(subset);
				subsets_util(A,result,subset,i+1);
				subset.pop_back();
		}
		return;
}


vector<vector<int> > subsets(vector<int> &A) {

		sort(A.begin(),A.end());
		vector<int> subset;
		vector<vector<int> > result;

		result.push_back(subset);
		int index = 0;
		subsets_util(A,result,subset,index);
		return result;
}

