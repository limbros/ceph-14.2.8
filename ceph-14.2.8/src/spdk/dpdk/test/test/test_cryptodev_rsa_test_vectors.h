/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2018 Cavium Networks
 */

#ifndef TEST_CRYPTODEV_RSA_TEST_VECTORS_H__
#define TEST_CRYPTODEV_RSA_TEST_VECTORS_H__

#include "rte_crypto_asym.h"

#define TEST_DATA_SIZE 4096

struct rsa_test_data {
	uint8_t data[TEST_DATA_SIZE];
	unsigned int len;
};

struct rsa_test_data rsaplaintext = {
	.data = {
		0xf8, 0xba, 0x1a, 0x55, 0xd0, 0x2f, 0x85, 0xae,
		0x96, 0x7b, 0xb6, 0x2f, 0xb6, 0xcd, 0xa8, 0xeb,
		0x7e, 0x78, 0xa0, 0x50
	},
	.len = 20
};

uint8_t rsa_n[] = {
	0xb3, 0xa1, 0xaf, 0xb7, 0x13, 0x08, 0x00,
	0x0a, 0x35, 0xdc, 0x2b, 0x20, 0x8d, 0xa1, 0xb5,
	0xce, 0x47, 0x8a, 0xc3, 0x80, 0xf4, 0x7d, 0x4a,
	0xa2, 0x62, 0xfd, 0x61, 0x7f, 0xb5, 0xa8, 0xde,
	0x0a, 0x17, 0x97, 0xa0, 0xbf, 0xdf, 0x56, 0x5a,
	0x3d, 0x51, 0x56, 0x4f, 0x70, 0x70, 0x3f, 0x63,
	0x6a, 0x44, 0x5b, 0xad, 0x84, 0x0d, 0x3f, 0x27,
	0x6e, 0x3b, 0x34, 0x91, 0x60, 0x14, 0xb9, 0xaa,
	0x72, 0xfd, 0xa3, 0x64, 0xd2, 0x03, 0xa7, 0x53,
	0x87, 0x9e, 0x88, 0x0b, 0xc1, 0x14, 0x93, 0x1a,
	0x62, 0xff, 0xb1, 0x5d, 0x74, 0xcd, 0x59, 0x63,
	0x18, 0x11, 0x3d, 0x4f, 0xba, 0x75, 0xd4, 0x33,
	0x4e, 0x23, 0x6b, 0x7b, 0x57, 0x44, 0xe1, 0xd3,
	0x03, 0x13, 0xa6, 0xf0, 0x8b, 0x60, 0xb0, 0x9e,
	0xee, 0x75, 0x08, 0x9d, 0x71, 0x63, 0x13, 0xcb,
	0xa6, 0x81, 0x92, 0x14, 0x03, 0x22, 0x2d, 0xde,
	0x55
};

uint8_t rsa_d[] = {
	0x24, 0xd7, 0xea, 0xf4, 0x7f, 0xe0, 0xca, 0x31,
	0x4d, 0xee, 0xc4, 0xa1, 0xbe, 0xab, 0x06, 0x61,
	0x32, 0xe7, 0x51, 0x46, 0x27, 0xdf, 0x72, 0xe9,
	0x6f, 0xa8, 0x4c, 0xd1, 0x26, 0xef, 0x65, 0xeb,
	0x67, 0xff, 0x5f, 0xa7, 0x3b, 0x25, 0xb9, 0x08,
	0x8e, 0xa0, 0x47, 0x56, 0xe6, 0x8e, 0xf9, 0xd3,
	0x18, 0x06, 0x3d, 0xc6, 0xb1, 0xf8, 0xdc, 0x1b,
	0x8d, 0xe5, 0x30, 0x54, 0x26, 0xac, 0x16, 0x3b,
	0x7b, 0xad, 0x46, 0x9e, 0x21, 0x6a, 0x57, 0xe6,
	0x81, 0x56, 0x1d, 0x2a, 0xc4, 0x39, 0x63, 0x67,
	0x81, 0x2c, 0xca, 0xcc, 0xf8, 0x42, 0x04, 0xbe,
	0xcf, 0x8f, 0x6c, 0x5b, 0x81, 0x46, 0xb9, 0xc7,
	0x62, 0x90, 0x87, 0x35, 0x03, 0x9b, 0x89, 0xcb,
	0x37, 0xbd, 0xf1, 0x1b, 0x99, 0xa1, 0x9a, 0x78,
	0xd5, 0x4c, 0xdd, 0x3f, 0x41, 0x0c, 0xb7, 0x1a,
	0xd9, 0x7b, 0x87, 0x5f, 0xbe, 0xb1, 0x83, 0x41
};

uint8_t rsa_e[] = {0x01, 0x00, 0x01};

/** rsa xform using exponent key */
struct rte_crypto_asym_xform rsa_xform = {
	.next = NULL,
	.xform_type = RTE_CRYPTO_ASYM_XFORM_RSA,
	.rsa = {
		.n = {
			.data = rsa_n,
			.length = sizeof(rsa_n)
		},
		.e = {
			.data = rsa_e,
			.length = sizeof(rsa_e)
		},
		.key_type = RTE_RSA_KEY_TYPE_EXP,
		.d = {
			.data = rsa_d,
			.length = sizeof(rsa_d)
		}
	}
};

#endif /* TEST_CRYPTODEV_RSA_TEST_VECTORS_H__ */
