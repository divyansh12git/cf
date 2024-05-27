#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string.h>
#include<cmath>
using namespace std;


#define INF 1e18
#define PI 3.141592653589793238462

#define ll long long
#define llfl(i,s,e) for(long long i=s;i<e;i++)
#define fl(i,s,e) for(int i=s;i<e;i++)


#define vsort(v) sort(v.begin(),v.end())
#define vreverse(v) reverse(v.begin(),v.end())

#define mapit(it,d1,d2,map) unordered_map<d1,d2>::iterator it=map.begin()
#define vecit(it,dt,vec) vector<dt>:: iterator it=vec.begin();

void solve(){
    //code here...
    int n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    fl(i,0,n)cin>>a[i];
    fl(i,0,n)cin>>b[i];
    int ans=0;
    int p1=n-1,p2=n-1;
    for(int i=n-1;i>=0;i--){
        if(a[p1]<=b[p2]){
            p1--;p2--;
        }else{
            p1--;
            ans++;
        }
    }
    cout<<ans<<endl;
        
    
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}



class Node{
    public:
    char data;
    Node* next;
    Node(char data){
        this->data=data;
        this->next=NULL;
    }
};
void insertAtHead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

int count(Node* &head){
    Node* temp=head;
    int count=0;
    while(temp!=head){
        count++;
        temp=temp->next;
    }
    return count;
}


// void solve(){
//     //code here...
//     int n;
//     cin>>n;
//     string s;
//     cin>>s;
//     Node* h=new Node(s[n-1]);
//     Node* t=h;

//     for(int i=n-2;i>=0;i--){
//         insertAtHead(h,s[i]);
//     }

//     t->next=h;
//     bool al=true;
//     while(count(h)>2){
//         Node* prev=t;
//         Node* curr=h;
//         Node* fr=curr->next;
//         bool x=true;
//         while(curr!=h || x){
//             x=false;
//         if(curr->data=='U'){
//             curr->next=NULL;
//             prev->next=fr;
//             prev->data=='U'?prev->data='D':prev->data='U';
//             fr->data=='U'?fr->data='D':fr->data='U';
//             if(curr==h){
//                 h=fr;
//             }if(curr==t){
//                 t=fr;
//             }
//         }
//         }
//     }


// }