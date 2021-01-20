class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int l = 256;
        int n = 0;
        long long sum = 0;
        int minx = 0;
        int maxx = 0;
        double p = 0.0;
        int znum = 0;
        int zx = 0;
        for( int i = 0; i < l; i++ ){
            n += count[ i ];
            sum += i * count[ i ];
            if( count[ i ] && !minx ) minx = i;
            if( count[ i ] ) maxx = i;
            if( count[ i ] > zx ){ zx = count[ i ]; znum = i;}
        }
        if( count [ 0 ] != 0 ) minx = 0;
        double zwnum = 0;
        int zw,zwx,t;
        p = (sum * 1.0) / n;
        if( n == 1 ){
            zwnum = sum;
        }
        else if( n % 2 ){
            zw = ( n + 1 ) / 2;
            zwx = 0;
            t = 0;
            while( zwx < zw && t < l){
                if( zwx + count[ t ] < zw ){
                    zwx += count[ t ];
                    t++;
                }
                if( zwx < zw && zwx + count[ t ] > zw ){
                    zwnum = t;
                    break;
                }
            }
        }
        else{
            zw = n / 2;
            zwx = 0;
            t = 0;
            while( zwx < zw && t < l ){
                if( zwx + count[ t ] < zw ){
                    zwx += count[ t ];
                    t++;
                }
                if(zwx < zw && zwx + count[ t ] > zw) {
                    zwnum = t;
                    break;
                }
                if( zwx + count[ t ] == zw ){
                    zwnum = t;
                    t++;
                    while( count[ t ] == 0 && t < l) t++;
                    zwx = zwnum + t;
                    zwnum = zwx * 1.0 / 2;
                }
            }
        }
        vector <double> ans;
        ans.push_back(minx);
        ans.push_back(maxx);
        ans.push_back(p);
        ans.push_back(zwnum);
        ans.push_back(znum);
        return ans;
    }
};
