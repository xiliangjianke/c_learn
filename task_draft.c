/*
 * programname:draft, practice for if else
 * author: neko	date: 20201128
*/

#include <stdio.h>

int main()
{
	int age=0;
	int weight=0;
	int figure=0; // 0-bad; 1-normal; 2-good
	int appearance=0; // 0-normal; 1-good

	printf("Please input age, weight, figure(0-bad,1-normal,2-good) and appearence(0-normal,1-good): ");
	scanf("%d %d %d %d",&age,&weight,&figure,&appearance);

	if (((age > 18) && (age < 25)) && ((weight > 165) && (weight < 178) && (figure == 2 ) && (appearance == 1)))
	{
		printf("Big beauty!(age: %d; weight: %d; figure: %d; appearance: %d)\n",age,weight,figure,appearance);
	}

	else if (((age > 18) && (age < 30)) && ((weight > 160) && (weight < 165) && ((figure == 2) || (figure == 1) ) && (appearance == 0) ))
	{
		
		printf("Normal beauty!(age: %d; weight: %d; figure: %d; appearance: %d)\n",age,weight,figure,appearance);
	}

	else if (((age > 35) && (age < 40)) && ((weight > 155) && (weight < 165) && ((figure == 0) || (figure == 1) ) && (appearance == 0) ))
	{
		printf("Poor beauty!(age: %d; weight: %d; figure: %d; appearance: %d)\n",age,weight,figure,appearance);
	}
	else
	{
		printf("Please input right number!(age: %d;weight: %d; figure: %d; appearance: %d)\n",age,weight,figure,appearance);
	}
}
