#include <stdio.h>
#include <stdlib.h>
#include<algorithm>
#include<iostream>

using namespace std;

#define REQUESTS 15

int start = 0;

int ran_array[REQUESTS];

int fcfs(int *ran_array) {

	int i = 0, head_movement = 0, this_start = ran_array[start];

    for(i = start; i < REQUESTS; i++) {

    	head_movement += abs(ran_array[i] - this_start);
    }

    for(i = 0; i < start; i++) {

    	head_movement += abs(this_start - ran_array[i]);
    }
        
    return head_movement;
}


int sstf(int *ran_array) {

	sort(ran_array, ran_array + REQUESTS);

	int small_i = start-1, large_i = start+1;
	int small_diff = 0, large_diff = 0;
	int head_movement = 0, total = REQUESTS-2, new_head = start, head_value = ran_array[start];
	
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


int scan(int *ranArray) {
	sort(ran_array, ran_array + REQUESTS);

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

	for(i = start+1; i < REQUESTS; i++) {

		curr_val = ran_array[i];
		difference = abs(curr_val - sav_val);
		head_movement += difference;
		sav_val = curr_val;

	}

	return head_movement;

}

int cscan(int *ranArray) {
	//sort(ran_array, ran_array + REQUESTS);

	int i = 0, curr_val = 0, sav_val = ran_array[start], difference = 0;
	int head_movement = 0, curr_i = 0, upper_bound = 199;

	for(i = start+1; i < REQUESTS; i++) {

		curr_val = ran_array[i];
		difference = abs(sav_val - curr_val);
		head_movement += difference;
		sav_val = curr_val;

	}

	head_movement += upper_bound - sav_val;
	sav_val = 0;
	head_movement += 199;

	for(i = 0; i < start; i++) {

		curr_val = ran_array[i];
		difference = abs(curr_val - sav_val);
		head_movement += difference;
		sav_val = curr_val;

	}

	return head_movement;
}


int look(int *ranArray) {

	int i = 0, curr_val = 0, sav_val = ran_array[start], difference = 0;
	int head_movement = 0, curr_i = 0;

	for(i = start+1; i < REQUESTS; i++) {

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

int clook(int *ranArray) {

	int i = 0, curr_val = 0, sav_val = ran_array[start], difference = 0;
	int head_movement = 0, curr_i = 0;

	for(i = start+1; i < REQUESTS; i++) {

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


	int i = 0;
	time_t t;
	//srand((unsigned) time_t(&t));

	for(i = 0; i < REQUESTS; i++) {

		ran_array[i] = rand() % 200;
	}
	cout << "Cylinders: " << endl;
	for(i = 0; i < REQUESTS; i++) {

		cout << ran_array[i] << " ";
	}

	printf("\nFCFS head movements: %d\n", fcfs(ran_array));
	printf("SSTF head movements: %d\n", sstf(ran_array));
	printf("SCAN head movements: %d\n", scan(ran_array));
	printf("CSCAN head movements: %d\n", cscan(ran_array));
	printf("LOOK head movements: %d\n", look(ran_array));
	printf("C-LOOK head movements: %d\n\n", clook(ran_array));

	return 0;
}

