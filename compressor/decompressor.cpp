#include<iostream>
#include<string>
#include<vector>


using namespace std;



int main(){
	freopen("test.ljcp","r",stdin);
	freopen("test.txt","w",stdout);
	vector<int> comp;
	int count=0,tt,k,r,p=0,p2p=0;
	char ex='\0';
	cin>>tt;
	char ans[tt][tt] = {'\0'};
	r=tt*tt;
	int i=0;
	
	while(count<r){
		cin>>i;
		if((comp.size() > 0) && (comp.size() % 2 == 1) )count+=i;
		comp.push_back(i);
	}
	count=0;
	for(i=0;i<comp.size();i+=2){
		ex=char(comp[i]);
		for(k=0;k<comp[i+1];k++){
			ans[(p)/tt][(p)%tt]=ex;
			p++;
		}
		count+=comp[i];
		p2p += 2;
	}
	cout<<tt<<endl;
	for(i=0;i<tt;i++){
		for(k=0;k<tt;k++){
			cout<<ans[i][k]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
