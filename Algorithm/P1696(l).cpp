#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int gcd(int x, int y){
	int z = y;
    while(x % y!=0)
    {
        z = x % y;
        x = y;
        y = z;
    }
    return z;
}
int a[1000], k = 0, fenzi = 1, fenmu = 1;
int main(){
	char s[1000];
	while(scanf("%s", s)!=EOF){
	memset(a, 0, sizeof(a));
	int l = strlen(s), q = 0;
	if(s[0] == '['){
		fenzi = 1; fenmu = 1;k = -1; q = 0;
		while(s[q] != ']') {
			if(s[q] >= '0' && s[q] <= '9') a[k] = a[k] * 10 + s[q] - '0';
			else k++;
			q++;
		}
		if(k == 0) {
			cout << a[0] << endl;continue;
		}
		fenmu = a[k];
		for(int i = 1; i < k; i++){
			int tmp2;
			tmp2 = fenmu * a[k - i] + fenzi;
			fenzi = fenmu;
			fenmu = tmp2;
		}
		fenzi += fenmu * a[0];
		int g;
		if( fenzi > fenmu ) g=gcd( fenmu, fenzi );
		else g = gcd(fenzi, fenmu);
		fenzi /= g; fenmu /= g;
		cout << fenzi << "/" << fenmu << endl;
	}
	else{
		int i; fenzi = 0; fenmu = 0;
		for(i = 0; s[i] != '/' && i < l ; i++) fenzi = fenzi * 10 + s[i] - '0';
		if( i == l ) {cout << '[' << fenzi << ']' << endl;}
		else{
		for(i++; i < l; i++) fenmu = fenmu * 10 + s[i] - '0';
		for(k = 0; ;k++){
			a[k] = fenzi / fenmu;
			int tmp = fenzi % fenmu;
			if(tmp == 0) break;
			fenzi = fenmu;
			fenmu = tmp;
		}

		if(k < 1) cout << "[" << a[0] << "]" << endl;
		else{
			cout << "[" << a[0] << ";";
			for(int i = 1; i < k; i++) cout << a[i] << ",";
			cout << a[k] << "]" << endl;
		}
		}
	}
	}
	return 0;
}
