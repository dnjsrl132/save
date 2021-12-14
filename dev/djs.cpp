#include<iostream>
#include<vector>

using namespace std;

class Disjiont_set{
	private:
		vector<int> parent,rank;
	public:
		Disjiont_set(int size){
			parent.resize(size);
			rank.resize(size,1);
			for(int i=0;i<size;i++) parent[i]=i;
		}
		int find(int u){
			if(parent[u]==u) return u;
			parent[u]=find(parent[u]);
			return parent[u];
		}
		bool Same_set(int u,int v){
			return find(u)==find(v);
		}
		void merge(int u, int v){
			u=find(u);
			v=find(v);
			if(u==v) return ;
			if(rank[u]>rank[v]){
				int temp=u;
				u=v;
				v=temp;
			}
			parent[u]=v;
			if(rank[u]==rank[v]) rank[v]++;
		}
};

int main(){
	int n;
	int x,y;
	int i;
	cin>>n;
	Disjiont_set djs(2*n);
	for(i=0;i<n;i++){
		cin>>x>>y;
		djs.merge(x,y);
	}
	printf("0");
	printf("%d",djs.Same_set(x,y));
	return 0;
}

