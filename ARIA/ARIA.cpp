#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include "GF_Mat(Calc).h"

using namespace std;
/*
* 16byte 자료형 어케담누 -> 16byte -> byte 배열에 오더링으로 담으면될듯
* 
1. 키 스케줄링
Plaintext : 00112233445566778899aabbccddeeff

Masterkey : 000102030405060708090a0b0c0d0e0f

Ciphertext : d718fbd6ab644c739da95f3be6451778
	unsigned int i;
	std::istringstream iss(key);
	iss >> std::hex >> i;

*/

byte SB[16][16] = {
	   
	 0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
	 0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
	 0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
	 0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
	 0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
	 0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
	  d0 ef aa fb 43 4d 33 85 45 f9 02 7f 50 3c 9f a8
	   51 a3 40 8f 92 9d 38 f5 bc b6 da 21 10 ff f3 d2
	   cd 0c 13 ec 5f 97 44 17 c4 a7 7e 3d 64 5d 19 73
	  60 81 4f dc 22 2a 90 88 46 ee b8 14 de 5e 0b db
	   e0 32 3a 0a 49 06 24 5c c2 d3 ac 62 91 95 e4 79
	   e7 c8 37 6d 8d d5 4e a9 6c 56 f4 ea 65 7a ae 08
	  ba 78 25 2e 1c a6 b4 c6 e8 dd 74 1f 4b bd 8b 8a
	   70 3e b5 66 48 03 f6 0e 61 35 57 b9 86 c1 1d 9e
	  e1 f8 98 11 69 d9 8e 94 9b 1e 87 e9 ce 55 28 df
	    8c a1 89 0d bf e6 42 68 41 99 2d 0f b0 54 bb 16

};

string Masterkey = "000102030405060708090a0b0c0d0e0f";//128bit 


void key_scheduling(string masterkey) {

	int padding = (256 - masterkey.length()*4)/4;

	masterkey.append(padding, '0');
	if (masterkey.length() != 64)
		fprintf(stderr, "키길이오류!");

	string KL, KR;
	KL = masterkey.substr(0, 32);
	KR = masterkey.substr(32, 32);

	byte kL[32];

	for (int i = 0; i < 32;i++) {
		std::istringstream iss(KL.substr(i,1));
		iss >> std::hex >> kL[i];
		cout << hex << kL[i];
	}
	cout << endl;

	cout << "KL :" << KL << endl;
	cout << "KR :" << KR << endl;
}

byte ARIA_Affine(byte w) {
	byte A
}

int main()
{
	
	key_scheduling(Masterkey);
	return 0;
}