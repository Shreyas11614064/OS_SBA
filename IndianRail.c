#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define SIZE 1500

struct station{
	int train[100];
	int seats[100][SIZE];
	int passenger[30000];
}s, *station;

struct arg_struct{
	struct station *station;
	int s;
	int t;
}args;
	
void station_init();
void *station_load_train(struct station *station, int count, int train_no);
void *station_wait_for_train(struct station *station);
void *station_on_board(struct station *station);

int i, j, n, pass, count, temp, seats_occupied;

int main(){
	pthread_t a_thread[100];
	void *thread_result;
	station_init();
	*station = &s;
	args.(*station) = *station;
	args.s = SIZE;
	for(i = 0; i < n; i++){
		printf("Train no. %d is arriving.", i+1);
		args.t = i;
		pthread_create(&a_thread[i], NULL, station_load_train, (void *)&args);
	}
}

void station_init(){
	printf("Enter the number of trains to arrive : ");
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		s.train[i] = 0;
		for(j = 0; j < SIZE; j++){
			s.seats[i][j] = 0;
		}
	}
	printf("Enter the number of passengers waiting : ");
	scanf("%d", &pass);
	for(i = 0; i < pass; i++){
		s.passenger[pass] = 1;
	}
}

void *station_load_train(void *arguments){
	struct arg_struct *args = (struct arg_struct *)arguments;
	
	
	
