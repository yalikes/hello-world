#include<cstddef>
typedef struct CSTashTag{
	int size;
	int quantity;
	int next;
	unsigned char*  storage;
}CStash;
void initialize(CStash* s,size_t size);
void cleanup(CStash* s);
int add(CStash* s, const unsigned char* element);
unsigned char* fetch(CStash* s,int index);
int count(CStash* s);
void inflate(CStash* s,int increase);
