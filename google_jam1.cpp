#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
ifstream in{ "A-large.in" };
ofstream out{ "out.txt" };

struct re
{
	re(char v, int c) : val(v), count(c){};
	char val;
	int count;
};

vector<re> res;
vector<int> split;


void func(const string& phone_num,const vector<int>& split)
{
	res.clear();
	for (int i = 0,sp_in=0; i < phone_num.size();sp_in++)
	{
		for (int j = 0; j < split[sp_in]; j++)
		{
			if (j == 0)
			{
				//res.push_back(new re{ phone_num.at(i), 1 });
				re tmp(phone_num.at(i), 1);
				res.push_back(tmp);
			}
			else
			{
				if (phone_num.at(i) == phone_num.at(i - 1))
					res[res.size() - 1].count++;
				else
				{
					//res.push_back(new re{ phone_num.at(i), 1 });
					re tmp(phone_num.at(i), 1);
					res.push_back(tmp);
				}
			}
			i++;
		}
	}
}
void output_num(char x)
{
	switch (x)
	{
	case '0':
		out << "zero";
		break;
	case '1':
		out << "one";
		break;
	case '2':
		out << "two";
		break;
	case '3':
		out << "three";
		break;
	case '4':
		out << "four";
		break;
	case '5':
		out << "five";
		break;
	case '6':
		out << "six";
		break;
	case '7':
		out << "seven";
		break;
	case '8':
		out << "eight";
		break;
	case '9':
		out << "nine";
		break;
	}
}
void output(ostream& out, re& r, bool is_first)
{
	if (!is_first)
		out << " ";
	if (r.count > 10)
	{
		for (int xx = 0; xx < r.count; xx++)
		{
			output_num(r.val);
			if (xx != r.count - 1)
				out << " ";
		}
		return;
	}
	//bool count_more_one = true;
	switch (r.count)
	{
	case 2:
		out << "double ";
		break;
	case 3:
		out << "triple ";
		break;
	case 4:
		out << "quadruple ";
		break;
	case 5:
		out << "quintuple ";
		break;
	case 6:
		out << "sextuple ";
		break;
	case 7:
		out << "septuple ";
		break;
	case 8:
		out << "octuple ";
		break;
	case 9:
		out << "nonuple ";
		break;
	case 10:
		out << "decuple ";
		break;
	default:
		break;
	}
	output_num(r.val);
}
void splitv(string& split_f)
{
	split.clear();
	string tmp;
	for (auto i = 0; i < split_f.size();i++)
	{
		//string tmp;
		if (split_f.at(i) == '-')
		{
			split.push_back(stoi(tmp));
			tmp.clear();
		}
		else
			tmp.append(split_f.substr(i,1));
		if (i == split_f.size()-1)
			split.push_back(stoi(tmp));
		//split.push_back(split_f.at(i) - '0');
		//i += 2;
	}
}
int main()
{
	int case_num;
	string phone, split_f;
	in >> case_num;
	for (int x = 0; x < case_num; x++)
	{
		out << "Case #" << x+1 << ": ";
		in >> phone >> split_f;
		splitv(split_f);
		func(phone, split);
		bool is_first = true;
		for (int i = 0; i < res.size(); i++)
		{
			if (i == 0)
			{
				output(out, res[i], is_first);
				is_first = false;
			}
			else
				output(out, res[i], is_first);
		}
		if (x!=case_num-1)
			out << endl;
	}
	return 0;
}
