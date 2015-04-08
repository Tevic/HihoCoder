#include "..\Head.h"

struct Module
{
	int wakeUpSignal;
	vector<int> sendSignal;
};

int main()
{
	freopen("Input.txt", "r", stdin);
	int nCase;
	cin >> nCase;
	for (size_t i = 0; i < nCase; i++)
	{
		int nModules, nSignals;
		cin >> nModules >> nSignals;
		queue<int> signalQueue;
		vector<Module*> moduleList;
		vector<int> wakeUpTimes(nModules);
		for (size_t i = 0; i < nSignals; i++)
		{
			int signal;
			cin >> signal;
			signalQueue.push(signal);
		}
		for (size_t i = 0; i < nModules; i++)
		{			
			Module* md = new Module();
			int wakeUpSignal;
			cin >> wakeUpSignal;
			md->wakeUpSignal = wakeUpSignal;
			wakeUpTimes[i]=0;
			int countSend;
			cin >> countSend;
			for (size_t i = 0; i < countSend; i++)
			{
				int signal;
				cin >> signal;
				md->sendSignal.push_back(signal);
			}
			moduleList.push_back(md);
		}
		while (!signalQueue.empty())
		{
			int signal = signalQueue.front();
			vector<int> wakeList;
			for (size_t i = 0; i < moduleList.size(); i++)
			{
				if (signal==moduleList[i]->wakeUpSignal)
				{
					wakeUpTimes[i]++;
					wakeList.push_back(i);
				}
			}
			for (size_t i = 0; i < wakeList.size(); i++)
			{
				for (size_t j = 0; j < moduleList[wakeList[i]]->sendSignal.size(); j++)
				{
					signalQueue.push(moduleList[wakeList[i]]->sendSignal[j]);
				}
			}
			signalQueue.pop();
		}
		for (size_t i = 0; i < wakeUpTimes.size(); i++)
		{
			cout << wakeUpTimes[i] << ' ';
		}
		cout << endl;
	}
}