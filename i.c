#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <string.h>
using namespace std;
char map[51][51];
int g,s;
int main() {
	cin >> g >>s;
	for(int i=0;i<g;i++)
		scanf("%s",map[i]);
	
	for(int i=0;i<g;i++){
	for(int x=0;x<s;x++)
		printf("%c",map[i][x]);
		cout << endl;
	}
	
	return 0;
}
