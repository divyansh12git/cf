#include <bits/stdc++.h> 
using namespace std; 

int lis[52][52][52][52]; 

int solve(int xx, int yy, int zz, int ww, vector<int>& uu) { 
  if (xx > yy) return 0; 
  if (xx == yy) { 
    if (uu[zz] < uu[xx] && uu[xx] <= uu[ww]) return 1; 
    return 0; 
  } 

  if (lis[xx][yy][zz][ww] != -1) return lis[xx][yy][zz][ww]; 
  int vv = max(solve(xx + 1, yy, zz, ww, uu), solve(xx, yy - 1, zz, ww, uu)); 
   
  if (uu[xx] >= uu[zz] && uu[xx] <= uu[ww]) { 
    vv = max(vv, 1 + solve(xx + 1, yy, xx, ww, uu)); 
    vv = max(vv, 1 + solve(xx + 1, yy - 1, zz, xx, uu)); 
    if (uu[yy] >= uu[zz] && uu[yy] <= uu[ww] && uu[xx] >= uu[yy]) 
        vv = max(vv, 2 + solve(xx + 1, yy - 1, yy, xx, uu)); 
  } 
   
  if (uu[yy] >= uu[zz] && uu[yy] <= uu[ww]) { 
    vv = max(vv, 1 + solve(xx, yy - 1, zz, yy, uu)); 
    vv = max(vv, 1 + solve(xx + 1, yy - 1, yy, ww, uu)); 
  } 

  return lis[xx][yy][zz][ww] = vv; 
} 

int main() { 
    int tt, rr = 1; 
    cin >> tt; 
    vector<int> ss(tt + 1, 0); 
    for (int mm = 0; mm < tt; mm++) cin >> ss[mm + 1]; 
    ss.push_back(1e9 + 1); 
    memset(lis, -1, sizeof(lis)); 
    cout << solve(1, tt, 0, tt + 1, ss); 

    return 0;
}
