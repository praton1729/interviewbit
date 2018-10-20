#define MAX 105
#define MOD 1000000007

int dp[MAX];
int nCk[MAX][MAX];
int log_2[MAX];

int choose(int n, int k){
    if(k>n) return 0;
    
    if(n<=1) return 1;
    
    if(k==0) return 1;
    
    if(nCk[n][k]!=-1) return nCk[n][k];
    
    int answer = choose(n-1, k-1) + choose(n-1, k);
    nCk[n][k] = answer;
    return answer;
}


int getleft(int n){
    if(n==1) return 1;
    
    int h = log_2[n];
    
    int numh = (1<<h);
    int last = n - (numh-1);
    
    if(last >= (numh/2)){
        return (numh-1);
    }
    else{
        return (numh - 1 - ((numh/2) - last));
    }
}

int n_max_heaps(int n){
    
    if(n<=1) return 1;
    
    if(dp[n]!=-1) return dp[n];
    
    int left = getleft(n);
    
    int ans = (n_max_heaps(left)%MOD)*choose(n-1, left)*n_max_heaps(n-1-left);
    
	ans %= MOD;
    dp[n] = ans;
    return ans;
}

int Solution::solve(int A) {
    
    int result;;
    int i,j;
    
    for(i=0;i<=A;i++){
        dp[i] = -1;
    }
    
    for(i=0;i<=A;i++){
        for(j=0;j<=A;j++){
            nCk[i][j] = -1;
        }
    }
    
    int current_log_2 = -1;
    int current_power_2 = 1;
    
    for(i=1;i<=A;i++){
        if(current_power_2==i){
            current_power_2 = current_power_2*2;
            current_log_2++;
        }
        log_2[i] = current_log_2;
    }
    
    result = n_max_heaps(A);
    return (result%MOD);
}

