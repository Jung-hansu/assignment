#include "./queue.h"

int main(){
	int service_time1 = 0, service_time2 = 0, total_wait = 0;
	int service_customer1, service_customer2, total_customer = 1;
	int minutes = 60;
	QType *queue = createQueue();

	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++){
		printf("현재시각=%d\n", clock);
		if ((rand() % 10) < 6){
			element customer;
			customer.id = total_customer++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enQueue(queue, customer);
			printf("고객 %d이 %d분에 들어옵니다. 업무처리시간= %d분\n", customer.id, customer.arrival_time, customer.service_time);
		}
		if (service_time1 || service_time2){
			if (--service_time1 > 0)
				printf("고객 %d A창구에서 업무처리중입니다.\n", service_customer1);
			if (--service_time2 > 0)
				printf("고객 %d B창구에서 업무처리중입니다.\n", service_customer2);
		}
		if (!is_empty(queue) && service_time1 <= 0){
			element customer = deQueue(queue);
			service_customer1 = customer.id;
			service_time1 = customer.service_time;
			printf("고객 %d이 %d분에 A창구에서 업무를 시작합니다. 대기시간은 %d분이었습니다.\n", customer.id, clock, clock - customer.arrival_time);
			total_wait += clock - customer.arrival_time;
		}
		else if (!is_empty(queue) && service_time2<= 0){
			element customer = deQueue(queue);
			service_customer2 = customer.id; 
			service_time2 = customer.service_time;
			printf("고객 %d이 %d분에 B창구에서 업무를 시작합니다. 대기시간은 %d분이었습니다.\n", customer.id, clock, clock - customer.arrival_time);
			total_wait += clock - customer.arrival_time;
		}
	}
	printf("전체 대기 시간 = %d분\n", total_wait);
	return 0;
}
