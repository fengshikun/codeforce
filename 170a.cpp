#include <iostream>
#include <set>
#define M 500
using namespace std;


struct people
{
	set<int> langs;
	int pa;
};
people peoples[M];

int find_pa(int index)
{
	if (peoples[index].pa!=index)
	{
		return find_pa(peoples[index].pa);
	}
	else
		return index;
}
void init(int n)
{
	for (int i=0;i<n;i++)
		peoples[i].pa=i;
}
void unionP(int n1,int n2)
{
	int x=find_pa(n1),y=find_pa(n2);
	if (x!=y)
		peoples[x].pa=y;
}
int reslut(int n)
{
	int re=-1;
	for (int x=0;x<n;x++)
		if (peoples[x].pa==x)
			re++;
	return re;
}
int main()
{
	int n,m;
	cin>>n>>m;
	init(n);
	int langs,ltmp;
	bool know_nothing=true;
	for (int i=0;i<n;i++)
	{
		cin>>langs;
		if(langs!=0)
			know_nothing=false;
		for (int j=0;j<langs;j++)
		{
			cin>>ltmp;
			peoples[i].langs.insert(ltmp);
			for (int k=0;k<i;k++)
				if(peoples[k].langs.count(ltmp)>0)
					unionP(k,i);
		}
	}
	if(!know_nothing)
		cout <<reslut(n)<<endl;
	else
		cout<<n<<endl;
	//system("pause");
	return 0;
}