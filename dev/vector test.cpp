#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	vector<string> makit;
	
	makit.push_back("python");
	makit.push_back("C++");
	makit.push_back("java");
	makit.push_back("scratch");
	makit.push_back("data_structrue");
	
	for(int i=0;i<makit.size();i++) cout<<makit[i]<<" ";
	
	cout<<endl;
	cout<<"scratch 삭제"<<endl;
	makit.erase(makit.begin()+3);
	
	for(int i=0;i<makit.size();i++) cout<<makit[i]<<" ";
	
	cout<<endl;
	cout<<"java찾아서 제거"<<endl;
	
	vector<string>::iterator it = find(makit.begin(),makit.end(),"java");
	
	makit.erase(it);
	
	for(int i=0;i<makit.size();i++) cout<<makit[i]<<" ";
	
	cout<<endl;
	cout<<"수업명 추가"<<endl;
	
	makit.insert(makit.begin()+2,"swift");
	makit.insert(makit.end(),"algorithm");
	
	for(int i=0;i<makit.size();i++) cout<<makit[i]<<" ";
	cout<<endl;
	cout<<"전체 수업 개수 : "<<makit.size()<<endl;
	
	cout<<"전체수업 초기화 "<<endl;
	makit.clear();
	
	if(makit.empty())	cout<<"수업이 비어있습니다."<<endl;
	else	cout<<"전체 수업 개수 : "<<makit.size()<<endl;
	
	return 0;
}
