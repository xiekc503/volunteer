#pragma once

class CCodingConv
{
public:
	// buf     - Ŀ�껺����
	// buf_len - Ŀ�껺�����ߴ�
	// src     - ԭʼ��
	// ����ֵΪת�����Ŀ���ֽ���
	static int GB2312_2_UTF8(char * buf, int buf_len, const char * src, int src_len = 0);
	static int UTF8_2_GB2312(char * buf, int buf_len, const char * src, int src_len = 0);
};
