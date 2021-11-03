#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

void fff(int *arr,int n,int k){
	std::deque<int> Qi(k);
	int i;
	for(i=0;i<k;++i){
		while((!Qi.empty()) && arr[i]>=arr[Qi.front()]) 
			Qi.pop_back();
		
		Qi.push_back(i);
		Qi.push_back(i);
	}
	for(;i<n;++i){
		printf("%d ",arr[Qi.front()]);
		while((!Qi.empty()) && Qi.front()<=i-k) 
			Qi.pop_front();

		while((!Qi.empty()) && Qi[i]>=arr[Qi.back()]) 
			Qi.pop_back();
		
		Qi.push_back(i);
	}
	printf("%d ",arr[Qi.front()]);

}
void printKMax(int * arr, int n, int k)
{
    std::deque<int>  Qi(k);
 
    int i;
    for (i = 0; i < k; ++i)
    {
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
        	Qi.pop_back();  // Remove from rear
 
        Qi.push_back(i);
    }
 
    for ( ; i < n; ++i)
    {
        printf("%d " , arr[Qi.front()]);
 
        while ( (!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front();  // Remove from front of queue
 
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
 
        Qi.push_back(i);
    }
 
    printf("%d " , arr[Qi.front()]);
}


int main(int argc , char * argv[]){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,k;
	scanf("%d",&n); int arr[n];
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	scanf("%d",&k);

	fff(arr,n,k);

	printf("\n");
	return 0;
}