#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Record{
public:
	int id;
	double score;
	Record(int i,int j)
	{
		id = i;
		score = j;
	};
};


unordered_map<int,double> hightfive(vector<Record> records) 
{
	class mycompare
	{
	public:
		bool operator()(const double& p1, const double& p2) 
		{
			return (p1 > p2);
		}
	};

	// unordered_map<int,priority_queue<double,vector<double>,mycompare> > result;
	unordered_map<int,priority_queue< double,vector<double>,greater<int> > > result;
	// unordered_map<int,priority_queue<double> > result;

	for(int i=0; i< records.size(); i++)
	{

		result[records[i].id].push(records[i].score);

		if(result[records[i].id].size() > 5)
		{
			result[records[i].id].pop();
		}
	}

	unordered_map<int,double> returns;

	for(auto n:result)
	{
		int sum = 0;

		while(n.second.size())
		{
			sum+=n.second.top();
			n.second.pop();
		}

		returns[n.first] =  sum/5;
	}

	return returns;
}

int main() 
{

	int history[12][2] = {{1,91},{1,92},{2,93},{2,99},{2,98},{2,97},{1,60},{1,58},{2,100},{1,61},{1,1000},{2,1000}};

	vector< Record > records;

	for(int i=0;i<12;i++)
		records.push_back( Record(history[i][0],history[i][1]));

	unordered_map<int,double> dd = hightfive(records);

	cout<<"!!!!!!!!!!!!!!!!!!!"<<endl;
	for(auto n:dd)
		cout<<n.first<<" "<<n.second<<endl;

    return 0;
}