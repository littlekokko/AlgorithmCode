#include<iostream>
#include<string>
using namespace std;
const int p[24][2] = { {1, 5}, {1, 2}, {2, 3}, {2, 6}, {3, 4}, {3, 7}, {4, 8}, {5, 6}, {5, 9}, {6, 7}, {6, 10}, {7, 8}, {7, 11}, {8, 12}, {9, 13}, {9, 10}, {10, 11}, {10, 14}, {11, 12}, {11, 15}, {12, 16}, {13, 14}, {14, 15}, {15, 16}};
int state[100000];
int matrix[16];
void getmatrix(int x){
	for(int i = 0; i < 16; i++){
		matrix[i] = x % 2;
		x = x / 2;
	}
}
int getstate(int x[]){
	int y = 0, w = 1;
	for(int i = 0; i < 16; i++){
		y += x[i] * w;
		w *= 2;
	}
	return y;
}
int main(){
	int en[16], ans = 0, result, length = 0, z = 0;
	int k = 0;
	string st[10];
	//输入
	for(int i = 0; i < 8; i++)
		cin >> st[i];
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			matrix[k++] = st[i][j] - '0';
	k = 0;
	for(int i = 4; i < 8; i++)
		for(int j = 0; j < 4; j++)
			en[k++] = st[i][j] - '0';
	result = getstate(en);
	//初始化队列，设置2个标记
	state[length++] = getstate(matrix);
	int b = 0, e;

	//状态转移
	while(++ans){
		e = length;
		for(; b < e; b++){
			for(int i = 0; i < 24; i++){
				getmatrix(state[b]);
				int tmp = matrix[p[i][0] - 1];
				matrix[p[i][0] - 1] = matrix[p[i][1] - 1];
				matrix[p[i][1] - 1] = tmp;
				int s = getstate(matrix);
				if(s == result) {
					z = 1;
					break;
				}
				int re = 0;
				for(int j = 0; j < length; j++)
					if(state[j] == s) {
						re = 1;
						break;
					}
				if(!re) state[length++] = s;
			}
			if(z == 1) break;
		}
		if(z == 1) break;
	}
	cout << ans << endl;
	return 0;
}
