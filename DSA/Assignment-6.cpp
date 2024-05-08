#include<iostream>
using namespace std;

int main(){
	int num, **dist;
	string *cities;
	cout<<"Enter number of cities: "; cin>>num;
	dist = new int*[num];
	cities = new string[num];
	for(int i = 0; i<num; i++){
		dist[i] = new int[num];
		cout<<"City "<<i+1<<": ";
		cin>>cities[i];
	}
	int distance;
	for(int i = 0; i<num; i++)
		for(int j = i; j<num; j++){
			if(i==j){
				dist[i][j] = 0;
				continue;
			}
			cout<<"\nEnter distance between:\n    "
			<<cities[i]<<" and "<<cities[j]<<": ";
			cin>>distance;
			dist[i][j] = distance;
			dist[j][i] = dist[i][j];
		}
	cout<<"\n== Adjacency Matrix ==\n";
	for(int i = 0; i<num; i++) cout<<cities[i]<<'-'<<i<<"  ";
	cout<<"\n\n";for(int i = 0; i<num; i++) cout<<"    "<<i;

	for(int i = 0; i<num; i++){
		cout<<endl<<i<<' ';
		for(int j = 0; j<num; j++){
			cout.width(4);
			cout.setf(ios::right, ios::adjustfield);
			cout<<dist[i][j]<<' ';
		}
	}
	cout<<"\n\n";
	return 0;
}
