//Compile using g++ -std=c++11
#include <iostream>
#include <vector>
using namespace std;

void PrintVector (const vector<int> & v){
	cout <<"[";
	for (auto e:v){
		cout<<e<<" ";
	}
	cout <<"]";

}

/* Find optimal solution to one-of-a-kind coin change problem. 
 check if we can use values in L[left...right] to make a sum of value, and find
the best solution, i.e., smallest set of coins tht make this value
 @param L, first, last: specify a sub-vector where coins/values are chosen from
 @param value: the sum/value we want to make
 @pre-condition: all parameters are initialized, L[] and value are non-negative
 @post-condition: return true/false depending on the checking result, if return true,
   used vector contains coins that make up the value, with the minimul # of elements from 
   L [first...last]
*/
bool CoinChange (vector<int> & L, int first, int last, int value, vector<int> & used)
{
    //Three base cases 
    if (value==0){
 	used.clear();
	return true;
    } else if (first>last){ //no more coins to use
	used.clear();
	return false;
   } else if (value<0) {
	used.clear();
	return false;
   }

   //general case below
   vector<int> used1;
   bool ret1= CoinChange (L, first, last-1, value-L[last], used1);
   if (ret1) 
        // used1 include all values from L[first...last-1] that add up to valeu-L[last]
        used1.push_back (L[last]);
        //now: used1 include all coins used from L[first...last} that add up to value

   vector<int> used2;
   // If not using L[last]... 
   bool ret2 = CoinChange (L, first, last-1, value, used2);

   if (ret1 && ret2) {
	if (used1.size() > used2.size())
		used = used2;
	else
		used = used1;
        return true;
   } else if (ret1) {
	used = used1;
	return true;
   } else if (ret2){
	used = used2;
	return true;
   } else {
	used.clear();
	return false;
   }
} 

/* Find whether there is solution to an K-of-a-kind coin change problem. 
 check if we can use values in L[left...right] to make a sum of value, and find
the best solution, i.e., smallest set of coins tht make this value
 @param L, first, last: specify a sub-vector where coins/values are chosen from
 @param value: the sum/value we want to make
 @pre-condition: all parameters are initialized, L[] and value are non-negative
 @post-condition: return true/false depending on the checking result, if return true,
   used vector contains coins that make up the value, with the minimul # of elements from 
   L [first...last]
*/
bool CoinChangeK (const vector<int> & coins, int first, int last, int value, int K)
{
   //Todo by you ... 

}

/* Find whether there is solution to an unlimited coin change problem. 
 check if we can use values in L[left...right] to make a sum of value, and find
the best solution, i.e., smallest set of coins tht make this value
 @param L, first, last: specify a sub-vector where coins/values are chosen from
 @param value: the sum/value we want to make
 @pre-condition: all parameters are initialized, L[] and value are non-negative
 @post-condition: return true/false depending on the checking result, if return true,
   bestSolution vector contains coins that make up the value with the minimul # of elements from 
   L [first...last]
*/
bool UnlimitedCoinChange (const vector<int> & coins, int value, vector<int>& bestSolution)
{
   //Todo by you ...
   //return true;
}

int main()
{
   vector<int> coins{2,5,3,10};
   vector<int> used;

   vector<int> values{4, 6,15, 18, 30, 41}; //use this to test

  cout <<"Enter coinchangek or unlimited to test the corresponding function:";
  string command;
  cin >> command;

  if (command=="oneofakind"){
         for (auto v: values) {
  	  	if (CoinChange (coins, 0, coins.size()-1, v, used))
   		{
			cout <<"value="<<v <<" True\n";
			//display used vector
        		for (int i=0;i<used.size();i++)
				cout <<used[i]<<" ";
        		cout<<endl;
   		}
   		else 
			cout <<"Value=" << v<<" False"<<endl;
   	} 
  } else if (command=="kofakind"){  
  	//Test of K-of-a-kind
	//make 20, k=1 ==> cannot be done 
  	if (CoinChangeK (coins, 0, coins.size()-1, 20, 1)!=false)
  	{
		cout <<"fail coinchangek test case #1\n";
       		return 1; //faild coinchangeK test 
  	}
	else{
		cout <<"pass coinchangek test case #1\n";
		return 0; //pass coinchangeK test
	}

	  //Make 9, k=3 ==> can be done 
	if (CoinChangeK (coins, 0, coins.size()-1, 9, 3)!=true)
  	{
		cout <<"fail coinchangek test case #2\n";
       		return 1; //faild coinchangeK test 
  	}
	else{
		cout <<"pass coinchangek test case $2";
		return 0; //pass coinchangeK test
	}  
  } else if (command=="unlimited"){
   	//Test UnlimitedCoinChange 
	vector<int> bestSolution;

	//Make 1? ==> impossible
   	if (UnlimitedCoinChange (coins, 1,bestSolution)!=false) {
      		cout <<"Failed UnlimitedCoinChange case 1\n";
		return 1; //failed unlimited test 
	}

	//Make 15 ==> yes, best solution is using {5,10} 
   	if (UnlimitedCoinChange (coins, 15, bestSolution)!=true) {
		cout <<"Failed UnlimitedCoinChange case 2\n";
		return 1;
	}
	vector<int> expectedSol{5,10}; 
        sort (bestSolution.begin(), bestSolution.end());
	if (bestSolution!=expectedSol){
		cout <<"Failed UnlimitedCoinChange case 2\n";
		return 1;

	}

	//Make 30 ==> yes, using {10,10,10} is optimal solution
   	if (UnlimitedCoinChange (coins, 30, bestSolution)!=true) {
		cout <<"Failed UnlimitedCoinChange case 3\n";
		return 1;
	}
	vector<int> expectedSol3{10,10,10}; 
        sort (bestSolution.begin(), bestSolution.end());
	if (bestSolution!=expectedSol3){
		cout <<"Failed UnlimitedCoinChange case 3\n";
		return 1;

	}

        cout <<"Pass unlimitedCoinChange cases\n";
        return 0;
  }

}
