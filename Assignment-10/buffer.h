// buffer.h file containing Circular Queue Implementation for the Producer-Consumer Problem
// Headers will be included in the source file where buffer.h will be invoked
typedef struct {
    int *arr,size,in,out;
} Buffer; // end of Buffer structure definition

Buffer* buff_init(Buffer* buf, int L) {
    buf=(Buffer*)malloc(sizeof(Buffer));
    buf->size=L;
    buf->arr=(int*)malloc(buf->size*sizeof(int));
    buf->in=buf->out=0;
    return buf;
} // end of fn.

void buff_insert(Buffer* buf, int item) {
    buf->arr[buf->in]=item;
    buf->in=(buf->in+1)%buf->size;
} // end of fn.

int buff_delete(Buffer* buf) {
    int deleted=buf->arr[buf->out];
    buf->out=(buf->out+1)%buf->size;
    return deleted;
} // end of fn.

void buff_destroy(Buffer* buf) {
    free(buf->arr);
    free(buf);
} // end of fn.