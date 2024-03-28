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

