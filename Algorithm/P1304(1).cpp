#include<iostream>
#include<string>
using namespace std;
bool huiwen(int a[], int l){
	for(int i = 0; i < l; i++) if(a[i] != a[l - i - 1]) return false;
	return true;
}
int N, tmp = 0, l, state = 0; string M; int a[100], b[100], c[100];
int main(){
	cin >> N >> M;
	for(int i = 0; i < M.length(); i++){
		if(M[i] - '9' <= 0) a[i] = M[i] - '0';
		else a[i] = M[i] - 'A' + 10;

	}
	l = M.length();
	for(int k = 0; k < 30; k++){
		tmp = 0;
		for(int i = 0; i < l; i++){
			b[i] = a[i] + a[l - 1 - i];
		}

		//大数加法
		for(int i = 0; i < l; i++){
			b[ i ] += tmp;
			a[ i ] = b[ i ] % N;
			tmp = b[ i ] / N;
		}
		if( tmp ) a[ l++ ] = tmp;
		if(huiwen(a, l)){
			cout << "STEP=" << k + 1 << endl;
			state = 1;
			break;
		}
	}
	if(!state) cout << "Impossible!" << endl;

	return 0;
}
