#include<iostream>
#include<queue>
#include<vector>
#define max 20006
using namespace std;
struct node
{
	int a;
	int dist;
};
int main()
{
  int visit[max]={0};
  vector<int> a[max];
  int n,m;
  cin>>n>>m;
  int cnt=2;
  for(int i=0;i<n+m-1;i++)
  {
    int k;
    cin>>k;
    a[k].push_back(cnt);
    a[cnt].push_back(k);
    cnt++;
  } 
  queue <int> Q;
  visit[1]=1;
  Q.push(1);
  int len=0;
  int k1;
  while(!Q.empty())//DFS 
  {
    int front=Q.front();
    Q.pop();
    int size=a[front].size();
    for(int i=0;i<size;i++)
    {
      if(visit[a[front][i]]==0) 
      {
        Q.push(a[front][i]);
        visit[a[front][i]]=1;
        k1=a[front][i];
      }
    }
  }
  //cout<<k1<<"\n";
  for(int i=1;i<=n+m;i++)
  {
  	visit[i]=0;
	}
	visit[k1]=1;
	queue <node> Q1;
	node v;
	v.a=k1;
	v.dist=0;
	Q1.push(v);
	int kk=0;
	while(!Q1.empty())
	{
		node front=Q1.front(),u;
    Q1.pop();
    int size=a[front.a].size();
    if(front.dist>kk) kk=front.dist;
    for(int i=0;i<size;i++)
    {
      if(visit[a[front.a][i]]==0) 
      {
      	u.a=a[front.a][i];
      	u.dist=front.dist+1;
        Q1.push(u);
        visit[a[front.a][i]]=1;   
      }
    }
	}
	cout<<kk;
  //cout<<k1;
  return 0;
}
