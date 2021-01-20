#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int MAX_LEN=1000;
int maxLen[MAX_LEN+1][MAX_LEN+1];
int bigest=0;

int conLCS(string s1,string s2){

	for(int i=0;i<=s1.length();i++) maxLen[i][0]=0;
	for(int i=0;i<=s2.length();i++) maxLen[0][i]=0;
	for(int i=1;i<=s1.length();i++){
		for(int j=1;j<=s2.length();j++){
			if(s1[i-1]==s2[j-1]){
				maxLen[i][j]=maxLen[i-1][j-1]+1;
				if(maxLen[i][j]>bigest) bigest=maxLen[i][j];

			}
			else maxLen[i][j]=0;

		}
	}
	return bigest;
}
int main(){
    string s1,s2;
    string st;
    cin >> st;
    int p = 0;
    while( p < st.length() ){
        p++;
        if( st[ p ] == ',' ) break;
    }
    s1 = st.substr( 0, p );
    s2 = st.substr(p + 1 ,st.length() - p - 1 );
	cout<<conLCS(s1,s2)<<endl;
    return 0;
}
