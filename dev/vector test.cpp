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
	cout<<"scratch ����"<<endl;
	makit.erase(makit.begin()+3);
	
	for(int i=0;i<makit.size();i++) cout<<makit[i]<<" ";
	
	cout<<endl;
	cout<<"javaã�Ƽ� ����"<<endl;
	
	vector<string>::iterator it = find(makit.begin(),makit.end(),"java");
	
	makit.erase(it);
	
	for(int i=0;i<makit.size();i++) cout<<makit[i]<<" ";
	
	cout<<endl;
	cout<<"������ �߰�"<<endl;
	
	makit.insert(makit.begin()+2,"swift");
	makit.insert(makit.end(),"algorithm");
	
	for(int i=0;i<makit.size();i++) cout<<makit[i]<<" ";
	cout<<endl;
	cout<<"��ü ���� ���� : "<<makit.size()<<endl;
	
	cout<<"��ü���� �ʱ�ȭ "<<endl;
	makit.clear();
	
	if(makit.empty())	cout<<"������ ����ֽ��ϴ�."<<endl;
	else	cout<<"��ü ���� ���� : "<<makit.size()<<endl;
	
	return 0;
}
