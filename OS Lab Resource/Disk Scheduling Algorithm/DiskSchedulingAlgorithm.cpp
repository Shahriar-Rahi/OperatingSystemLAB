#include <stdio.h>
#include <stdlib.h>
#include<algorithm>
#include<iostream>
#include<time.h>

using namespace std;

//int REQUESTS;
int trail_track;

int start = 0;

//int ran_array[REQUESTS];

int fcfs(int *ran_array, int arr_size) {
	//int arr_size = sizeof ran_array / sizeof ran_array[0];
	int i = 0, head_movement = 0, this_start = ran_array[start];

    for(i = start; i < arr_size; i++) {

    	head_movement += abs(ran_array[i] - this_start);
    }

    for(i = 0; i < start; i++) {

    	head_movement += abs(this_start - ran_array[i]);
    }
        
    return head_movement;
}


int sstf(int *ran_array, int arr_size) {

	//sort(ran_array, ran_array + REQUESTS);
	//int arr_size = sizeof ran_array / sizeof ran_array[0];

	int small_i = start - 1, large_i = start+1;
	int small_diff = 0, large_diff = 0;
	int head_movement = 0, total = arr_size-2, new_head = start, head_value = ran_array[start];
	
	while(total >= 0) {

		small_diff = abs(ran_array[new_head] - ran_array[small_i]);
		large_diff = abs(ran_array[large_i] - ran_array[new_head]);

		if(small_diff < large_diff) {

			head_movement += small_diff;
			new_head = small_i;
			small_i--;
			
		} else {

			head_movement += large_diff;
			new_head = large_i;
			large_i++;
		}

		total--;

	}

	return head_movement;

}


int scan(int *ran_array, int arr_size) {
	//sort(ran_array, ran_array + REQUESTS);
	//int arr_size = sizeof ran_array / sizeof ran_array[0];

	int i = 0, curr_val = 0, sav_val = ran_array[start], difference = 0;
	int head_movement = 0, curr_i = 0;

	for(i = start-1; i >= 0; --i) {

		curr_val = ran_array[i];
		difference = abs(sav_val - curr_val);
		head_movement += difference;
		sav_val = curr_val;

	}

	head_movement += sav_val;
	sav_val = 0;

	for(i = start+1; i < arr_size; i++) {

		curr_val = ran_array[i];
		difference = abs(curr_val - sav_val);
		head_movement += difference;
		sav_val = curr_val;

	}

	return head_movement;

}

int cscan(int *ran_array, int arr_size) {
	//sort(ran_array, ran_array + REQUESTS);
	//int arr_size = sizeof ran_array / sizeof ran_array[0];
	int i = 0, curr_val = 0, sav_val = ran_array[start], difference = 0;
	int head_movement = 0, curr_i = 0, upper_bound = trail_track - 1;

	for(i = start+1; i < arr_size; i++) {

		curr_val = ran_array[i];
		difference = abs(sav_val - curr_val);
		head_movement += difference;
		sav_val = curr_val;

	}

	head_movement += upper_bound - sav_val;
	sav_val = 0;
	head_movement += trail_track - 1;

	for(i = 0; i < start; i++) {

		curr_val = ran_array[i];
		difference = abs(curr_val - sav_val);
		head_movement += difference;
		sav_val = curr_val;

	}

	return head_movement;
}


int look(int *ran_array, int arr_size) {
	//int arr_size = sizeof ran_array / sizeof ran_array[0];
	int i = 0, curr_val = 0, sav_val = ran_array[start], difference = 0;
	int head_movement = 0, curr_i = 0;

	for(i = start+1; i < arr_size; i++) {

		curr_val = ran_array[i];
		difference = abs(sav_val - curr_val);
		head_movement += difference;
		sav_val = curr_val;

	}

	for(i = start-1; i >= 0; --i) {

		curr_val = ran_array[i];
		difference = abs(curr_val - sav_val);
		head_movement += difference;
		sav_val = curr_val;

	}

	return head_movement;
}

int clook(int *ran_array, int arr_size) {
	//int arr_size = sizeof ran_array / sizeof ran_array[0];
	int i = 0, curr_val = 0, sav_val = ran_array[start], difference = 0;
	int head_movement = 0, curr_i = 0;

	for(i = start+1; i < arr_size; i++) {

		curr_val = ran_array[i];
		difference = abs(sav_val - curr_val);
		head_movement += difference;
		sav_val = curr_val;

	}

	for(i = 0; i < start; i++) {

		curr_val = ran_array[i];
		difference = abs(curr_val - sav_val);
		head_movement += difference;
		sav_val = curr_val;

	}	

	return head_movement;
}


int main () {
	int REQUESTS;
	cout << "Number of requests: \n";
	cin >> REQUESTS;
	cout << "Trail_track: \n";
	cin >> trail_track;
	srand(time(NULL));
	int i = 0;
	//time_t t;
	//srand((unsigned) time_t(&t));
	int ran_array[REQUESTS];

	for(i = 0; i < REQUESTS; i++) {

		ran_array[i] = rand() % trail_track;
		//cin >> ran_array[i];
	}
	cout << "Cylinders: " << endl;
	for(i = 0; i < REQUESTS; i++) {

		cout << ran_array[i] << " ";
	}

	printf("\nFCFS head movements: %d\n", fcfs(ran_array, REQUESTS));
	printf("SSTF head movements: %d\n", sstf(ran_array, REQUESTS));
	printf("SCAN head movements: %d\n", scan(ran_array, REQUESTS));
	printf("CSCAN head movements: %d\n", cscan(ran_array, REQUESTS));
	printf("LOOK head movements: %d\n", look(ran_array, REQUESTS));
	printf("C-LOOK head movements: %d\n\n", clook(ran_array, REQUESTS));

	return 0;
}
