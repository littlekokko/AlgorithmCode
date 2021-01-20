#include <iostream>
#include <cstdio>
#include <algorithm>
 using namespace std;
double a, b, c, d;
double f(double x)
{
    double ans = a*x*x*x + b*x*x + c*x + d;
    return ans;
}
int main()
{
    int tot = 2;
    cin >> a >> b >> c >> d;
    for(int i = -100; i <= 100; i++)
    {
        if(f(i) == 0)
        {
            printf("%.2lf",(double)i);
            if(!(tot--))
                putchar('\n');
            else
                putchar(' ');
            continue;
        }
        if(f(i) * f(i+1) < 0)
        {
            for(double k = (double)i; k <= (double)i+1.1; k += 0.001)
            {
                //cout << "f(k) = " << f(k) << " k = " << k <<  endl;
                if(f(k) < 0.001 && f(k) > -0.001)
                {
                    printf("%.2lf",k);
                    if(!(tot--))
                        putchar('\n');
                    else
                        putchar(' ');
                    break;
                }
            }
        }
    }
    return 0;
}
