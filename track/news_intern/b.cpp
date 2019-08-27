#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> A;


int solution(vector<int> &A)
{
    int f[120000];
    int ans = A.size()+1, l = 0;
    int now_piece = 0, tot_piece=0;
    memset(f,0,sizeof(f));

    for (int i=0; i<A.size(); ++i)
        if (++f[A[i]] == 1) tot_piece++;

    memset(f,0,sizeof(f));
    for (int r=0; r<A.size(); ++r)
    {
        if (++f[A[r]] == 1)
            now_piece+=1;
        while (f[A[l]]>1) {f[A[l]]--,l++;}
        if (now_piece==tot_piece)
            ans = min(ans, r-l+1);
    }
    return ans;

}

int main()
{
    A.push_back(7);
    A.push_back(3);
    A.push_back(7);
    A.push_back(3);
    A.push_back(1);
    A.push_back(3);
    A.push_back(4);
    A.push_back(1);
    cout<<solution(A)<<endl;
    return 0;
}
