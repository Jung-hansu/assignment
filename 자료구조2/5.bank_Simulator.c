#include "./queue.h"

int main(){
	int service_time1 = 0, service_time2 = 0, total_wait = 0;
	int service_customer1, service_customer2, total_customer = 1;
	int minutes = 60;
	QType *queue = createQueue();

	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++){
		printf("����ð�=%d\n", clock);
		if ((rand() % 10) < 6){
			element customer;
			customer.id = total_customer++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enQueue(queue, customer);
			printf("�� %d�� %d�п� ���ɴϴ�. ����ó���ð�= %d��\n", customer.id, customer.arrival_time, customer.service_time);
		}
		if (service_time1 || service_time2){
			if (--service_time1 > 0)
				printf("�� %d Aâ������ ����ó�����Դϴ�.\n", service_customer1);
			if (--service_time2 > 0)
				printf("�� %d Bâ������ ����ó�����Դϴ�.\n", service_customer2);
		}
		if (!is_empty(queue) && service_time1 <= 0){
			element customer = deQueue(queue);
			service_customer1 = customer.id;
			service_time1 = customer.service_time;
			printf("�� %d�� %d�п� Aâ������ ������ �����մϴ�. ���ð��� %d���̾����ϴ�.\n", customer.id, clock, clock - customer.arrival_time);
			total_wait += clock - customer.arrival_time;
		}
		else if (!is_empty(queue) && service_time2<= 0){
			element customer = deQueue(queue);
			service_customer2 = customer.id; 
			service_time2 = customer.service_time;
			printf("�� %d�� %d�п� Bâ������ ������ �����մϴ�. ���ð��� %d���̾����ϴ�.\n", customer.id, clock, clock - customer.arrival_time);
			total_wait += clock - customer.arrival_time;
		}
	}
	printf("��ü ��� �ð� = %d��\n", total_wait);
	return 0;
}
