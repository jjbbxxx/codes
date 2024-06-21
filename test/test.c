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
    // ����һ�� mbuf
    struct mbuf *m = (struct mbuf *)malloc(MSIZE);
    m->m_data = m->m_dat;

    // ȡ��һ������ָ�룬���������� m_dat ��
    char *data = m->m_data + 52;  // m_dat �е�һ��ƫ�Ƶ�ַ

    // ʹ�� dtom ���ȡ���� data �� mbuf �ṹָ��
    struct mbuf *m_orig = dtom(data);

    // ��ӡ���
    printf("Original mbuf address: %p\n", (void *)m);
    printf("Recovered mbuf address: %p\n", (void *)m_orig);

    free(m);
    return 0;
}
