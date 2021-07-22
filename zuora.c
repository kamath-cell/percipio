#include<stdio.h>
int ways(int,int);
int numberOfWaysForSum(int,int);

int ways(int t,int k)
{
	int M = 1000000007,W[t+1][k+1],i,j,m;
	for(j=1;j<=k;j++)
		W[0][j] = 1;
	for(i=0;i<=t;i++)
		W[i][1] = 1;
    for(i=1;i<=t;i++)
    {
    	for(j=2;j<=k;j++)
    	{
    		m = i-j;
    		if(m >= j || !m)
    			W[i][j] = (W[i][j-1]%M + W[m][j]%M)%M;
    		else if( i < j && m < 0)
    			W[i][j] = W[i][j-1];
    		else if(m < j && m > 0)
    			W[i][j] = (W[i][j-1]%M + W[m][m]%M)%M;
    	}
    }
    /*
    for(i=0;i<=t;i++)
    {
    	for(j=0;j<=k;j++)
    		printf("%d\t",W[i][j]);
    	printf("\n");
    }
    */
    return W[t][k];
}

int numberOfWaysForSum(int n, int k) {
  int a[k + 1][n + 1],M = 1000000007;
  for (int i = 1; i <= n; i++) {
    a[1][i] = 1;

  }
  for (int i = 1; i <= k; i++) {
    a[i][0] = 1;
  }
  for (int i = 2; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      if (j >= i) {
        a[i][j] = (a[i][j - i]%M + a[i - 1][j]%M)%M;

      } else {
        a[i][j] = a[i - 1][j];
      }

    }
  }
  return a[k][n];
}

int main(int argc, char const *argv[])
{
	printf("%d   %d\n\n",ways(5,3),numberOfWaysForSum(5,3));
	printf("%d   %d\n\n",ways(6,2),numberOfWaysForSum(6,2));
	printf("%d   %d\n\n",ways(20,7),numberOfWaysForSum(20,7));
	printf("%d   %d\n\n",ways(200,30),numberOfWaysForSum(200,30));
	return 0;
}