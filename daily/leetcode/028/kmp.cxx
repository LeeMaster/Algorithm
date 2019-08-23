#include<vector>
#include<string>
#include<iostream>

using namespace std;

/**
 * for substrings in needle
 *  next[substring.tail] = max(pre,tail); //find the max bifix length as the index 
 * 
 */
vector<int> next(string needle){
  vector<int> result(needle.size());
  result[0] = -1;
  int k = -1;
  int j = 0;
  while(j < needle.size() - 1){
    if(k == -1 || needle[j] == needle[k]){
      k++;
      j++;
      result[j] = k;
    }else{
      k = result[k];
    }
  }
  return result;
}

/**
 * KMP 算法主要的目标是在每一次失配的时候，通过一个失配数组获取j下一次匹配的位置
 */
int kmp(string haystack,string needle){
  if(needle.empty())return 0;
  auto fail = next(needle);
  int i = 0,j = 0;
  while(i < haystack.size() && j < needle.size()){
    if(j == -1 || haystack[i] == needle[j]){
      i++;
      j++;
    }else{
      j = fail[j];
    }
  }
  if(j == needle.size())return i - j;
  return -1;
}


#define TEST(N) test##N

void test1(){
  cout << "Test1: " << (kmp("helllo","") == 0) << endl;  
}

void test2(){
  cout << "Test2: " << (kmp("helllo","hexx") == -1) << endl;   
}

void test3(){
  cout << "Test3: " << (kmp("helllo","hell") == 0) << endl; 
}

void test4(){
  cout << "Test4: " << (kmp("helllo","ll") == 2) << endl;  
}

void test5(){
  cout << "Test5: " << (kmp("helllo","ellx") == -1) << endl;    
}

void test6(){
  cout << "Test6: " << (kmp("","ellx") == -1) << endl;     
}

void test7(){
  cout << "Test6: " << (kmp("ellx","ellx") == 0) << endl;
}

int main(){
  TEST(1)();
  TEST(2)();
  TEST(3)();
  TEST(4)();
  TEST(5)();
  TEST(6)();
  TEST(7)();
}



