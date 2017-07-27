#include <iostream>
#include "B_Plus_Tree.h"
#include <set>
#include <ctime>

using namespace std;

int main()
{
	bptNode* root = new bptNode(true, nullptr, 3);
	/*	while (true) {
		cout << "1.insert \t2.delete \t3.search \t4.print \t5.exit \n" << flush;
		int sel(0);
		cin >> sel;
		switch (sel) {
			case 1: {
				cout << "@> ";
				int input;
				while (cin >> input) {
					if (root->find(input)) {
						cout << input << " existed." << endl;
						break;
					}
					root = root->insert(input, input);
				}
				cin.clear();
				cin.ignore(1024, '\n');
				break;
			}
			case 2: {
				cout << "@> ";
				int input;
				cin >> input;
				try {
					root = root->del(input);
					if (root->empty()) root = inherit(root);
				}
				catch (runtime_error err) {
					cout << err.what();
				}
				break;
			}
			case 3: {
				cout << "@> ";
				int input;
				cin >> input;
				if (root->find(input)) cout << root->search(input) << endl;
				else {
					cout << "Not found" << endl;
				}
				break;
			}
			case 4: {
				cout << root->traverse() << endl;
				break;
			}
			case 5: {
				return 0;
				break;
			}
			default:
				break;
		}
	}
*/
	
	set<int> testset;// = { 10, 90, 100, 110, 120, 130, 140 ,150,160, 170, 180,190, 200 };
	//20 ,30, 40 , 50, 60, 70, 80, 
	srand(time(0));
	for (int i = 0; i != 5000; i++) {
		int n = rand() % 20000;
		if (testset.find(n)==testset.end()) testset.insert(n);
	}
	for (set<int>::const_iterator it = testset.cbegin(); it != testset.cend(); ++it) {
		root = root->insert(*it, *it);
	}

	cout << root->traverse() << endl;

	/*   del 150
	root = root->del(150);
	root = inherit(root);
	//   del 10
	root = root->del(10);
	root = inherit(root);
	//   del 170
	root = root->del(170);
	root = inherit(root);
	*/
	/*for (set<int>::iterator it = testset.begin(); it != testset.end(); ++it) {
		root = root->del(*it);
		root = inherit(root);
		cout << "\n";
		cout << root->traverse() << endl;
		//testset.erase(it);
	}*/
	
	for (int i = 0; i != 10 && !testset.empty() && !root->empty(); ++i) {
		int n = rand() % testset.size();
		set<int>::iterator it = testset.begin();
		while (--n > 0) it++;
		root = root->del(*it);
		root = inherit(root);
		cout << root->traverse() << endl;
		testset.erase(it);
	}
	
	int flag = 1;
	for (int i = 0; i != 2000; ++i) {
		flag = (flag + rand()) % 3;
		if (flag == 0) {
			if (testset.empty() || root->empty()) continue;
			int n = rand() % testset.size();
			set<int>::iterator it = testset.begin();
			while (--n > 0) it++;
			root = root->del(*it);
			root = inherit(root);
			testset.erase(it);
		}
		else {
			int n = rand() % 100000;
			if (testset.find(n) == testset.end()) {
				testset.insert(n);
				root->insert(n, n);
			}
			else continue;
		}
	}
	cout << root->traverse() << endl;
	return 0;
}