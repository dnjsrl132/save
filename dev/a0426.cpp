#include<iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int i=0;
    while(seoul[i]!="\0"){
        if(seoul[i]=="Kim") break;
        i++;
    }
    answer+="abc";
    return answer;
}
int main(){
	vector<string> s;
	for(int i=0;i<2;i++){
		getline(cin,s[i]);
	}
	printf("%s",solution(s));
	return 0;
}
