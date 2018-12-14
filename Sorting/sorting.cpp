#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono; 

//prints 100 newlines to clear terminal
void clear(){
	for(int i=0; i<100; i++){
		cout<<"\n";
	}
}

//Prints out a given vector
void printList(vector<int> &list, int size){
	
	for(int i = 0; i<size; i++){
		cout<<list[i]<<" ";
	}
	cout<<"\n\n";
}

//Swaps two ints
void swap(int *x, int *y){
	
	int temp = *x;
	*x = *y;
	*y = temp;
}

//Sorts a given vector by Selection Sort
void Selection(vector<int> &list, int size){

	cout<<"Applying Selection Sort:\n"<<endl;
	for(int i = 0; i<size-1; i++){
		int min = i;
		for(int j = i+1; j<size; j++){
			if(list[j]<list[min]){
				min = j;
			}
		}
		swap(&list[min], &list[i]);
	}
}

//Sorts a given vector by Bubble Sort
void Bubble(vector<int> &list, int size){
	
	//bool keeps track if done
	bool done;
	
	cout<<"Applying Bubble Sort:\n"<<endl;
	for(int i = 0; i < size-1; i++){
		done = true;
		for(int j = 0; j < size-i-1; j++){
			if(list[j]>list[j+1]){
				swap(list[j],list[j+1]);
				done=false;			//swapping means list is not sorted
			}
		}
		if(done==true){		//if there was no swap, list is sorted
			break;
		}
	}
}


int main(){

	clear();
	srand(time(NULL));

	vector<int> list;
	int size, choice;
	
	cout<<"What size should your list be? ";
	cin >> size;
	
	
	while(1){
		
		//fill list with random ints between 1-100
		for(int i=0; i<size; i++){
			list.push_back((rand()%100)+1);
		}
		
		//menu for asking what alg to use
		cout<<"\n\nPlease choose what sorting algorithm you want to use:"<<endl;
		cout<<"(1) Selection Sort"<<endl;
		cout<<"(2) Bubble Sort"<<endl;
		cout<<"(99) Quit"<<endl;
		cout<<":";
		cin >> choice;

		cout<<"\n\nUnsorted list:"<<endl;
		printList(list,size);
		
		//Start timer
		high_resolution_clock::time_point t1 = high_resolution_clock::now(); 

		switch(choice){
			case 1:
				Selection(list,size);
				break;
			case 2: 
				Bubble(list,size);
				break;
			case 99:
				return 0;
		}
		//end timer
		high_resolution_clock::time_point t2 = high_resolution_clock::now(); 

		auto duration = duration_cast<microseconds>(t2 - t1); 
		
  		cout<<"Sorted List"<<endl;
		printList(list, size);
		
		cout << "Time taken to sort list of size "<<size<<": "<< duration.count() << " microseconds" << endl; 
  
		//clear list each time
		list.clear();
	}
}
