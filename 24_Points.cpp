//这是正版24，11.20改的

#include <iostream>
#include <stack>
#include <vector>
#include <set>
//#include <string>
using namespace std;

struct node{
	int x=0,y=1;
}now;
int a[5];

bool st[5];
char opert[4]={'+','-','*','/'};
//vector<string> act;
set<string> act;
string chang="";

int gcd(int a,int b)
{
	if(a==0&&b==0) return 1;
	if(b==0) return a;
	return gcd(b,a%b);
}

node  fun(node now,int num,char op)
{
	if(chang=="") chang+=to_string(now.x);
	switch (op) {
	case '+':
		//TODO
		now.x=now.x+now.y*num;
		if(now.x==0) now.y=1;
		else{
			int g=gcd(now.x,now.y);
			now.x/=g,now.y/=g;
		}
		break;
	case '-':
		//TODO
		now.x=now.x-now.y*num;
		if(now.x==0) now.y=1;
		else{
			int g=gcd(now.x,now.y);
			now.x/=g,now.y/=g;
		}
		
		break;
	case '*':
		now.x=now.x*num;
		if(now.x==0) now.y=1;
		else{
			int g=gcd(now.x,now.y);
			now.x/=g,now.y/=g;
		}
		break;
	case '/':
		now.y=now.y*num;
		if(now.x==0) now.y=1;
		else{
			int g=gcd(now.x,now.y);
			now.x/=g,now.y/=g;
		}
		break;
	default:
		//TODO
		break;
	}
	return now;
}


//换个顺序的
node fun2(int num,node now,char op)
{
	if(chang=="") chang+=to_string(num);
	int t=now.x;
	switch (op) {
	case '+':
		//TODO
		now.x=now.x+now.y*num;
		if(now.x==0) now.y=1;
		else{
			int g=gcd(now.x,now.y);
			now.x/=g,now.y/=g;
		}
		break;
	case '-':
		//TODO
		//if(chang=="") chang+=to_string(num);
		now.x=now.y*num-now.x;
		if(now.x==0) now.y=1;
		else{
			int g=gcd(now.x,now.y);
			now.x/=g,now.y/=g;
		}
		
		break;
	case '*':
		now.x=now.x*num;
		if(now.x==0) now.y=1;
		else{
			int g=gcd(now.x,now.y);
			now.x/=g,now.y/=g;
		}
		break;
	case '/':
		//if(chang=="") chang+=to_string(num);
		now.x=now.y*num;
		now.y=t;
		if(now.x==0) now.y=1;
		else{
			int g=gcd(now.x,now.y);
			now.x/=g,now.y/=g;
		}
		break;
	default:
		//TODO
		break;
	}
	return now;
}

void dfs(node now,int u)
{
	if(u==0)
	{
		if(now.x==24&&now.y==1) act.insert(chang);
		//chang="";
		return ;
	}
	for(int i=1;i<=4;i++)
	{
		if(st[i]==1) continue;
		
		for(int j=0;j<4;j++)
		{
			st[i]=1;
			if((j==3&&a[i]!=0)||j!=3)
			{
				node now1=fun(now,a[i],opert[j]);
				{chang.insert(0,"(");chang+=opert[j];chang+=to_string(a[i]);chang+=')';}
				dfs(now1,u-1);
				//delete
				{
					int co1=to_string(a[i]).size(),co2=chang.size();
					chang.erase(co2-co1-2,co1+2);
					chang.erase(0,1);
				}
			}
			
			if(opert[j]=='-'||opert[j]=='/')
			{
				if((j==3&&now.x!=0)||j!=3)
				{
					node now2=fun2(a[i],now,opert[j]);
					{string uu ="";uu+=opert[j];chang.insert(0,uu);chang.insert(0,to_string(a[i]));chang.insert(0,"(");chang+=')';}
					//{chang.insert(0,"(");chang+=opert[j];chang+=to_string(a[i]);chang+=')';}
					dfs(now2,u-1);
					//delete
					{
						int co1=to_string(a[i]).size(),co2=chang.size();
						chang.erase(co2-1,1);
						chang.erase(0,co1+2);
						
					}
				}
				
			}
			
			st[i]=0;
			
		}
		
	}
	
}

int main() 
{
	system("chcp 65001");
	printf("这是一个计算24点的程序。请输入4个整数：\n");
	for(int i=1;i<=4;i++)
		cin>>a[i];
	
	for(int i=1;i<=4;i++)
	{
		//chang+=to_string(a[i]);
		chang="";
		now.x=a[i];now.y=1;
		st[i]=1;
		dfs(now,3);
		st[i]=0;
	}
	
	cout<<act.size()<<endl;
	//return 0;
	for(auto i:act)
	{
		cout<<i<<endl;
	}
	return 0;
}



/*
def fun():
print('这是一个计算24点的程序。请输入4个整数：')
print('①：')
a=int(input())
print('②：')
b=int(input())
print('③：')
c=int(input())
print('④：')
d=int(input())
l=[a,b,c,d]
l.sort()
for(int i=0;i<4;i++)
*/

