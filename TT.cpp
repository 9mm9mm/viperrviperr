#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class T
{
 int P;
 int *v;
 public:
 int n;
 T(int P, int n = 0){
  if(P&&n){
   this->P=P;v=new int[this->n=n];
   for(int i=0;i<n;i++){v[i]=int();}}
  else{SetZero();}}
 T(){SetZero();}
 ~T(){Clean();}
 T(const T&b){CopyOnly(b);}
 T& operator=(const T&b){if(&b!=this){Clean();CopyOnly(b);}return *this;}
 void SetZero(){v=nullptr;n=0;P=0;};
 void Clean(){delete[] v, SetZero();};
 
 void CopyOnly(const T& b){
  if(b.n != 0){
   v=new int[n=b.n];
   for(int i=0;i<n;i++){
    v[i]=b.v[i];}
   P=b.P;
  }
  else{SetZero();}
 }

 T(const vector<int>&b){
  if(!b.empty()){
   this->n=b.size()-1;
   v=new int[n];
   P=b[0];
   for(int i=0;i<this->n;i++){
    v[i]=b[i+1];}
  }
  else{SetZero();}
 }
 int& operator[](int i){if(i>=n){cout<<i<<"index error";}return v[i];}
 const int& operator[](int i)const{return v[i];}
 
 void sort(){
  if (n==0) return;
  if (P==1){
   for(int i = 0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
     if(v[j]<v[j+1]){swap(v[j],v[j+1]);}
    }
   }
  }
  else{
   for(int i = 0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
     if(v[j]>v[j+1]){swap(v[j],v[j+1]);}
    }
   }
  }
 }
 
 void print(ostream &os) const{
  os<<P<<"~~~";
  for (int i = 0; i<n;i++){
   os<<v[i]<<' ';
  }
  os<<'\n';
 }
};

int main(){
 ofstream out("data.res");
 T* matrix;
 int n = 0;
 for(int I=0;I<2;I++){
  ifstream in("data.dat");
  if (!in){out<<"ERROR"<<endl; return -1;}
  string line;
  if(I==0){
   while(getline(in,line)){if(line.empty()){continue;}n++;}
   matrix = new T[n];
  }
  else{
   int i = 0;
   int all = 0; int maximum = 0; int cur = 0;
   while(getline(in, line)){
    int num;
    if(line.empty()){continue;}
    istringstream iss(line);
    vector<int> values;
    while(iss>>num){
     values.push_back(num);}
    matrix[i]=values;
    cur = values.size();
    if(cur>maximum){maximum=cur;}
    i++;
    all+=cur;
   }
   if ((all-i)%(maximum-1)!=0){out<<"ERROR"<<endl;delete[] matrix; return -1;}
   else{
    for(int j=0;j<n;j++){matrix[j].sort();}

    for (int i = 0; i < n - 1; i++) {
     for (int j = 0; j < n - i - 1; j++) {
      if (matrix[j][matrix[j].n-1] < matrix[j + 1][matrix[j + 1].n-1]) {
       swap(matrix[j], matrix[j + 1]);
      }
     }
    }
    for (int j=0;j<n;j++){matrix[j].print(out);}
    out<<endl;
   }
  }
  in.close();
 }
 delete[] matrix;
 out.close();
 return 0;
}
  
  











 