//https://leetcode.com/problems/3sum/description/
/*
Given an integer array nums, return all 
the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k,
and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int s1, int s2){
	return s1 > s2;
}

vector<vector<int>> ThreeSum(vector<int> &nums){
	std::sort(nums.begin(), nums.end(), compare);
	int p;
	int q;
	vector<vector<int>> sol {};
	for (int i=0; i<(nums.size()-2); i++){
		if (nums[i]<0){
			break;
		}
		if (i>0 &&nums[i]==nums[i-1]){
			continue;
		}
		p = i+1;
		q = nums.size()-1;
		while (p < q){
			if (nums[i]+nums[p]+nums[q]==0){
				sol.push_back({nums[i], nums[p], nums[q]});
				p++;
				while (nums[p]==nums[p-1] && p<q){
					p++;
				}
				q--;
				while (nums[q]==nums[q+1] && q>p){
					q--;
				}
			}
			else if (nums[i]+nums[p]+nums[q]<0){
				q--;
			}
			else{
				p++;
			}
		}
	}
	return sol;
}

int main(int argc, char **argv)
{
	//vector<int> nums = {-1, 0, 1, 2, -1, 4};
	//vector<int> nums = {0, 1, 1};
	vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0};
	
	vector<vector<int>> triples = ThreeSum(nums);
	
	
	
	for (vector<int> v : triples){
		for (int n: v){
			cout << n << ",  ";
		}
		cout <<"\n";
	}
	return 0;
}

