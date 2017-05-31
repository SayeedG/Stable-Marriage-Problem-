//Sayeed Gulmahamad
#include <iostream>
#include <cmath>
using namespace std;
   void print(int b[]){
	static int count=0;
	cout<< "answer: " << ++count << endl;
	for(int y=0;y<3;y++){
	   cout<<b[y] << " ";
	}
	   cout << endl;
	}
	void backtrack(int &c){
	   c--;
	}
//row test and diagonal tests
	bool test(int b[], int c){
	   int mp[3][3]={{0,2,1},{0,2,1},{1,2,0}};
	int wp[3][3]={{2,1,0},{0,1,2},{2,0,1}};
	
	for(int d=0; d<c; d++){ //if the same match occurs
	   if(b[c]==b[d]) return false;
	}
	for(int m=0; m<c;m++){ //test to see if unstable
	  if(mp[m][b[c]]< mp[m][b[m]] && wp[b[c]][m] < wp[b[c]][c])return false;
	  if(mp[c][b[m]]< mp[c][b[c]] && wp[b[m]][c] < wp[b[m]][m])return false;
	}
	return true;
	}

int main() {
	int mp[3][3]={0,2,1,0,2,1,1,2,0};
	int wp[3][3]={2,1,0,0,1,2,2,0,1};

	int b[3], c;
	b[0]=-1;
	c=0;
	bool frombacktrack=false;

	while(true){
	   while(c<3){
		if(!frombacktrack)
		   b[c]=0;
		   frombacktrack=false;
		   while(true){
			if(b[c]==3){
			   b[c]=0;
			   backtrack(c);
			   if(c==-1){
				return 0;
				}
			}
			else if(test(b,c))
			break;
			b[c]++;
			}
			c++;
			}
		print(b);
		c--;
		b[c]=0;
		backtrack(c);
		if(c==-1){
		   return 0;
		}
		b[c]++;
		frombacktrack=true;
	}
}
	
