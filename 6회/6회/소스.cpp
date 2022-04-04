#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

int main() {
	uint8_t data[11] = { 0x12, 0x12, 0x12, 0x12, 0x12, 0xAB, 0xCD, 0x98, 0x76 };

	union _Data_ {
		uint8_t receiveData[7];

		struct {
			uint8_t head[5];
			uint8_t body[4];
			uint8_t tail[2];
		}msg;

	}storage;

	memcpy(&storage, data, 11);

	printf("head: ");
	for (int i = 0; i < 5; i++) {
		printf("%02X ", storage.msg.head[i]);
	}
	printf("\n");


	printf("body: ");
	for (int i = 0; i < 4; i++) {
		printf("%02X ", storage.msg.body[i]);
	}
	printf("\n");

	printf("tail: ");
	for (int i = 0; i < 2; i++) {
		printf("%02X ", storage.msg.tail[i]);
	}
	printf("\n");

	return 0;
}