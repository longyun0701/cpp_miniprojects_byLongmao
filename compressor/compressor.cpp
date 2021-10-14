#include<iostream>
#include<string>
#include<vector>


using namespace std;



int main(){
	freopen("test.txt","r",stdin);
	freopen("test.ljcp","w",stdout);
	vector<int> comp;
	int count=0,tt,k,r,p=0,tmp;
	char ex='\0';
	cin>>tt;
	char ans[tt][tt] = {'\0'};
	r=tt*tt;
	int i=0;
	
	for(i=0;i<tt;i++){
		for(k=0;k<tt;k++){
			cin>>ans[i][k];
		}
	}
	cout<<tt<<" ";
	
	while(p<r){
		ex=ans[p/tt][p%tt];
		//cout<<p<<" "<<ex<<endl;
		tmp=0;
		while(ans[p/tt][p%tt]==ex){
			//cout<<ans[p/tt][p%tt]<<endl;
			p++;
			tmp++;
		}
		//cout<<"i'm alive"<<endl;
		comp.push_back(int(ex));
		comp.push_back(tmp);
	}
	for(i=0;i<comp.size();i++){
		cout<<comp[i]<<" ";
	}
	return 0;
}
