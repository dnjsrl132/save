#include <stdio.h>

double Answer;

int main(void)
{
	int T, test_case;
	int R,s,e,t;
	int l,r,h;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		Answer=0;
		scanf("%d %d %d",&R,&s,&e);
        scanf("%d",&t);
        for(int i=0;i<t;i++){
        	scanf("%d %d %d",&l,&r,&h);
        	Answer+=r-s-R;
        	if(h>R) Answer+=2*(h-R);
        	s=R+r;
		}
		Answer+=t*3.1415926*R;
		printf("Case #%d\n", test_case+1);
	        	printf("%lf\n", Answer);
	}
	return 0;
}
