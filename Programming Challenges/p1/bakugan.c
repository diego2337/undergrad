#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
	int R, mark[11], leti[11], m_sum, l_sum, i;
	bool first;
	scanf("%d", &R);
	while(R != 0)
	{
		m_sum = 0;
		l_sum = 0;
		first = true;
		for(i = 0; i < R; i++)
		{
			scanf("%d", &mark[i]);
		}
		for(i = 0; i < R; i++)
		{
			scanf("%d", &leti[i]);
		}
		for(i = 0; i < R; i++)
		{
			if(i >=2 && first)
			{
				if(mark[i] == mark[i-1] && mark[i-1] == mark[i-2])
				{
					if(leti[i] == leti[i-1] && leti[i-1] == leti[i-2])
					{
						/*Do nothing*/
					}
					else
					{
						m_sum = m_sum + 30;
					}
					first = false;
				}
				else if(leti[i] == leti[i-1] && leti[i-1] == leti[i-2])
				{
					if(mark[i] == mark[i-1] && mark[i-1] == mark[i-2])
					{
						/*Do nothing*/
					}
					else
					{
						l_sum = l_sum + 30;
					}
					first = false;
				}
			}
			m_sum = m_sum + mark[i];
			l_sum = l_sum + leti[i];
		}
		if(m_sum == l_sum)
			printf("T");
		else if(m_sum > l_sum)
			printf("M");
		else
			printf("L");
		printf("\n");
		scanf("%d", &R);
	}
	return 0;
}