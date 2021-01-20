#include<iostream>
#include<algorithm>
using namespace std;

int a[1000];
int b[1000];

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)break;
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < n; i++)cin >> b[i];
		sort(a, a + n);
		sort(b, b + n);
		int lowa = 0, lowb = 0, higha = n - 1, highb = n - 1, sum = 0;
		while (lowa <= higha)
		{
			if (a[lowa] < b[lowb])
			{
				lowa++;
				highb--;
				sum--;
			}
			else if (a[lowa]>b[lowb])
			{
				lowa++;
				lowb++;
				sum++;
			}
			else
			{
				if (a[higha]>b[highb])
				{
					higha--;
					highb--;
					sum++;
				}
				else
				{
					sum -= (a[lowa] < b[highb]);
					lowa++;
					highb--;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
