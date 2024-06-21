#include <stdio.h>
#include <stdlib.h>

#define MSIZE 256

struct mbuf {
    struct mbuf *m_next;
    struct mbuf *m_nextpkt;
    int m_len;
    char *m_data;
    int m_flags;
    char m_dat[MSIZE - sizeof(struct mbuf *) * 2 - sizeof(int) * 3 - sizeof(char *)];
};

#define dtom(x) ((struct mbuf *)((int)(x) & ~(MSIZE-1)))

int main() {
    // 分配一个 mbuf
    struct mbuf *m = (struct mbuf *)malloc(MSIZE);
    m->m_data = m->m_dat;

    // 取得一个数据指针，假设数据在 m_dat 中
    char *data = m->m_data + 52;  // m_dat 中的一个偏移地址

    // 使用 dtom 宏获取包含 data 的 mbuf 结构指针
    struct mbuf *m_orig = dtom(data);

    // 打印结果
    printf("Original mbuf address: %p\n", (void *)m);
    printf("Recovered mbuf address: %p\n", (void *)m_orig);

    free(m);
    return 0;
}
