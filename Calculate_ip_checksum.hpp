#include <cstdint>
#include <arpa/inet.h>
#include <netinet/ip.h>

#pragma once

class Calculate_ip_checksum {
public:
	uint16_t checksum;
public:
	Calculate_ip_checksum(struct iphdr *p);
};

Calculate_ip_checksum::Calculate_ip_checksum(struct iphdr *p)
{
	p->check = 0;
	uint16_t *tmp = (uint16_t *)p;
	int result = 0;

	for (int i = 1; i <= 10; i++) {
		result += *tmp;
		tmp++;
	}

	result = result + (result >> 16);
	checksum = htons(~result);
}
