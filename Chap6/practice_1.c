#include <stdio.h>

int main(void)
{
	/*
	�� �Ƕ�̵� 
	*********  �� 9�� ��ĭ 0�� i = 4 j = 0 
	 *******   �� 7�� ��ĭ 2�� i = 3 j = 1 ��ĭ�� j�� 0�� �κа� �������� ����
	  *****    �� 5�� ��ĭ 4�� i = 2 j = 2 
	   ***     �� 3�� ��ĭ 6�� i = 1 j = 3 
	    *      �� 1�� ��ĭ 8�� i = 0 j = 4 

	��ĭ : (i*2)��
    */
	int i, j;

	for (i = 4; i > 0; i--)
	{
		for (j = 0; j < 2*i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 5-i; j++)
		{
			printf("*");
		}
		

		/*for (j = 4; j > i; j--)
		{
			printf(" ");
		}

		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}*/

		printf("\n");
	}

	return 0;

}