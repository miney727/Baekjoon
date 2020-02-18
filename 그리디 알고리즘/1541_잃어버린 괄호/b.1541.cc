#include <iostream>
#include <string>
using namespace std;

int main()
{
	int hab = 0;
	bool minus = false;
	string formula,temp;
	cin >> formula;
	for (int i = 0; i < formula.length(); i++)
	{

		if ((formula[i] == '+') || (formula[i] == '-'))
		{
			if (minus)
			{
				hab -= stoi(temp);
			}
			else
			{
				hab += stoi(temp);
			}
			if (formula[i] == '-')
			{
				minus = true;
			}
			temp = "";
			continue;
		}
		temp += formula[i];
	}
	if (minus)
	{
		hab -= stoi(temp);
	}
	else
	{
		hab += stoi(temp);
	}
	cout << hab << endl;
	return 0;
}
