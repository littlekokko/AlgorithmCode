#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
double p = 0.6180339887498949;
int n;
double w[10000];
int main(){
	int a, b, mid;
	a = 0;
	b = 0;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> w[i];
	sort(w, w + n);
	for(int i = 0; i < n - 1; i++){
		//二分搜索从小到大找到最后一个小于p的数k
		int begin = i, end = n - 1;
		while(end - begin > 1){
			int mid = (begin + end) / 2;
			if(w[i] / w[mid] < p)
                end = mid;
			else
                begin = mid;
		}

		//end和end+1和ans比较哪一个更接近p
		if(fabs(w[i] / w[end] - p) < fabs(w[a] / w[b] - p)){
			a = i;
			b = end;
		}
		if(fabs(w[i] / w[end - 1] - p) < fabs(w[a] / w[b] - p)){
			a = i;
			b = end - 1;
		}
	}
	cout << int(w[a]) << endl;
	cout << int(w[b]);
	return 0;
}
